/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
dzieñ ostatniej aktualizacji 05.10 2016*/

#pragma once
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
	string demagedText;				//Zmienna przechowuj¹ca tekst startowy z b³êdem
	int menuChoice = 0;				//Zmienna pomocnicza do wyboru opcji b³êdu, w menu programu
	int bitChoice = 0;				//Zmienna pomocnicza do wyboru ilosci bitow CRC
	


	openStartFile(startText);							//Funkcja otwieraj¹ca plik tekstowy i przypisuj¹ca go do zmiennej "startText"
	saveBinaryFile(startText,startBinary);				//Funkcja zmieniaj¹ca tekst starttowy na kod binarny i zapisuj¹ca go do pliku i przypisuj¹ca go do zmiennej "startBinary"
	menu(&menuChoice, &bitChoice);						//menu programu
	demageText(menuChoice, startBinary, demagedText);	//funkcja uszkadzaj¹ca plik startowy
	bitParzystosci(startBinary, demagedText);			//funkcja sprawdzaj¹ca bit parzystosci
	CRC(bitChoice);

	system("pause");
	return 0;
}