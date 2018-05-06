#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

/* 노트 떨어지는 그래픽 */

class Note    : public AnimatedAppComponent 
{
public:
    Note();
    ~Note();
	void update() override;
    void paint (Graphics&) override;
    void resized() override;
	void DownNote();

	void AddNote(const Rectangle<float>& rect);
	void SetNotePos(const Rectangle<float>& rect);
	//getMillisecondsSinceLastUpdate() update호출한수
private:
	Rectangle<float> block;
	unsigned int bpm;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

