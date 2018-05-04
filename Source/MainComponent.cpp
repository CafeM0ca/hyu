#include "MainComponent.h"
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (1920,1080);

	addAndMakeVisible(keycomponent);
//쓰레드로 분리해야함..? 
	// keycomponent가 pressed를 보내면 
	// notecomponent가 addListener등록하고 신호받아야함
    addAndMakeVisible(notecomponent);
	addAndMakeVisible(menu);
	addAndMakeVisible(map);
	notecomponent.setBounds(0,0,getWidth(),getHeight());
	menu.setBounds(0,0,getWidth(),getHeight());
	map.setBounds(0,0,getWidth(),getHeight());
	
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
		
	g.fillAll(Colour(13,13,13));
	g.setColour(Colour(255,91,51));
	g.setFont(60.0f);

	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로
}

void MainComponent::resized()
{

}

