#include "../JuceLibraryCode/JuceHeader.h"
#include "SoundComponent.h"
/* ------------------------------------------------------------ */
/*
	1. 디렉토리에서 노래제목을 다 긁어온다.
	2. 긁어온 데이터를 vector에 삽입한다.
	3. 방향키를 움직일때마다 해당하는 노래를 vector::iterator가 갖고있는다.
	4. paint()에서 vector::iterator를 출력해준다.
	5. 만약 엔터가 눌렸으면 노래 제목을 반환하고 객체를 소멸한다.
	6. 반환된 객체는 MainComponent가 넘겨받고 Audio 객체가 재생하며 noteManager을 생성한다.
*/
SoundComponent::SoundComponent()
{

	std::cout << "SoundComponent Ctor" << std::endl;
	addKeyListener(this);
	loadSongList();
}
SoundComponent::~SoundComponent()
{
		
}
void SoundComponent::paint (Graphics& g)
{
	g.fillAll(Colour(13, 13, 13));
	g.setColour(Colour(Colours::magenta));
	g.setFont(40.0f);
	g.drawText("w(prev) / s(next)", 0, 0, getWidth(), getHeight() / 4, Justification::centred,true); // triangle
	g.setColour(Colour(Colours::deepskyblue));
	g.setFont(30.0f);
	if(pos == -1)
		g.drawText("NULL", 0, 0, getWidth(), getHeight() / 2, Justification::centred,true);
	else 
		g.drawText(songList.at(pos), 0, 0, getWidth(), getHeight() / 2, Justification::centred,true);
}

void SoundComponent::resized()
{
}

bool SoundComponent::keyPressed(const KeyPress& key, Component *c)
{
	std::cout << "MainComponent keyPressed" << std::endl;
	// no event = return false, else return true . no touch. is ok
	if (c == this) {
		std::cout << "same object" << std::endl;
	}
	if (!songList.empty()) {
		if(key.getTextCharacter() == 's'  && pos < songList.size() - 1)
		{
			pos++;
			repaint();
			return true;
		}
		else if(key.getTextCharacter() == 'w' && pos > 0)
		{
			pos--;
			repaint();
			return true;
		}
		
		else if (key == KeyPress::returnKey) {
			std::cout << "SoundComponent KeyPress return key" << std::endl;
			songSelected = true;
			removeKeyListener(this);	// 더 이상 SoundComponent가 키입력을 받지 않음
			return false;		// MainComponent의  KeyPress로 전달됨
		}
	}
	return false;
}
void SoundComponent::loadSongList()
{
	DirectoryIterator iter (File ("./Song/"), true, "*.mp3");
	while (iter.next())
	{
		File filename (iter.getFile());
		songList.push_back(filename.getFileNameWithoutExtension().toStdString());
	}
	if (songList.size() == 0)
		pos = -1;
}


Audio::Audio() :state(Stopped)
{
	// prepareToPlay() -> getNextAudioBlock() -> releaseResource()
	formatManager.registerBasicFormats();       // [1]
	//transportSource.addChangeListener(this);
	changeState(Stopped);
	setAudioChannels (0, 2); 
}

Audio::~Audio()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio(); 
}

void Audio::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.
	// Audio 시작전에 호출된다. 호출된 후 오디오 스레드는 오디오 블럭들을 getNextAudioBlock() 함수를 통해서 요청하기 시작한다.
	// samplesPerBlockExpected : getNextAudioBlock() 함수에서 오디오 버퍼가 요청 될 때마다 요청할 수 있는 오디오 버퍼의 크기
	// sampleRate : 하드웨어의 현재 샘플 속도를 알려준다. 톤을 합성, 이퀄라이제이션을 사용하는 것과 같이 주파수 의존적인 작업을 수행하는 경우 필요.
	// 지연 효과를 사용하는 경우 샘플 속도를 알아야한다.
	transportSource.prepareToPlay(samplesPerBlockExpected,sampleRate);
}

void Audio::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	// AudioSourceChannelInfo->buffer : AudioSampleBuffer 객체는 여러 채널 오디오의 버퍼 데이터. 다차원 float배열.
	// getNextAudioBlock()가 호출되면 이 버퍼는 아무 오디오 데이터를 지정한 디바이스의 오디오 입력으로부터 포함.
	// AudioSampleBuffer.getNumChannels90 : 버퍼내 오디오 채널 수 반환. setAudioChannels()의 출력 채널 개수와 일치
	// AudioSourceChannelInfo.startSample : getNextAudioBlockI() 함수가 일기/쓰기를 시작해야하는 버퍼
	// AudioSourceChannelInfo.numSamples : 읽어지거나 써저야하는 버퍼안의 샘플 수

    // Your audio-processing code goes here!
    // (to prevent the output of random noise)
	if (readerSource == nullptr)
	{
		bufferToFill.clearActiveBufferRegion();
		return;
	}
	
	transportSource.getNextAudioBlock (bufferToFill);
}


void Audio::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
	// AudioSource의 구현부. 아무래도 AudioSource를 확인해야할듯.
	transportSource.releaseResources();
}

void Audio::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


void Audio::selectSong(const File& file)
{	

	AudioFormatReader *reader = formatManager.createReaderFor(file);
	if(reader != nullptr)
	{
		//재생시간 
		duration = reader->lengthInSamples / reader->sampleRate; 
		

		//ScopedPointer는 스마트 포인터 같은 개념
		ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader,true);
		/*
		 setSource  삽입할 소스를 설정
		 * 1 nullptr, 
		 * 2 버퍼 읽을 사이즈, 
		 * 3 백그라운드 버퍼읽기 쓰레드
		 * 4 샘플의 재생속도. 0이면 조절안함 알아서 음정도 맞춰줌
		 * 5 재생하는데 필요한 채널 수
		 */
		transportSource.setSource(newSource,0,nullptr,reader->sampleRate);
		readerSource = newSource.release();
		changeState(Starting); // 파일 경로지정하고 다 셋팅한 후 Starting해야함.
	}
}
 

void Audio::changeState (TransportState newState)
{
	if (state != newState)
	{
		state = newState;
		
		switch (state)
		{
			case Stopped:        
				transportSource.setPosition (0.0);
				break;
			
			case Starting:   
				// start setSource로 설정되면 재생.
				// 이 객체에 등록된 ChangeListener에 메시지를 보냄. 메시지를 보냄
				transportSource.start();
				break;
				
			case Playing: 
				break;
				
			case Stopping:
				transportSource.stop();
				break;
		}
	}
}
