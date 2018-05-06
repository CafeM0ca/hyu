/*
  ==============================================================================
    NoteFrameComponent.h
    Created: 22 Feb 2018 8:07:50pm
    Author:  moca
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

typedef struct {
		float single;
		// something other data.. ex multi
}MapData; 


class Map  : public Component
{
public:
    Map();
    ~Map();

    void paint (Graphics&) override;
    void resized() override;
	void InitDefaultMap(int width,int height);

	MapData map_info;
	void ChangeMap(/*MapMode mode = MapMode::single*/);
	void MapDataUpdate();
	Rectangle<float> GetBaseRectangle();
private:
	Rectangle<float> vertical1;
	Rectangle<float> vertical2;
	Rectangle<float> vertical3;
	Rectangle<float> vertical4;
	Rectangle<float> key_frame1;
	Rectangle<float> key_frame2;
	Rectangle<float> key_frame3;
	Rectangle<float> key_frame4;
	Rectangle<float> urteil;
	enum class MapMode{
		single
		// something other mode,, ex multi
	};
	MapMode mode;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Map)
};

