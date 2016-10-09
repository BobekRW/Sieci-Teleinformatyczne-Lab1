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
	string startText;				//Zmienna pomocnicza przechowuj¹ca wczytany na pocz¹tku tekst
	string startBinary;				//Zmienna przechowuj¹ca tekst startowy zapisany za pomoc¹ kodu binarnego
	string demagedText;				//Zmienna przechowuj¹ca tekst startowy z b³êdem
	int menuChoice = 0;				//Zmienna pomocnicza do wyboru opcji b³êdu, w menu programu
	int bitChoice = 0;				//Zmienna pomocnicza do wyboru ilosci bitow CRC
	string fileName;				//Zmienna nazwy pliku do odczytania
	


	menu(&menuChoice, &bitChoice, fileName);			//menu programu
	openStartFile(startText,fileName);					//Funkcja otwieraj¹ca plik tekstowy i przypisuj¹ca go do zmiennej "startText" 
	saveBinaryFile(startText, startBinary);				//Funkcja zmieniaj¹ca tekst startowy na kod binarny i zapisuj¹ca go do pliku i przypisuj¹ca go do zmiennej "startBinary"
	demageText(menuChoice, startBinary, demagedText);	//funkcja uszkadzaj¹ca plik startowy
	saveDemageText(demagedText);						//funkcja zapisuj¹ca uszkodzony wiadomoosc do pliku txt
	bitParzystosci(startBinary, demagedText);			//funkcja sprawdzaj¹ca wiadomosc za pomoca bit parzystosci
	controlNumber(startBinary, demagedText);			//funkcja sprawdzaj¹ca wiadomosc za pomoca cyfry kontrolnej
	CRC(bitChoice,startBinary,demagedText);				//funkcja sprawdzaj¹ca wiadomosc za pomoca metody CRC

	system("pause");
	return 0;
}