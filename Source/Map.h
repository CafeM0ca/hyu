#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Map  : public Component
{
public:
    Map();
    ~Map();

    void paint (Graphics&) override;
    void resized() override;

private:
	Line<float> vertical1;
	Line<float> vertical2;
	Line<float> vertical3;
	Line<float> vertical4;
	Line<float> vertical5;
	Rectangle<float> key_frame1;
	Rectangle<float> key_frame2;
	Rectangle<float> key_frame3;
	Rectangle<float> key_frame4;
	Rectangle<float> urteil;
	const KeyPress dkey = KeyPress('d');
	const KeyPress fkey = KeyPress('f');
	const KeyPress jkey = KeyPress('j');
	const KeyPress kkey = KeyPress('k');
	
   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Map)
};

