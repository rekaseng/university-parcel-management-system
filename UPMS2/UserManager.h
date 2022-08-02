//UserManager.h
#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H

class UserManager
{
public:
	int insertUser(User* user);
	int updateUser(User* user, int input);
	User* selectUser(string userID);
	User* userForgotPassword(string userID, string phoneNumber);
};

#endif // !USERMANAGER_H
