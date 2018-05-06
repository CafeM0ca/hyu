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
Map::Map() : mode(MapMode::single)
{   
	DBG("map init");
}

Map::~Map()
{

}
void Map::InitDefaultMap(int width,int height) 
{
	map_info.single = width/12;
	ChangeMap();
}

void Map::paint (Graphics& g)
{
	
    g.setColour(Colour(255,133,51));
	
	g.drawRect(vertical1,2.0f);
	g.drawRect(vertical2,2.0f);
	g.drawRect(vertical3,2.0f);
	g.drawRect(vertical4,2.0f);

	g.setColour(Colours::white);
	g.drawRect(urteil,2.0f);
	
	g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	g.setFont(Font(60.0f,Font::bold));
	g.setColour(Colours::white);
	g.drawText("D",key_frame1,Justification::centred,true);
	g.drawText("F",key_frame2,Justification::centred,true);
	g.drawText("J",key_frame3,Justification::centred,true);
	g.drawText("K",key_frame4,Justification::centred,true);

//	g.drawRect(frame5,2.0f);
//	g.drawRect(frame6,2.0f);

}

void Map::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	//
}

void Map::ChangeMap( /*MapMode::single*/) 
{
	//mode = m;
  	switch(mode){
		case MapMode::single:
			vertical1.setBounds(map_info.single*4,-10,map_info.single,getHeight()+10);   
			vertical2.setBounds(map_info.single*5,-10,map_info.single,getHeight()+10);   
			vertical3.setBounds(map_info.single*6,-10,map_info.single,getHeight()+10);   
			vertical4.setBounds(map_info.single*7,-10,map_info.single,getHeight()+10);   
	
			urteil.setBounds(map_info.single*4,getHeight()/12*10.5,map_info.single*4,getHeight()/30);
			key_frame1.setBounds(map_info.single*4,getHeight()/12*10.5+getHeight()/30,map_info.single,getHeight() - getHeight()/12*10.5 - getHeight()/30);
			key_frame2.setBounds(map_info.single*5,getHeight()/12*10.5+getHeight()/30,map_info.single,getHeight() - getHeight()/12*10.5 - getHeight()/30);
			key_frame3.setBounds(map_info.single*6,getHeight()/12*10.5+getHeight()/30,map_info.single,getHeight() - getHeight()/12*10.5 - getHeight()/30);
			key_frame4.setBounds(map_info.single*7,getHeight()/12*10.5+getHeight()/30,map_info.single,getHeight() - getHeight()/12*10.5 - getHeight()/30);
	}
}

Rectangle<float> Map::GetBaseRectangle()
{
	switch(mode){
		case MapMode::single:
			return Rectangle<float>(map_info.single*4,map_info.single*11,map_info.single,30);   
	}
}

void Map::MapDataUpdate()
{
	map_info.single = getWidth() / 12;
}
