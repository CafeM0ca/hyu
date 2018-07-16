#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h"
#include "SongLayout.h"
#include "NoteComponent.h"
//#include "Audio.h" //auido 임시
class Interface   : public Component
{
public:
    Interface();
    ~Interface();
    void paint (Graphics& g) override;
    void resized() override;

private:
	NoteManager noteManager;
	Map map;

//	SongLayout songLayout;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Interface)
};
