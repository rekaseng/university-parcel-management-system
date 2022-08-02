//ParcelManager.cpp
#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Parcel.h"
#include "ParcelManager.h"
#include "User.h"
#include "UserManager.h"
#include "Tracking.h"
#include "TrackingManager.h"

int ParcelManager::insertParcel(Parcel* parcel, string id)
{
	Tracking* tracking;
	User* user;
	DatabaseConnection dbConn;
	PreparedStatement* psOne = dbConn.prepareStatement("INSERT INTO Parcel VALUES (?, ?, ?, ?, ?)");

	psOne->setString(1, parcel->tracking_no);
	psOne->setString(2, parcel->status);
	psOne->setString(3, parcel->datetime);
	psOne->setString(4, parcel->location);
	psOne->setString(5, parcel->userID);

	int status1 = psOne->executeUpdate();

	PreparedStatement* psTwo = dbConn.prepareStatement("INSERT INTO Tracking VALUES (?, ?, ?, ?, ?)");

	psTwo->setString(1, parcel->status);
	psTwo->setString(2, id);
	psTwo->setString(3, parcel->tracking_no);
	psTwo->setString(4, parcel->datetime);
	psTwo->setString(5, parcel->location);

	int status2 = psTwo->executeUpdate();

	string notification = parcel->tracking_no + " - " + parcel->status + " - " + parcel->datetime;

	cout << notification << endl;
	
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE User_ SET notification = ? WHERE user_id = ?");
	ps->setString(1, notification);
	ps->setString(2, parcel->userID);
	int status3 = ps->executeUpdate();
	delete ps;
	

	delete psTwo;
	delete psOne;

	return status3;
}

int ParcelManager::updateParcel(Parcel* parcel, string id)
{
	int status2;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Parcel WHERE tracking_no = ?");

	ps->setString(1, parcel->tracking_no);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{

		parcel->userID = rs->getString(5);

		PreparedStatement* psOne = dbConn.prepareStatement("UPDATE Parcel SET status = ? WHERE tracking_no = ?");
		psOne->setString(1, parcel->status);
		psOne->setString(2, parcel->tracking_no);
		int statusOne = psOne->executeUpdate();
		delete psOne;

		PreparedStatement* psTwo = dbConn.prepareStatement("UPDATE Parcel SET datetime = ? WHERE tracking_no = ?");
		psTwo->setString(1, parcel->datetime);
		psTwo->setString(2, parcel->tracking_no);
		int statusTwo = psTwo->executeUpdate();
		delete psTwo;

		PreparedStatement* psThree = dbConn.prepareStatement("UPDATE Parcel SET location = ? WHERE tracking_no = ?");
		psThree->setString(1, parcel->location);
		psThree->setString(2, parcel->tracking_no);
		int statusThree = psThree->executeUpdate();
		delete psThree;

		PreparedStatement* psFour = dbConn.prepareStatement("INSERT INTO Tracking VALUES (?, ?, ?, ?, ?)");

		psFour->setString(1, parcel->status);
		psFour->setString(2, id);
		psFour->setString(3, parcel->tracking_no);
		psFour->setString(4, parcel->datetime);
		psFour->setString(5, parcel->location);

		status2 = psFour->executeUpdate();

		delete psFour;

		string notification = parcel->tracking_no + " - " + parcel->status + " - " + parcel->datetime;

		cout << notification << endl;

		PreparedStatement* ps = dbConn.prepareStatement("UPDATE User_ SET notification = ? WHERE user_id = ?");
		ps->setString(1, notification);
		ps->setString(2, parcel->userID);
		int statusFour = ps->executeUpdate();
		delete ps;
	}
	else
	{
		cout << "Tracking number not found!" << endl;
	}

	return status2;
}

Parcel* ParcelManager::selectParcel(string tracking_no)
{
	Parcel* parcel = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Parcel WHERE tracking_no = ?");

	ps->setString(1, tracking_no);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		parcel = new Parcel();

		parcel->tracking_no = rs->getString(1);
		parcel->status = rs->getString(2);
		parcel->datetime = rs->getString(3);
		parcel->location = rs->getString(4);
		parcel->userID = rs->getString(5);
		cout << "\n	The parcel info: " << endl;
		cout << "Status: " << parcel->status << "." << endl;
		cout << "Date & Time: " << parcel->datetime << "." << endl;
		cout << "Location: " << parcel->location << "." << endl;
		cout << "User ID: " << parcel->userID << "." << endl;
	}
	else
	{
		cout << "Invalid tracking number!" << endl;
	}

	delete rs;
	delete ps;

	return parcel;
}

Parcel* ParcelManager::userSelectParcel(string userID)
{
	Parcel* parcel = NULL;
	int noOfParcel = 0, noParcelCollection = 0;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Parcel WHERE user_id = ?");

	ps->setString(1, userID);

	ResultSet* rs = ps->executeQuery();
	
	while (rs->next())
	{
			noOfParcel++;
			parcel = new Parcel();

			parcel->tracking_no = rs->getString(1);
			parcel->status = rs->getString(2);
			parcel->datetime = rs->getString(3);
			parcel->location = rs->getString(4);
			parcel->userID = rs->getString(5);

			cout << "\n	Your " << noOfParcel << "parcel info: " << endl;
			cout << "Tracking No: " << parcel->tracking_no << "." << endl;
			cout << "Status: " << parcel->status << "." << endl;
			cout << "Date & Time: " << parcel->datetime << "." << endl;
			cout << "Location: " << parcel->location << "." << endl;
			cout << "User ID: " << parcel->userID << "." << endl;


			if (parcel->status == "Ready for collection")
				noParcelCollection++;
	}

	cout << "\nThere are " << noOfParcel << " found in your list." << endl;
	cout << "No of parcel READY FOR COLLECTION = " <<noParcelCollection<<endl;

	delete rs;
	delete ps;

	return parcel;
}