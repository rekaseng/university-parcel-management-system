//TrackingManager.cpp
#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Tracking.h"
#include "TrackingManager.h"


Tracking* TrackingManager::selectTracking(string tracking_no)
{
	Tracking* tracking = NULL;
	int noOfTracking = 0;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Tracking WHERE tracking_no = ?");

	ps->setString(1, tracking_no);

	ResultSet* rs = ps->executeQuery();

	while (rs->next())
	{
		noOfTracking++;
		tracking = new Tracking();

		tracking->status = rs->getString(1);
		tracking->adminID = rs->getString(2);
		tracking->tracking_no = rs->getString(3);
		tracking->datetime = rs->getString(4);
		tracking->location = rs->getString(5);

		cout << endl<<"  "<<tracking_no<<" "<< noOfTracking << "Tracking info: " << endl;
		cout << "Status: " << tracking->status << "." << endl;
		cout << "Date & Time: " << tracking->datetime << "." << endl;
		cout << "Location: " << tracking->location << "." << endl;
		cout << "Admin ID: " << tracking->adminID << "." << endl;

	}

	cout << "\nThere are " << noOfTracking << " tracking info found." << endl;
	delete rs;
	delete ps;

	return tracking;
}