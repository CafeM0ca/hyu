#include "Interface.h"
Interface::Interface() 
{
    setSize (1280,720);
	setOpaque(true);		// 컴포넌트에 가려진 뒷부분 최적화
	setWantsKeyboardFocus(true); // 전체 컴포넌트에 대해 입력을 받는다.
	//변수이름.ChangeListener(this); // 해당 변수에 포커스가 잡힘
//	addAndMakeVisible(songLayout);
	addAndMakeVisible(map);
	addAndMakeVisible(noteManager);
	//audio.SelectSong();
}

Interface::~Interface()
{
}
void Interface::paint (Graphics& g) 
{
		
	g.fillAll(Colour(13,13,13));
//	g.setColour(Colour(255,91,51));
	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로

}

void Interface::resized()
{

//	songLayout.setBounds(0,0,getWidth()/3,getHeight());
	map.setBounds(getWidth()/12*4,0,getWidth()/12*4,getHeight());
	noteManager.setBounds(getWidth()/12*4,0,getWidth()/12*4,getHeight());

}

void Interface::run()
{
	
}
