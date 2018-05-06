#include "MainComponent.h"
MainComponent::MainComponent() 
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (1080,720);
	addAndMakeVisible(keycomponent);
	addAndMakeVisible(note);
	addAndMakeVisible(menu);
	addAndMakeVisible(map);
	menu.setBounds(0,0,getWidth(),getHeight());
	map.setBounds(0,0,getWidth(),getHeight());
	map.InitDefaultMap(getWidth(),getHeight());
	note.setBounds(0,0,getWidth(),getHeight());
	note.SetNotePos(Rectangle<float>(map.GetBaseRectangle()));
	//note.AddNote(Rectangle<float>(map.map_info.single*4,0,map.map_info.single*4,getHeight()));
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
		
	g.fillAll(Colour(13,13,13));
	g.setColour(Colour(255,91,51));
	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로
}

void MainComponent::resized()
{

}

