#include "Interface.h"
Interface::Interface() 
{
    setSize (1280,720);

	addAndMakeVisible(songLayout);
	addAndMakeVisible(map);
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

	songLayout.setBounds(0,0,getWidth()/3,getHeight());

	map.setBounds(getWidth()/12*4,0,getWidth()/12*4,getHeight());
}


