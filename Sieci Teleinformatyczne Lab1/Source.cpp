/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
dzie� ostatniej aktualizacji 05.10 2016*/

#pragma once
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
	string demagedText;				//Zmienna przechowuj�ca tekst startowy z b��dem
	int menuChoice = 0;				//Zmienna pomocnicza do wyboru opcji b��du, w menu programu
	


	openStartFile(startText);							//Funkcja otwieraj�ca plik tekstowy i przypisuj�ca go do zmiennej "startText"
	saveBinaryFile(startText,startBinary);				//Funkcja zmieniaj�ca tekst starttowy na kod binarny i zapisuj�ca go do pliku i przypisuj�ca go do zmiennej "startBinary"
	menu(&menuChoice);									//menu programu
	demageText(menuChoice, startBinary, demagedText);	//funkcja uszkadzaj�ca plik startowy


	cin.get();
	cin.get();
	return 0;
}