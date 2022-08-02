//LoginManager.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "User.h"
#include "Admin.h"
#include "LoginManager.h"
#include "UserManager.h"
#include "AdminManager.h"

LoginManager::LoginManager()
{}

//function for user to login
bool LoginManager::userLogin(string userID, string userPassword)
{
	string id;
	User* user = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM User_ WHERE User_id = ? AND User_password = ?");

	ps->setString(1, userID);
	ps->setString(2, userPassword);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		user = new User();

		user->userID = rs->getString(1);
		user->firstname = rs->getString(2);
		user->lastname = rs->getString(3);
		user->email = rs->getString(4);
		user->password = rs->getString(5);
		if (user->password != userPassword)
		{
			cout << "Invalid userID and password." << endl;
			cout << "User Login not successful!" << endl;
			id = login();
			return false;
		}
		user->phone = rs->getString(6);
		user->faculty = rs->getString(7);
		user->residential = rs->getString(8);
		user->notification = rs->getString(9);

		cout << "User Login successful!" << endl;
		return true;
	}
	else
	{
		cout << "Invalid userID and password." << endl;
		cout << "User Login not successful!" << endl;
		id = login();
		return false;
	}

	delete rs;
	delete ps;




}

//function for admin to login
bool LoginManager::adminLogin(string adminID, string adminPassword)
{
	Admin* admin = NULL;
	string id;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Administrator WHERE Admin_id = ? AND Admin_password = ?");

	ps->setString(1, adminID);
	ps->setString(2, adminPassword);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		admin = new Admin();

		admin->adminID = rs->getString(1);
		admin->firstname = rs->getString(2);
		admin->lastname = rs->getString(3);
		admin->email = rs->getString(4);
		admin->password = rs->getString(5);
		if (admin->password != adminPassword)
		{
			cout << "Invalid adminID and password." << endl;
			cout << "Admin Login not successful!" << endl;
			id=login();
			return false;
		}
		admin->phone = rs->getString(6);

		cout << "Admin Login successful!" << endl;
		return true;
	}
	else
	{
		cout << "Invalid adminID and password." << endl;
		cout << "Admin Login not successful!" << endl;
		id = login();
		return false;
	}

	delete rs;
	delete ps;
}


//function for  login as a whole
string LoginManager::login()
{
	int choice;
	string id;
	string phoneNumber;
	LoginManager foruser;
	LoginManager foradmin;
	UserManager userManager;
	AdminManager adminManager;
	LoginManager loginManager;
	cout << endl << "*****Login Page*****" << endl;
	cout << "\nLogin as User or Admin? \n 1. User 2. Admin 3.Forgot password : ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		cout << "Enter userID: ";
		cin >> userID;
		cout << "Enter userPassword: ";
		cin >> userPassword;
		foruser.userLogin(userID, userPassword);
		return userID;
	}
	else if (choice == 2)
	{
		cout << "Enter adminID: ";
		cin >> adminID;
		cout << "Enter adminPassword: ";
		cin >> adminPassword;
		foradmin.adminLogin(adminID, adminPassword);
		return adminID;
	}
	else if (choice == 3)
	{
		cout << "Enter userID or adminID to change password: ";
		cin.get();
		getline(cin, id);
		cout << "Enter your phone number for verification: ";
		getline(cin, phoneNumber);
		
		char firstletter = id.at(0);

		while (firstletter != 'A' && firstletter != 'a' && firstletter != 'B' && firstletter != 'b')
		{
			cout << "The id is not valid!" << endl;
			cout << "Enter userID or adminID to change password: ";
			getline(cin, id);
			cout << "Enter your phone number for verification: ";
			getline(cin, phoneNumber);
			firstletter = id.at(0);
		}
		if (firstletter == 'B' || firstletter == 'b')
		{
			User* user = userManager.userForgotPassword(id, phoneNumber);
			id = loginManager.login();
			return id;
		}
		else
		{
			Admin* admin = adminManager.adminForgotPassword(id, phoneNumber);
			id = loginManager.login();
			return id;
		}
		
	}
	else
		cout << "Invalid input!" << endl;
}