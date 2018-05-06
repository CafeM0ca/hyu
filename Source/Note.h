#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

/* 노트 떨어지는 그래픽 */

class Note    : public AnimatedAppComponent 
{
public:
    Note();
	Note(Rectangle<float> r);
    ~Note();
	void update() override;
    void paint (Graphics&) override;
    void resized() override;
	void DownNote();

	void AddNote(const Rectangle<float>& rect);
	void SetNotePos(const Rectangle<float>& rect);
private:
	Rectangle<float> block;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

