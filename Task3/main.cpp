#include <iostream>
#include <Windows.h>
#include "Facade.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FacadeFileBase f;
	int choice = -1;
	string word, EN, RU;

	while (choice != 0)
	{
		system("cls");
		cout << "Welcome to EN/RU (RU/EN) dictionary." << endl;
		cout << "(1) Translate  (2) Add word  (3) Detele word  (4) Load dict  (5) Save dict  (0) Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Translation: " << f.GetTranslation() << endl;
			break;
		case 2:
			system("cls");
			EN = RU = "";
			cout << "Adding word to dictionary." << endl;
			cout << "Enter EN word: ";
			cin >> EN;
			cout << "Enter RU word: ";
			cin >> RU;
			f.AddNewWord(EN, RU);
			break;
		case 3:
			system("cls");
			word = "";
			cout << "Deleting word from dictionary." << endl;
			cout << "Enter word: ";
			cin >> word;
			f.DeleteWord(word);
			break;
		case 4:
			f.ReadFromBase();
			break;
		case 5:
			cout << "Dictionary: " << (f.WriteToBase() ? "saved." : "not saved.") << endl;
			break;
		case 0:
			cout << "Have a nice day." << endl;
			break;
		default:
			cout << "Invalid input. Try again." << endl;
			break;
		}
		system("pause");
	}
	return 0;
}