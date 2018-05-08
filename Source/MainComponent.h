#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//#include "KeyComponent.h"
#include "Menu.h"
#include "Map.h"
#include "Note.h"
//#include "BackgroundImageComponent.h"
class MainComponent   : public Component

{
public:
    MainComponent();
    ~MainComponent();
    void paint (Graphics& g) override;
    void resized() override;
private:
	//KeyComponent keycomponent;
	Menu menu;
	Map map;
	Note note;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
