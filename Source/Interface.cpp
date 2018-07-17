#include "Interface.h"

Interface::Interface() 
{
//	setOpaque(true);		// 컴포넌트에 가려진 뒷부분 최적화
	setWantsKeyboardFocus(true); // 전체 컴포넌트에 대해 입력을 받는다.
//	addAndMakeVisible(songLayout);
	addAndMakeVisible(noteManager);
	addAndMakeVisible(map);
	//audio.SelectSong();
    setSize (1280,720);
}

Interface::~Interface()
{

}
void Interface::paint (Graphics& g) 
{
		
	g.fillAll(Colour(13,13,13));
//	g.setColour(Colour(255,91,51));
//	g.fillRect(Rectangle<int>(0, 0, 100, 100));
	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로
	
}

void Interface::resized()
{

//	songLayout.setBounds(0,0,getWidth()/3,getHeight());
	noteManager.setBounds(getWidth() / 3, 0, getWidth() / 3, getHeight());
	map.setBounds(getWidth() / 3 , 0, getWidth() / 3, getHeight());
}

