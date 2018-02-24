#pragma once //한번만 컴파일되도록

#include <iostream>
using namespace std;

class KeyControl
{
public:
	KeyControl(){};
	~KeyControl(){};

	void PressKey();
private:
	//char key;
};

void KeyControl::PressKey(){
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
