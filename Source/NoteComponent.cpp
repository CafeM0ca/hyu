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
	generateNote();
}

NoteManager::~NoteManager()
{

}


void NoteManager::update()
{
	// 활성화된 노트까지 매 주기마다 y값 수정
	std::cout << "--------------active note: " << activePos <<  "-----------------------" << std::endl; 
	/*
	Rectangle<float> *ptr = nullptr;
	int popcnt = 0;
	for (int i = 0; i < notePos; i++) {
		ptr = &noteDeque.at(i).rect;
		if (ptr->getY() > getHeight()) {
			noteDeque.pop_front();
			popcnt++;
		}
		else {
			ptr->setY(ptr->getY()+10);
		}
	}
	notePos -= popcnt;
	notePos++;		// 매 초마다 노트수 증가
	*/
	// 1. 노트가 바닥치기 전까지 다 pop 
	if(activePos < noteDeque.size()) {
		Random rand;
		rand.setSeedRandomly();
		auto r = rand.getSystemRandom().nextInt(Range<int>(0, 20));
		if(r == 1)
			activePos++;
	}
	if (!noteDeque.empty() && noteDeque.front().rect.getY() >= getHeight()) {
		std::cout << "pop note" << std::endl;
		noteDeque.pop_front();
		activePos--;										// pop된 노트 개수만큼 현재 위치 조절
	}

	if (!noteDeque.empty()) {									// 검사 안하면 에러발생 가능성!
		// 2. 정리된 deque의 rect.y를 조절 
		int currentPos = 0;
		for (auto& i : noteDeque) {
			if (currentPos < activePos) {
				std::cout << currentPos << " note.y += 10" << std::endl;
				i.rect.setY(i.rect.getY() + /*10*/ 15);
				currentPos++;
			}
			else break;
		}
	}
}
void NoteManager::paint(Graphics& g)
{
	g.fillAll(Colour(13, 13, 13));
	g.setColour(Colour(222,222,222));

	if (!noteDeque.empty()) {
		int currentPos = 0;
		for (auto i : noteDeque) {
			if (currentPos < activePos) {
				g.fillRect(i.rect);
				currentPos++;
			}
			else break;
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
	for (int i = 0; i < /*playTime*/ 30000; i++) {
		auto location = rand.getSystemRandom().nextInt(Range<int>(0, 4));
		noteDeque.push_back(Note((1280 /12 *location) , 0, 1280 / 12, 10));
	}
}
