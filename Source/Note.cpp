/*
  ==============================================================================
    Note.cpp
    Created: 22 Feb 2018 10:36:30pm
    Author:  moca
  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Note.h"

//==============================================================================
Note::Note() :x1(0),x2(0),y1(-20),y2(0),speed(10)
{
	DBG("Note Ctor");
	cnt=0;
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
//	cachedImage_bono = ImageCache::getFromMemoey(bono_png,bono_pngSize);
//	setSize(110,100);
	colour = Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f);
}

Note::~Note()
{ } 

void Note::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.
       You should replace everything in this method with your own
       drawing code..
    */
	//g.drawRect(getWidth()/12,y1,getWidth(),y2);
	//g.fillRect(getWidth()/12*3,y1,getWidth(),y2);
	
	// 무지개 노트
	//g.setColour (Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f));
	g.setColour(colour);
	g.drawLine(0,y1,getWidth(),y1,20);
	DownNote();
		//g.setColour (Colours::white);
		//g.drawLine(0,y1-0.5,getWidth(),y2-0.5,25);
//g.drawImage(cachedImage_bono,getWidth()/12*4,getHeight()/12*11,getWidth()/12*4,getHeight()),0,0,cachedImage_bono.getWidth(),cachedImage_bono.getHeight());
//
}

void Note::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

//void Note::repaint(int x,int y,int width,int height) override

void Note::DownNote(){
	if(y1 < getHeight()/12*12)
	{
		/* 노트 배속 공식
		 */
		y1 = y2;
		y2 += 20;
	}
	else
	{
		y1 = -20;
		y2 = 0;
	//	colour = Colour((juce::uint32) Random::getSystemRandom().nextInt()).withAlpha(0.5f).withBrightness(0.7f);

	}
	cnt++;
	repaint();
}

//NoteThread
NoteThread::NoteThread() :Thread("Note Thread")
{
	DBG("NoteThread");
	priority = 1;	
	startThread(priority++);
}

NoteThread::~NoteThread()
{
	stopThread(100);
}

void NoteThread::run() 
{
	while(!threadShouldExit()) //쓰레드가 끝나지 않았으면
	{
		wait(10); //10ms cpu쉼. 원할하게 작동시키기위해 
		
		const MessageManagerLock mml(Thread::getCurrentThread());
		if(!mml.lockWasGained()) return;

		DownNote();
	}
}

//NoteThreadPoolJob
NoteThreadPoolJob::NoteThreadPoolJob() :ThreadPoolJob("MultiThread job")
{
	DBG("NoteThreadPoolJob ctor");
}

NoteThreadPoolJob::~NoteThreadPoolJob()
{

}











//NoteController
NoteController::NoteController()
{
	setOpaque(true);
	DBG("NoteController");
	bgm.SelectSong(); 
	bgm.changeState(bgm.Stopping);
	DBG("Stopped song");
	LoadGame();
}

NoteController::~NoteController()
{
	pool.removeAllJobs(true,2000);
}

void NoteController::paint(Graphics& g)
{
	//범위 지정해야함
	g.setColour(Colours::white);
}

void NoteController::resized()
{

}

void NoteController::resetNotes()
{
	pool.removeAllJobs(true,4000);
	notes.clear();
}

void NoteController::setUsingPool(bool usepool)
{
	isUsingPool = true;
	resetNotes();
}

void NoteController::addNote()
{
	//큐에 노트를 넣음
	if(isUsingPool)
	{
		NoteThreadPoolJob *newNote = new NoteThreadPoolJob();
		notes.add(newNote);
		addAndMakeVisible(newNote);
		pool.addJob(newNote,false);
		DBG("isUsingPool");
	}
	else
	{
		NoteThread *newNote = new NoteThread();
		notes.add(newNote);
		addAndMakeVisible(newNote);
		DBG("not isUsingPool");
	}
}

void NoteController::removeNote()
{
	//큐를 비움
}

bool NoteController::CheckingNoteMap()
{
	//파일의 해당하는 맵이 있는지 찾는다.
}

void NoteController::LoadGame()
{
	DBG("Start Song");
	bgm.changeState(bgm.Stopped);
	bgm.changeState(bgm.Playing);
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
	//음악 파일의 시간을 불러옴
	//타이머 시작
	//입력받음
	//타이머 종료
	
	//중간저장? 나중에추가 
	//맵을 저장할껀지 선택
	//종료 
}
