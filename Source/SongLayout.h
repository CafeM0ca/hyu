#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SongLayout    : public Component
{
public:
    SongLayout();
    ~SongLayout();

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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongLayout)
};
