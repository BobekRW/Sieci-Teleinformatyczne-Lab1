/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
dzieñ ostatniej aktualizacji 05.10 2016*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include "function.h"

using namespace std;

int main(){
	string startText;				//Zmienna pomocnicza przechowuj¹ca wczytany na pocz¹tku tekst
	string startBinary;				//Zmienna przechowuj¹ca tekst startowy zapisany za pomoc¹ kodu binarnego


	openFile(startText);
	saveFile(startText);


	
	cin.get();
	return 0;
}