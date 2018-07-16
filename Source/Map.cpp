#include "../JuceLibraryCode/JuceHeader.h"
#include "Map.h" 
//==============================================================================
Map::Map() 
{   
	DBG("map init");
}

Map::~Map()
{

}

void Map::paint (Graphics& g)
{
	
	// D F J K 부분 덮기 
	//g.setColour(Colours::blue);
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
	vertical1.setBounds(0,-10,getWidth()/4,getHeight()+10);   
	vertical2.setBounds(getWidth()/4,-10,getWidth()/4,getHeight()+10);   
	vertical3.setBounds(getWidth()/4*2,-10,getWidth()/4,getHeight()+10);   
	vertical4.setBounds(getWidth()/4*3,-10,getWidth()/4,getHeight()+10);   

	float urteil_height = getHeight()/12*10.5; // 판정포인트 시작y
	float keyframe_height = urteil_height + getHeight()/30; // 키입력칸 시작 y
	urteil.setBounds(0,urteil_height,getWidth(),getHeight()/30);
	key_frame1.setBounds(0,keyframe_height,getWidth()/4,getHeight() - keyframe_height);
	key_frame2.setBounds(getWidth()/4,keyframe_height,getWidth()/4,getHeight() - keyframe_height);
	key_frame3.setBounds(getWidth()/4*2,keyframe_height,getWidth()/4,getHeight() - keyframe_height);
	key_frame4.setBounds(getWidth()/4*3,keyframe_height,getWidth()/4,getHeight() - keyframe_height);

}

