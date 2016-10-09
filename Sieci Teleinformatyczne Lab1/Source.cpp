/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1
data ostatniej aktualizacji 09.10 2016*/

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
	string fileName;				//Zmienna nazwy pliku do odczytania
	


	menu(&menuChoice, &bitChoice, fileName);			//menu programu
	openStartFile(startText,fileName);					//Funkcja otwieraj�ca plik tekstowy i przypisuj�ca go do zmiennej "startText" 
	saveBinaryFile(startText, startBinary);				//Funkcja zmieniaj�ca tekst startowy na kod binarny i zapisuj�ca go do pliku i przypisuj�ca go do zmiennej "startBinary"
	demageText(menuChoice, startBinary, demagedText);	//funkcja uszkadzaj�ca plik startowy
	saveDemageText(demagedText);						//funkcja zapisuj�ca uszkodzony wiadomoosc do pliku txt
	bitParzystosci(startBinary, demagedText);			//funkcja sprawdzaj�ca wiadomosc za pomoca bit parzystosci
	controlNumber(startBinary, demagedText);			//funkcja sprawdzaj�ca wiadomosc za pomoca cyfry kontrolnej
	CRC(bitChoice,startBinary,demagedText);				//funkcja sprawdzaj�ca wiadomosc za pomoca metody CRC

	system("pause");
	return 0;
}