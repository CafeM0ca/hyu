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
//

/* 노래를 방향키를 누를때마다 값을 불러올것인가? 그리고 그게 합리적인가?...합리적*/
Menu::Menu()
{

	// 글씨 색 미지정
	addAndMakeVisible(before_song);
	addAndMakeVisible(current_song);
	addAndMakeVisible(after_song);
	addAndMakeVisible(exit);
	/*
	before_song.setText("Song1",dontSendNotification);
	before_song.setColour(Label::textColourId,Colours::black);
	before_song.setFont(Font(80.0f,Font::bold));
	before_song.setJustificationType(Justification::centred);
	*/
	//current_song.setText(bgm.getSongName(),dontSendNotification);
	//getFileNameWithoutExtension
	current_song.setText(song_name.GetSongName(),dontSendNotification);
	current_song.setColour(Label::textColourId,Colours::black);
	current_song.setFont(Font(80.0f,Font::bold));
	current_song.setJustificationType(Justification::centred);
	/*
	after_song.setText("Song1",dontSendNotification);
	after_song.setColour(Label::textColourId,Colours::black);
	after_song.setFont(Font(80.0f,Font::bold));
	after_song.setJustificationType(Justification::centred);
	*/

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
	// 블럭 색 미지정
	// 뒷배경
	g.setColour(Colour(159,255,128));
	g.drawRect(0,0,450,getHeight());
	g.fillRect(0,0,450,getHeight());

	g.setColour(Colours::violet);
	g.setColour(Colours::darkviolet);
	g.drawRoundedRectangle(0,getHeight()/6,450,getHeight()-getHeight()/2,20,10);
	g.fillRoundedRectangle(Rectangle<float>(0,getHeight()/6,450,getHeight()-getHeight()/2),20);

	g.setColour(Colours::blue);
	
	g.setColour(Colours::red);
	g.drawEllipse(getWidth()-50,0,50,50,3);
	g.fillEllipse(getWidth()-50,0,50,50);
}

void Menu::resized()
{
	current_song.setBounds(0,getHeight()/4+140,450,150);
	exit.setBounds(getWidth()-50,0,50,50);
}
