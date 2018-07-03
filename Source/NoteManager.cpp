#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteManager.h"
//#include "Audio.h"
NoteManager::NoteManager() : snote(60)
{
	addAndMakeVisible(snote);		
	std::cout << "noteManager: getWidth()" << getWidth() << std::endl;
}

NoteManager::~NoteManager()
{
}

void NoteManager::paint(Graphics& g)
{

}

void NoteManager::resized()
{
	snote.setBounds(0,0,getWidth(),getHeight());
}
void NoteManager::playSong()
{
//	song.SelectSong();	
}
