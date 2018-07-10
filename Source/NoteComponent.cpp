#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"
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

Note::~Note()
{

}
//////////////////////////////////////////////////////////////////////////////////////////////////////

SingleNote::SingleNote(const float nx, const float ny, const float nwidth, const float nheight, const short _bpm = 60) 
	: rect(nx, ny, nwidth, nheight),
	Note(_bpm)
{
	DBG("SingleNote ctor");
}

SingleNote::~SingleNote()
{

}

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
}

NoteManager::~NoteManager()
{

}

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
{
	/* 
	노트를 list에 다 넣는다.
    게임 시작중에 startTimer의 인자를 제각각으로 만들어서 노트를 떨어뜨린다.
    노트의 개수는 1초당 1개꼴로 만들며 곡의 난이도나 템포에 따라 변동조절한다.
	*/
	
	for (int i = 0; i < playTime; i++) {
		snoteList.push_back()
	}
}