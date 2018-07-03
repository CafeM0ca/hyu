#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h"
#include "SongLayout.h"
#include "NoteManager.h"
//#include "Audio.h" //auido 임시
class Interface   : public Component, private ChangeListener
{
public:
    Interface();
    ~Interface();
    void paint (Graphics& g) override;
    void resized() override;

private:
	Map map;
	NoteManager noteManager;

//	SongLayout songLayout;
	void run();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Interface)
};
