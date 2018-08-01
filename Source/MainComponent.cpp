#include "MainComponent.h"

MainComponent::MainComponent() 
{
	setOpaque(true);		// 컴포넌트에 가려진 뒷부분 최적화. 많은 사람들이 가능하면 쓰라고 한다.
	//setWantsKeyboardFocus(true); // 전체 컴포넌트에 대해 입력을 받는다.
	songLayout.setWantsKeyboardFocus(true);
	addAndMakeVisible(songLayout);
	addAndMakeVisible(noteManager);
	addAndMakeVisible(map);
	//audio.SelectSong();
//	noteManager.setWantsKeyboardFocus(true);
//	noteManager.generateNote();
    setSize (1280,720);
}

MainComponent::~MainComponent()
{

}
void MainComponent::paint (Graphics& g) 
{
		
	g.fillAll(Colour(13,13,13));
//	g.setColour(Colour(255,91,51));
//	g.fillRect(Rectangle<int>(0, 0, 100, 100));
	//Rectanble을 만들어 상대적으로 접근할 필요가 있음. KeyComponent에도 마찬가지로
}

void MainComponent::resized()
{
	noteManager.setBounds(getWidth() / 3, 0, getWidth() / 3, getHeight());
	map.setBounds(getWidth() / 3 , 0, getWidth() / 3, getHeight());
	songLayout.setBounds(0,0,getWidth()/3,getHeight());
}


