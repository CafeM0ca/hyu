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
	g.setColour(Colours::orange);
	g.fillRect(key_frame1);
	g.fillRect(key_frame2);
	g.fillRect(key_frame3);
	g.fillRect(key_frame4);


    g.setColour(Colour(255,133,51));
	g.drawLine(vertical1,7.0f);
	g.drawLine(vertical2,7.0f);
	g.drawLine(vertical3,7.0f);
	g.drawLine(vertical4,7.0f);
	g.drawLine(vertical5,7.0f);

	// judgement rectangle
	g.setColour(Colours::white);
	g.drawRect(urteil,5.0f);
	
	// text in rectangle
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
	float width = getWidth() / 4;
	float urteil_height = getHeight()/12*10.5; // 판정포인트 시작y
	float keyframe_height = urteil_height + getHeight()/30; // 키입력칸 시작 y
	/*
	vertical1.setBounds(0,       -10, width, getHeight()+10);   
	vertical2.setBounds(width,   -10, width, getHeight()+10);   
	vertical3.setBounds(width*2, -10, width, getHeight()+10);   
	vertical4.setBounds(width*3, -10, width + 2, getHeight()+10);   
	*/
	vertical1.setStart(3,0);
	vertical1.setEnd(3,getHeight());
	vertical2.setStart(width,0);
	vertical2.setEnd(width,getHeight());
	vertical3.setStart(width*2,0);
	vertical3.setEnd(width*2,getHeight());
	vertical4.setStart(width*3,0);
	vertical4.setEnd(width*3,getHeight());
	vertical5.setStart(width*4,0);
	vertical5.setEnd(width*4,getHeight());





	urteil    .setBounds(0, urteil_height, getWidth(), getHeight()/30);
	key_frame1.setBounds(0,       keyframe_height, width, getHeight() - keyframe_height);
	key_frame2.setBounds(width,   keyframe_height, width, getHeight() - keyframe_height);
	key_frame3.setBounds(width*2, keyframe_height, width, getHeight() - keyframe_height);
	key_frame4.setBounds(width*3, keyframe_height, width, getHeight() - keyframe_height);
}

