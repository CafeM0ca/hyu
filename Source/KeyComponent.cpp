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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "KeyComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs] 
//==============================================================================
KeyComponent::KeyComponent () :press_check(unpressed)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]
	setWantsKeyboardFocus(true);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeyComponent::~KeyComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
	switch(press_check)
	{
		case d_pressed:
				g.setColour(Colours::pink);
				g.fillRect(getWidth()/12*4+3,getHeight()/12*10.69,
							getWidth()/12-6,getHeight()/12*0.32);	
				press_check = unpressed;
				break;
		case f_pressed:
				g.setColour(Colours::pink);
				g.fillRect(getWidth()/12*5+3,getHeight()/12*10.69,
							getWidth()/12-6,getHeight()/12*0.32);	
				press_check = unpressed;
				break;
		case j_pressed:
				g.setColour(Colours::pink);
				g.fillRect(getWidth()/12*6+3,getHeight()/12*10.69,
							getWidth()/12-6,getHeight()/12*0.32);	
				press_check = unpressed;
				break;
		case k_pressed:
				g.setColour(Colours::pink);
				g.fillRect(getWidth()/12*7+3,getHeight()/12*10.69,
							getWidth()/12-6,getHeight()/12*0.32);	
				press_check = unpressed;
				break;

	}
}

//[/UserPaint]

void KeyComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

bool KeyComponent::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
	switch(key.getTextCharacter()){
		case 'd':
			DBG("d pressed");
			press_check = d_pressed;
			break;
		case 'f':
			DBG("f pressed");
			press_check = f_pressed;
			break;
		case 'j':
			DBG("j pressed");
			press_check = j_pressed;
			//
			break;
		case 'k':
			DBG("k pressed");
			press_check = k_pressed;
			break;
	}
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
