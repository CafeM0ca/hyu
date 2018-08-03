#include "MainComponent.h"

MainComponent::MainComponent() 
{
	//std::cout << "MainComponent Ctor" << std::endl;
	setOpaque(true);		// 컴포넌트에 가려진 뒷부분 최적화. 많은 사람들이 가능하면 쓰라고 한다.
//	songLayout.setWantsKeyboardFocus(true); // 전체 컴포넌트에 대해 입력을 받는다.
	songLayout = new SoundComponent;
	addKeyListener(songLayout);
	addKeyListener(this);
	addAndMakeVisible(songLayout);
	addAndMakeVisible(noteManager);
	addAndMakeVisible(map);
	addAndMakeVisible(song);
    setSize (1280,720);
}

MainComponent::~MainComponent()
{
	removeKeyListener(this);
	if (songLayout != nullptr) {
		delete songLayout;
		songLayout = nullptr;
	}
}
void MainComponent::paint (Graphics& g) 
{
	g.fillAll(Colour(13,13,13));
}

void MainComponent::resized()
{
	noteManager.setBounds(getWidth() / 3, 0, getWidth() / 3, getHeight());
	map.setBounds(getWidth() / 3 , 0, getWidth() / 3, getHeight());
	if(songLayout != nullptr)
		songLayout->setBounds(0,0,getWidth()/3,getHeight());
}

bool MainComponent::keyPressed(const KeyPress& key, Component *c)
{
	//std::cout << "MainComponent keyPressed" << std::endl;
	if (key == KeyPress::returnKey && song.getState() != Audio::TransportState::Starting) {
	//	std::cout << "MainComponent KeyPress return key" << std::endl;
	//	std::cout << songLayout->getSongName() << std::endl;
		song.selectSong(File("./Song/" + songLayout->getSongName() + ".mp3"));
		song.changeState(Audio::TransportState::Starting);
		noteManager.generateNote();
		removeKeyListener(songLayout);
		delete songLayout;
		songLayout = nullptr;
	}
	else if (key.getTextCharacter() == 'r' && songLayout == nullptr) {
		noteManager.clear();
		songLayout = new SoundComponent;
		songLayout->setBounds(0,0,getWidth()/3,getHeight());
		addKeyListener(songLayout);
		addAndMakeVisible(songLayout);
		song.changeState(Audio::TransportState::Finish);
	}
	return false;
}
