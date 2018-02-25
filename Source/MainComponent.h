/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteInterfaceComponent.h"
#include "KeyComponent.h"
//#include "BackgroundImageComponent.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AnimatedAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void update() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
private:
    //==============================================================================
    // Your private member variables go here...
//	BackgroundImageComponent pink_tree_img;
    NoteComponent notecomponent;
	KeyComponent keycomponent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
