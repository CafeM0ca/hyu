/*
  ==============================================================================

    KeyComponent.h
    Created: 24 Feb 2018 6:38:12pm
    Author:  moca

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//==============================================================================
/*
*/

class KeyComponent    : public Component						//public KeyListener
{
public:
    KeyComponent();
    ~KeyComponent();

    void paint (Graphics&) override;
    void resized() override;
	//virtual bool keyPressed(const KeyPress& key) override;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyComponent)
};




