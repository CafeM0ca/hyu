/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/ 


class KeyComponent : public KeyListener
{
public:
	~KeyComponent();
	bool keyPressed(const KeyPress& key,Component *c) override;
	bool keyStateChanged(bool isKeyDown,Component *c) override;
	bool isPressed(); 
	//bool dkey=false,fkey=false,jkey=false,kkey=false;
private:
	KeyPress dkey,fkey,jkey,kkey; 
};

//[EndFile] You can add extra defines here...
//[/EndFile]
