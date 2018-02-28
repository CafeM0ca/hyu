/*
  ==============================================================================
    Map.cpp
    Created: 22 Feb 2018 8:07:50pm
    Author:  moca
  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h"

//==============================================================================
Map::Map()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

Map::~Map()
{
}

void Map::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.
       You should replace everything in this method with your own
       drawing code..
    */
    g.setColour(Colours::black);

    g.drawRect(0,0,getWidth(),getHeight(),1);
	
}

void Map::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
