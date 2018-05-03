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

KeyComponent::KeyComponent() : dkey('d'),fkey('f'),jkey('j'),kkey('k'),qkey('q'),wkey('w'),tabkey(KeyPress::tabKey)

{
	setWantsKeyboardFocus(true);
}
KeyComponent::~KeyComponent()
{
}

bool KeyComponent::keyPressed(const KeyPress& key)
{
	if(key == dkey){
		if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
		
		} else if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //d f j

		} else if(fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //d f k

		} else if(jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //d j k

		} else if(fkey.isCurrentlyDown()){ //d f

		} else if(jkey.isCurrentlyDown()){ //d j 

		} else if(kkey.isCurrentlyDown()){ //d k 

		} else{ // d

		}
	} if(key == fkey){
		if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
		
		} else if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //f d j

		} else if(dkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //f d k

		} else if(jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //f j k

		} else if(dkey.isCurrentlyDown()){ //f f

		} else if(jkey.isCurrentlyDown()){ //f j 

		} else if(kkey.isCurrentlyDown()){ //f k 

		} else{ // f

		}
	} 
	else if(key == qkey){
		DBG("qkey press");
	} else if(key == wkey){
		DBG("wkey press");
	} else if(key == tabkey){
		DBG("tabkey press");
	} 
	else
		return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.

	return true;
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
