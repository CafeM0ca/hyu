#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"
Note::Note() : bpm(0),del_cnt(0)
{
	addAndMakeVisible(key);
	setFramesPerSecond(60); // bpm조절
}

Note::~Note()
{ 

} 

/*
void Note::timerCallback()
{
	if(note_list.size() > 30)
		note_list.clear();
}
*/

void Note::update()
{
	// setFramesPerSecond에 맞춰서 떨어진다. 60이면 1초에 60번 호출됨.
	if(Random::getSystemRandom().nextInt(Range<int>(1,15)) == 1 && note_list.size() <= 30){	
		AddNote(block);
	}
	/*
	if(note_list.size() == 30)
	{
		note_list.clear();
	}
	*/
	if(note_list.size() > 0)
		DownNote();
	if(note_list.size() >= 30){
		if(del_cnt == 120){
			note_list.clear();
			del_cnt = 0;
		}
		else
			del_cnt++;
	}
}

void Note::paint (Graphics& g)
{
	// 무지개 노트
	g.fillAll(Colour(13,13,13));
	
	g.setColour(Colours::pink);
	//g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	for(auto& i : note_list)
		g.fillRect(i);
	//g.fillRect(block);
	//g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.7f).withBrightness(0.5f));
	g.setColour(Colour(255,51,0));
	if(key.dkey.isCurrentlyDown()){
		g.fillRect(getWidth()/12*4+2,getHeight()/12*10.5,getWidth()/12-2,getHeight()/30);
	} 
	if(key.fkey.isCurrentlyDown()){
		g.fillRect(getWidth()/12*5+2,getHeight()/12*10.5,getWidth()/12-2,getHeight()/30);
	}
	if(key.jkey.isCurrentlyDown()){
		g.fillRect(getWidth()/12*6+2,getHeight()/12*10.5,getWidth()/12-2,getHeight()/30);
	}
	if(key.kkey.isCurrentlyDown()){
		g.fillRect(getWidth()/12*7+2,getHeight()/12*10.5,getWidth()/12-2,getHeight()/30);
	}
}

void Note::resized()
{

}

void Note::SetNotePos(const Rectangle<float>& rect)
{
	block = rect;
}
void Note::DownNote(){
	unsigned short note_cnt = 0;	
	for(auto &i : note_list)
	{
		if(i.getY() <= getHeight()/12*10.5+getHeight()/30){
			i.setY(i.getY()+10);
		}
	}
	/*
	for(auto i=0;i<note_cnt;i++){
		DBG("pop");
		note_list.pop_front();
	}
	*/
	/*
	for(auto& i : note_list){

	}
	if(block.getY() <= getHeight()/12*10.5+getHeight()/30){
		block.setY(block.getY()+20);
	}
	else
	{
		block.setX(getWidth()/12 * Random::getSystemRandom().nextInt(Range<int>(4,8)));
		block.setY(-10);
		bpm++;
	}
	if(Random::getSystemRandom().nextInt(Range<int>(1,5)) == 2)
	{
		AddNote(block);
	}
	*/
}
void Note::AddNote(Rectangle<float>& rect)
{
	rect.setX(getWidth()/12 * Random::getSystemRandom().nextInt(Range<int>(4,8)));
	note_list.push_back(rect);
}
