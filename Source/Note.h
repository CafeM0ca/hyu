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
	/********************************************/
	void setBPM(unsigned short v);
private:
	Rectangle<float> note;

	static unsigned short BPM;	
	Time startTime;
	RelativeTime rtime;

	const KeyPress dkey;
	const KeyPress fkey;
	const KeyPress jkey;
	const KeyPress kkey;
	enum class Timing{
		hyu,
		hmm?,
		no	
	};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

class SingleNote : public Note
{
public:

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SingleNote)
};
/*
 * 1. 노트 개수를 일정 갯수까지 추가한다.
 * 2. 노트리스트가 비워져있지 않다면 DownNote를 실행
 */
