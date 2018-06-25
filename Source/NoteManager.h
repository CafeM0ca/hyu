#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//#include "Note.h"
//#include "Audio.h"
class NoteManager    : public Component
{
public:
    NoteManager();
    ~NoteManager();

    void paint (Graphics&) override;
    void resized() override;
	void playSong();

private:
//	Note note;
//	Audio song;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteManager)
};
