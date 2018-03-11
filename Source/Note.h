/*
  ==============================================================================
    Note.h
    Created: 22 Feb 2018 10:36:30pm
    Author:  moca
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//==============================================================================
/*
*/
class Note    : public Component  
{
public:
    Note();
    ~Note();

    void paint (Graphics&) override;
    void resized() override;
	inline float GetX1() const { return x1; }
	inline float GetX2() const { return x2; }
	inline float GetY1() const { return y1; }
	inline float GetY2() const { return y2; }
	inline float GetSpeed() const { return speed; }
	void DownNote();
private:
	int cnt;
	float x1,x2,y1,y2;
	float speed;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};

class NoteThread : public Note, public Thread
{
public:
	NoteThread();
	~NoteThread();
	void run() override;

private:
	Note note; //동적할당해서 큐에 때려박아 
	int priority; //우선순위
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteThread)
};


class NoteController : public NoteThread, private Timer
{
public:
	NoteController();
	~NoteController();

private:
	ThreadPool pool{4}; //
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteController)
};
};
