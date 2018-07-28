#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"
Note::Note(const float& x, const float& y, const float& width, const float& height)
	: rect(x, y, width, height)
{
	DBG("Note Component ctor");
}
Note::~Note()
{

}
NoteManager::NoteManager()
{
	setFramesPerSecond(60);
}

NoteManager::~NoteManager()
{

}


void NoteManager::update()
{
	// 활성화된 노트까지 매 주기마다 y값 수정
	//std::cout << "--------------active note: " << activePos <<  "-----------------------" << std::endl; 
	
	// 1. 노트가 바닥치기 전까지 다 pop 
	/*
	if(activePos < noteDeque.size()) {
		Random rand;
		rand.setSeedRandomly();
		auto r = rand.getSystemRandom().nextInt(Range<int>(0, 20));
		if(r == 1)
			activePos++;
	}
	if (!noteDeque.empty() && noteDeque.front().rect.getY() >= getHeight()) {
		//std::cout << "pop note" << std::endl;
		noteDeque.pop_front();
		activePos--;										// pop된 노트 개수만큼 현재 위치 조절
	}

	if (!noteDeque.empty()) {									// 검사 안하면 에러발생 가능성!
		// 2. 정리된 deque의 rect.y를 조절 
		// 
		for(int currentPos = 0;currentPos < activePos; currentPos++) {
			noteDeque.at(currentPos).rect.setY(noteDeque.at(currentPos).rect.getY() + 10);
		}
	}
	*/
}
void NoteManager::paint(Graphics& g)
{
	g.fillAll(Colour(13, 13, 13));
	g.setColour(Colour(222,222,222));

	// 
	float urteil_height = getHeight()/12*10.5; // 판정포인트 시작y
	float keyframe_height = urteil_height + getHeight()/30; // 키입력칸 시작 y
	float width = getWidth() / 4;

	g.setColour(Colours::lightpink);
	if(dkey.isCurrentlyDown()) 
		g.fillRect(Rectangle<float>{0,urteil_height, width, keyframe_height});
	if(fkey.isCurrentlyDown()) 
		g.fillRect(Rectangle<float>{width, urteil_height, width, keyframe_height});
	if(jkey.isCurrentlyDown()) 
		g.fillRect(Rectangle<float>{width*2, urteil_height, width, keyframe_height});
	if(kkey.isCurrentlyDown()) 
		g.fillRect(Rectangle<float>{width*3 ,urteil_height, width, keyframe_height});
		
	if (!noteDeque.empty()) {
		g.setColour(Colours::lightpink);
		for(int currentPos = 0;currentPos < activePos; currentPos++) {
			g.fillRect(noteDeque.at(currentPos).rect);
		}
	}
}
void NoteManager::resized()
{
	width = getWidth();
}

void NoteManager::generateNote(const short playTime /* 3분 00초 */)
{
	/* 
	노트를 list에 다 넣는다.
    게임 시작중에 startTimer의 인자를 제각각으로 만들어서 노트를 떨어뜨린다.
    노트의 개수는 1초당 1개꼴로 만들며 곡의 난이도나 템포에 따라 변동조절한다.
	생성 알고리즘을 여기에서 정의.
	*/
	Random rand;
	rand.setSeedRandomly();
	auto pwid = getParentWidth() / 3;
	std::cout << pwid << std::endl;
	for (int i = 0; i < playTime ; i++) {
		auto location = rand.getSystemRandom().nextInt(Range<int>(0, 4));
		const auto rail = rand.getSystemRandom().nextInt(Range<int>(0, 4));
		noteDeque[rail].push_back(Note((1280 /12 *location) , 0, 1280 / 12, 10));
	}
}
