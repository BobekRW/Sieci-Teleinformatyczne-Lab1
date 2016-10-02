/*Robert Wyszecki
Sieci Teleinformatyczne
Laboratorium nr 1*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main(){
	bool done = 1;
	int choice = 0;
	while (done){
		cout << "1.Show text\n";
		cout << "2.End\n";
		cout << "Please choice operation: ";
		cin >> choice;
		switch (choice){
			case 1: cout << "Hello" << endl;
				break;
			case 2: done = 0;
				break;
			default: cout << "ERROR! Unknown command" << endl;
				break;
		}
		cin.clear();
		cin.sync();
	}

	cin.get();
	return 0;
}