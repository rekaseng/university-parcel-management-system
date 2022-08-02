//CollectionManager.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Collection.h"
#include "CollectionManager.h"
#include "User.h"

//function to insert collection
int CollectionManager::insertCollection(Collection* collection)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Collection VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setInt(1, collection->collectionNum);
	ps->setString(2, collection->recipient_fname);
	ps->setString(3, collection->recipient_lname);
	ps->setString(4, collection->datetime);
	ps->setString(5, collection->location);
	ps->setString(6, collection->signature);
	ps->setString(7, collection->userID);
	ps->setString(8, collection->adminID);
	ps->setString(9, collection->tracking_no);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

//function to update collection
int CollectionManager::updateCollection(Collection* collection, int input)
{

	if (input == 1)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE Collection SET recipient_fname = ? WHERE tracking_no = ?");
		ps->setString(1, collection->recipient_fname);
		ps->setString(2, collection->tracking_no);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else if (input == 2)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE Collection SET recipient_lname = ? WHERE tracking_no = ?");
		ps->setString(1, collection->recipient_lname);
		ps->setString(2, collection->tracking_no);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else if (input == 3)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE Collection SET datetime = ? WHERE tracking_no = ?");
		ps->setString(1, collection->datetime);
		ps->setString(2, collection->tracking_no);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else if (input == 4)
	{
		DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("UPDATE Collection SET location = ? WHERE tracking_no = ?");
		ps->setString(1, collection->location);
		ps->setString(2, collection->tracking_no);
		int status = ps->executeUpdate();
		delete ps;
		return status;
	}
	else
		cout << endl;
}

//function to select collection for admin 
Collection* CollectionManager::selectCollection(string tracking_no)
{
	Collection* collection = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Collection WHERE tracking_no = ?");

	ps->setString(1, tracking_no);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		collection = new Collection();

		collection->collectionNum = rs->getInt(1);
		collection->recipient_fname = rs->getString(2);
		collection->recipient_lname = rs->getString(3);
		collection->datetime = rs->getString(4);
		collection->location = rs->getString(5);
		collection->signature = rs->getString(6);
		collection->userID = rs->getString(7);
		collection->adminID = rs->getString(8);
		collection->tracking_no = rs->getString(9);

	
		cout << "Collection Number: " << collection->collectionNum << "." << endl;
		cout << "Recipient Firstname: " << collection->recipient_fname << "." << endl;
		cout << "Recipient Lastname: " << collection->recipient_lname << "." << endl;
		cout << "Date & Time: " << collection->datetime << "." << endl;
		cout << "Location: " << collection->location << "." << endl;
		cout << "Signature: " << collection->signature << "." << endl;
		cout << "User ID: " << collection->userID << "." << endl;
		cout << "Admin ID: " << collection->adminID << "." << endl;
		cout << "Tracking number: " << collection->tracking_no << "." << endl;
		
		
	}
	else
	{
		cout << "Invalid tracking number!/ No record!" << endl;
	}


	delete rs;
	delete ps;

	return collection;
}


//function to select collection for user
Collection* CollectionManager::userSelectCollection(string id)
{
	Collection* collection = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Collection WHERE user_id = ?");

	ps->setString(1, id);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		collection = new Collection();

		collection->collectionNum = rs->getInt(1);
		collection->recipient_fname = rs->getString(2);
		collection->recipient_lname = rs->getString(3);
		collection->datetime = rs->getString(4);
		collection->location = rs->getString(5);
		collection->signature = rs->getString(6);
		collection->userID = rs->getString(7);
		collection->adminID = rs->getString(8);
		collection->tracking_no = rs->getString(9);

		cout << "\n	Your collection info: " << endl;
		cout << "Collection Number: " << collection->collectionNum << "." << endl;
		cout << "Recipient Firstname: " << collection->recipient_fname << "." << endl;
		cout << "Recipient Lastname: " << collection->recipient_lname << "." << endl;
		cout << "Date & Time: " << collection->datetime << "." << endl;
		cout << "Location: " << collection->location << "." << endl;
		cout << "Signature: " << collection->signature << "." << endl;
		cout << "User ID: " << collection->userID << "." << endl;
		cout << "Admin ID: " << collection->adminID << "." << endl;
		cout << "Tracking number: " << collection->tracking_no << "." << endl;


	}
	else
	{
		cout << "Invalid tracking number!/ No record!" << endl;
	}


	delete rs;
	delete ps;

	return collection;
}

//function to delete collection for admin
int CollectionManager::deleteCollection(string tracking_no)
{
	int status = 0;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Collection WHERE tracking_no = ?");

	ps->setString(1, tracking_no);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM Collection WHERE tracking_no = ?");
		ps->setString(1, tracking_no);
	    status = ps->executeUpdate();
		cout << "Collection with tracking number: " << tracking_no << " has been deleted." << endl;
	}
	else
	{
		cout << "No record found!" << endl;
		status = 0;
	}
	delete ps;
	return status;
}