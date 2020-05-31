#include "Authorization.h"
#include "UserMenu.h"
#include "AdminMenu.h"
#include "Bools.h"

#pragma comment(lib, "ws2_32.lib")

Authorization adminValue, *adminPtr, userValue, *userPtr;
string adminPathFile = "D://University//4 �������//��������//KURSACH//SAIPIS KURSACH//SAIPIS CP Server//admin.txt", userPathFile = "user.txt", admin = "�������������", user = "������������";
AdminMenu aMenu;
UserMenu uMenu;

void menu(SOCKET S,Authorization menu,Authorization * autho, string pathFile, string value) {
	int choice = 1;
	while (choice != 0) {
		cout << "���� " << value << endl;
		cout << "1.����" << endl;
		cout << "2.�����������" << endl;
		cout << "3.������ ������?" << endl;
		cout << "0.����� �� ����" << endl;
		green cout << "(���� �����)>>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			if (pathFile == adminPathFile) {
				char message[] = "1";
				send(S, message, sizeof(message), 0);
			}
			if (pathFile == userPathFile) {
				char message[] = "2";
				send(S, message, sizeof(message), 0);
			}
			if (menu.authorization(S,autho, pathFile, value)) {
				if (pathFile == adminPathFile) {
					aMenu.adminMenu();
				}
				if (pathFile == userPathFile) {
					aMenu.userMenu();
				}
			}
			break;
		}
		case 2: {
			menu.registration(autho, pathFile, value);
			break;
		}
		case 3: {
			menu.forgotPassword(autho, pathFile);
			break;
		}
		}
	}
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		red cout << "������ WSAStartup!" << endl;
		return 1;
	}
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		red cout << "����������� ���������� � ��������!" << endl;
		return 1;
	}
	int choice = 1;
	while (choice != 0) {
		cout << "������� ����" << endl;
		cout << "1.������ ��� ���������������" << endl;
		cout << "2.������ ��� �������������" << endl;
		cout << "0.����� �� ���������" << endl;
		green cout << "(���� �����)>>>";
		cin >> choice; white;
		system("cls");
		switch (choice) {
		case 1: {
			menu(Connection,adminValue,adminPtr, adminPathFile, admin);
			break;
		}
		case 2: {
			menu(Connection,userValue, userPtr, userPathFile, user);
			break;
		}
		default: {
			red noValue white;
			break;
		}
		}
	}
}