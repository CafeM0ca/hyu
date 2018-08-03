#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SoundComponent    : public Component, public KeyListener
{
public:
    SoundComponent();
    ~SoundComponent();

    void paint (Graphics&) override;
    void resized() override;
	bool keyPressed (const KeyPress&, Component *) override;

	void loadSongList();	
	bool isSongSelected() const { return songSelected; }
	std::string getSongName() const { return songList.at(pos); }
private:
	std::vector<std::string> songList; 
	int pos = 0;
	std::string songTitle{ "Press W or S" };
	bool songSelected = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoundComponent)
};


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
	void selectSong(const File&);
	enum TransportState
	{
		Stopped,
		Starting,
		Playing,
		Stopping
	};
	void changeState(TransportState newState);
	double duration; 
private:
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    TransportState state;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Audio)
};
