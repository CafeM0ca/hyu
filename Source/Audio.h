#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
/*
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
	inline TransportState GetState() const { return state; }
	void changeState(TransportState newState);
	inline String GetSongName() const { return file.getFileNameWithoutExtension(); }
	inline String GetSongMap() const { return GetSongName()+".hm";	}
	String GetSongData() { return file.loadFileAsString(); }
	double duration; 
private:
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    TransportState state;
	
	File file;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Audio)
};

*/
