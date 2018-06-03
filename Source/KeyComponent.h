/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once
<<<<<<< HEAD

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyComponent  : public Component
{
public:
    //==============================================================================
    KeyComponent ();
    ~KeyComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    bool keyPressed (const KeyPress& key) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyComponent)
=======
#include "../JuceLibraryCode/JuceHeader.h"
	
class KeyComponent : public Component
{
public:
	KeyComponent();
	~KeyComponent();
	bool keyPressed(const KeyPress& key) override;
	void paint(Graphics&) override;
	int GetKeyStatus();
	
	typedef struct {
		bool d,f,j,k;
	}KeyStatus; 
	KeyStatus key_status;
    
	KeyPress dkey,fkey,jkey,kkey;
private:
	KeyPress tabkey,qkey,wkey; 
JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyComponent)
>>>>>>> a29efea4015d8bbd60648e4759f193521b1d06dd
};

//[EndFile] You can add extra defines here...
//[/EndFile]
