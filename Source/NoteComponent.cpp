#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteComponent.h"
Note::Note(const float& x, const float& y, const float& width, const float& height)
	: rect(x, y, width, height), state(Judgement::none)
{
	DBG("Note Component ctor");

}
Note::~Note()
{

}
NoteManager::NoteManager()
{
	setFramesPerSecond(60);
	setWantsKeyboardFocus(true);
	grabKeyboardFocus();
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
	for (int i = 0; i < 1; i++) {
		if (activePos[i] < noteDeque[i].size()) {
			Random rand;
			rand.setSeedRandomly();
			auto r = rand.getSystemRandom().nextInt(Range<int>(0, 50));
			if (r == 1)
				activePos[i]++;
		}
		
		while (!noteDeque[i].empty()) {
			if (noteDeque[i].front().state != Judgement::none) {
				std::cout << "note status is not Judgement::noen. pop note" << std::endl;
				noteDeque[i].pop_front();
				activePos[i]--;
			}
			else if (noteDeque[i].front().rect.getY() >= jendY + noteDeque[i].front().rect.getHeight()) {
				std::cout << "nstartY over. pop note" << std::endl;
				noteDeque[i].pop_front();
				activePos[i]--;										// pop된 노트 개수만큼 현재 위치 조절
				combo = 0;
			}
			else break;
		}
	
	if (!noteDeque[i].empty()) {
																		// 2. 정리된 deque의 rect.y를 조절 
			note_startY = noteDeque[0].front().rect.getY();
			note_endY = note_startY + noteDeque[0].front().rect.getHeight();		
			int currentPos = 0;
			for (auto& j : noteDeque[i]) {
				if (currentPos < activePos[i]) {
					//	std::cout << currentPos << " note.y += 10" << std::endl;
					j.rect.setY(j.rect.getY() + /*10*/ 15);
					//std::cout << j.rect.getY() << std::endl;
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

	g.setColour(Colours::blue);
	g.fillRect(Rectangle<int>(0, 600, getWidth() / 4, 40));
	
	g.setColour(Colours::fuchsia);

	for (int i = 0; i < 4; i++)
	{
		if (!noteDeque[i].empty()) {
			
			int currentPos = 0;
			for (auto& j : noteDeque[i]) {
				if (currentPos < activePos[i]) {
					g.fillRect(j.rect);
					currentPos++;
				}
				else break;
			}
			/* before
				note_startY = noteDeque[0].front().rect.getY();
				note_endY = note_startY + noteDeque[0].front().rect.getHeight();
			*/
		}
	}
	float effectWidth = getWidth() / 4;

	if (dkey.isCurrentlyDown()) {
		switch (noteDeque[0].front().state)
		{
		case Judgement::wow:
			g.setColour(Colours::gold);
			break;
		case Judgement::ok:
			g.setColour(Colours::silver);
			break;
		case Judgement::hyu:
			g.setColour(Colours::aliceblue);
			break;
		case Judgement::oops:
			g.setColour(Colours::crimson);
			break;
		default:
			g.setColour(Colours::orange);
			break;
		}
		g.fillRect(Rectangle<float>(0, jstartY, effectWidth, jendY));
	}
	if (fkey.isCurrentlyDown()) {
		switch (noteDeque[1].front().state)
		{
		case Judgement::wow:
			g.setColour(Colours::gold);
			break;
		case Judgement::ok:
			g.setColour(Colours::silver);
			break;
		case Judgement::hyu:
			g.setColour(Colours::aliceblue);
			break;
		case Judgement::oops:
			g.setColour(Colours::crimson);
			break;
		default:
			g.setColour(Colours::orange);
			break;
		}
		g.fillRect(Rectangle<float>(effectWidth, jstartY, effectWidth, jendY));
	}
	if (jkey.isCurrentlyDown()) {
		switch (noteDeque[2].front().state)
		{
		case Judgement::wow:
			g.setColour(Colours::gold);
			break;
		case Judgement::ok:
			g.setColour(Colours::silver);
			break;
		case Judgement::hyu:
			g.setColour(Colours::aliceblue);
			break;
		case Judgement::oops:
			g.setColour(Colours::crimson);
			break;
		default:
			g.setColour(Colours::orange);
			break;
		}
		g.fillRect(Rectangle<float>(effectWidth * 2, jstartY, effectWidth, jendY));
	}
	if (kkey.isCurrentlyDown()) {
		switch (noteDeque[3].front().state)
		{
		case Judgement::wow:
			g.setColour(Colours::gold);
			break;
		case Judgement::ok:
			g.setColour(Colours::silver);
			break;
		case Judgement::hyu:
			g.setColour(Colours::aliceblue);
			break;
		case Judgement::oops:
			g.setColour(Colours::crimson);
			break;
		default:
			g.setColour(Colours::orange);
			break;
		}
		g.fillRect(Rectangle<float>(effectWidth * 3, jstartY, effectWidth, jendY));
	}

	g.setColour(Colours::white);
	g.setFont(Font(100.0f));
	g.drawText(std::to_string(combo), 0, 0, effectWidth, getHeight(), Justification::centred);
	
}
void NoteManager::resized()
{
	jstartY = getHeight() / 12 * 10; // 판정포인트 시작y
	jendY = jstartY + 40; // 판정포인트 끝y
}
bool NoteManager::keyPressed(const KeyPress& key)
{
	std::cout << "keyPressed called!!!!" << std::endl;
	int index;
	if (key == dkey)
	{
		std::cout << "keyPressed dkey" << std::endl;
		index = 0;
		
		std::cout << "note_startY: " << note_startY << std::endl;
		//assert(note_startY < getHeight());
		if(!noteDeque[index].empty() && note_startY > getHeight()/ 2)
			judgeNote(index, note_startY, note_endY); 
		return true;
	}
	else if (key == fkey)
	{
		std::cout << "keyPressed fkey" << std::endl;
		index = 1;
		const int note_startY = noteDeque[index].front().rect.getY();
		const int note_endY = note_startY + noteDeque[index].front().rect.getHeight();
		judgeNote(index, note_startY, note_endY);
		return true;
	}
	else if (key == jkey)
	{
		std::cout << "keyPressed jkey" << std::endl;
		index = 2;
		const int note_startY = noteDeque[index].front().rect.getY();
		const int note_endY = note_startY + noteDeque[index].front().rect.getHeight();
		judgeNote(index, note_startY, note_endY);
		return true;
	}
	else if (key == kkey)
	{
		std::cout << "keyPressed kkey" << std::endl;
		index = 3;
		const int note_startY = noteDeque[index].front().rect.getY();
		const int note_endY = note_startY + noteDeque[index].front().rect.getHeight();
		judgeNote(index, note_startY, note_endY);
		return true;
	}
	return false;
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
		//auto location = rand.getSystemRandom().nextInt(Range<int>(0, 4));
		//noteDeque[location].push_back(Note((1280 / 12 * location), 0, 1280 / 12, 10));
		noteDeque[0].push_back(Note((1280 / 12 * 0), 0, 1280 / 12, 15));
	}
}
void NoteManager::judgeNote(const short& idx, const int& nstartY, const int& nendY)
{
	std::cout << "jstartY : " << jstartY << ", jendY : " << jendY << std::endl;
	std::cout << "nstartY: " << nstartY << ", nendY: " << nendY << std::endl;
	//assert(nstartY < getHeight() || nendY < getHeight());
	//if (!noteDeque[idx].empty() && noteDeque[idx].front().rect.getY() > getHeight() && noteDeque[idx].front().state == Judgement::none) {
	if (noteDeque[idx].front().state == Judgement::none) {
		if (nendY < jstartY || nstartY > jendY) {											// note 가 판정선에 걸치지 않는 경우
			noteDeque[idx].front().state = Judgement::oops;
			score.push(Judgement::oops);
			combo = 0;
			std::cout << "====== oops!!! ======" << std::endl;
		}
		else if (nstartY < jstartY && nendY < jendY) {										// note 가 판정선 윗쪽에 걸치는 경우
			noteDeque[idx].front().state = Judgement::ok;
			score.push(Judgement::ok);
			combo++;
			std::cout << "===== ok!!! =====" << std::endl;
		}
		else if (nstartY < jendY &&  nendY > jendY) {										// note 가 판정선 아래에 걸치는 경우
			noteDeque[idx].front().state = Judgement::hyu;
			score.push(Judgement::hyu);
			combo++;
			std::cout << "====== hyu!!! ======" << std::endl;
		}
		else if (nstartY >= jstartY && nendY <= jendY) {									// note 가 판정선 안에 들어가는 경우
			noteDeque[idx].front().state = Judgement::wow;
			score.push(Judgement::wow);
			combo++;
			std::cout << "====== wow!!! =======" << std::endl;
		}
	}
	else {
		std::cout << "note under half line" << std::endl;
	}
}