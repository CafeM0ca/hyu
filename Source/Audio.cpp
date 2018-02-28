/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "Audio.h"

//==============================================================================
Audio::Audio() :state(Stopped)
{
    // Make sure you set the size of the component after
    // you add any child components.

    // specify the number of input and output channels that we want to open
	//formatManager.registerFormat(new MP3AudioFormat(),false);
	formatManager.registerBasicFormats(); //default wav
	//transportSource.addChangeListener(this);	
    setAudioChannels (0, 2);
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

	transportSource.prepareToPlay(samplesPerBlockExpected,sampleRate);
}

void Audio::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
	if(readerSource == nullptr)
	{	
		bufferToFill.clearActiveBufferRegion();
		return;
	}
	transportSource.getNextAudioBlock(bufferToFill);
	transportSource.start();
}

void Audio::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
	transportSource.releaseResources();
}

void Audio::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	openButton.setBounds(0,0,50,30);
}

void Audio::PlaySong()
{	
	File file("/home/moca/coding/cpp/hyu/Song/Diffrent Heaven - Nekozilla.wav");
	AudioFormatReader *reader = formatManager.createReaderFor(file);

	if(reader != nullptr)
	{
		DBG("띠용");
		//ScopedPointer는 스마트 포인터 같은 개념
		ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader,true);
		transportSource.setSource(newSource,0,nullptr,reader->sampleRate);
		//playButton.setEnabled(true);
		readerSource = newSource.release();
	}
}
