//System.cpp
#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "User.h"
#include "UserManager.h"
#include "Admin.h"
#include "AdminManager.h"
#include "Parcel.h"
#include "ParcelManager.h"
#include "Tracking.h"
#include "TrackingManager.h"
#include "Collection.h"
#include "CollectionManager.h"
#include "System.h"

void System::displayUser()
{
	UserManager userManager;
	string userID;
	cout << endl << "*****Display User information*****" << endl;
	cout << "\nPlease enter your userID:" << endl
		<< "User ID:\t";
	cin.get();
	getline(cin, userID);
	User* user = userManager.selectUser(userID);
}

void System::userDisplayUser(string id)
{
	UserManager userManager;
	User* user = userManager.selectUser(id);
}

void System::addUser()
{
	UserManager userManager;
	string userID;
	User* user = new User();

	cout << "Please enter the new user details" << endl
		<< "User ID:\t";
	cin.get();
	getline(cin, user->userID);
	while (user->userID.empty())
	{
		cout <<endl<< "User ID is a mandatory information" << endl;
		cout << "User ID:\t";
		getline(cin, user->userID);
	}
	
	cout << "Firstname:\t";
	getline(cin, user->firstname);
	while (user->firstname.empty())
	{
			cout << endl << "Firstname is a mandatory information" << endl;
			cout << "Firstname:\t";
			getline(cin, user->firstname);
	}

		cout << "Lastname:\t";
		getline(cin, user->lastname);
	while (user->lastname.empty())
	{
			cout << endl << "Lastname is a mandatory information" << endl;
			cout << "Lastname:\t";
			getline(cin, user->lastname);
	}

		cout << "Email:\t";
		getline(cin, user->email);
		while (user->email.empty())
		{
			cout << endl << "Email is a mandatory information" << endl;
			cout << "Email:\t";
			getline(cin, user->email);
		}

		cout << "Faculty:\t";
		getline(cin, user->faculty);
		while (user->faculty.empty())
		{
			cout << endl << "Faculty is a mandatory information" << endl;
			cout << "Faculty:\t";
			getline(cin, user->faculty);
		}

		user->password = user->userID;

		int status = userManager.insertUser(user);

		if (status != 0)
			cout << "Successfully added a new user." << endl;
		else
			cout << "Unable to add a new user." << endl;
}

void System::userUpdateUser(string id)
{
	UserManager userManager;
	string userID;
	User* user = new User();
	cout << endl << "*****Update User Information*****" << endl;
	user->userID =id;

	int input;
	cout << "Choose which attributes do you wish to update: " << endl;
	cout << "1. password\n2. phone\n3. residential\n" << endl
		<< "Input: ";
	cin >> input;

	if (input == 1)
	{
		cout << "Please enter the new password" << endl << "Password:\t";
		cin.get();
		getline(cin, user->password);
	}
	else if (input == 2)
	{
		cout << "Please enter the new phone number" << endl << "Phone:\t";
		cin.get();
		getline(cin, user->phone);
	}
	else if (input == 3)
	{
		cout << "Please enter the new residential" << endl << "Residential:\t";
		cin.get();
		getline(cin, user->residential);
	}
	else
		cout << "Invalid input\n";

	int status = userManager.updateUser(user, input);

	if (status != 0)
		cout << "Successfully updated." << endl;
	else
		cout << "Unable to update." << endl;
}

void System::updateUser()
{
	UserManager userManager;
	string userID;
	User* user = new User();
	cout << endl << "*****Update User Information*****" << endl;
	cout << "Please enter the user details to update" << endl
		<< "User ID:\t";
	cin.get();
	getline(cin, user->userID);

	int input;
	cout << "Choose which attributes do you wish to update: " << endl;
	cout << "1. password\n2. phone\n3. residential\n" << endl
		<< "Input: ";
	cin >> input;

	if (input == 1)
	{
		cout << "Please enter the new password" << endl << "Password:\t";
		cin.get();
		getline(cin, user->password);
	}
	else if (input == 2)
	{
		cout << "Please enter the new phone number" << endl << "Phone:\t";
		cin.get();
		getline(cin, user->phone);
	}
	else if (input == 3)
	{
		cout << "Please enter the new residential" << endl << "Residential:\t";
		cin.get();
		getline(cin, user->residential);
	}
	else
		cout << "Invalid input\n";

	int status = userManager.updateUser(user, input);

	if (status != 0)
		cout << "Successfully updated." << endl;
	else
		cout << "Unable to update." << endl;
}

void System::displayAdmin()
{
	AdminManager adminManager;
	string adminID;
	
	cout << endl << "*****Display administrator information*****" << endl;
	cout << "\nPlease enter the administrator you want to search:" << endl
		<< "Admin ID:\t";
	cin.get();
	getline(cin, adminID);

	Admin* admin = adminManager.selectAdmin(adminID);
	cout << endl;
}

void System::addAdmin()
{
	AdminManager adminManager;
	string adminID;
	cout << endl << "*****Add New Administrator Information*****" << endl;
	Admin* admin = new Admin();

	cout << "Please enter the new admin details" << endl
		<< "Admin ID:\t";
	cin.get();
	getline(cin, admin->adminID);
	while (admin->adminID.empty())
	{
		cout << endl << "Admin ID is a mandatory information" << endl;
		cout<< "Admin ID:\t";
		getline(cin, admin->adminID);
	}

	cout << "Firstname:\t";
	getline(cin, admin->firstname);
	while (admin->firstname.empty())
	{
		cout << endl << "Firstname is a mandatory information" << endl;
		cout << "Firstname:\t";
		getline(cin, admin->firstname);
	}

	cout << "Lastname:\t";
	getline(cin, admin->lastname);
	while (admin->lastname.empty())
	{
		cout << endl << "Lastname is a mandatory information" << endl;
		cout << "Lastname:\t";
		getline(cin, admin->lastname);
	}

	cout << "Email:\t";
	getline(cin, admin->email);
	while (admin->email.empty())
	{
		cout << endl << "Email is a mandatory information" << endl;
		cout << "Email:\t";
		getline(cin, admin->email);
	}

	cout << "Password:\t";
	getline(cin, admin->password);
	while (admin->password.empty())
	{
		cout << endl << "Password is a mandatory information" << endl;
		cout << "Password:\t";
		getline(cin, admin->password);
	}

	cout << "Phone:\t";
	getline(cin, admin->phone);
	while (admin->phone.empty())
	{
		cout << endl << "Phone is a mandatory information" << endl;
		cout << "Phone:\t";
		getline(cin, admin->phone);
	}

	int status = adminManager.insertAdmin(admin);

	if (status != 0)
		cout << "Successfully added a new admin." << endl;
	else
		cout << "Unable to add a new admin." << endl;
}

void System::updateAdmin()
{
	AdminManager adminManager;
	string adminID;
	cout << endl << "*****Update Administrator Information*****" << endl;
	Admin* admin = new Admin();
	cout << "Please enter the admin details to update" << endl
		<< "Admin ID:\t";
	cin.get();
	getline(cin, admin->adminID);

	int input;
	cout << "Choose which attributes do you wish to update: " << endl;
	cout << "1. password\n2. phone\n" << endl
		<< "Input: ";
	cin >> input;

	if (input == 1)
	{
		cout << "Please enter the new password" << endl << "Password:\t";
		cin.get();
		getline(cin, admin->password);
	}
	else if (input == 2)
	{
		cout << "Please enter the new phone number" << endl << "Phone:\t";
		cin.get();
		getline(cin, admin->phone);
	}
	else
		cout << "Invalid input\n";

	int status = adminManager.updateAdmin(admin, input);

	if (status != 0)
		cout << "Successfully updated." << endl;
	else
		cout << "Unable to update." << endl;
}

void System::displayParcel()
{
	ParcelManager parcelManager;
	string tracking_no;
	cout << endl << "*****Display parcel information*****" << endl;
	cout << "\nPlease enter the parcel you want to search:" << endl
		<< "Tracking_no:\t";
	cin.get();
	getline(cin, tracking_no);

	Parcel* parcel = parcelManager.selectParcel(tracking_no);
	cout << endl;
}

void System::userDisplayParcel(string id)
{
	ParcelManager parcelManager;
	Parcel* parcel = parcelManager.userSelectParcel(id);
	cout << endl;
}

void System::addParcel(string id)
{
	ParcelManager parcelManager;
	string tracking_no;
	Parcel* parcel = new Parcel();

	cout << endl << "*****Add New Parcel Information*****" << endl;
	cout << "Please enter the new parcel details" << endl
		<< "Tracking number:\t";
	cin.get();
	getline(cin, parcel->tracking_no);
	while (parcel->tracking_no.empty())
	{
		cout << endl << "Tracking number is a mandatory information" << endl;
		cout << "Tracking number:\t";
		getline(cin, parcel->tracking_no);
	}

	cout << "Status(Arrived University Mail Office/ Ready for collection/ Collected)\t";
	getline(cin, parcel->status);
	while (parcel->status.empty())
	{
		cout << endl << "Status is a mandatory information" << endl;
		cout << "Status(Arrived University Mail Office/ Ready for collection/ Collected):\t";
		getline(cin, parcel->status);
	}

	cout << "Datetime(Format LIKE '2020-10-31 17:24:35', 'YYYY-MM-DD HH24:MI:SS'):\t ";
	getline(cin, parcel->datetime);
	while (parcel->datetime.empty())
	{
		cout << endl << "Datetime is a mandatory information" << endl;
		cout << "Datetime(Format LIKE '2020-10-31 17:24:35', 'YYYY-MM-DD HH24:MI:SS'):\t ";
		getline(cin, parcel->datetime);
	}

	cout << "Location:\t";
	getline(cin, parcel->location);
	while (parcel->location.empty())
	{
		cout << endl << "Location is a mandatory information" << endl;
		cout << "Location:\t";
		getline(cin, parcel->location);
	}

	cout << "UserID:\t";
	getline(cin, parcel->userID);
	while (parcel->userID.empty())
	{
		cout << endl << "UserID is a mandatory information" << endl;
		cout << "UserID:\t";
		getline(cin, parcel->userID);
	}

	int status = parcelManager.insertParcel(parcel, id);

	if (status != 0)
		cout << "Successfully added a new parcel." << endl;
	else
		cout << "Unable to add a new parcel." << endl;
}

void System::updateParcel(string id)
{
	ParcelManager parcelManager;
	string tracking_no;
	Parcel* parcel = new Parcel();
	cout << endl << "*****Update Parcel Information*****" << endl;
	cout << "Please enter the parcel details to update" << endl
		<< "Tracking number:\t";
	cin.get();
	getline(cin, parcel->tracking_no);

	cout << "Status(Arrived University Mail Office/ Ready for collection/ Collected):\t";
	getline(cin, parcel->status);

	cout << "Please enter the updated datetime" << endl << "Datetime(Format LIKE '2020-10-31 17:24:35', 'YYYY-MM-DD HH24:MI:SS'):\t";
	getline(cin, parcel->datetime);
	
	cout << "Please enter the updated location" << endl << "Location:\t";
	getline(cin, parcel->location);
	

	int status = parcelManager.updateParcel(parcel, id);

	if (status == 0)
		cout << "Unable to update." << endl;
}

void System::displayTracking()

{
	string tracking_no;
	TrackingManager trackingManager;
	cout << endl << "*****Display tracking information*****" << endl;
	cout << "\nPlease enter the tracking you want to search:" << endl
		<< "Tracking_no:\t";
	cin.get();
	getline(cin, tracking_no);

	Tracking* tracking = trackingManager.selectTracking(tracking_no);
	cout << endl;
}




void System::deleteCollection()
{
	CollectionManager collectionManager;
	int collectionNum;
	string tracking_no;
	cout << endl << "*****Delete collection information*****" << endl;
	cout << "\nPlease enter your collection tracking number for deletion:" << endl
		<< "Tracking Number:\t";
	cin.get();
	getline(cin, tracking_no);

	int status = collectionManager.deleteCollection(tracking_no);

	if (status == 0)
		cout << "Unable to update." << endl;
}

void System::displayCollection()
{
	CollectionManager collectionManager;
	int collectionNum;
	string tracking_no;
	cout << endl << "*****Display collection information*****" << endl;
	cout << "\nPlease enter your collection tracking number:" << endl
		<< "Tracking Number:\t";
	cin.get();
	getline(cin, tracking_no);

	Collection* collection = collectionManager.selectCollection(tracking_no);
}

void System::userDisplayCollection(string id)
{
	CollectionManager collectionManager;
	Collection* collection = collectionManager.userSelectCollection(id);
}

void System::addCollection()
{
	CollectionManager collectionManager;
	int collectionNum, collectionNo;
	string tracking_no;
	Collection* collection = new Collection();
	cout << endl << "*****Add New Collection Information*****" << endl;
	cout << "Please enter the new collection details" << endl;

	cout << "Collection number:\t";
	cin >> collection->collectionNum;
	/*
	while (collection->collectionNum == NULL)
	{
		cout << endl << "Collection number is a mandatory information" << endl;
		cout << "Collection number:\t";
		cin >> collectionNo;
	}
	collection->collectionNum = collectionNo;
*/

	cout << "Recipient firstname:\t";
	cin.get();
	getline(cin, collection->recipient_fname);
	while (collection->recipient_fname.empty())
	{
		cout << endl << "Recipient firstname is a mandatory information" << endl;
		cout << "Recipient firstname:\t";
		getline(cin, collection->recipient_fname);
	}


	cout << "Recipient lastname:\t";
	getline(cin, collection->recipient_lname);
	while (collection->recipient_lname.empty())
	{
		cout << endl << "Recipient lastname is a mandatory information" << endl;
		cout << "Recipient lastname:\t";
		getline(cin, collection->recipient_lname);
	}

	cout << "UserID:\t";
	getline(cin, collection->userID);
	while (collection->userID.empty())
	{
		cout << endl << "UserID is a mandatory information" << endl;
		cout << "UserID:\t";
		getline(cin, collection->userID);
	}

	cout << "Datetime(Format LIKE '2020-10-31 17:24:35', 'YYYY-MM-DD HH24:MI:SS'):\t ";
	getline(cin, collection->datetime);
	while (collection->datetime.empty())
	{
		cout << endl << "Datetime is a mandatory information" << endl;
		cout << "Datetime(Format LIKE '2020-10-31 17:24:35', 'YYYY-MM-DD HH24:MI:SS'):\t ";
		getline(cin, collection->datetime);
	}

	cout << "Location:\t";
	getline(cin, collection->location);
	while (collection->location.empty())
	{
		cout << endl << "Location is a mandatory information" << endl;
		cout << "Location:\t";
		getline(cin, collection->location);
	}

	cout << "Signature:\t";
	getline(cin, collection->signature);
	while (collection->signature.empty())
	{
		cout << endl << "Signature is a mandatory information" << endl;
		cout << "Signature:\t";
		getline(cin, collection->signature);
	}

	cout << "AdminID:\t";
	getline(cin, collection->adminID);
	while (collection->adminID.empty())
	{
		cout << endl << "AdminID is a mandatory information" << endl;
		cout << "AdminID:\t";
		getline(cin, collection->adminID);
	}

	cout << "Tracking_no:\t";
	getline(cin, collection->tracking_no);
	while (collection->tracking_no.empty())
	{
		cout << endl << "Tracking_no is a mandatory information" << endl;
		cout << "Tracking_no:\t";
		getline(cin, collection->tracking_no);
	}

	int status = collectionManager.insertCollection(collection);

	if (status != 0)
		cout << "Successfully added a new collection." << endl;
	else
		cout << "Unable to add a new collection." << endl;
}

void System::updateCollection()
{
	CollectionManager collectionManager;
	int collectionNum;
	string tracking_no;
	Collection* collection = new Collection();
	cout << endl << "*****Update Collection Information*****" << endl;
	cout << "Please enter the collection details to update" << endl
		<< "Tracking number:\t";
	cin.get();
	getline(cin, collection->tracking_no);

	int input;
	cout << "Choose which attributes do you wish to update: " << endl;
	cout << "1. recipient firstname\n2. recipient lastname\n3. Datetime\n4. Location\n" << endl
		<< "Input: ";
	cin >> input;

	if (input == 1)
	{
		cout << "Please enter the updated recipient_fname" << endl << "Recipient firstname:\t";
		cin.get();
		getline(cin, collection->recipient_fname);
	}
	if (input == 2)
	{
		cout << "Please enter the updated recipient_lname" << endl << "Recipient lastname:\t";
		cin.get();
		getline(cin, collection->recipient_lname);
	}
	else if (input == 3)
	{
		cout << "Please enter the updated datetime" << endl << "Datetime(Format LIKE '2020-10-31 17:24:35', 'YYYY-MM-DD HH24:MI:SS'):\t";
		cin.get();
		getline(cin, collection->datetime);
	}
	else if (input == 4)
	{
		cout << "Please enter the updated location" << endl << "Location:\t";
		cin.get();
		getline(cin, collection->location);
	}
	else
		cout << "Invalid input\n";

	int status = collectionManager.updateCollection(collection, input);

	if (status != 0)
		cout << "Successfully updated." << endl;
	else
		cout << "Unable to update." << endl;
}