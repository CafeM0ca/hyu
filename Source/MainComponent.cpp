#include "MainComponent.h"

MainComponent::MainComponent() 
{
	std::cout << "MainComponent Ctor" << std::endl;
	setOpaque(true);		// 컴포넌트에 가려진 뒷부분 최적화. 많은 사람들이 가능하면 쓰라고 한다.
//	songLayout.setWantsKeyboardFocus(true); // 전체 컴포넌트에 대해 입력을 받는다.
	addKeyListener(this);
	addAndMakeVisible(songLayout);
	addAndMakeVisible(noteManager);
	addAndMakeVisible(map);
	addAndMakeVisible(song);
//	noteManager.setWantsKeyboardFocus(true);
//	noteManager.generateNote();
    setSize (1280,720);
}

MainComponent::~MainComponent()
{
	removeKeyListener(this);
}
void MainComponent::paint (Graphics& g) 
{
	g.fillAll(Colour(13,13,13));
}

void MainComponent::resized()
{
	noteManager.setBounds(getWidth() / 3, 0, getWidth() / 3, getHeight());
	map.setBounds(getWidth() / 3 , 0, getWidth() / 3, getHeight());
	songLayout.setBounds(0,0,getWidth()/3,getHeight());
}

bool MainComponent::keyPressed(const KeyPress& key, Component *c)
{
	std::cout << "MainComponent keyPressed" << std::endl;
	if (key == KeyPress::returnKey) {
		std::cout << "MainComponent KeyPress return key" << std::endl;
		std::cout << songLayout.getSongName() << std::endl;
		song.selectSong(File("./Song/" + songLayout.getSongName() + ".mp3"));
		song.changeState(Audio::TransportState::Starting);
		songLayout.addKeyListener(&songLayout);
	}
	return false;
}
