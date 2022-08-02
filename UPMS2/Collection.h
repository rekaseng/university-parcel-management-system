//Collection.h
#pragma once
#include <string>
using namespace std;

#ifndef COLLECTION_H
#define COLLECTION_H

class Collection
{
public:
	int collectionNum;
	string tracking_no, signature, location, datetime, adminID, recipient_fname, recipient_lname,
		userID;
};

#endif