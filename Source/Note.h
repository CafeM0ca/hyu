#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <list>
/* 노트 떨어지는 그래픽 */

/* 생성되는 노트를 큐에 넣고 라인이 지나면 앞에서부터 뺸다.
 */

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
	std::list<Rectangle<float>> note_list;
	Rectangle<float> block;
	unsigned int bpm;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

