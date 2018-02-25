#include "KeyControl.h"

void PressKey(){
	char key = cin.get();
	switch(key){
		case 'd':
			cout << "d pressed\n";
			break;
		case 'f':
			cout << "f pressed\n";
			break;
		case 'j':
			cout << "j pressed\n";
			break;
		case 'k':
			cout << "k pressed\n";
			break;
		defalut: break;
	}
	cin.clear();
}
