#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h"
#include "SoundComponent.h"
#include "NoteComponent.h"
class MainComponent   : public Component
{
public:
    MainComponent();
    ~MainComponent();
    void paint (Graphics& g) override;
    void resized() override;

private:
	SoundComponent songLayout;
	NoteManager noteManager;
	Map map;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
