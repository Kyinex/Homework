#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void create(string name) {
	string content;
	ofstream fout(name);
	cout << "Введите содержание файла:\n";
	getline(cin, content);
	fout << content;
	fout.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name, content;

	cout << "Название файла : ";
	getline(cin, name);
	name = name + ".txt";

	ifstream fin(name);
	if (!fin.is_open()) {
		cout << "\n Не удалось открыть файл.";
	}
	else {
		string replacement;
		string s;
		content = "";
		cout << "Введите символ-замену разделителям(пробелам): ";
		getline(cin, replacement);

		while (!fin.eof()) {
			getline(fin, s);
			content += s + "\n";
		}
		if (replacement != " ") {
			while (content.find(' ') != -1) {
				content.replace(content.find(' '), 1, replacement);
			}
		}
		fin.close();
		ofstream fout(name);
		fout << content;
		fout.close();
		cout << "\n________________________________________________________\n\n";
		ifstream fin(name);
		if (!fin.is_open()) {
			cout << "\n Не удалось открыть файл.";
		}
		else {
			while (!fin.eof()) {
				getline(fin, s);
				cout << s;
			}
		}
	}

}
