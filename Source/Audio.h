/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class Audio   : public AudioAppComponent 
{
public:
    //==============================================================================
    Audio();
    ~Audio();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void resized() override;
	void SelectSong();
	enum TransportState
	{
		Stopped,
		Starting,
		Playing,
		Stopping
	};
	inline int GetSongLength(double len) const
	{
		return static_cast<int>(len);
	}
	void changeState(TransportState newState);
private:
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    TransportState state;
	
	File file;

	double duration; 
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Audio)
};
