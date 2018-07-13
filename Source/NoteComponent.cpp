#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"
Note::Note(const float& x, const float& y, const float& width, const float& height)
	: rect(x, y, width, height)
{
	DBG("Note Component ctor");
}
Note::~Note()
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
SingleNote::SingleNote(const float& nx, const float& ny, const float& nwidth, const float& nheight)
//: Note(nx, ny, nwidth, nheight)
{
	setNote(nx, ny, nwidth, nheight);
	DBG("SingleNote ctor");
}

SingleNote::~SingleNote()
{

}

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

//////////////////////////////////////////////////////////////////////////////////////////////////////

NoteManager::NoteManager()
{
	setFramesPerSecond(60);
	generateNote();
}

NoteManager::~NoteManager()
{

}


void NoteManager::update()
{
	// 활성화된 노트까지 매 주기마다 y값 수정
	notePos++;		// 매 초마다 노트수 증가
	Rectangle<float> *ptr = nullptr;
	int popcnt = 0;
	for (int i = 0; i <= notePos; i++) {
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
	repaint();
}
void NoteManager::paint(Graphics& g)
{
	g.fillAll(Colour(222, 222, 13));
	g.setColour(Colour(222,222,222));

	for (int i = 0; i <= notePos; i++) {
		g.fillRect(noteDeque.at(i).rect);
	}
}
void NoteManager::resized()
{

}

void NoteManager::generateNote(const short playTime /* 3분 00초 */)
{
	/* 
	노트를 list에 다 넣는다.
    게임 시작중에 startTimer의 인자를 제각각으로 만들어서 노트를 떨어뜨린다.
    노트의 개수는 1초당 1개꼴로 만들며 곡의 난이도나 템포에 따라 변동조절한다.
	*/
	Random rand;
	rand.setSeedRandomly();
	auto pwid = getParentWidth() / 3;
	std::cout << pwid << std::endl;
	for (int i = 0; i < playTime; i++) {
		auto location = rand.getSystemRandom().nextInt(Range<int>(0, 2));
		noteDeque.push_back(Note(pwid / 4 * location , 0, pwid / 4, 10));

	}
}