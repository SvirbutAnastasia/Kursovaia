#include "AdminMenu.h"

vector<Worker> worker;
vector<Worker> forFile;

fstream dataBaseIsOpen;
ofstream dataBaseIsEmpty;
string pathFileProduction = "production.txt";

void AdminMenu::adminMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "Меню администратора" << endl;
		cout << "1.Создать БД" << endl;
		cout << "2.Добавить" << endl;
		cout << "3.Редактировать" << endl;
		cout << "4.Удалить" << endl;
		cout << "5.Сортировать" << endl;
		cout << "6.Поиск" << endl;
		cout << "7.Показать" << endl;
		cout << "8.Метод взвешенных экспертных оценок" << endl;
		cout << "9.Записать данные в БД" << endl;
		cout << "0.Выход из меню" << endl;
		green cout << "(поле ввода)>>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			try
			{
				fileCreating();
			}
			catch (logic_error & le)
			{
				red cout << le.what() << endl; white
			}
			break;
		}
		case 2: {
			insert();
			break;
		}
		case 3: {
			redact();
			break;
		}
		case 4: {
			try
			{
				erase();
			}
			catch (logic_error & le)
			{
				red cout << le.what() << endl; white
			}
			break;
		}
		case 5: {
			sort();
			break;
		}
		case 6: {
			try
			{
				search();
			}
			catch (invalid_argument & ia)
			{
				red cout << ia.what() << endl; white
			}
			break;
		}
		case 7: {
			show(forFile);
			break;
		}
		case 8: {
			mainFunction();
			break;
		}
		case 9: {
			fileInsert();
			break;
		}
		default: {
			red noValue white;
			break;
		}
		}
	}
}

void AdminMenu::insert()
{
	Worker w1;
	cin >> w1;
	worker.push_back(w1);
}

void AdminMenu::redact()
{
	forFile.clear();
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		while (!dataBaseIsOpen.eof()) {
			Worker w;
			dataBaseIsOpen >> w;
			forFile.push_back(w);

		}
		int position = 0, number = 0;
		show(forFile);
		cout << "Введите номер: " << endl;
		cin >> number;
		number = number - 1;
		for (auto it = forFile.begin(); it != forFile.end() - 1; it++) {
			if (number == position ) {
				int choice = 1;
				while (choice != 0) {
					cout << left << "Редактируем по" << endl;
					cout << "1.Названию производства автомобилей" << endl;
					cout << "2.Фамилии сотрудников" << endl;
					cout << "3.Имени сотрудников" << endl;
					cout << "4.Должности сотрудников" << endl;
					cout << "5.Возрасту сотрудников" << endl;
					cout << "6.Стажу сотрудников" << endl;
					cout << "7.Норме за смену(кол-во автомобилей)" << endl;
					cout << "8.Показать изменения" << endl;
					cout << "0.Выход" << endl;
					green cout << ">>>" << endl;
					cin >> choice; white;
					switch (choice)
					{
					case 1: {
						forFile[position].setProductionName();
						break;
					}
					case 2: {
						forFile[position].setSurname();
						break;
					}
					case 3: {
						forFile[position].setName();
						break;
					}
					case 4: {
						forFile[position].setPersonPosition();
						break;
					}
					case 5: {
						forFile[position].setAge();
						break;
					}
					case 6: {
						forFile[position].setExperience();
						break;
					}
					case 7: {
						forFile[position].setCarNumber();
						break;
					}
					case 8: {
						int count = 1;
						cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << " " << setw(4) << "№" << "|" << setw(20) << "Название автопроизводства" << "|" << setw(15) << "Фамилия сотрудника" << "|" << setw(15) << "Имя сотрудника" << "|" << setw(15) << "Должность сотрудника" << "|" << setw(15) << "Возраст сотрудника" << "|" << setw(15) << "Стаж сотрудника" << "|" << setw(15) << "Норма(кол-во автомобилей)" << "|" << endl;
						cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
						for (auto it = forFile.begin() ; it != forFile.end()-1 ; it++) {
							cout << setw(3) << count++ << ")." << *it << endl;
							cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
						}
						break;
					}
					default:
						break;
					}
				}
			}
			else position++;
		}
		if (position != forFile.size()) {
			dataBaseIsOpen.close();
			cout << "Данный номер отредактирован!" << endl;
			dataBaseIsEmpty.open(pathFileProduction);
			dataBaseIsEmpty.close();
		}
		else throw logic_error("Такой номер не существует!");
	}
	else {
		throw logic_error("Ошибка в открытии БД!");
		dataBaseIsOpen.close();
	}
}

void AdminMenu::erase()
{
	try
	{
		forFile.clear();
		dataBaseIsOpen.open(pathFileProduction);
		if (dataBaseIsOpen.is_open()) {
			while (!dataBaseIsOpen.eof()) {
				Worker w;
				dataBaseIsOpen >> w;
				forFile.push_back(w);
			}
			int position = 0, number = 0;
			show(forFile);
			cout << "Введите номер, который хотите удалить: " << endl;
			cin >> number;
			for (auto it = forFile.begin(); it != forFile.end(); it++) {
				if (number == position + 1) {
					forFile.erase(it);
					position--;
					break;
				}
				else position++;
			}
			if (position != forFile.size()) {
				green cout << "Сотрудник с таким номером успешно удален" << endl; white
					dataBaseIsEmpty.open(pathFileProduction);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				forFile.clear();
				show(forFile);
				dataBaseIsEmpty.close();
			}
			else throw logic_error("Такой номер не существует");
		}
		else throw logic_error("Ошибка при открытии файла");
		dataBaseIsOpen.close();
	}
	catch (logic_error & le)
	{
		red cout << le.what() << endl; white
	}
}

void AdminMenu::fileCreating()
{
	try
	{
		dataBaseIsOpen.open(pathFileProduction);
		if (!dataBaseIsOpen.is_open()) {
			dataBaseIsEmpty.open(pathFileProduction);
			green cout << "БД успешно создана!" << endl; white
			dataBaseIsEmpty.close();
		}
		else {
			throw logic_error("БД уже существует!");
		}
	}
	catch (logic_error & le)
	{
		red cout << le.what() << endl; white
	}
	dataBaseIsOpen.close();
}

void AdminMenu::fileInsert()
{
	if (worker.empty()) {
		throw range_error("Отсутствуют данные в векторе!");
	}
	else {
		dataBaseIsOpen.open(pathFileProduction);
		if (dataBaseIsOpen.is_open()) {
			dataBaseIsOpen.close();
			dataBaseIsOpen.open(pathFileProduction, fstream::app);
			for (auto it = worker.begin(); it != worker.end(); it++) {
				dataBaseIsOpen << *it << endl;
			}

			green cout << "Данные успешно записаны в БД!" << endl; white
		}
		else {
			red cout << "Отсутствует доступ к БД!" << endl; white
		}
		dataBaseIsOpen.close();
	}
}

void UserMenu::userMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "Меню администратора" << endl;
		cout << "1.Сортировать" << endl;
		cout << "2.Поиск" << endl;
		cout << "3.Показать" << endl;
		cout << "4.Метод взвешенных экспертных оценок" << endl;
		cout << "0.Выход из меню" << endl;
		green cout << "(поле ввода)>>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			sort();
			break;
		}
		case 2: {
			try
			{
				search();
			}
			catch (invalid_argument & ia)
			{
				red cout << ia.what() << endl; white
			}
			break;
		}
		case 3: {
			show(forFile);
			break;
		}
		case 4: {
			mainFunction();
			break;
		}
		default: {
			red noValue white;
			break;
		}
		}
	}
}

void UserMenu::show(vector<Worker> w)
{
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		while (!dataBaseIsOpen.eof()) {
			Worker workerObject;
			dataBaseIsOpen >> workerObject;
			w.push_back(workerObject);
		}
		int count = 1;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << " " << setw(4) << "№" << "|" << setw(20) << "Название автопроизводства" << "|" << setw(15) << "Фамилия сотрудника" << "|" << setw(15) << "Имя сотрудника" << "|" << setw(15) << "Должность сотрудника" << "|" << setw(15) << "Возраст сотрудника" << "|" << setw(15) << "Стаж сотрудника" << "|" << setw(15) << "Норма(кол-во автомобилей)" << "|" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (auto it = w.begin(); it != w.end() - 1; it++) {
			cout << setw(3) << count++ << ")." << *it << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else throw logic_error("Ошибка в открытии БД!");
	w.clear();
	dataBaseIsOpen.close();
}

void UserMenu::search()
{
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << left << "Поиск по" << endl;
			cout << "1.Названию автомобильного производства" << endl;
			cout << "2.Фамилии сотрудников" << endl;
			cout << "3.Имени сотрудников" << endl;
			cout << "4.Должности сотрудников" << endl;
			cout << "5.Возрасту сотрудников" << endl;
			cout << "6.Стажу сотрудников" << endl;
			cout << "7.Норме за смену(кол-во автомобилей)" << endl;
			cout << "8.Перезаписать в файл отсортированные данные" << endl;
			cout << "0.Выход" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				forFile.clear();
				while(!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string productionName;
				cin.get();
				getline(cin, productionName);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getProductionName().c_str(), productionName.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 2: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string surname;
				cin.get();
				getline(cin, surname);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getSurname().c_str(), surname.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 3: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string name;
				cin.get();
				getline(cin, name);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getName().c_str(), name.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 4: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string personPosition;
				cin.get();
				getline(cin, personPosition);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(it->getPersonPosition().c_str(), personPosition.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 5: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string age;
				cin.get();
				getline(cin, age);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getAge()).c_str(), age.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 6: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string experience;
				cin.get();
				getline(cin, experience);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getExperience()).c_str(), experience.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 7: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				int count = 0;
				string carNumber;
				cin.get();
				getline(cin, carNumber);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					if (strstr(to_string(it->getCarNumber()).c_str(), carNumber.c_str()) != NULL)
						cout << *it << endl;
					else count++;
				}
				if (count == forFile.size()) throw invalid_argument("Ничего не найдено...");
				break;
			}
			case 8: {
				dataBaseIsEmpty.open(pathFileProduction);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				green cout << "отсортирвоанные данные перезаписаны в файл!" << endl; white
					dataBaseIsEmpty.close();
				break;
			}
			default: {
				red noValue white;
				break;
			}
			}
		}
	}
	else {
		red cout << "Отсутствует доступ к БД!" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::sort()
{
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << "Сортировка по" << endl;
			cout << "1.Названию автомобильного производства" << endl;
			cout << "2.Фамилии сотрудников" << endl;
			cout << "3.Имени сотрудников" << endl;
			cout << "4.Должности сотрудников" << endl;
			cout << "5.Возрасту сотрудников" << endl;
			cout << "6.Стажу сотрудников" << endl;
			cout << "7.Норме за смену(кол-во автомобилей)" << endl;
			cout << "8.Перезаписать в файл отсортированные данные" << endl;
			cout << "0.Выход" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getProductionName().c_str(), it2->getProductionName().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 2: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getSurname().c_str(), it2->getSurname().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 3: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getName().c_str(), it2->getName().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 4: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (strcmp(it1->getPersonPosition().c_str(), it2->getPersonPosition().c_str()) < 0) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 5: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getAge() < it2->getAge()) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 6: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getExperience() < it2->getExperience()) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 7: {
				forFile.clear();
				while (!dataBaseIsOpen.eof()) {
					Worker w;
					dataBaseIsOpen >> w;
					forFile.push_back(w);
				}
				for (auto it1 = forFile.begin(); it1 != forFile.end() - 1; it1++) {
					for (auto it2 = forFile.begin(); it2 != forFile.end() - 1; it2++) {
						if (it1->getCarNumber() < it2->getCarNumber()) {
							Worker w = *it1;
							*it1 = *it2;
							*it2 = w;
						}
					}
				}
				break;
			}
			case 8: {
				if (forFile.empty()) {
					red cout << "Данные не были отсортированы!" << endl; white
				}
				else {
					dataBaseIsEmpty.open(pathFileProduction);
					for (auto it = forFile.begin(); it != forFile.end(); it++) {
						dataBaseIsEmpty << *it << endl;
					}
					green cout << "отсортирвоанные данные перезаписаны в файл!" << endl; white
						dataBaseIsEmpty.close();
				}
				break;
			}
			default: {
				red noValue white;
				break;
			}
			}
		}
	}
	else {
		red cout << "Отсутствует доступ к БД!" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::mainFunction()
{
	forFile.clear();
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		int count = 0;
		while (!dataBaseIsOpen.eof()) {
			Worker w;
			dataBaseIsOpen >> w;
			forFile.push_back(w);
			count++;
		}
		double **matrix = new double*[count];
		for (int i = 0; i < count; i++) {
			matrix[i] = new double[3];
		}
		double criteriasArray[] = { 0.7,0.4,0.2 }, sumCriterias = 0.0, *weights = new double[count];
		for (int i = 0; i < count; i++) {
			weights[i] = 0;
		}
		for (int i = 0; i < 3; i++) {
			sumCriterias += criteriasArray[i]; //сумма оценок компетентности экспертов	
		}
		int rows = 0, columns = 0;
		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getAge();
			rows++;
		}
		columns++;
		rows = 0;
		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getExperience();
			rows++;
		}
		rows = 0;
		columns++;
		for (auto it = forFile.begin(); it != forFile.end(); it++) {
			matrix[columns][rows] = it->getCarNumber();
			rows++;
		}
		columns++;
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				matrix[i][j] /= 100;
			}
		}
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows-1; j++) {
				weights[i] += matrix[i][j] * criteriasArray[j];
			}
		}
		cout << "Матрица компетентности экспертов" << endl;
		cout << "K/Z ";
		int point = 0;
		while (point != columns) {
			cout << " Z" << point + 1<< " ";
			point++;
		}
		cout << endl;
		for (int i = 0; i < columns; i++) {
			cout << "K" << i + 1 << " ";
			for (int j = 0; j < rows; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "К1 - Возраст" << endl;
		cout << "К2 - Стаж" << endl;
		cout << "К3 - Норма по автомобилям(кол-во шт)" << endl;
		cout << "Предпочтение целей : \n";
		for (int i = 0; i < columns; i++) {
			cout << weights[i] << " ";
		}
		cout << endl;
		delete[] matrix;
		delete weights;
	}
	else cout << "Ошибка в открытии БД!" << endl;
	dataBaseIsOpen.close();
}
