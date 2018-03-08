/*
  ==============================================================================
    This file was auto-generated!
  ==============================================================================
*/

#include "MainComponent.h"
//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (1980,1280);
    setFramesPerSecond (100); // This sets the frequency of the update calls.


	//쓰레드로 분리해야함..? 
	// keycomponent가 pressed를 보내면 
	// notecomponent가 addListener등록하고 신호받아야함
    addAndMakeVisible(notecomponent);
    addAndMakeVisible(keycomponent);
	addAndMakeVisible(menu);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::update()
{
    // This function is called at the frequency specified by the setFramesPerSecond() call
    // in the constructor. You can use it to update counters, animate values, etc.
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::white);
    notecomponent.setBounds(0,0,getWidth(),getHeight());
	keycomponent.setBounds(0,0,getWidth(),getHeight());
	menu.setBounds(0,0,getWidth(),getHeight());
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

