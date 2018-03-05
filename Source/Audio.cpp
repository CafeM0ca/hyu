/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "Audio.h"

//==============================================================================
Audio::Audio() :state(Stopped)
{
	
	formatManager.registerBasicFormats();       // [1]
//	transportSource.addChangeListener(this);
//	changeState(Playing);
	SelectSong();
	setAudioChannels (0, 2);
//	SelectSong();
}

Audio::~Audio()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
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
	File file("/home/moca/coding/cpp/hyu/Song/test.wav");
	AudioFormatReader *reader = formatManager.createReaderFor(file);
	
	if(reader != nullptr)
	{
		//ScopedPointer는 스마트 포인터 같은 개념
		ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader,true);

		/* setSource  삽입할 소스를 설정
		 * 1 nullptr, 
		 * 2 버퍼 읽을 사이즈, 
		 * 3 백그라운드 버퍼읽기 쓰레드
		 * 4 샘플의 재생속도. 0이면 조절안함 알아서 음정도 맞춰줌
		 * 5 재생하는데 필요한 채널 수*/
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

