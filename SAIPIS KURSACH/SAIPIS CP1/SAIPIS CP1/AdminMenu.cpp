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
		cout << "���� ��������������" << endl;
		cout << "1.������� ��" << endl;
		cout << "2.��������" << endl;
		cout << "3.�������������" << endl;
		cout << "4.�������" << endl;
		cout << "5.�����������" << endl;
		cout << "6.�����" << endl;
		cout << "7.��������" << endl;
		cout << "8.����� ���������� ���������� ������" << endl;
		cout << "9.�������� ������ � ��" << endl;
		cout << "0.����� �� ����" << endl;
		green cout << "(���� �����)>>>";
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
		cout << "������� �����: " << endl;
		cin >> number;
		number = number - 1;
		for (auto it = forFile.begin(); it != forFile.end() - 1; it++) {
			if (number == position ) {
				int choice = 1;
				while (choice != 0) {
					cout << left << "����������� ��" << endl;
					cout << "1.�������� ������������ �����������" << endl;
					cout << "2.������� �����������" << endl;
					cout << "3.����� �����������" << endl;
					cout << "4.��������� �����������" << endl;
					cout << "5.�������� �����������" << endl;
					cout << "6.����� �����������" << endl;
					cout << "7.����� �� �����(���-�� �����������)" << endl;
					cout << "8.�������� ���������" << endl;
					cout << "0.�����" << endl;
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
						cout << " " << setw(4) << "�" << "|" << setw(20) << "�������� ����������������" << "|" << setw(15) << "������� ����������" << "|" << setw(15) << "��� ����������" << "|" << setw(15) << "��������� ����������" << "|" << setw(15) << "������� ����������" << "|" << setw(15) << "���� ����������" << "|" << setw(15) << "�����(���-�� �����������)" << "|" << endl;
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
			cout << "������ ����� ��������������!" << endl;
			dataBaseIsEmpty.open(pathFileProduction);
			dataBaseIsEmpty.close();
		}
		else throw logic_error("����� ����� �� ����������!");
	}
	else {
		throw logic_error("������ � �������� ��!");
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
			cout << "������� �����, ������� ������ �������: " << endl;
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
				green cout << "��������� � ����� ������� ������� ������" << endl; white
					dataBaseIsEmpty.open(pathFileProduction);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				forFile.clear();
				show(forFile);
				dataBaseIsEmpty.close();
			}
			else throw logic_error("����� ����� �� ����������");
		}
		else throw logic_error("������ ��� �������� �����");
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
			green cout << "�� ������� �������!" << endl; white
			dataBaseIsEmpty.close();
		}
		else {
			throw logic_error("�� ��� ����������!");
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
		throw range_error("����������� ������ � �������!");
	}
	else {
		dataBaseIsOpen.open(pathFileProduction);
		if (dataBaseIsOpen.is_open()) {
			dataBaseIsOpen.close();
			dataBaseIsOpen.open(pathFileProduction, fstream::app);
			for (auto it = worker.begin(); it != worker.end(); it++) {
				dataBaseIsOpen << *it << endl;
			}

			green cout << "������ ������� �������� � ��!" << endl; white
		}
		else {
			red cout << "����������� ������ � ��!" << endl; white
		}
		dataBaseIsOpen.close();
	}
}

void UserMenu::userMenu()
{
	int choice = 1;
	while (choice != 0) {
		forFile.clear();
		cout << "���� ��������������" << endl;
		cout << "1.�����������" << endl;
		cout << "2.�����" << endl;
		cout << "3.��������" << endl;
		cout << "4.����� ���������� ���������� ������" << endl;
		cout << "0.����� �� ����" << endl;
		green cout << "(���� �����)>>>";
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
		cout << " " << setw(4) << "�" << "|" << setw(20) << "�������� ����������������" << "|" << setw(15) << "������� ����������" << "|" << setw(15) << "��� ����������" << "|" << setw(15) << "��������� ����������" << "|" << setw(15) << "������� ����������" << "|" << setw(15) << "���� ����������" << "|" << setw(15) << "�����(���-�� �����������)" << "|" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		for (auto it = w.begin(); it != w.end() - 1; it++) {
			cout << setw(3) << count++ << ")." << *it << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else throw logic_error("������ � �������� ��!");
	w.clear();
	dataBaseIsOpen.close();
}

void UserMenu::search()
{
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << left << "����� ��" << endl;
			cout << "1.�������� �������������� ������������" << endl;
			cout << "2.������� �����������" << endl;
			cout << "3.����� �����������" << endl;
			cout << "4.��������� �����������" << endl;
			cout << "5.�������� �����������" << endl;
			cout << "6.����� �����������" << endl;
			cout << "7.����� �� �����(���-�� �����������)" << endl;
			cout << "8.������������ � ���� ��������������� ������" << endl;
			cout << "0.�����" << endl;
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
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
				if (count == forFile.size()) throw invalid_argument("������ �� �������...");
				break;
			}
			case 8: {
				dataBaseIsEmpty.open(pathFileProduction);
				for (auto it = forFile.begin(); it != forFile.end(); it++) {
					dataBaseIsEmpty << *it << endl;
				}
				green cout << "��������������� ������ ������������ � ����!" << endl; white
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
		red cout << "����������� ������ � ��!" << endl; white
	}
	dataBaseIsOpen.close();
}

void UserMenu::sort()
{
	dataBaseIsOpen.open(pathFileProduction);
	if (dataBaseIsOpen.is_open()) {
		int choice = 1;
		while (choice != 0) {
			cout << "���������� ��" << endl;
			cout << "1.�������� �������������� ������������" << endl;
			cout << "2.������� �����������" << endl;
			cout << "3.����� �����������" << endl;
			cout << "4.��������� �����������" << endl;
			cout << "5.�������� �����������" << endl;
			cout << "6.����� �����������" << endl;
			cout << "7.����� �� �����(���-�� �����������)" << endl;
			cout << "8.������������ � ���� ��������������� ������" << endl;
			cout << "0.�����" << endl;
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
					red cout << "������ �� ���� �������������!" << endl; white
				}
				else {
					dataBaseIsEmpty.open(pathFileProduction);
					for (auto it = forFile.begin(); it != forFile.end(); it++) {
						dataBaseIsEmpty << *it << endl;
					}
					green cout << "��������������� ������ ������������ � ����!" << endl; white
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
		red cout << "����������� ������ � ��!" << endl; white
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
			sumCriterias += criteriasArray[i]; //����� ������ �������������� ���������	
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
		cout << "������� �������������� ���������" << endl;
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
		cout << "�1 - �������" << endl;
		cout << "�2 - ����" << endl;
		cout << "�3 - ����� �� �����������(���-�� ��)" << endl;
		cout << "������������ ����� : \n";
		for (int i = 0; i < columns; i++) {
			cout << weights[i] << " ";
		}
		cout << endl;
		delete[] matrix;
		delete weights;
	}
	else cout << "������ � �������� ��!" << endl;
	dataBaseIsOpen.close();
}
