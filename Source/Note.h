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
	bool keyPressed(const KeyPress&) override;
	bool RemoveNote(Rectangle<float> rect);
protect:
	enum class Timing{
		hyu,
		oh,
		no	
	};
private:
	Rectangle<float> block;

	Time startTime;
	RelativeTime rtime;

	unsigned int bpm;
	unsigned int del_cnt;

	KeyPress dkey;
	KeyPress fkey;
	KeyPress jkey;
	KeyPress kkey;
	void downNote();
	void generateNote();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

class SingleNote : public Note
{
public:

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SingleNote)
}
/*
 * 1. 노트 개수를 일정 갯수까지 추가한다.
 * 2. 노트리스트가 비워져있지 않다면 DownNote를 실행
 */
