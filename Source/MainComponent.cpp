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
    setSize (1280,1080);
    setFramesPerSecond (60); // This sets the frequency of the update calls.
    addAndMakeVisible(nframe1);
    addAndMakeVisible(nframe2);
    addAndMakeVisible(nframe3);
    addAndMakeVisible(nframe4);
	addAndMakeVisible(nframe5);
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
    //setBounds는 화면에 표시할 영역. 3,4인자는 1,2인자로부터의 떨어진 값
    nframe1.setBounds(getWidth()/12*4,0,getWidth()/12,getHeight());   
    nframe2.setBounds(getWidth()/12*5,0,getWidth()/12,getHeight());   
    nframe3.setBounds(getWidth()/12*6,0,getWidth()/12,getHeight());   
    nframe4.setBounds(getWidth()/12*7,0,getWidth()/12,getHeight());   
	nframe5.setBounds(getWidth()/12*4,getHeight()/12*11,getWidth()/12*4,getHeight());
    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
