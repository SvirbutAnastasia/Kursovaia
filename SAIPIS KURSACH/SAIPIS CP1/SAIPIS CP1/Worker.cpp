#include "Worker.h"
#include "Bools.h"

ostream & operator>>(fstream & stream, Worker & worker)
{
	stream >> worker.productionName >> worker.surname >> worker.name >> worker.personPosition >> worker.age >> worker.experience >> worker.carNumber;
	return stream;
}

istream & operator>>(istream & stream, Worker & worker)
{
	while (1) {
		cout << "�������� ������������" << endl;
		stream >> worker.productionName;
		if (checkString(worker.productionName)) break;
		else worker.productionName = "";
	}
	while (1) {
		cout << "������� ������� ����������" << endl;
		stream >> worker.surname;
		if (checkString(worker.surname)) break;
		else worker.surname = "";
	}
	while (1) {
		cout << "������� ��� ����������" << endl;
		stream >> worker.name;
		if (checkString(worker.name)) break;
		else worker.name = "";
	}
	while (1) {
		cout << "��������� ����������" << endl;
		stream >> worker.personPosition;
		if (checkString(worker.personPosition)) break;
		else worker.personPosition = "";
	}
	while (1) {
		cout << "������� ����������" << endl;
		stream >> worker.age;
		if (checkNumber(worker.age)) break;
		else worker.age = 0;
	}
	while (1) {
		cout << "���� ����������" << endl;
		stream >> worker.experience;
		if (checkNumber(worker.experience)) break;
		else worker.experience = 0;
	}
	while (1) {
		cout << "��������� ����� ������������(���-�� �����������)" << endl;
		stream >> worker.carNumber;
		if (checkNumber(worker.carNumber)) break;
		else worker.carNumber = 0;
	}
	return stream;
}

ostream & operator<<(ostream & stream, Worker & worker)
{
	stream << "|" << setw(25) << worker.getProductionName() << "|" << setw(18) << worker.getSurname() << "|" << setw(15) << worker.getName() << "|" << setw(20) << worker.getPersonPosition() << "|" << setw(18) << worker.getAge() << "|" << setw(15) << worker.getExperience() << "|" << setw(25) << worker.getCarNumber() << "|";
	return stream;
}

ostream & operator<<(fstream & stream, Worker & worker)
{
	stream << worker.getProductionName() << " " << worker.getSurname() << " " << worker.getName() << " " << worker.getPersonPosition() << " " << worker.getAge() << " " << worker.getExperience() << " " << worker.getCarNumber();
	return stream;
}

ostream& operator<<(ofstream& stream, Worker& worker)
{
	stream << worker.getProductionName() << " " << worker.getSurname() << " " << worker.getName() << " " << worker.getPersonPosition() << " " << worker.getAge() << " " << worker.getExperience() << " " << worker.getCarNumber();
	return stream;
}

void Worker::setSurname()
{
	int count = 1;
	while (1) {
		cout << "�������: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, surname);
		if (checkString(surname)) {
			break;
		}
	}
}

void Worker::setProductionName()
{
	int count = 1;
	while (1) {
		cout << "�������� �������������� ������������: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, productionName);
		if (checkString(productionName)) {
			break;
		}
	}
}

void Worker::setName()
{
	int count = 1;
	while (1) {
		cout << "���: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, name);
		if (checkString(name)) {
			break;
		}
	}
}

void Worker::setPersonPosition()
{
	int count = 1;
	while (1) {
		cout << "���������: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, personPosition);
		if (checkString(personPosition)) {
			break;
		}
	}
}

void Worker::setAge()
{
	int count = 1;
	while (1) {
		cout << "������� ����������: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, name);//int
		if (checkString(name)) {
			break;
		}
	}
}

void Worker::setExperience()
{
	int count = 1;
	while (1) {
		cout << "���� ����������: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, name);//int
		if (checkString(name)) {
			break;
		}
	}
}

void Worker::setCarNumber()
{
	int count = 1;
	while (1) {
		cout << "���������� ����������� �� �����: " << endl;
		if (count == 1) {
			cin.get();
		}
		getline(cin, name);//double
		if (checkString(name)) {
			break;
		}
	}
}



string Worker::getSurname()
{
	return surname;
}

string Worker::getName()
{
	return name;
}

double Worker::getExperience()
{
	return experience;
}

int Worker::getCarNumber()
{
	return carNumber;
}

int Worker::getAge()
{
	return age;
}
