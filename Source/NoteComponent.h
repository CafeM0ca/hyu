#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <list>
/* 노트 떨어지는 그래픽 */

/* 생성되는 노트를 큐에 넣고 라인이 지나면 앞에서부터 뺸다.
 */

class Note    : public AnimatedAppComponent 
{
public:
	Note(const short&);
	~Note();
	/********************************************/
protected:
	//Time startTime;
	//RelativeTime rtime;

	const KeyPress dkey;
	const KeyPress fkey;
	const KeyPress jkey;
	const KeyPress kkey;
	const short bpm;
	//void effectSound();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

class SingleNote : public Note
{
public:
	SingleNote() = delete;
	SingleNote(const float x, const float y, const float width, const float height, const short bpm);
	~SingleNote();
	void update() override;
    void paint (Graphics&) override;
    void resized() override;
	void setRect(const float x, const float y, const float width, const float height);
	//bool keyPressed(const KeyPress&) override;
private:
	short x,y;
	static const short width,height;
	Rectangle<float> rect;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SingleNote)
};

class NoteManager : public Component, private Timer
{
public:
	NoteManager();
	~NoteManager();
	void paint(Graphics&) override;
	void resized() override;
	void timerCallback() override;
private:
	// note queue
	SingleNote snote;
	std::list<SingleNote> snoteList;
	int activationNoteCnt;
	bool initNote = false;
	void generateNote(const short playTime);
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NoteManager)
};

/* 전체 런타임이 있고 그를 노트의 갯수만큼 분할한 시간 -0.3~+0.1 까지 설정하여 노트를 삽입

*/
