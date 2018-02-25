/*
  ==============================================================================
    NoteFrameComponent.h
    Created: 22 Feb 2018 8:07:50pm
    Author:  moca
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//==============================================================================
/*
*/
class NoteFrameComponent    : public Component
{
public:
    NoteFrameComponent();
    ~NoteFrameComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteFrameComponent)
};

