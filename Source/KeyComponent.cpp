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
#include "KeyComponent.h"

KeyComponent::KeyComponent()
{

}
KeyComponent::~KeyComponent()
{

}

bool KeyComponent::keyPressed(const KeyPress& key,Component *c)
{
	DBG("KeyPressed");
	/*
	pressed_check = true;
	DBG("when..");
	switch(key.getTextCharacter()){
		case 'd':
			dkey = true;
			DBG("d pressed");
			break;
		case 'f':
			fkey = true;
			DBG("f pressed");
			break;
		case 'j':
			DBG("j pressed");
			jkey = true;
			//
			break;
		case 'k':
			kkey = true;
			DBG("k pressed");
			break;
	}
	*/
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
}

bool KeyComponent::keyStateChanged(bool isKeyDown,Component *c)
{
	DBG("setWantsKeyboardFocus");
	/*
	if(isKeyDown == true) //키가 눌리는 경우
	{
	DBG("he");	
		if(dkey == true)
		{
			dkey = false;
		}
		else if(fkey == true)
		{

			fkey = false;
		}
		else if(jkey == true)
		{

			jkey = false;
		}
		else if(kkey == true)
		{
			kkey = false;

		}
		return true;
	}
	else*/ return false;
}

bool KeyComponent::isPressed()
{
	/*
	if(pressed_check == true)
	{
		pressed_check = false;
		return true;
	}
	else */return false;
}

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
