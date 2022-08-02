//UserManager.cpp
#include <stdlib.h>
#include<time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "User.h"
#include "UserManager.h"

int UserManager::insertUser(User* user)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO User_ VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, user->userID);
	ps->setString(2, user->firstname);
	ps->setString(3, user->lastname);
	ps->setString(4, user->email);
	ps->setString(5, user->password);
	ps->setString(6, user->phone);
	ps->setString(7, user->faculty);
	ps->setString(8, user->residential);
	ps->setString(9, user->notification);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int UserManager::updateUser(User* user, int input)
{

	if (input == 1)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE User_ SET user_password = ? WHERE user_id = ?");
		ps->setString(1, user->password);
		ps->setString(2, user->userID);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else if (input == 2)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE User_ SET phone = ? WHERE user_id = ?");
		ps->setString(1, user->phone);
		ps->setString(2, user->userID);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else if (input == 3)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE User_ SET residential = ? WHERE user_id = ?");
		ps->setString(1, user->residential);
		ps->setString(2, user->userID);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else
		cout << endl;
}

User* UserManager::selectUser(string userID)
{
	User* user = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM User_ WHERE User_id = ?");

	ps->setString(1, userID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		user = new User();

		user->userID = rs->getString(1);
		user->firstname = rs->getString(2);
		user->lastname = rs->getString(3);
		user->email = rs->getString(4);
		user->password = rs->getString(5);
		user->phone = rs->getString(6);
		user->faculty = rs->getString(7);
		user->residential = rs->getString(8);
		user->notification = rs->getString(9);
		
		cout << "\n	User info: " << endl;
		cout << "Firstname: " << user->firstname << "." << endl;
		cout << "Lastname: " << user->lastname << "." << endl;
		cout << "Phone: " << user->phone << "." << endl;
		cout << "Email: " << user->email << "." << endl;
		cout << "Faculty: " << user->faculty << "." << endl;
		cout << "Residential: " << user->residential << "." << endl;
		cout << "Notification: " << user->notification << "." << endl;
		
	}
	else
	{
		cout << "Invalid UserID!" << endl;
	}

	delete rs;
	delete ps;

	return user;
}

User* UserManager::userForgotPassword(string userID, string phoneNumber)
{
	User* user = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM User_ WHERE User_id = ?");

	ps->setString(1, userID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		user = new User();

		user->userID = rs->getString(1);
		user->firstname = rs->getString(2);
		user->lastname = rs->getString(3);
		user->email = rs->getString(4);
		user->password = rs->getString(5);
		user->phone = rs->getString(6);
		user->faculty = rs->getString(7);
		user->residential = rs->getString(8);
		user->notification = rs->getString(9);
		
		if (phoneNumber != user->phone)
		{
			cout << "The phone number is incorrect." << endl;
			cout << "The account cannot be verified." << endl;
			return user;
		}
		else
		{
			srand(time(0));
			int c;
			c = rand();
			cout <<"Your new password is "<< c;
			stringstream ss;
			ss << c;
			string s;
			ss >> s;

			PreparedStatement* ps = dbConn.prepareStatement("UPDATE User_ SET user_password = ? WHERE user_id = ?");
			ps->setString(1, s);
			ps->setString(2, userID);
			int status = ps->executeUpdate();
			delete ps;
			cout << "\nPassword changed successfully." << endl;
			return user;
		}
	}
	else
	{
		cout << "ID not found!" << endl;
	}

	delete rs;
	delete ps;

	return user;
}