/*
  ==============================================================================

    Menu.cpp
    Created: 8 Mar 2018 5:09:14am
    Author:  moca

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Menu.h"

//==============================================================================
Menu::Menu()
{
	addAndMakeVisible(lab);
	addAndMakeVisible(exit);
	lab.setText("text",dontSendNotification);
	lab.setColour(Label::textColourId,Colours::black);
	exit.setText("exit",dontSendNotification);
	exit.setJustificationType(Justification::centred);
	exit.setColour(Label::textColourId,Colours::black);
}


Menu::~Menu()
{
}

void Menu::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

/*
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("Menu", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
				*/
	g.drawRect(0.0f,0.0f,100.0f,100.0f);
	g.setColour(Colours::blue);
	g.fillRect(0,0,100,100);
	
	g.setColour(Colours::red);
	g.drawEllipse(getWidth()-50,0,50,50,3);
	g.fillEllipse(getWidth()-50,0,50,50);
}

void Menu::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	lab.setBounds(0,0,100,100);
	exit.setBounds(getWidth()-50,0,50,50);

}
