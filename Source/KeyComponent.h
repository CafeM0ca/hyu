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

class KeyComponent    : public Component
{
public:
    KeyComponent();
    ~KeyComponent();

    void paint (Graphics&) override;
    void resized() override;

	//originatingComponent key이벤트를 받을 컴포넌트 
	bool KeyListener::keyPressed(const KeyPress& key,
			Component *originatingComponent) override;
private:
	KeyPress key;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyComponent)
};

