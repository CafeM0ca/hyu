/*
  ==============================================================================
    Note.cpp
    Created: 22 Feb 2018 10:36:30pm
    Author:  moca
  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"
#include <fstream>
//==============================================================================
Note::Note():x1(3),x2(0),y1(-20),y2(0),speed(10)
{
	DBG("Note Ctor");
	cnt=0;
	colour = Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f);
}

Note::~Note()
{ } 

void Note::paint (Graphics& g)
{
	DBG("hi");	
	// 무지개 노트
	//g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	g.setColour(colour);
	g.drawLine(getWidth()/12*x1,y1,getWidth()/12*x1+getWidth()/12,y1,20);
	DownNote();
}

void Note::resized()
{

}


void Note::DownNote(){
	DBG("DownNote");
	if(y1 < getHeight()/12*12+10)
	{
		/* 노트 배속 공식
		 */
		y1 = y2;
		y2 += 20;
	}
	else
	{
		//노트를 만들 필요가 없어짐 
		// 시그널을 보내 동적할당 해제해야함
	}
	cnt++;
	DBG("repaint");
	repaint();
}

//NoteThread
NoteThread::NoteThread() :Thread("Note Thread")
{
	DBG("NoteThread");
	priority = 1;	
	startThread();
}

NoteThread::~NoteThread()
{
	stopThread(100);
	DBG("delete thread");
}

void NoteThread::run() 
{
	DBG("run");
	while(!threadShouldExit()) //쓰레드가 끝나지 않았으면
	{
		wait(10); //10ms cpu쉼. 원할하게 작동시키기위해 
		
		const MessageManagerLock mml(Thread::getCurrentThread());
		if(!mml.lockWasGained()) return;

		DBG("DownNoteCall-run");
		DownNote();
	}
}





//NoteController
NoteController::NoteController() :sec(0)
{
	addKeyListener(&keylistener);
	setWantsKeyboardFocus(true);
	bgm.changeState(bgm.Stopped);
	LoadGame();
}

NoteController::~NoteController()
{
	pool.removeAllJobs(true,2000);
}

void NoteController::paint(Graphics& g)
{
}

void NoteController::resized()
{
}

void NoteController::resetNotes()
{
	pool.removeAllJobs(true,4000);
}


void NoteController::addNote()
{

	if(keylistener.isPressed())
	{
		DBG("key pressed");
		if(keylistener.dkey == true)
		{
			NoteThread *nt = new NoteThread();
			addAndMakeVisible(nt);
			nt->setBounds(0,0,getWidth(),getHeight());
			nt->setRange(nt->Range::d);
			notes.add(nt);
		}
	else if(keylistener.fkey == true)
		{
			NoteThread *nt = new NoteThread();
			addAndMakeVisible(nt);
			nt->setBounds(0,0,getWidth(),getHeight());
			nt->setRange(nt->Range::f);
			notes.add(nt);
		}
	else if(keylistener.jkey == true)
		{
			NoteThread *nt = new NoteThread();
			addAndMakeVisible(nt);
			nt->setBounds(0,0,getWidth(),getHeight());
			nt->setRange(nt->Range::j);
			notes.add(nt);
		}		
	else if(keylistener.kkey == true)
		{
			NoteThread *nt = new NoteThread();
			addAndMakeVisible(nt);
			nt->setBounds(0,0,getWidth(),getHeight());
			nt->setRange(nt->Range::k);
			notes.add(nt);
			
		}	
	}
}


void NoteController::removeNote()
{	
	for(int i=0;i<notes.size();i++)
		notes.remove(i);	
} 

bool NoteController::CheckingNoteMap()
{
	//파일의 해당하는 맵이 있는지 찾는다.
	std::ifstream hm("/home/moca/coding/cpp/hyu/Song/test.hm");
	if(hm.is_open())
	{
		//찾음
		DBG("file found");
		return true;
	}
	else
	{
		//없음 파일 만들어야함.
		DBG("file not found");
		return false;
	}
}
void NoteController::LoadGame()
{
	//노트 맵이 있는지 체킹 
	if(CheckingNoteMap())
	{
		//실행	StartGame();
	}
	else
	{
		//노트 생성 
		GenerateNote();
	}
}

void NoteController::GenerateNote()
{
	bgm.SelectSong();
	startTimer(1);	//1sec = 1000ms
	//음악 파일의 시간을 불러옴
	//타이머 시작
	// * 키 포커스를 준다.
	// * 누를떄마다 노트가 떨어지는걸 보여준다.
	//j * 저장한다.
	//중간저장? 나중에추가 
	//맵을 저장할껀지 선택
	//종료 
}

void NoteController::timerCallback()
{
	static int cnt = 0;
	if(GetSec()+5 > bgm.GetSongLength(bgm.duration)*1000) //노래 길이 + 5sec  
	{
		DBG("노래 끝났습니다");
		stopTimer();
		sec = 0;
	}
	else
	{
		if(notes.size() < 6000){
			addNote();				
			DBG(cnt++);
		}
	}
}

