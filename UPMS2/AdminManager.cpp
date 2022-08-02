//AdminManager.cpp
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
#include "Admin.h"
#include "AdminManager.h"

int AdminManager::insertAdmin(Admin* admin)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Administrator VALUES (?, ?, ?, ?, ?, ?)");

	ps->setString(1, admin->adminID);
	ps->setString(2, admin->firstname);
	ps->setString(3, admin->lastname);
	ps->setString(4, admin->email);
	ps->setString(5, admin->password);
	ps->setString(6, admin->phone);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int AdminManager::updateAdmin(Admin* admin, int input)
{

	if (input == 1)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE Administrator SET admin_password = ? WHERE admin_id = ?");
		ps->setString(1, admin->password);
		ps->setString(2, admin->adminID);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else if (input == 2)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE Administrator SET phone = ? WHERE admin_id = ?");
		ps->setString(1, admin->phone);
		ps->setString(2, admin->adminID);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else
		cout << endl;
}

Admin* AdminManager::selectAdmin(string adminID)
{
	Admin* admin = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Administrator WHERE Admin_id = ?");

	ps->setString(1, adminID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		admin = new Admin();

		admin->adminID = rs->getString(1);
		admin->firstname = rs->getString(2);
		admin->lastname = rs->getString(3);
		admin->email = rs->getString(4);
		admin->password = rs->getString(5);
		admin->phone = rs->getString(6);

		cout << "\n	Admin info: " << endl;
		cout << "Firstname: " << admin->firstname << "." << endl;
		cout << "Lastname: " << admin->lastname << "." << endl;
		cout << "Phone: " << admin->phone << "." << endl;
		cout << "Email: " << admin->email << "." << endl;
	}else
	{
		cout << "Invalid AdminID!" << endl;
	}

	delete rs;
	delete ps;
	return admin;
}

Admin* AdminManager::adminForgotPassword(string adminID, string phoneNumber)
{
	Admin* admin = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Administrator WHERE Admin_id = ?");

	ps->setString(1, adminID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		admin = new Admin();

		admin->adminID = rs->getString(1);
		admin->firstname = rs->getString(2);
		admin->lastname = rs->getString(3);
		admin->email = rs->getString(4);
		admin->password = rs->getString(5);
		admin->phone = rs->getString(6);


		if (phoneNumber != admin->phone)
		{
			cout << "The phone number is incorrect." << endl;
			cout << "The account cannot be verified." << endl;
			return admin;
		}
		else
		{
			srand(time(0));
			int c;
			c = rand();
			cout << "Your new password is " << c;
			stringstream ss;
			ss << c;
			string s;
			ss >> s;

			PreparedStatement* ps = dbConn.prepareStatement("UPDATE Administrator SET admin_password = ? WHERE admin_id = ?");
			ps->setString(1, s);
			ps->setString(2, adminID);
			int status = ps->executeUpdate();
			delete ps;
			cout << "\nPassword changed successfully." << endl;
			return admin;
		}
	}
	else
	{
		cout << "ID not found!" << endl;
	}

	delete rs;
	delete ps;

	return admin;
}