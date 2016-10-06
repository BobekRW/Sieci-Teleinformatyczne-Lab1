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
	for (std::size_t i = 0; i < In.size(); ++i)
	{
		plik << bitset<8>(In.c_str()[i]);
		bitset<8> b(In.c_str()[i]);
		Out += b.to_string();
	}



	plik.close();
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
	if (suma1 == suma2)
		cout << "Wiadomosc wyslana poprawnie" << endl;
	else
		cout << "Wiadomosc zostala uszkodzona podczas przesylania" << endl;

}

void menu(int *fchoice, int *bchoice){
	cout << "Prosze podac dla jakiego bledu przeslania wiadomosci, program ma zadzialac.(od 0% do 15%) " << endl;
	cout << "Wybor: ";
	cin >> *fchoice;
	while (cin.good() == false || (*fchoice <0 || *fchoice >15)){
		cout << "Podana wartosc jest niepoprawna prosze podac poprawna wartosc.\nWybor:";
		cin.clear();
		cin.sync();
		cin >> *fchoice;
	}

	cout << "Prosze podac dla ilu bitow program ma przeprowadzic CRC (max 32)" << endl;
	cout << "Wybor: ";
	cin >> *bchoice;
	while (cin.good() == false || (*bchoice <0 || *bchoice >32)){
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

void CRC(int bChoice){
	char dzielnikCRC[33] = { 0 };
	srand(time(NULL));
	for(int i = 0; i < bChoice+1; i++){
		if (i == 0 || i == bChoice)								//Warunek konieczny aby na poczatku i koncu dzielnika by³a 1
			dzielnikCRC[i] = '1';											
		else{
			if (rand() % 4 >1)
				dzielnikCRC[i] = '1';
			else
				dzielnikCRC[i] = '0';
		}
	}
	
	for (int i = 0; i < bChoice+1; i++){
		cout << dzielnikCRC[i];
	}
	cout << endl;
}
