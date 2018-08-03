#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h"
#include "SoundComponent.h"
#include "NoteComponent.h"
class MainComponent   : public Component, private KeyListener
{
public:
    MainComponent();
    ~MainComponent();
    void paint (Graphics& g) override;
    void resized() override;
	bool keyPressed(const KeyPress&, Component *) override;
private:
	SoundComponent songLayout;
	NoteManager noteManager;
	Map map;
	Audio song;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
