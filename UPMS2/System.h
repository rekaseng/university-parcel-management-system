#pragma once
//System.h
#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

class System
{
public:
	void userDisplayUser(string id);
	void displayUser();
	void addUser();
	void updateUser();
	void displayAdmin();
	void addAdmin();
	void updateAdmin();
	void displayParcel();
	void addParcel(string id);
	void updateParcel(string id);
	void displayTracking();
	void displayCollection();
	void addCollection();
	void updateCollection();
	void userDisplayParcel(string id); 
	void userDisplayCollection(string id);
	void deleteCollection();
	void userUpdateUser(string id);
};

#endif // !SYSTEM_H