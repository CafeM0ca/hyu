/*
  ==============================================================================

    Menu.h
    Created: 8 Mar 2018 5:09:14am
    Author:  moca

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/

class Menu    : public Component
{
public:
    Menu();
    ~Menu();

    void paint (Graphics&) override;
    void resized() override;

private:
	Label lab;
	Label exit;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Menu)
};
