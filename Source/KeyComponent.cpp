/*
  ==============================================================================
    KeyComponent.cpp
    Created: 24 Feb 2018 6:38:12pm
    Author:  moca
  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "KeyComponent.h"
//#include "KeyControl.h"
//==============================================================================
KeyComponent::KeyComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	addAndMakeVisible(key);	
//	grapKeyBoardFocus();
}

KeyComponent::~KeyComponent()
{
}

void KeyComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.
       You should replace everything in this method with your own
       drawing code..
    */
	
	g.setColour(Colours::black);
	g.setFont(60.0f);
	g.drawText("D",getWidth()/12*4,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	g.drawText("F",getWidth()/12*5,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	g.drawText("J",getWidth()/12*6,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	g.drawText("K",getWidth()/12*7,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centredBottom,true);
	
}

void KeyComponent::resized()
{
   // This method is where you should set the bounds of any child
    // components that your component contains..
	

}
/*
bool KeyPressed(const KeyPress& key) override{
	DBG("Key Pressed");
	return false;
	}
}
*/
/*
virtual bool keyPress (const KeyPress& key) override{
	cout << "keyPress excuted";
	return false;
}
*virtual /
