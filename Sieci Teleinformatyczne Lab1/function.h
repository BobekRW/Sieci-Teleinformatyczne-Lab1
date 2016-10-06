#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <bitset>
#include <ctime>

using namespace std;

void openStartFile(string &txt){
	fstream plik;
	plik.open("start.txt");
	if (plik.good() == false){																	//Sprawdzenie czy odczytanie pliku siê powiod³o
		cout << "Error!\n Can't open file\n";
		exit(0);
	}
	else{
		while (!plik.eof()){
			getline(plik, txt);
		}
	}
	plik.close();
}

void saveBinaryFile(string In, string &Out){

	string tmp;
	fstream plik;
	plik.open("startBinary.txt", ios::out);
	for (std::size_t i = 0; i < In.size(); ++i)
	{
		plik << bitset<8>(In.c_str()[i]);
		bitset<8> b(In.c_str()[i]);
		Out += b.to_string();
	}



	plik.close();
}

void bitParzystosci(string *in, string *out){
	int suma = 0;

}

void menu(int *choice){
	cout << "Prosze podac dla jakiego bledu przeslania wiadomosci, program ma zadzialac.(od 1% do 15%) " << endl;
	cout << "Wybor: ";
	cin >> *choice;
	while (cin.good() == false || (*choice <1 || *choice >15)){
		cout << "Podana wartosc jest niepoprawna prosze podac poprawna wartosc.\nWybor:";
		cin.clear();
		cin.sync();
		cin >> *choice;
	}
}

void demageText(int menuChoice, string In, string &Out){
	int operations;
	operations = In.size()*menuChoice / 100;
	int tempNumber = 0;								//Zmienna pomocnicza do zapisania na chwile wylosowanej liczby
	int numbers[35] = { 0 };						//tablica przechowuj¹ wylosowane liczby
	int i = 0;										//zmienna przechowuj¹ca iloœæ liczb wylosowanych
	int tmp = 0;									//Zmienna pomocnicza do zapisania na chwile numeru bitu, który ma byæ zmieniony 
	srand(time(NULL));								//Zeruje zarodek
	
	while (i < operations){							
		tempNumber = rand() % 200;
		if (i == 0)
			numbers[i] = tempNumber;
		else{
			for (int j = 0; j < i; j++){
				while(numbers[j] == tempNumber){
					tempNumber = rand() % 200;
					j = 0;
				}
			}
			numbers[i] = tempNumber;
		}
		i++;
	}
	
	Out = In;

	for (int j = 0; j < i; j++){
		tmp = numbers[j];
		if (Out[tmp] == '1')
			Out[tmp] = '0';
		else if (Out[tmp] == '0')
			Out[tmp] = '1';
	}
}

