/*
  ==============================================================================
    NoteComponent.h
    Created: 23 Feb 2018 8:41:53pm
    Author:  moca
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"
#include "NoteFrameComponent.h"
//==============================================================================
/*
*/
class NoteComponent    : public Component
{
public:
    NoteComponent();
    ~NoteComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    NoteFrameComponent nframe1;
    NoteFrameComponent nframe2;
    NoteFrameComponent nframe3;
    NoteFrameComponent nframe4;
    NoteFrameComponent nframe5;
    NoteFrameComponent nframe6;

    Note block;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteComponent)
};

