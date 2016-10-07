/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
data ostatniej aktualizacji 07.10 2016*/

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
	int bitChoice = 0;				//Zmienna pomocnicza do wyboru ilosci bitow CRC
	


	openStartFile(startText);							//Funkcja otwieraj�ca plik tekstowy i przypisuj�ca go do zmiennej "startText"
	saveBinaryFile(startText,startBinary);				//Funkcja zmieniaj�ca tekst starttowy na kod binarny i zapisuj�ca go do pliku i przypisuj�ca go do zmiennej "startBinary"
	menu(&menuChoice, &bitChoice);						//menu programu
	demageText(menuChoice, startBinary, demagedText);	//funkcja uszkadzaj�ca plik startowy
	bitParzystosci(startBinary, demagedText);			//funkcja sprawdzaj�ca bit parzystosci
	sumaMod10(startBinary, demagedText);				//funkcja sprawdzajaca sume modulo 10
	CRC(bitChoice);

	system("pause");
	return 0;
}