#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <bitset>
#include <ctime>
#include <Windows.h>

using namespace std;

void openStartFile(string &txt,string fileName){
	fstream plik;
	plik.open(fileName);
	if (plik.good() == false){																	//Sprawdzenie czy odczytanie pliku siê powiod³o
		cout << "Error!\n Can't open file\n";
		Sleep(3000);																			//Usypiamy program na 3 s
		exit(0);																				//jesli nie, wychodze z programu
	}
	else{																						//jesli plik istnieje	
		while (!plik.eof()){																	//to do czasu az funkcja dojdzie do ostatniej linii
			getline(plik, txt);																	//otwieram pobrana linie z pliku i zapisuje do zmiennej (w tym przypadku "txt")
		}
	}
	plik.close();
}

void saveBinaryFile(string In, string &Out){

	string tmp;
	fstream plik;
	plik.open("startBinary.txt", ios::out);
	for (int i = 0; i < In.size(); ++i)
	{
		plik << bitset<8>(In.c_str()[i]);
		bitset<8> b(In.c_str()[i]);
		Out += b.to_string();
	}

	plik.close();
}

void saveDemageText(string In){
	fstream plik;
	plik.open("demageBinaryText.txt", ios::out);
	plik << In;
	plik.close();
}

void menu(int *fchoice, int *bchoice, string &openTxtChoice){
	cout << "Prosze podac nazwe pliku do otwarcia: ";
	cin >> openTxtChoice;
	cout << "Prosze podac dla jakiego bledu przeslania wiadomosci, program ma zadzialac.(od 0% do 15%) " << endl;
	cout << "Wybor: ";
	cin >> *fchoice;
	while (cin.good() == false || (*fchoice <0 || *fchoice >15)){
		cout << "Podana wartosc jest niepoprawna prosze podac poprawna wartosc.\nWybor:";
		cin.clear();
		cin.sync();
		cin >> *fchoice;
	}

	cout << "Prosze podac dla ilu bitow program ma przeprowadzic CRC (max 64)" << endl;
	cout << "Wybor: ";
	cin >> *bchoice;
	while (cin.good() == false || (*bchoice <1 || *bchoice >64)){
		cout << "Podana wartosc jest niepoprawna prosze podac poprawna wartosc.\nWybor:";
		cin.clear();
		cin.sync();
		cin >> *bchoice;
	}
}

void demageText(int menuChoice, string In, string &Out){
	Out = In;
	int operations;
	operations = In.size()*menuChoice / 100;
	int tempNumber = 0;								//Zmienna pomocnicza do zapisania na chwile wylosowanej liczby
	int numbers[35] = { 0 };						//tablica przechowuj¹ wylosowane liczby
	int i = 0;										//zmienna przechowuj¹ca iloœæ liczb wylosowanych
	int tmp = 0;									//Zmienna pomocnicza do zapisania na chwile numeru bitu, który ma byæ zmieniony 
	srand(time(NULL));								//Zeruje zarodek

	
	while (i < operations){							
		tempNumber = rand() % 200;								//Losuje liczbe
		if (i == 0)												//jesli licznik równy 0, zapisuje liczbe
			numbers[i] = tempNumber;
		else{													//jesli nie
			for (int j = 0; j < i; j++){						//sprawdzam czy juz znajduje sie w tablicy wylosowanych liczb
				while(numbers[j] == tempNumber){				//jesli sie znajduje, losuje kolejna liczbe
					tempNumber = rand() % 200;
					j = 0;										//a for'a zeruje
				}
			}
			numbers[i] = tempNumber;							//przypisuje wylosowna liczbe, do tablicy liczb wylosowanych
		}
		i++;													//implementuje licznik
	}
	
	for (int j = 0; j < i; j++){								//petla do uszkadzania tekstu
		tmp = numbers[j];										//przypisanie do zmiennej pomocniczej nr bitu, który ma zostac zmieniony
		if (Out[tmp] == '1')					
			Out[tmp] = '0';									
		else if (Out[tmp] == '0')
			Out[tmp] = '1';
	}
}

void bitParzystosci(string In, string Out){
	int suma1 = 0;
	int suma2 = 0;
	for (int i = 0; i < In.size(); i++){
		if (In[i] == '1')
			suma1 += 1;
		if (Out[i] == '1')
			suma2 += 1;
	}

	cout << "Bit parzystosci: ";
	if (suma1 == suma2)
		cout << "Wiadomosc wyslana poprawnie" << endl;
	else
		cout << "Wiadomosc zostala uszkodzona podczas wysylania" << endl;
}

void controlNumber(string In, string Out){
	int weightOfNumber[200] = { 0 };				//zmienna przechowuj¹ca wagi odpowiednich bitow
	string tmp;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 200; i++){					//ustalanie wag, dla poszczegolnych bitow
		if (i == 0)
			weightOfNumber[i] = 200;
		else if (i == 199)
			weightOfNumber[i] = 202;
		else{
			weightOfNumber[i] = i;
		}
	}

	for (int i = 0; i < In.size(); i++){			//sumowanie
		sum1 += ((int)In[i] - 48)*weightOfNumber[i];
		sum2 += ((int)Out[i] - 48)*weightOfNumber[i];
	}

	cout << "Cyfra kontrolna: ";					//sprawdzenie, czy suma wiadomosci wyslanej mod 10 jest rowna sumie mod 10 wiadomosci odebranej
	if (sum1 % 10 == sum2 % 10)
		cout << "Wiadomosc wyslana poprawnie" << endl;
	else
		cout << "Wiadomosc zostala uszkodzona podczas wysylania" << endl;
}

void XOR(int bChoice, string dzielnik, string In, string &result){
	int help = 1;
	int i=0;
	bool done = false;
	string tmpIn;
	for (int j = 0; j < In.size() + bChoice; j++){
		if (j < In.size())
			tmpIn += In[j];
		else
			tmpIn += '0';
	}
	while (!done){
		i = 0;
		help = 1;
		while (tmpIn[i] == '0'){
			i++;
			help++;
		}
		for (int j = 0; j < dzielnik.size(); j++){
			if ((int)dzielnik[j] % 48 == (int)tmpIn[i]%48)
				tmpIn[i] = '0';
			else
				tmpIn[i] = '1';
			i++;
		}
		if (help+dzielnik.size()>=tmpIn.size())
			done = true;
	}

	for (int j = bChoice; j > 0; j--){
		result += tmpIn[tmpIn.size() - j];
	}
}

void readXOR(string dzielnik, string In, string resultXOR, string &result){
	int help = 1;
	int i = 0;
	bool done = false;
	string tmpIn = In + resultXOR;

	while (!done){
		i = 0;
		help = 1;
		while (tmpIn[i] == '0'){
			i++;
			help++;
		}
		for (int j = 0; j < dzielnik.size(); j++){
			if ((int)dzielnik[j] % 48 == (int)tmpIn[i] % 48)
				tmpIn[i] = '0';
			else
				tmpIn[i] = '1';
			i++;
		}
		if (help + dzielnik.size() >= tmpIn.size())
			done = true;
	}

	cout << "CRC: ";
	for (int j = 0; j < tmpIn.size(); j++){
		if ((int)tmpIn[j]%48 != 0){
			cout << "Wiadomosc zostala uszkodzona podczas wyslania" << endl;
			break;
		}
		else if (j == tmpIn.size()-1 && (int)tmpIn[j]%48==0)
			cout << "Wiadomosc wyslana poprawnie" << endl;
	}

}


void CRC(int bChoice,string start, string demage){
	char tempDzielnikCRC[65] = { 0 };
	string dzielnik;
	string outCRC1;
	string checkCRC;
	srand(time(NULL));
	for(int i = 0; i < bChoice+1; i++){
		if (i == 0 || i == bChoice)								//Warunek konieczny aby na poczatku i koncu dzielnika by³a 1
			tempDzielnikCRC[i] = '1';											
		else{													//Warunek tworzenia kolejnych liczb crc
			if (rand() % 4 >1)									
				tempDzielnikCRC[i] = '1';
			else
				tempDzielnikCRC[i] = '0';
		}
		dzielnik += tempDzielnikCRC[i];
	}
	XOR(bChoice, dzielnik, start, outCRC1);
	readXOR(dzielnik, demage, outCRC1, checkCRC);
}





