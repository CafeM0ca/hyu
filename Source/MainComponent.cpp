#include "MainComponent.h"
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (1980,1280);

	addAndMakeVisible(keycomponent);
//쓰레드로 분리해야함..? 
	// keycomponent가 pressed를 보내면 
	// notecomponent가 addListener등록하고 신호받아야함
    addAndMakeVisible(notecomponent);
//    addAndMakeVisible(keycomponent);
	addAndMakeVisible(menu);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
		
	g.fillAll(Colour(13,13,13));
    notecomponent.setBounds(0,0,getWidth(),getHeight());
	menu.setBounds(0,0,getWidth(),getHeight());
}

void MainComponent::resized()
{
}

