
/*
  ==============================================================================
	NoteComponent.cpp
    Created: 23 Feb 2018 8:41:53pm
    Author:  moca
  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"

//==============================================================================
NoteComponent::NoteComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(nframe1);
    addAndMakeVisible(nframe2);
    addAndMakeVisible(nframe3);
    addAndMakeVisible(nframe4);
    addAndMakeVisible(nframe5);
    addAndMakeVisible(nframe6);
    addAndMakeVisible(block1);
    addAndMakeVisible(block2);
    addAndMakeVisible(block3);
    addAndMakeVisible(block4);
	addAndMakeVisible(bgm);
}

NoteComponent::~NoteComponent()
{
}

void NoteComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.
       You should replace everything in this method with your own
       drawing code..
    jk*/
	//map frame
	g.setColour(Colours::black);
    nframe1.setBounds(getWidth()/12*4,0,getWidth()/12,getHeight());   
    nframe2.setBounds(getWidth()/12*5,0,getWidth()/12,getHeight());   
    nframe3.setBounds(getWidth()/12*6,0,getWidth()/12,getHeight());   
    nframe4.setBounds(getWidth()/12*7,0,getWidth()/12,getHeight());   
	nframe5.setBounds(getWidth()/12*4,getHeight()/12*11,getWidth()/12*4,getHeight());
    nframe6.setBounds(getWidth()/12*4,getHeight()/12*10.75,getWidth()/12*4,getHeight()); //판정 포인트 0.25
	
	//note  
	DBG("draw note");
	block1.setBounds(getWidth()/12*4+3,0,getWidth()/12-6,getHeight()/12*11);
	block2.setBounds(getWidth()/12*5+3,0,getWidth()/12-6,getHeight()/12*11);
	block3.setBounds(getWidth()/12*6+3,0,getWidth()/12-6,getHeight()/12*11);
	block4.setBounds(getWidth()/12*7+3,0,getWidth()/12-6,getHeight()/12*11);
	/*
	block2.setBounds(getWidth()/12*5,block2.GetY1(),getWidth()/12,block2.GetY2());
	block3.setBounds(getWidth()/12*6,block3.GetY1(),getWidth()/12,block3.GetY2());
	block4.setBounds(getWidth()/12*7,block4.GetY1(),getWidth()/12,block4.GetY2());
	*/

	g.setColour(Colours::black);
	g.setFont(60.0f);

	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로
	//입력효과를 줄때 필요함
	g.drawText("D",getWidth()/12*4,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	g.drawText("F",getWidth()/12*5,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	g.drawText("J",getWidth()/12*6,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	g.drawText("K",getWidth()/12*7,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
}

void NoteComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
