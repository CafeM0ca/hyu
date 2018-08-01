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
	setFramesPerSecond(120);
	setWantsKeyboardFocus(true);
	addAndMakeVisible(comboLabel);
	comboLabel.setJustificationType(Justification::centred);
	comboLabel.setFont(Font(50.0f));
}
NoteManager::~NoteManager()
{
	
}
void NoteManager::update()
{
	// 향후 비동기로 레일 별로 async해줘야한다. 아래 로직을 처리해주는 함수를 만들고 처리
	for (int i = 0; i < noteRails; i++) {
		// 선제 조건을 이전 노트의 Y값에 따라 정의하여 조절가능.			
		if (activePos[i] < noteDeque[i].size()) {
			Random rand;
			rand.setSeedRandomly();
			auto r = rand.getSystemRandom().nextInt(Range<int>(0, 300));
			if (r == 1)
				activePos[i]++;
		}
		
		// 1. 노트가 소모되기 전까지 다 pop 
		while (!noteDeque[i].empty()) {
			if (noteDeque[i].front().state != Judgement::none) {								// keyPressed() 함수를 통해 처리된 노트
				//std::cout << "note status is not Judgement::noen. pop note" << std::endl;
				noteDeque[i].pop_front();
				activePos[i]--;
			}
			else if (noteDeque[i].front().rect.getY() >= jendY + noteDeque[i].front().rect.getHeight()) {	// 눌리지 않은 노트 처리
				//std::cout << "nstartY over. pop note" << std::endl;
				score.push(Judgement::oops);
				keyPressedColor[i] = Colours::crimson;
				comboLabel.setBounds(0, 0, getWidth(), jstartY);
				comboLabel.setBounds(pressEffectWidth * i, 0, pressEffectWidth, jendY);
				comboLabel.setColour(Label::textColourId, Colours::crimson);
				comboLabel.setColour(Label::outlineColourId, Colours::orangered);
				comboLabel.setText("oops", NotificationType::dontSendNotification);
				noteDeque[i].pop_front();
				activePos[i]--;																		    // pop된 노트 개수만큼 현재 위치 조절
				combo = 0;
			}
			else break;
		}

	// 2. 정리된 deque의 rect.y를 조절 
	if (!noteDeque[i].empty()) {
			nstartY[i] = noteDeque[i].front().rect.getY();												// 판정에 쓰일 노트좌표
			nendY[i] = nstartY[i] + noteDeque[i].front().rect.getHeight();		
			int currentPos = 0;
			for (auto& j : noteDeque[i]) {
				if (currentPos < activePos[i]) {
					j.rect.setY(j.rect.getY() + 15);
					currentPos++;
					//std::cout << j.rect.getY() << std::endl;
					//std::cout << currentPos << " note.y += 10" << std::endl;
				}
				else break;
			}
		}
	}
}
void NoteManager::paint(Graphics& g)
{
	// remove afterimage
	g.fillAll(Colour(13, 13, 13));

	// draw Note 
	g.setColour(Colours::fuchsia);
	for (int i = 0; i < noteRails; i++)
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
		}
	}
	// when keypressed, color painting judgement line
	if (dkey.isCurrentlyDown()) {
		g.setColour(keyPressedColor[0]);
		g.fillRect(Rectangle<float>(0, jstartY, pressEffectWidth, jendY));
	}
	if (fkey.isCurrentlyDown()) {
		g.setColour(keyPressedColor[1]);
		g.fillRect(Rectangle<float>(pressEffectWidth, jstartY, pressEffectWidth, jendY));
	}
	if (jkey.isCurrentlyDown()) {
		g.setColour(keyPressedColor[2]);
		g.fillRect(Rectangle<float>(pressEffectWidth * 2, jstartY, pressEffectWidth, jendY));
	}
	if (kkey.isCurrentlyDown()) {
		g.setColour(keyPressedColor[3]);
		g.fillRect(Rectangle<float>(pressEffectWidth * 3, jstartY, pressEffectWidth, jendY));
	}
}
void NoteManager::resized()
{
	jstartY = getHeight() / 12 * 10; // 판정포인트 시작y
	jendY = jstartY + 40; // 판정포인트 끝y
	pressEffectWidth = getWidth() / 4;
}
bool NoteManager::keyPressed(const KeyPress& key)
{
	if (const int index = [this, key]()->auto {
				if      (key == dkey) return 0;
				else if (key == fkey) return 1;
				else if (key == jkey) return 2;
				else if (key == kkey) return 3;
				else				  return -1;
			}(); index >= 0 && index <= 3) {
		if(!noteDeque[index].empty() && nstartY[index] > getHeight() / 2)
			judgeNote(index, nstartY[index], nendY[index]);
		return true;
	} else return false;
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
	for (int i = 0; i < playTime; i++) {
		auto location = rand.getSystemRandom().nextInt(Range<int>(0, noteRails));
		noteDeque[location].push_back(Note((1280 / 12 * location), 0, 1280 / 12, 15));
	}
}
void NoteManager::judgeNote(const short& idx, const int& nstartY, const int& nendY)
{
	//std::cout << "jstartY : " << jstartY << ", jendY : " << jendY << std::endl;
	//std::cout << "nstartY: " << nstartY << ", nendY: " << nendY << std::endl;
	//assert(nstartY < getHeight() || nendY < getHeight());
	//if (!noteDeque[idx].empty() && noteDeque[idx].front().rect.getY() > getHeight() && noteDeque[idx].front().state == Judgement::none) {
	if (noteDeque[idx].front().state == Judgement::none) {
		comboLabel.setBounds(pressEffectWidth * idx, 0, pressEffectWidth, jendY);
		if (nendY < jstartY || nstartY > jendY) {											// note 가 판정선에 걸치지 않는 경우
			combo = 0;
			noteDeque[idx].front().state = Judgement::oops;
			score.push(Judgement::oops);

			keyPressedColor[idx] = Colours::crimson;
			comboLabel.setColour(Label::textColourId, Colours::crimson);
			comboLabel.setColour(Label::outlineColourId, Colours::orangered);
			comboLabel.setText("oops", NotificationType::dontSendNotification);
		}
		else if (nstartY < jstartY && nendY < jendY) {										// note 가 판정선 윗쪽에 걸치는 경우
			combo++;
			noteDeque[idx].front().state = Judgement::ok;
			score.push(Judgement::ok);

			keyPressedColor[idx] = Colours::silver;
			comboLabel.setColour(Label::textColourId, Colours::silver);
			comboLabel.setColour(Label::outlineColourId, Colours::orangered);
			comboLabel.setText("ok\n" + std::to_string(combo), NotificationType::dontSendNotification);
		}
		else if (nstartY < jendY &&  nendY > jendY) {										// note 가 판정선 아래에 걸치는 경우
			combo++;
			noteDeque[idx].front().state = Judgement::hyu;
			score.push(Judgement::hyu);

			keyPressedColor[idx] = Colours::aliceblue;
			comboLabel.setColour(Label::textColourId, Colours::aliceblue);
			comboLabel.setColour(Label::outlineColourId, Colours::orangered);
			comboLabel.setText("hyu\n" + std::to_string(combo), NotificationType::dontSendNotification);
		}
		else if (nstartY >= jstartY && nendY <= jendY) {									// note 가 판정선 안에 들어가는 경우
			combo++;
			noteDeque[idx].front().state = Judgement::wow;
			score.push(Judgement::wow);

			keyPressedColor[idx] = Colours::gold;
			comboLabel.setColour(Label::textColourId, Colours::gold);
			comboLabel.setColour(Label::outlineColourId, Colours::orangered);
			comboLabel.setText("wow\n" + std::to_string(combo), NotificationType::dontSendNotification);
		}
	}
	else {
		//std::cout << "note under half line" << std::endl;
		keyPressedColor[idx] = Colours::orangered;
		comboLabel.setText("", NotificationType::dontSendNotification);
	}
}