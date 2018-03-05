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
	//static const char* bono_png;
	//tatic const int bono_pngSize;
	void DoubleBufferfing() const;
	int cnt;
	float x1,x2,y1,y2;
	float speed;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};
