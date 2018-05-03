#include "MainComponent.h"
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (1980,1280);

	addAndMakeVisible(keycomponent);
//쓰레드로 분리해야함..? 
	// keycomponent가 pressed를 보내면 
	// notecomponent가 addListener등록하고 신호받아야함
    addAndMakeVisible(notecomponent);
	addAndMakeVisible(menu);
	notecomponent.setBounds(0,0,getWidth(),getHeight());
	menu.setBounds(0,0,getWidth(),getHeight());
	
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
		
	g.fillAll(Colour(13,13,13));
   g.setColour(Colour(255,91,51));
	g.setFont(60.0f);

	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로
	//입력효과를 줄때 필요함
	g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	g.drawText("D",getWidth()/12*4,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centred,true);
	g.drawText("F",getWidth()/12*5,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centred,true);
	g.drawText("J",getWidth()/12*6,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centred,true);
	g.drawText("K",getWidth()/12*7,getHeight()/11*10,getWidth()/12,getHeight()/11,Justification::centred,true);


}

void MainComponent::resized()
{

}

