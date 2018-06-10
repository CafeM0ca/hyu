#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h"
#include "Note.h"
#include "SongLayout.h"
//#include "Audio.h" //auido 임시
class Interface   : public Component
{
public:
    Interface();
    ~Interface();
    void paint (Graphics& g) override;
    void resized() override;

private:
	Map map;
	Note note;

	SongLayout songLayout;
	 
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Interface)
};
