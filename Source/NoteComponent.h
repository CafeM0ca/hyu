#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
<<<<<<< HEAD
#include <list>
=======
#include <deque>
>>>>>>> test
/* 노트 떨어지는 그래픽 */

/* 생성되는 노트를 큐에 넣고 라인이 지나면 앞에서부터 뺸다.
 */

<<<<<<< HEAD
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
=======
class Note    
{
public:
	Note() {}
	 Note(const float& x, const float& y, const float& width, const float& height);
	virtual ~Note();
	/********************************************/
	Rectangle<float> rect;
private:
	//Time startTime;
	//RelativeTime rtime;
	const KeyPress& dkey = KeyPress('d');
	const KeyPress& fkey = KeyPress('f');
	const KeyPress& jkey = KeyPress('j');
	const KeyPress& kkey = KeyPress('k');
	//void effectSound();
};
/*
class SingleNote : public Note
{
public:
	SingleNote() {}
	SingleNote(const float& x, const float& y, const float& width, const float& height);
	~SingleNote();
	inline auto getX() const { return rect.getX(); };
	inline auto getY() const { return rect.getY(); };
	inline auto getWidth() const { return rect.getWidth(); };
	inline auto getHeight() const{ return rect.getHeight(); };
	inline auto getRect() const { return rect; }
	inline void setX(const float& x) { rect.setX(x); };
	inline void setY(const float& y) { rect.setY(y); };
	inline void setWidth(const float& width) { rect.setWidth(width); };
	inline void setHeight(const float& height) { rect.setHeight(height); };
	void setNote(const float& x, const float& y, const float& width, const float& height);

};
*/
class NoteManager : public AnimatedAppComponent
>>>>>>> test
{
public:
	NoteManager();
	~NoteManager();
<<<<<<< HEAD
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
=======
	void update() override;
	void paint(Graphics&) override;
	void resized() override;
private:
	// note queue
	std::deque<Note> noteDeque;
	int activePos= 0;
	bool initNote = false;
	void generateNote(const short playTime = 300);
	int width;
>>>>>>> test
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NoteManager)
};

/* 전체 런타임이 있고 그를 노트의 갯수만큼 분할한 시간 -0.3~+0.1 까지 설정하여 노트를 삽입

*/
