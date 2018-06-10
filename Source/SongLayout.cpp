#include "../JuceLibraryCode/JuceHeader.h"
#include "SongLayout.h"
/* ------------------------------------------------------------ */
SongLayout::SongLayout() :
	songTitle("Press W or S"),
	wkey('w'),
	skey('s'),
	isSelected(false)
{
	loadSongList();
	setWantsKeyboardFocus(true);

	songListIter = songList.begin();
}

SongLayout::~SongLayout()
{
	
}

void SongLayout::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
	g.setColour(Colour(Colours::magenta));

	g.setFont(40.0f);
	g.drawText("w(prev) / s(next)",0,0,getWidth(),getHeight()/4,Justification::centred,true); // triangle

	g.setColour(Colour(Colours::deepskyblue));
	g.setFont(30.0f);
	g.drawText(songTitle,0,0,getWidth(),getHeight()/2,Justification::centred,true);
	/*
	Path wqTriangle;
	wqTriangle.addTriangle(getWidth()/2,getHeight()/10,getWidth()/2-getWidth()/8,getHeight()/8,getWidth()/2+getWidth()/8,getHeight()/8);
	g.fillPath(wqTriangle);
	*/
	
}

void SongLayout::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}

bool SongLayout::keyPressed(const KeyPress& key)
{
	// no event = return false, else return true . no touch. is ok
	
	if(key == skey && *songListIter != songList.back())
	{
		DBG(*songListIter);
		setSongTitle(getNextSongTitle());
		repaint();
	}
	else if(key == wkey && songListIter != songList.begin())
	{
		DBG(*songListIter);
		setSongTitle(getPrevSongTitle());
		repaint();
	}
	else if(key == KeyPress::returnKey)
		changeIsSelected();
	return false;
}
void SongLayout::loadSongList()
{
	DirectoryIterator iter (File ("./Song/"), true, "*.mp3");
	while (iter.next())
	{
		File filename (iter.getFile());
		songList.push_back(filename.getFileNameWithoutExtension().toStdString());
	}

	for(auto& i : songList)
		DBG(i);
}

void SongLayout::setSongTitle(const std::string& st)
{
	songTitle = st;
}

std::string& SongLayout::getNextSongTitle() 
{
	return *(++songListIter);	
}

std::string& SongLayout::getPrevSongTitle() 
{
	return *(--songListIter);
}

std::string SongLayout::getSongTitle() const
{
	return songTitle;
}

void SongLayout::changeIsSelected()
{
	DBG("SongLayout::changeIsSelected()");
	isSelected = !isSelected;
}

bool SongLayout::getIsSelected() const
{
	return isSelected;
}
