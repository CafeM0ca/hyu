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

private:
	static const char* bono_png;
	static const int bono_pngSize;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Note)
};
