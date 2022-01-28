#include <Windows.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Написать программу «справочник».Создать два одномерных
//массива.Один массив хранит номера мобильных телефонов,
//второй — домашние телефонные номера.
//Реализовать меню для пользователя :
//■ Отсортировать по номерам мобильных
//■ Отсортировать по домашним номерам телефонов;
//■ Вывести пользовательский данные;
//■ Выход.

void printArrays(vector<string>& person, vector<string>& mobile, vector<string>& home);
void sortArrays(vector<string>& origin, vector<string>& additional1, vector<string>& additional2);
void setPersonalData(vector<string>& person, vector<string>& mobile, vector<string>& home);

int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	char choise;
	bool isRun = true;

	vector<string> person = {"Петров Пётр Петрович", "Сидоров Василий Максимович", "Иванов Иван Иванович" };
	vector<string> mobile = {"+7-999-448-69-36", "+7-911-556-88-91", "+7-928-564-78-98"};
	vector<string> home = {"595-022-56-98", "395-556-22-66", "195-369-45-97"};

	while (isRun) {
		cout << "Выберите действие: " << endl;
		cout << "1 - Вывести справочники" << endl;
		cout << "2 - Ввести данные в справочник" << endl;
		cout << "3 - Сортировка по имени" << endl;
		cout << "4 - Сортировать по номерам мобильных телефонов" << endl;
		cout << "5 - Сортировать по номерам домашних телефонов" << endl;
		cout << "X - Выход" << endl;
		cout << "Выберите пункт меню: ";
		cin >> choise;

		switch (tolower(choise)) {
			case '1':
				printArrays(person, mobile, home);
				break;
			case '2':
				setPersonalData(person, mobile, home);
				break;
			case '3':
				sortArrays(person, mobile, home);
				printArrays(person, mobile, home);
				break;
			case '4':
				sortArrays(mobile, person, home);
				printArrays(person, mobile, home);
				break;
			case '5':
				sortArrays(home, mobile, person);
				printArrays(person, mobile, home);
				break;
			case 'х': // русская хэ
			case 'x': // английский икс
				isRun = false;
				break;
			default:
				break;
		}

		if (!isRun) break;

		cin.get(); cin.get();

		system("cls");
	}

	return 0;
}

void printArrays(vector<string>& person, vector<string>& mobile, vector<string>& home) {
	cout << endl;
	for (int i = 0; i < person.size(); i++) {
		cout << person[i] << "\t";
		cout << mobile[i] << "\t";
		cout << home[i] << endl;
	}
}

void sortArrays(vector<string>& origin, vector<string>& additional1, vector<string>& additional2) {
	for (int i = 0; i < origin.size(); i++) {
		for (int j = 0; j < origin.size() - 1; j++) {
			if (origin[j] > origin[j + 1]) {
				swap(origin[j], origin[j + 1]);
				swap(additional1[j], additional1[j + 1]);
				swap(additional2[j], additional2[j + 1]);
			}
		}
	}
}

void setPersonalData(vector<string>& person, vector<string>& mobile, vector<string>& home) {
	string person_last_name, person_first_name, person_middle_name, _mobile, _home;

	cout << "Введите Фамилию: "; cin >> person_last_name;
	cout << "Введите Имя: "; cin >> person_first_name;
	cout << "Введите Отчество: "; cin >> person_middle_name;
	cout << "Введите мобильный номер телефона: "; cin >> _mobile;
	cout << "Введите домашний номер телефона: "; cin >> _home;

	person.push_back(person_last_name + " " + person_first_name + " " + person_middle_name);
	mobile.push_back(_mobile);
	home.push_back(_home);
}
