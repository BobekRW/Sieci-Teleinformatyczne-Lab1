#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <bitset>

using namespace std;

void openFile(string &txt){
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

void saveFile(string In){

	string tmp;
	fstream plik;
	plik.open("startBinary.txt", ios::out);
	for (std::size_t i = 0; i < In.size(); ++i)
	{
		plik << bitset<8>(In.c_str()[i]);
	}

	

	plik.close();
}

void changeToBinary(string In){
	for (std::size_t i = 0; i < In.size(); ++i)
	{
		cout << bitset<8>(In.c_str()[i]);
	}
}