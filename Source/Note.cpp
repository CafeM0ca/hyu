#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"
Note::Note(unsigned short _bpm = 60) : 
	BPM(_bpm),
	dkey('d'),
	fkey('f'),
	jkey('j'),
	kkey('k'),
{
	note = Rectangle<float>(0,-30,getWidth()/4,-10);
	DBG("Note Component ctor");
	setFramesPerSecond(BPM); // bpm조절
//	setWantsKeyboardFocus(true);
}

Note::~Note()
{ 

} 

void Note::update()
{
	// setFramesPerSecond에 맞춰서 떨어진다. 60이면 1초에 60번 호출됨.
	
	//downNote();
}

void Note::paint (Graphics& g)
{
	// 무지개 노트
//	g.fillAll(Colour(13,13,13));
	
	//g.setColour(Colour(254,20,133));
	//g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	
	//g.fillRect(block);
	/*
	g.setColour (Colour(Colours::deepskyblue).withBrightness(0.7f));
	//g.setColour(Colour(255,51,0));
	if(dkey.isCurrentlyDown()){
		g.fillRect(2,getHeight()/12*10.5,getWidth()/4-2,getHeight()/30);
	} 
	if(fkey.isCurrentlyDown()){
		g.fillRect(getWidth()/4+2,getHeight()/12*10.5,getWidth()/4-2,getHeight()/30);
	}
	if(jkey.isCurrentlyDown()){
		g.fillRect(getWidth()/4*2+2,getHeight()/12*10.5,getWidth()/4-2,getHeight()/30);
	}
	if(kkey.isCurrentlyDown()){
		g.fillRect(getWidth()/4*3+2,getHeight()/12*10.5,getWidth()/4-2,getHeight()/30);
	}
	*/
}

void Note::resized()
{

}

bool Note::keyPressed(const KeyPress& key)
{
	/*
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
*/
	return false;	

}

