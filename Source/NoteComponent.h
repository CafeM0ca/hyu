#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <deque>
#include <queue>
#include <string>
#include <cassert>
/* 노트 떨어지는 그래픽 */

/* 생성되는 노트를 큐에 넣고 라인이 지나면 앞에서부터 뺸다.
*/
enum class Judgement : int {
	wow = 120,
	ok = 100,
	hyu = 70,
	oops = 0,
	none = -1
};

class Note
{
public:
	Note() {}
	Note(const float& x, const float& y, const float& width, const float& height);
	virtual ~Note();
	/********************************************/
	Rectangle<float> rect;
	Judgement state{ Judgement::none };
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
{ public: SingleNote() {}
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
{
public:
	NoteManager();
	~NoteManager();
	void update() override;
	void paint(Graphics&) override;
	void resized() override;
	bool keyPressed(const KeyPress&) override;
	void generateNote(const short playTime = 300);
private:
	std::deque<Note> noteDeque[4];
	std::queue<Judgement> score;
	int activePos[4]{ 0 };											// 큐에서 활성화된 노트 pos 나중에 Note class로 빼야할듯
	int combo = 0;
	bool initNote = false;
	void judgeNote(const short&, const float&, const float&, const float&, const float&);
	const KeyPress dkey = KeyPress('d');
	const KeyPress fkey = KeyPress('f');
	const KeyPress jkey = KeyPress('j');
	const KeyPress kkey = KeyPress('k');
	const KeyPress myKey[4]{ KeyPress('d'), KeyPress('f'), KeyPress('j'), KeyPress('k') };
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NoteManager)
};

/* 전체 런타임이 있고 그를 노트의 갯수만큼 분할한 시간 -0.3~+0.1 까지 설정하여 노트를 삽입
*/