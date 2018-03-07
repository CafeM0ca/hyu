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
Note::Note() :x1(0),x2(0),y1(-20),y2(0),speed(1)
{
	cnt=0;
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
//	cachedImage_bono = ImageCache::getFromMemoey(bono_png,bono_pngSize);
//	setSize(110,100);
}

Note::~Note()
{
}

void Note::DoubleBufferfing() const{
//	Graphics g;
//	g.drawLine(0,)
}

void Note::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.
       You should replace everything in this method with your own
       drawing code..
    */
	//g.drawRect(getWidth()/12,y1,getWidth(),y2);
	//g.fillRect(getWidth()/12*3,y1,getWidth(),y2);
	g.setColour (Colours::blue);
	g.drawLine(0,y1,getWidth(),y1,20);
	DownNote();
		//g.setColour (Colours::white);
		//g.drawLine(0,y1-0.5,getWidth(),y2-0.5,25);
//g.drawImage(cachedImage_bono,getWidth()/12*4,getHeight()/12*11,getWidth()/12*4,getHeight()),0,0,cachedImage_bono.getWidth(),cachedImage_bono.getHeight());
//
}

void Note::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

//void Note::repaint(int x,int y,int width,int height) override

void Note::DownNote(){
	if(y1 < getHeight()/12*12)
	{
		/* 노트 배속 공식
		 */
		y1 = y2;
		y2 += 20;
	}
	else
	{
		y1 = -20;
		y2 = 0;
	}
	cnt++;
}

/*
void Note::run() 
{

}
*/
