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
    virtual ~Note();
	bool keyPressed(const KeyPress&) override;
	/********************************************/
protected:
	//Time startTime;
	//RelativeTime rtime;

	const KeyPress dkey;
	const KeyPress fkey;
	const KeyPress jkey;
	const KeyPress kkey;
	enum class Timing{
		hyu,
		hmm,
		no	
	};
	//void effectSound();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

class SingleNote : public Note
{
public:
	SingleNote() = delete;
	SingleNote(short x,short y, short width, short height);
	~SingleNote();
	void update() override;
    void paint (Graphics&) override;
    void resized() override;
private:
	short x,y;
	static const short width,height;
	Rectangle rect;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SingleNote)
};
/*
 * 1. 노트 개수를 일정 갯수까지 추가한다.
 * 2. 노트리스트가 비워져있지 않다면 DownNote를 실행
 */



class NoteManager
{
	public:
		NoteManager();
		~NoteManager();
	private:
		// note queue
		
}
