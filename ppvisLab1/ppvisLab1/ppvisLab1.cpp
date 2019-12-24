#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "dict.h"
using namespace std;

void menu() {
	cout << "What do you want?";
	cout << "\n1. Add new word and its translate\n2. Delete word from dictionary\n3. Search translate of word\n4. Rewrite translation of word\n5. Know a count of translation of words in dictionary\n6. Add new words in dictionary from file(file needed to be in same directory, that .exe file is)\n0.Exit\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	dict* root = new dict("root", "корень", NULL, NULL);
	bool fromfile = false, is_root = true;
	int cont;
	string temp;
	string en, ru;
	int g = 1000;
	dict* temporar = new dict("suck", "сосать", NULL, NULL);

	menu();
	cin >> cont;
	while (cont != 0)
	{
		system("cls");
		while(cont > 5 && cont < 1) {
			cout << "its not a 1,2,3,4,5";
			system("pause");
			menu();
			cin >> cont;
		}
		
		switch (cont)
		{
		case 1:
			if (!fromfile) {
				if (is_root) {
					cout << "Write english word:\t";
					cin >> en;
					cout << "\nWrite russian translation of this word:\t";
					cin >> ru;
					root->newstring(en, ru);
					is_root = 0;
					system("pause");
					system("cls");
					break;
				}
				if (!is_root) {
					cout << "Write english word:\t";
					cin >> en;
					cout << "Write russian translation of this word:\t";
					cin >> ru;
					dict* temp = new dict(en, ru, NULL, NULL);
					*root += temp;
					system("pause");
					system("cls");
					break;
				}
			}
			if (fromfile) {
				cout << "Write english word:\t";
				cin >> en;
				cout << "Write russian translation of this word:\t";
				cin >> ru;
				dict* temp = new dict(en, ru, NULL, NULL);
				*root += temp;
				system("pause");
				system("cls");
				break;
			}
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Write a word to delete: \t";
			cin >> temp;
			*root -= temp;
			system("cls");
			cout << "Word and it translation has been deleted";
			temp.clear();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Write a word what translation you search:\t";
			cin >> temp;
			temporar = (*root)[temp];
			system("cls");
			cout << "you searched: " << temporar->engret();
			cout << "\ntranslate in russian: " << temporar->rusret();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Write a word what translation you search:\t";
			cin >> temp;
			temporar = (*root)[temp];
			system("cls");
			cout << "Write a new word in russian:\t";
			cin >> temp;
			(*temporar)(temp);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "count of words: ";
			g = root->count_of_words(root);
			cout << g;
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Enter the file name: ";
			cin >> temp;
			root->fromdoc(temp);
			fromfile = true;
			system("pause");
			system("cls");
			break;
		}
		menu();
		cin >> cont;
	}
	return 0;
}