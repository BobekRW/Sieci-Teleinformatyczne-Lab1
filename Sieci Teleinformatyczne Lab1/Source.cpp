/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
dzie� ostatniej aktualizacji 05.10 2016*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include "function.h"

using namespace std;

int main(){
	string startText;				//Zmienna pomocnicza przechowuj�ca wczytany na pocz�tku tekst
	string startBinary;				//Zmienna przechowuj�ca tekst startowy zapisany za pomoc� kodu binarnego


	openFile(startText);
	saveFile(startText);


	
	cin.get();
	return 0;
}