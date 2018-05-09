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
	key_status = {false,false,false,false};
	setWantsKeyboardFocus(true);
	DBG("key");
}
KeyComponent::~KeyComponent()
{
}

bool KeyComponent::keyPressed(const KeyPress& key)
{

	if(key == dkey){
		if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("dkey base 3key");	
			key_status.d = key_status.f = key_status.j = key_status.k = true;
		} else if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //d f j
			DBG("dkey base f j key");	
			key_status.d = key_status.f = key_status.j = true;
		} else if(fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //d f k
			DBG("dkey base f k key");	
			key_status.d = key_status.f = key_status.k = true;
		} else if(jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //d j k
			DBG("dkey base j k key");	
			key_status.d = key_status.j = key_status.k = true;
		} else if(fkey.isCurrentlyDown()){ //d f
			DBG("dkey base f key");	
			key_status.d = key_status.f = true;
		} else if(jkey.isCurrentlyDown()){ //d j 
			DBG("dkey base j key");	
			key_status.d = key_status.j = true;
		} else if(kkey.isCurrentlyDown()){ //d k 
			DBG("dkey base k key");	
			key_status.d = key_status.k = true;
		} else{ // d
			DBG("only dkey");	
			key_status.d = true;
		}
	} else if(key == fkey){
		if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("fkey base 3key");	
			key_status.d = key_status.f = key_status.j = key_status.k = true;
		} else if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //f d j
			DBG("fkey base d j key");	
			key_status.d = key_status.f = key_status.j = true;
		} else if(dkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //f d k
			DBG("fkey base d k key");	
			key_status.d = key_status.f = key_status.k = true;
		} else if(jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //f j k
			DBG("fkey base j k key");	
			key_status.j = key_status.f = key_status.k = true;
		} else if(dkey.isCurrentlyDown()){ //f d
			DBG("fkey base d key");	
			key_status.f = key_status.d = true;
		} else if(jkey.isCurrentlyDown()){ //f j 
			DBG("fkey base j key");	
			key_status.f = key_status.j = true;
		} else if(kkey.isCurrentlyDown()){ //f k 
			DBG("fkey base k key");	
			key_status.f = key_status.k = true;
		} else{ // f
			DBG("only fkey");	
			key_status.f = true;
		}
	} else if(key == jkey){
		if(dkey.isCurrentlyDown() && fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("jkey base 3key");	
			key_status.d = key_status.f = key_status.j = key_status.k = true;
		} else if(dkey.isCurrentlyDown() && fkey.isCurrentlyDown()){ //j d f
			DBG("jkey base d j key");	
			key_status.d = key_status.f = key_status.j = true;
		} else if(dkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //j d k
			DBG("jkey base d k key");	
			key_status.d = key_status.k = key_status.j = true;
		} else if(fkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //j f k
			DBG("jkey base j k key");	
			key_status.f = key_status.k = key_status.j = true;
		} else if(dkey.isCurrentlyDown()){ //j d
			DBG("jkey base d key");	
			key_status.d = key_status.j = true;
		} else if(fkey.isCurrentlyDown()){ //j f 
			DBG("jkey base j key");	
			key_status.f = key_status.j = true;
		} else if(kkey.isCurrentlyDown()){ //j k 
			DBG("jkey base k key");	
			key_status.k = key_status.j = true;
		} else{ // f
			DBG("only jkey");	
			key_status.j = true;
		}
	} else if(key == kkey){
		if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown() && kkey.isCurrentlyDown()){ //3키 
			DBG("kkey base 3key");	
			key_status.d = key_status.f = key_status.j = key_status.k = true;
		} else if(dkey.isCurrentlyDown() && fkey.isCurrentlyDown()){ //k d f
			DBG("kkey base d j key");	
			key_status.d = key_status.f =  key_status.k = true;
		} else if(dkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //k d j
			DBG("kkey base d k key");	
			key_status.j = key_status.d =  key_status.k = true;
		} else if(fkey.isCurrentlyDown() && jkey.isCurrentlyDown()){ //k f j
			DBG("kkey base j k key");	
			key_status.j = key_status.f =  key_status.k = true;
		} else if(dkey.isCurrentlyDown()){ //j d
			DBG("kkey base d key");	
			key_status.j = key_status.d = true;
		} else if(fkey.isCurrentlyDown()){ //j f 
			DBG("kkey base j key");	
			key_status.j = key_status.f = true;
		} else if(jkey.isCurrentlyDown()){ //k j 
			DBG("kkey base k key");	
			key_status.j = key_status.k = true;
		} else{ // f
			key_status.k = true;
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
	// 임시
	DBG("paint");
	g.setColour(Colours::pink);
	/*
	if(d == true){
		d = false;
		g.drawRect(getWidth()/12*4,getHeight()/12*10.5,getWidth()/12,getHeight()/30);
	} else if(f == true){
		f = false;
		g.drawRect(getWidth()/12*4,getHeight()/12*10.5,getWidth()/12,getHeight()/30);
	} else if(j == true){
		j = false;
		g.drawRect(getWidth()/12*4,getHeight()/12*10.5,getWidth()/12,getHeight()/30);
	} else if(k == true){
		k = false;
		g.drawRect(getWidth()/12*4,getHeight()/12*10.5,getWidth()/12,getHeight()/30);
	}
	*/
}
int KeyComponent::GetKeyStatus()
{
	KeyStatus temp = key_status;	
	key_status.d = false ;
	key_status.f = false ;
	key_status.j = false ;
	key_status.k = false ;
	
if(temp.d == true) return 1;
	else if(temp.f == true) return 2;
	else if(temp.j == true) return 3;
	else if(temp.k == true) return 4;
	else return 0;
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
