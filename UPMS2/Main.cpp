#include <iostream>
#include <string>
#include <cctype>
using namespace std;

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
#include "LoginManager.h"
#include "System.h"

int main()
{
	UserManager userManager;
	string userID;
	AdminManager adminManager;
	string adminID;
	ParcelManager parcelManager;
	string tracking_no;
	TrackingManager trackingManager;
	CollectionManager collectionManager;
	int collectionNum;
	LoginManager loginManager;
	System system;
	int userOption = 0;
	int adminOption = 0;
	int option = 0;
	int data = 0;
	int userPage = 0, adminPage = 0;
	


	cout << endl << "************Universiti Teknikal Malaysia Melaka*********************" << endl << endl;
	cout << "\tUniversity Parcel Management System\t\t" << endl << endl;

	string id = loginManager.login();

	char firstletter = id.at(0);

	while (firstletter != 'A' && firstletter != 'a' && firstletter != 'B' && firstletter != 'b')
	{
		id = loginManager.login();
	}

	while (firstletter == 'B' || firstletter == 'b')
	{
		cout << endl << "*****User Homepage*****" << endl;
		cout << "1. Display User Information\n2. Display administrator information\n3. Display parcel information\n"
			<< "4. Display tracking information\n5. Display collection information\n6. Update user information\n7. Logout" << endl;
		cout << "Option: ";
		cin >> userOption;

		//error handling when user didnt enter correct userOption 
		while (userOption != 1 && userOption != 2 && userOption != 3 && userOption != 4 && userOption != 5 && userOption != 6 && userOption != 7)
		{
			cout << "Invalid input" << endl;
			cout << endl << "*****User Homepage*****" << endl;
			cout << "1. Display User Information\n2. Display administrator information\n3. Display parcel information\n"
				<< "4. Display tracking information\n5. Display collection information\n6. Update user information\n7. Logout" << endl;
			cout << "Option: ";
			cin >> userOption;
		}

		//userOption 1: Display User Information
		while (userOption == 1)
		{
			system.userDisplayUser(id);
			cout << "\nWhich page do you wish to proceed?" << endl;
			cout << "1. Display User Information\n2. User Homepage\n3. Logout\nPage: ";
			cin >> userPage;
			if (userPage == 1)
			{
				userOption = 1;
			}
			else if (userPage == 2)
			{
				firstletter = 'B';
				userOption = 0;
			}
			else if (userPage == 3)
				return 0;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Display User Information\n2. User Homepage\n3. Logout\nPage: ";
				cin >> userPage;
			}
		}
		while (userOption == 2)
		{
			system.displayAdmin();
			cout << "Which page do you wish to proceed?" << endl;
			cout << "1. Display administrator Information\n2. User Homepage\n3. Logout\nPage: ";
			cin >> userPage;
			if (userPage == 1)
			{
				userOption = 2;
			}
			else if (userPage == 2)
			{
				firstletter = 'B';
				userOption = 0;
			}
			else if (userPage == 3)
				return 0;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "Which page do you wish to proceed?" << endl;
				cout << "1. Display administrator Information\n2. User Homepage\n3. Logout\nPage: ";
				cin >> userPage;
			}
		}
		while (userOption == 3)
		{
			system.userDisplayParcel(id);
			cout << "Which page do you wish to proceed?" << endl;
			cout << "1. Display parcel Information\n2. User Homepage\n3. Logout\nPage: ";
			cin >> userPage;
			if (userPage == 1)
			{
				userOption = 3;
			}
			else if (userPage == 2)
			{
				firstletter = 'B';
				userOption = 0;
			}
			else if (userPage == 3)
				return 0;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "Which page do you wish to proceed?" << endl;
				cout << "1. Display parcel Information\n2. User Homepage\n3. Logout\nPage: ";
				cin >> userPage;
			}
		}
		while (userOption == 4)
		{
			system.displayTracking();
			cout << "Which page do you wish to proceed?" << endl;
			cout << "1. Display tracking Information\n2. User Homepage\n3. Logout\nPage: ";
			cin >> userPage;
			if (userPage == 1)
			{
				userOption = 4;
			}
			else if (userPage == 2)
			{
				firstletter = 'B';
				userOption = 0;
			}
			else if (userPage == 3)
				return 0;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "Which page do you wish to proceed?" << endl;
				cout << "1. Display tracking Information\n2. User Homepage\n3. Logout\nPage: ";
				cin >> userPage;
			}
		}
		while (userOption == 5)
		{
			system.userDisplayCollection(id);
			cout << "\nWhich page do you wish to proceed?" << endl;
			cout << "1. Display collection Information\n2. User Homepage\n3. Logout\nPage: ";
			cin >> userPage;
			if (userPage == 1)
			{
				userOption = 5;
			}
			else if (userPage == 2)
			{
				firstletter = 'B';
				userOption = 0;
			}
			else if (userPage == 3)
				return 0;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Display collection Information\n2. User Homepage\n3. Logout\nPage: ";
				cin >> userPage;
			}
		}
		while (userOption == 6)
		{
			system.userUpdateUser(id);
			cout << "\nWhich page do you wish to proceed?" << endl;
			cout << "1. Update user Information\n2. User Homepage\n3. Logout\nPage: ";
			cin >> userPage;
			if (userPage == 1)
			{
				userOption = 6;
			}
			else if (userPage == 2)
			{
				firstletter = 'B';
				userOption = 0;
			}
			else if (userPage == 3)
				return 0;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Update user Information\n2. User Homepage\n3. Logout\nPage: ";
				cin >> userPage;
			}

		}
		while (userOption == 7)
			return 0;

	}

	while (firstletter == 'A'|| firstletter == 'a')
	{
		cout << endl << "*****Administrator Homepage*****" << endl;
		cout << "Data to add/update/display:\n1. User\n2. Administrator\n3. Parcel\n4. Tracking\n5. Collection\n6. Logout" << endl;
		cout << "Data :";
		cin >> data;
		cout << endl;
		while (data != 1 && data != 2 && data != 3 && data != 4 && data != 5 && data != 6)
		{
			cout << "Invalid input!" << endl;
			cout << endl << "*****Administrator Homepage*****" << endl;
			cout << "Data to add/update/display:\n1. User\n2. Administrator\n3. Parcel\n4. Tracking\n5. Collection\n6. Logout" << endl;
			cout << "Data :";
			cin >> data;
			cout << endl;
		}
		while (data == 1)
		{
			cout << endl << "*****User Info Page*****" << endl;
			cout << "1. Add New User Information" << endl;
			cout << "2. Update User Information" << endl;
			cout << "3. Display User Information" << endl;
			cout << "4. Administrator Homepage" << endl;
			cout << "5. Logout" << endl;
			cout << "Option: ";
			cin >> adminOption;
			while (adminOption != 1 && adminOption != 2 && adminOption != 3 && adminOption != 4 && adminOption != 5)
			{
				cout << "Invalid input!" << endl;
				cout << endl << "*****User Info Page*****" << endl;
				cout << "1. Add New User Information" << endl;
				cout << "2. Update User Information" << endl;
				cout << "3. Display User Information" << endl;
				cout << "4. Administrator Homepage" << endl;
				cout << "5. Logout" << endl;
				cout << "Option: ";
				cin >> adminOption;
			}
			while (adminOption == 1)
			{
				system.addUser();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. User Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;

				if (adminPage == 1)
				{
					data = 1; 
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. User Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 2)
			{
				system.updateUser();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. User Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 1;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. User Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 3)
			{
				system.displayUser();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. User Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 1;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. User Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 4)
			{
				data = 0; adminOption = 0; adminPage = 0;
				firstletter = 'A';
			}
			while (adminOption == 5)
				return 0;
		}
		while (data == 2)
		{
			cout << endl << "*****Administrator Info Page*****" << endl;
			cout << "1. Add New Administrator Information" << endl;
			cout << "2. Update Administrator Information" << endl;
			cout << "3. Display Administrator Information" << endl;
			cout << "4. Administrator Homepage" << endl;
			cout << "5. Logout" << endl;
			cout << "Option: ";
			cin >> adminOption;
			while (adminOption != 1 && adminOption != 2 && adminOption != 3 && adminOption != 4 && adminOption != 5)
			{
				cout << "Invalid input!" << endl;
				cout << endl << "*****Administrator Info Page*****" << endl;
				cout << "1. Add New Administrator Information" << endl;
				cout << "2. Update Administrator Information" << endl;
				cout << "3. Display Administrator Information" << endl;
				cout << "4. Administrator Homepage" << endl;
				cout << "5. Logout" << endl;
				cout << "Option: ";
				cin >> adminOption;
			}
			while (adminOption == 1)
			{
				system.addAdmin();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Administrator Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 2;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Administrator Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 2)
			{
				system.updateAdmin();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Administrator Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 2;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Administrator Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 3)
			{
				system.displayAdmin();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Administrator Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 2;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Administrator Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 4)
			{
				data = 0; adminOption = 0; adminPage = 0;
				firstletter = 'A';
			}
			while (adminOption == 5)
				return 0;
		}
		while (data == 3)
		{
			cout << endl << "*****Parcel Info Page*****" << endl;
			cout << "1. Add New Parcel Information" << endl;
			cout << "2. Update Parcel Information" << endl;
			cout << "3. Display Parcel Information" << endl;
			cout << "4. Administrator Homepage" << endl;
			cout << "5. Logout" << endl;
			cout << "Option: ";
			cin >> adminOption;
			while (adminOption != 1 && adminOption != 2 && adminOption != 3 && adminOption != 4 && adminOption != 5)
			{
				cout << "Invalid input!" << endl;
				cout << endl << "*****Parcel Info Page*****" << endl;
				cout << "1. Add New Parcel Information" << endl;
				cout << "2. Update Parcel Information" << endl;
				cout << "3. Display Parcel Information" << endl;
				cout << "4. Administrator Homepage" << endl;
				cout << "5. Logout" << endl;
				cout << "Option: ";
				cin >> adminOption;
			}
			while (adminOption == 1)
			{
				system.addParcel(id);
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Parcel Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 3;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Parcel Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 2)
			{
				system.updateParcel(id);
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Parcel Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 3;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Parcel Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 3)
			{
				system.displayParcel();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Parcel Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 3;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Parcel Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 4)
			{
				data = 0; adminOption = 0; adminPage = 0;
				firstletter = 'A';
			}
			while (adminOption == 5)
				return 0;
		}
		while (data == 4)
		{
			cout << endl << "*****Tracking Info Page*****" << endl;
			cout << "1. Display Tracking Information" << endl;
			cout << "2. Administrator Homepage" << endl;
			cout << "3. Logout" << endl;
			cout << "Option: ";
			cin >> adminOption;
			while (adminOption != 1 && adminOption != 2 && adminOption != 3 )
			{
				cout << "Invalid input!" << endl;
				cout << endl << "*****Tracking Info Page*****" << endl;
				cout << "1. Display Tracking Information" << endl;
				cout << "2. Administrator Homepage" << endl;
				cout << "3. Logout" << endl;
				cout << "Option: ";
				cin >> adminOption;
			}
			while (adminOption == 1)
			{
				system.displayTracking();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Tracking Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 4;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Tracking Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 2)
			{
				data = 0; adminOption = 0; adminPage = 0;
				firstletter = 'A';
			}
			while (adminOption == 3)
				return 0;
		}
		while (data == 5)
		{
			cout << endl << "*****Collection Info Page*****" << endl;
			cout << "1. Add New Collection Information" << endl;
			cout << "2. Update Collection Information" << endl;
			cout << "3. Display Collection Information" << endl;
			cout << "4. Delete Collection Information" << endl;
			cout << "5. Administrator Homepage" << endl;
			cout << "6. Logout" << endl;
			cout << "Option: ";
			cin >> adminOption;
			while (adminOption != 1 && adminOption != 2 && adminOption != 3 && adminOption != 4 && adminOption != 5)
			{
				cout << "Invalid input!" << endl;
				cout << endl << "*****Collection Info Page*****" << endl;
				cout << "1. Add New Collection Information" << endl;
				cout << "2. Update Collection Information" << endl;
				cout << "3. Display Collection Information" << endl;
				cout << "4. Administrator Homepage" << endl;
				cout << "5. Logout" << endl;
				cout << "Option: ";
				cin >> adminOption;
			}
			while (adminOption == 1)
			{
				system.addCollection();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 5;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}

			}
			while (adminOption == 2)
			{
				system.updateCollection();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 5;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 3)
			{
				system.displayCollection();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 5;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				}
			}
			while (adminOption == 4)
			{
				system.deleteCollection();
				cout << "\nWhich page do you wish to proceed?" << endl;
				cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
				cin >> adminPage;
				if (adminPage == 1)
				{
					data = 5;
					adminOption = 0;
					adminPage = 0;
				}
				else if (adminPage == 2)
				{
					data = 0; adminOption = 0; adminPage = 0;
					firstletter = 'A';
				}
				else if (adminPage == 3)
				{
					return 0;
				}
				else
				{
					cout << "Invalid input!" << endl;
					cout << "\nWhich page do you wish to proceed?" << endl;
					cout << "1. Collection Info Page\n2. Administrator Homepage\n3. Logout\nPage: ";
					cin >> adminPage;
				} 
			}
			while (adminOption == 5)
			{
				data = 0; adminOption = 0; adminPage = 0;
				firstletter = 'A';
			}
			while (adminOption == 6)
			{
				return 0;
			}
		}
		while (data == 6)
		{
			return 0;
		}

	}
	return 0;
}

		


		