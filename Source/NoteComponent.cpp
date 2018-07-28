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
	//std::cout << "--------------active note: " << activePos <<  "-----------------------" << std::endl; 
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
	for (int i = 0; i < 4; i++) {
		if(activePos[i] < noteDeque[i].size()) {
			Random rand;
			rand.setSeedRandomly();
			auto r = rand.getSystemRandom().nextInt(Range<int>(0, 30));
			if(r == 1)
				activePos[i]++;
		}
		if (!noteDeque[i].empty() && noteDeque[i].front().rect.getY() >= getHeight()) {
			std::cout << "pop note" << std::endl;
			noteDeque[i].pop_front();
			activePos[i]--;										// pop된 노트 개수만큼 현재 위치 조절
		}

		if (!noteDeque[i].empty()) {									// 검사 안하면 에러발생 가능성!
			// 2. 정리된 deque의 rect.y를 조절 
			int currentPos = 0;
			for (auto& j : noteDeque[i]) {
				if (currentPos < activePos[i]) {
	//				std::cout << currentPos << " note.y += 10" << std::endl;
					j.rect.setY(j.rect.getY() + /*10*/ 15);
					currentPos++;
				}
				else break;
			}
		}
	}

}
void NoteManager::paint(Graphics& g)
{
	g.fillAll(Colour(13, 13, 13));
	g.setColour(Colours::fuchsia);

	float startY[4]{ 0 }, endY[4]{ 0 };
	for (int i = 0; i < 4; i++)
	{
		if (!noteDeque[i].empty()) {
			int currentPos = 0;
			for (auto j : noteDeque[i]) {
				if (currentPos < activePos[i]) {
					g.fillRect(j.rect);
					currentPos++;
				}
				else break;
			}
			startY[i] = noteDeque[i].front().rect.getY();
			endY[i] = startY[i] + noteDeque[i].front().rect.getHeight();
		}
	}
	const float&& judgement_start = getHeight()/12*10.5; // 판정포인트 시작y
	const float&& judgement_end = judgement_start + getHeight()/30; // 판정포인트 끝y

	// note가 start에 걸치면 ok,  end에 걸치면 hyu
	// 판정선 안에 정확히 들어가면 wow
	// else oops 

	for(short index = 0; index < 4; index++) {
		switch(judgeNote(myKey[index], index, std::move(startY[index]), std::move(endY[index]), 
					std::move(judgement_start), std::move(judgement_end))){
			case NoteManager::Judgement::wow :
				g.setColour(Colours::gold);
				break;
			case NoteManager::Judgement::ok :
				g.setColour(Colours::azure);
				break;
			case NoteManager::Judgement::hyu :
				g.setColour(Colours::mintcream);
				break;
			case NoteManager::Judgement::oops :
				g.setColour(Colours::crimson);
				break;
			case NoteManager::Judgement::none :
				g.setColour(Colour(13,13,13));
		}
		g.fillRect(Rectangle<float>(width * index, judgement_start, width / 4, judgement_end));
		g.setFont(Font(Font::bold, 130.0f));
		g.setColour(Colours::white);
		g.drawText(std::to_string(combo), 0, 0, getWidth(), getHeight(), Justification::centred);
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
	for (int i = 0; i < playTime; i++) {
		auto location = rand.getSystemRandom().nextInt(Range<int>(0, 4));
		noteDeque[location].push_back(Note((1280 /12 *location) , 0, 1280 / 12, 10));
	}
}
NoteManager::Judgement NoteManager::judgeNote(const KeyPress& key, const short& idx, 
		const float&& nstartY, const float&& nendY, const float&& jstartY, const float&& jendY)
{
	if (!noteDeque[idx].empty()) {
		if(key.isCurrentlyDown()){
			if (nstartY > jstartY- getHeight() / 5 && nstartY + nendY < jstartY 
				|| nstartY > jendY) {
				score.push(Judgement::oops);
				combo = 0;
				std::cout << "====== oops!!! ======" << std::endl;
				std::cout << "nstartY: " << nstartY << ", nendY: " << nendY << std::endl;
				return Judgement::oops;
			}
			else if (nstartY < jstartY && nstartY + nendY < jendY) {
				score.push(Judgement::ok);
				combo++;
				std::cout << "===== ok!!! =====" << std::endl;
				std::cout << "nstartY: " << nstartY << ", nendY: " << nendY << std::endl;
				return Judgement::ok;
			}
			else if (nstartY > jstartY && nstartY + nendY > jendY) {
				score.push(Judgement::hyu);
				combo++;
				std::cout << "====== hyu!!! ======" << std::endl;
				std::cout << "nstartY: " << nstartY << ", nendY: " << nendY << std::endl;
				return Judgement::hyu;
			}
			else if (nstartY >= jstartY && nstartY + nendY <= jendY) {
				score.push(Judgement::wow);
				combo++;
				std::cout << "====== wow!!! =======" << std::endl;
				std::cout << "nstartY: " << nstartY << ", nendY: " << nendY << std::endl;
				return Judgement::wow;
			}
			else {
				// nothing do 
				std::cout << "===== already note Y =====" << std::endl;
			}
		} 
	}
	return Judgement::none;
}
