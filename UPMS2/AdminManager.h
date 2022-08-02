//AdminManager.h
#pragma once
#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

class AdminManager
{
public:
	int insertAdmin(Admin* admin);
	int updateAdmin(Admin* admin, int input);
	Admin* selectAdmin(string adminID);
	Admin* adminForgotPassword(string adminID, string phoneNumber);
};

#endif // !ADMINMANAGER_H
