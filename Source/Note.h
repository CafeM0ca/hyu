#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "KeyComponent.h"
#include <list>
/* 노트 떨어지는 그래픽 */

/* 생성되는 노트를 큐에 넣고 라인이 지나면 앞에서부터 뺸다.
 */
class Note    : public AnimatedAppComponent //,private Timer
{
public:
    Note();
    ~Note();
	void update() override;
    void paint (Graphics&) override;
    void resized() override;
	void AddNote(Rectangle<float>& rect); // 노트 패턴마다 만들기. ex) 단일노트, 이중노트, 롱노트
	void RemoveNote(Rectangle<float> rect);
	void SetNotePos(const Rectangle<float>& rect);
	//getMillisecondsSinceLastUpdate() update호출한수
private:
	std::list<Rectangle<float>> note_list;
	Rectangle<float> block;
	unsigned int bpm;
	unsigned int del_cnt;
	void DownNote();
	KeyComponent key;
	//void timerCallback() override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

/*
 * 1. 노트 개수를 일정 갯수까지 추가한다.
 * 2. 노트리스트가 비워져있지 않다면 DownNote를 실행
 */
