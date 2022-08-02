//LoginManager.h
#pragma once
#include <string>
#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

class LoginManager
{
private:
	string userID;
	string adminID;
	string userPassword;
	string adminPassword;

public:
	LoginManager();
	bool userLogin(string userID, string userPassword);
	bool adminLogin(string adminID, string adminPassword);
	string login();


};

#endif // !LOGINMANAGER
