#pragma once
#include "Libraries.h"

class Authorization {
	string login, password;
public:
	Authorization() { login = password = ""; }
	bool authorization(SOCKET S, Authorization *autho, string pathFile, string value);
	void registration(Authorization *autho, string pathFile, string value);
	void forgotPassword(Authorization *autho, string pathFile);
};