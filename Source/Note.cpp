/*
  ==============================================================================

    Note.cpp
    Created: 22 Feb 2018 10:36:30pm
    Author:  moca

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"

//==============================================================================
Note::Note()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
//	cachedImage_bono = ImageCache::getFromMemoey(bono_png,bono_pngSize);
//	setSize(110,100);
}

Note::~Note()
{
}

void Note::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.setColour (Colours::black);
//	g.drawRect(getWidth()/12*4,0,getWidth()/getWidth()/12*4,getHeight()/12*11);
//	g.fillRect(getWidth()/12*4,0,getWidth()/getWidth()/12*4,getHeight()/12*11);
	g.drawRect(0,0,100,50);
	g.fillRect(0,0,100,50);

//g.drawImage(cachedImage_bono,getWidth()/12*4,getHeight()/12*11,getWidth()/12*4,getHeight()),0,0,cachedImage_bono.getWidth(),cachedImage_bono.getHeight());
}

void Note::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
