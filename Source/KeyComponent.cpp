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
			DBG("dkey base 3key");	
		} else if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //d f j
			DBG("dkey base f j key");	
		} else if(fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //d f k
			DBG("dkey base f k key");	
		} else if(jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //d j k
			DBG("dkey base j k key");	
		} else if(fkey.isCurrentlyDown()){ //d f
			DBG("dkey base f key");	
		} else if(jkey.isCurrentlyDown()){ //d j 
			DBG("dkey base j key");	
		} else if(kkey.isCurrentlyDown()){ //d k 
			DBG("dkey base k key");	
		} else{ // d
			DBG("only dkey");	
		}
	} else if(key == fkey){
		if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("fkey base 3key");	
		} else if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //f d j
			DBG("fkey base d j key");	
		} else if(dkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //f d k
			DBG("fkey base d k key");	
		} else if(jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //f j k
			DBG("fkey base j k key");	
		} else if(dkey.isCurrentlyDown()){ //f d
			DBG("fkey base d key");	
		} else if(jkey.isCurrentlyDown()){ //f j 
			DBG("fkey base j key");	
		} else if(kkey.isCurrentlyDown()){ //f k 
			DBG("fkey base k key");	
		} else{ // f
			DBG("only fkey");	
		}
	} else if(key == jkey){
		if(dkey.isCurrentlyDown() && fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("jkey base 3key");	
		} else if(dkey.isCurrentlyDown() && fkey.isCurrentlyDown()){ //j d f
			DBG("jkey base d j key");	
		} else if(dkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //j d k
			DBG("jkey base d k key");	
		} else if(fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //j f k
			DBG("jkey base j k key");	
		} else if(dkey.isCurrentlyDown()){ //j d
			DBG("jkey base d key");	
		} else if(fkey.isCurrentlyDown()){ //j f 
			DBG("jkey base j key");	
		} else if(kkey.isCurrentlyDown()){ //j k 
			DBG("jkey base k key");	
		} else{ // f
			DBG("only jkey");	
		}
	} else if(key == kkey){
		if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("kkey base 3key");	
		} else if(dkey.isCurrentlyDown() && fkey.isCurrentlyDown()){ //k d f
			DBG("kkey base d j key");	
		} else if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //k d j
			DBG("kkey base d k key");	
		} else if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //k f j
			DBG("kkey base j k key");	
		} else if(dkey.isCurrentlyDown()){ //j d
			DBG("kkey base d key");	
		} else if(fkey.isCurrentlyDown()){ //j f 
			DBG("kkey base j key");	
		} else if(jkey.isCurrentlyDown()){ //j j 
			DBG("kkey base k key");	
		} else{ // f
			DBG("only kkey");	
		}
	} else if(key == qkey){
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

void KeyComponent::paint(Graphics& g)
{

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
