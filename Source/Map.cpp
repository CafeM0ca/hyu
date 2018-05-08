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
	
	// note 덮기위해
	g.fillRect(key_frame1);
	g.fillRect(key_frame2);
	g.fillRect(key_frame3);
	g.fillRect(key_frame4);


    g.setColour(Colour(255,133,51));
	g.drawRect(vertical1,2.0f);
	g.drawRect(vertical2,2.0f);
	g.drawRect(vertical3,2.0f);
	g.drawRect(vertical4,2.0f);

	g.setColour(Colours::white);
	g.drawRect(urteil,2.0f);
	

	g.setFont(Font(60.0f,Font::bold));
	g.setColour(Colours::white);
	g.drawText("D",key_frame1,Justification::centred,true);
	g.drawText("F",key_frame2,Justification::centred,true);
	g.drawText("J",key_frame3,Justification::centred,true);
	g.drawText("K",key_frame4,Justification::centred,true);


}

void Map::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	//
}

void Map::ChangeMap( /*MapMode::single*/) 
{
	// 나중에 모드 추가할때 this.mode를 변경해야함.
  	switch(mode){
		case MapMode::single:
			vertical1.setBounds(map_info.single*4,-10,map_info.single,getHeight()+10);   
			vertical2.setBounds(map_info.single*5,-10,map_info.single,getHeight()+10);   
			vertical3.setBounds(map_info.single*6,-10,map_info.single,getHeight()+10);   
			vertical4.setBounds(map_info.single*7,-10,map_info.single,getHeight()+10);   
	
			float urteil_height = getHeight()/12*10.5; // 판정포인트 시작y
			float keyframe_height = urteil_height + getHeight()/30; // 키입력칸 시작 y
			urteil.setBounds(map_info.single*4,urteil_height,map_info.single*4,getHeight()/30);
			key_frame1.setBounds(map_info.single*4,keyframe_height,map_info.single,getHeight() - keyframe_height);
			key_frame2.setBounds(map_info.single*5,keyframe_height,map_info.single,getHeight() - keyframe_height);
			key_frame3.setBounds(map_info.single*6,keyframe_height,map_info.single,getHeight() - keyframe_height);
			key_frame4.setBounds(map_info.single*7,keyframe_height,map_info.single,getHeight() - keyframe_height);
	}
}

Rectangle<float> Map::GetBaseRectangle()
{
	switch(mode){
		case MapMode::single:
			return Rectangle<float>(map_info.single*4,-10,map_info.single,getHeight()/30*0.75);   
	}
}

void Map::MapDataUpdate()
{
	// 화면 크기조절할때 호출
	map_info.single = getWidth() / 12;
}
