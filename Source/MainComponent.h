#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"
#include "KeyComponent.h"
#include "Menu.h"
#include "Map.h"
//#include "BackgroundImageComponent.h"
class MainComponent   : public Component

{
public:
    MainComponent();
    ~MainComponent();

    void paint (Graphics& g) override;
    void resized() override;
private:
//	BackgroundImageComponent pink_tree_img;
    NoteComponent notecomponent;
	KeyComponent keycomponent;
	Menu menu;
	Map map;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
