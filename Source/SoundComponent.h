#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SoundComponent    : public Component
{
public:
    SoundComponent();
    ~SoundComponent();

    void paint (Graphics&) override;
    void resized() override;
	bool keyPressed (const KeyPress&) override;
	void loadSongList();	
	void setSongTitle(const std::string&);
	inline std::string& getNextSongTitle(); 
	inline std::string& getPrevSongTitle();
	inline std::string getSongTitle() const;

	// for change map
	inline void changeIsSelected();
	bool getIsSelected() const;
private:
	std::vector<std::string> songList; std::vector<std::string>::iterator songListIter;
	std::string songTitle;
	const KeyPress wkey;
	const KeyPress skey;
	bool isSelected;
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
