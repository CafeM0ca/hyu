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
#include "Map.h"
#include "Audio.h"
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
    Map nframe1;
    Map nframe2;
    Map nframe3;
    Map nframe4;
    Map nframe5;
    Map nframe6;

    Note block;
	Audio bgm;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteComponent)
};

