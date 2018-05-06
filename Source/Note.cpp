#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"
Note::Note() : bpm(0)
{
	setFramesPerSecond(120);
}
Note::~Note()
{ 
} 

void Note::update()
{
	// setFramesPerSecond에 맞춰서 떨어진다. 60이면 1초에 60번 호출됨.
	DownNote();
}

void Note::paint (Graphics& g)
{
	std::cout << getMillisecondsSinceLastUpdate() << std::endl;
	// 무지개 노트
	g.fillAll(Colour(13,13,13));
	
	g.setColour(Colours::red);
//	g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	g.fillRect(block);
}

void Note::resized()
{

}

void Note::SetNotePos(const Rectangle<float>& rect)
{
	block = rect;
}

void Note::DownNote(){
	if(block.getY() <= getHeight()/12*10.5+getHeight()/30){
		block.setY(block.getY()+20);
	}
	else
	{
		block.setX(getWidth()/12 * Random::getSystemRandom().nextInt(Range<int>(4,8)));
		block.setY(-10);
		bpm++;
	}
}

void Note::AddNote(const Rectangle<float>& rect)
{

}
