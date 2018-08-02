#include "../JuceLibraryCode/JuceHeader.h"
#include "SoundComponent.h"
/* ------------------------------------------------------------ */
SoundComponent::SoundComponent() :
	songTitle("Press W or S"),
	wkey('w'),
	skey('s'),
	isSelected(false)
{
	loadSongList();
	songListIter = songList.begin();
}

SoundComponent::~SoundComponent()
{
	
}

void SoundComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
	g.setColour(Colour(Colours::magenta));

	g.setFont(40.0f);
	g.drawText("w(prev) / s(next)",0,0,getWidth(),getHeight()/4,Justification::centred,true); // triangle

	g.setColour(Colour(Colours::deepskyblue));
	g.setFont(30.0f);
	g.drawText(songTitle,0,0,getWidth(),getHeight()/2,Justification::centred,true);
	/*
	Path wqTriangle;
	wqTriangle.addTriangle(getWidth()/2,getHeight()/10,getWidth()/2-getWidth()/8,getHeight()/8,getWidth()/2+getWidth()/8,getHeight()/8);
	g.fillPath(wqTriangle);
	*/
	
}

void SoundComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}

bool SoundComponent::keyPressed(const KeyPress& key)
{
	// no event = return false, else return true . no touch. is ok
	
	if(key == skey && *songListIter != songList.back())
	{
		DBG(*songListIter);
		setSongTitle(getNextSongTitle());
		repaint();
		return true;
	}
	else if(key == wkey && songListIter != songList.begin())
	{
		DBG(*songListIter);
		setSongTitle(getPrevSongTitle());
		repaint();
		return true;
	}
	else if (key == KeyPress::returnKey) {
		changeIsSelected();
		return true;
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

	for(auto& i : songList)
		DBG(i);
}

void SoundComponent::setSongTitle(const std::string& st)
{
	songTitle = st;
}

std::string& SoundComponent::getNextSongTitle() 
{
	return *(++songListIter);	
}

std::string& SoundComponent::getPrevSongTitle() 
{
	return *(--songListIter);
}

std::string SoundComponent::getSongTitle() const
{
	return songTitle;
}

void SoundComponent::changeIsSelected()
{
	DBG("SoundComponent::changeIsSelected()");
	isSelected = !isSelected;
}

bool SoundComponent::getIsSelected() const
{
	return isSelected;
}


Audio::Audio() :state(Stopped), file("./Song/aya.wav")
{
	
	formatManager.registerBasicFormats();       // [1]
//	transportSource.addChangeListener(this);
	changeState(Playing);
	setAudioChannels (0, 2); 
	SelectSong();
}

Audio::~Audio()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

void Audio::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
	// AudioSource의 구현부. AudioSource를 구현하라.
	transportSource.prepareToPlay(samplesPerBlockExpected,sampleRate);
}

void Audio::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
	// AudioSource참고
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


void Audio::SelectSong()
{
	// debug
	//	File file("./../../../Song/Defqwop-HeartAfire.mp3");
	File file("./aya.mp3");
	// release
	auto *reader = formatManager.createReaderFor(file);
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
