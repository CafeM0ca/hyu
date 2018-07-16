#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"
<<<<<<< HEAD
Note::Note(const short& _bpm = 60) : 
	dkey('d'),
	fkey('f'),
	jkey('j'),
	kkey('k'),
	bpm(_bpm)
{

	DBG("Note Component ctor");
	setFramesPerSecond(bpm); // bpm조절
//	setWantsKeyboardFocus(true);
}

=======
Note::Note(const float& x, const float& y, const float& width, const float& height)
	: rect(x, y, width, height)
{
	DBG("Note Component ctor");
}
>>>>>>> test
Note::~Note()
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD

SingleNote::SingleNote(const float nx, const float ny, const float nwidth, const float nheight, const short _bpm = 60) 
	: rect(nx, ny, nwidth, nheight),
	Note(_bpm)
{
=======
/*
SingleNote::SingleNote(const float& nx, const float& ny, const float& nwidth, const float& nheight)
//: Note(nx, ny, nwidth, nheight)
{
	setNote(nx, ny, nwidth, nheight);
>>>>>>> test
	DBG("SingleNote ctor");
}

SingleNote::~SingleNote()
{

}

<<<<<<< HEAD
void SingleNote::update()
{
	rect.setY(rect.getY()+10);
}

void SingleNote::paint (Graphics& g)
{

	// 무지개 노트
	//g.fillAll(Colour(13,13,13));

	g.fillAll(Colour(13, 13, 13));		// 남은 부분 덧칠. 없애면 노트 잔상남음

//	g.setColour(Colour(254,20,133));
	g.setColour(Colour(Random::getSystemRandom().nextInt(Range<int>(100, 256)),
				Random::getSystemRandom().nextInt(Range<int>(50, 200)), 200));
	//g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	g.fillRect(rect);
	std::cout << "x : " << rect.getX() << ", y: " << rect.getY() << ", width: " << rect.getWidth() << ", height: "
		<< rect.getHeight() << std::endl;
	/*
	g.setColour (Colour(Colours::deepskyblue).withBrightness(0.7f));
	//g.setColour(Colour(255,51,0));
	if(dkey.isCurrentlyDown()){
		g.fillRect(2,getHeight()/12*10.5,getWidth()/4-2,getHeight()/30);
	} 
	*/
}

void SingleNote::resized()
{
}
=======
>>>>>>> test
/*
bool SingleNote::keyPressed(const KeyPress& key)
{
	/*
	 * 판정포인트 확인.
	 * 범위에 Timing .
	 * never use float. because float calculate is unsafety
	 *
	
	float y = 0.0f, h = 0.0f;
	float timingStart = getHeight()/12*10.5; // 판정포인트 시작y
	float timingEnd = timingStart + getHeight()/30; // 키입력칸 시작 y
	

	// perfect
	if(key == dkey && !drailNote.empty()){
		y = drailNote.front().getY();
		h = y + drailNote.front().getHeight();

		if(y >= timingStart && h <= timingEnd){			// perfect
			drail.push_back(Timing::hyu);
			drailNote.pop_front();

			} 
		else if((y < timingStart && y+h >= timingStart) || (y >= timingStart && h > timingEnd)){										// good
			drail.push_back(Timing::oh);
			drailNote.pop_front();
		}
		else if(h > getHeight()/2){				// miss
			drail.push_back(Timing::no);
			drailNote.pop_front();
		} 
	}
	if(key == fkey && !frailNote.empty()){
		y = frailNote.front().getY();
		h = y + frailNote.front().getHeight();

		if(y >= timingStart && h <= timingEnd){
			frail.push_back(Timing::hyu);
			frailNote.pop_front();
		} // good
		else if((y < timingStart && y+h >= timingStart) || (y >= timingStart && h > timingEnd)){
			frail.push_back(Timing::oh);
			frailNote.pop_front();
		}
		else if(h > getHeight()/2){
			frail.push_back(Timing::no);
			frailNote.pop_front();
		} // miss
	}
	if(key == jkey && !jrailNote.empty()){
		y = jrailNote.front().getY();
		h = y + jrailNote.front().getHeight();

		if(y >= timingStart && h <= timingEnd){
			jrail.push_back(Timing::hyu);
			jrailNote.pop_front();
		} // good
		else if((y < timingStart && y+h >= timingStart) || (y >= timingStart && h > timingEnd)){
			jrail.push_back(Timing::oh);
			jrailNote.pop_front();
		}
		else if(h > getHeight()/2){
			jrail.push_back(Timing::no);
			jrailNote.pop_front();
		} // miss
	}
	if(key == kkey && !krailNote.empty()){
		y = krailNote.front().getY();
		h = y + krailNote.front().getHeight();

		if(y >= timingStart && h <= timingEnd){
			krail.push_back(Timing::hyu);
			krailNote.pop_front();
		} // good
		else if((y < timingStart && y+h >= timingStart) || (y >= timingStart && h > timingEnd)){
			krail.push_back(Timing::oh);
			krailNote.pop_front();
		}
		else if(h > getHeight()/2){
			krail.push_back(Timing::no);
			krailNote.pop_front();
		} // miss
	}
	return false;	
}
*/

<<<<<<< HEAD
void SingleNote::setRect(const float x, const float y, const float width, const float height)
{
	rect.setX(x);
	rect.setY(y);
	rect.setWidth(width);
	rect.setHeight(height);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

NoteManager::NoteManager()
	: snote(0,10,100,10)
{
=======
//////////////////////////////////////////////////////////////////////////////////////////////////////

NoteManager::NoteManager()
{
	setFramesPerSecond(60);
	generateNote();
>>>>>>> test
}

NoteManager::~NoteManager()
{

}

<<<<<<< HEAD
void NoteManager::paint(Graphics& g)
{

}

void NoteManager::resized()
{
	for(int i = 0; i < activationNoteCnt; i++)
		snoteList[i].setBounds(0, 0, getWidth(), getHeight());
}

void NoteManager::timerCallback()
{
	if (!initNote) {

	}
}

void NoteManager::generateNote(const short playTime = 300 /* 3분 00초 */)
=======

void NoteManager::update()
{
	// 활성화된 노트까지 매 주기마다 y값 수정
	std::cout << "--------------active note: " << activePos <<  "-----------------------" << std::endl; 
	/*
	Rectangle<float> *ptr = nullptr;
	int popcnt = 0;
	for (int i = 0; i < notePos; i++) {
		ptr = &noteDeque.at(i).rect;
		if (ptr->getY() > getHeight()) {
			noteDeque.pop_front();
			popcnt++;
		}
		else {
			ptr->setY(ptr->getY()+10);
		}
	}
	notePos -= popcnt;
	notePos++;		// 매 초마다 노트수 증가
	*/
	// 1. 노트가 바닥치기 전까지 다 pop 
	if(activePos < noteDeque.size())
		activePos++;
	if (!noteDeque.empty() && noteDeque.front().rect.getY() >= getHeight()) {
		std::cout << "pop note" << std::endl;
		noteDeque.pop_front();
		activePos--;										// pop된 노트 개수만큼 현재 위치 조절
	}

	if (!noteDeque.empty()) {									// 검사 안하면 에러발생 가능성!
		// 2. 정리된 deque의 rect.y를 조절 
		int currentPos = 0;
		for (auto& i : noteDeque) {
			if (currentPos < activePos) {
				std::cout << currentPos << " note.y += 10" << std::endl;
				i.rect.setY(i.rect.getY() + 10);
				currentPos++;
			}
			else break;
		}
	}
}
void NoteManager::paint(Graphics& g)
{
	g.fillAll(Colour(13, 13, 13));
	g.setColour(Colour(222,222,222));

	if (!noteDeque.empty()) {
		int currentPos = 0;
		for (auto i : noteDeque) {
			if (currentPos < activePos) {
				g.fillRect(i.rect);
				currentPos++;
			}
			else break;
		}
	}
}
void NoteManager::resized()
{
	width = getWidth();
}

void NoteManager::generateNote(const short playTime /* 3분 00초 */)
>>>>>>> test
{
	/* 
	노트를 list에 다 넣는다.
    게임 시작중에 startTimer의 인자를 제각각으로 만들어서 노트를 떨어뜨린다.
    노트의 개수는 1초당 1개꼴로 만들며 곡의 난이도나 템포에 따라 변동조절한다.
<<<<<<< HEAD
	*/
	
	for (int i = 0; i < playTime; i++) {
		snoteList.push_back()
=======
	생성 알고리즘을 여기에서 정의.
	*/
	Random rand;
	rand.setSeedRandomly();
	auto pwid = getParentWidth() / 3;
	std::cout << pwid << std::endl;
	for (int i = 0; i < playTime; i++) {
		auto location = rand.getSystemRandom().nextInt(Range<int>(0, 4));
		noteDeque.push_back(Note((1280 /12 *location) , 0, 1280 / 12, 10));

>>>>>>> test
	}
}