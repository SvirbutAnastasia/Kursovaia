#pragma once
#include "Production.h"

class Worker
	:public Production
{
protected:
	string name, surname;
	double experience;
	int age, carNumber;
public:
	Worker() {
		name = surname = "";
		experience = age = carNumber = 0;
	}
	void setProductionName();
	void setName();
	void setSurname();
	void setExperience();
	void setAge();
	void setPersonPosition();
	void setCarNumber();
	string getSurname();
	string getName();
	double getExperience();
	int getCarNumber();
	int getAge();
	friend ostream& operator >> (fstream & stream, Worker&worker);
	friend istream& operator >> (istream & stream, Worker&worker);
	friend ostream& operator << (ostream & stream, Worker&worker);
	friend ostream& operator << (fstream & stream, Worker&worker);
	friend ostream& operator << (ofstream& stream, Worker&worker);
};