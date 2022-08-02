//ParcelManager.h
#pragma once
#ifndef PARCELMANAGER_H
#define PARCELMANAGER_H

class ParcelManager
{
public:
	int insertParcel(Parcel* parcel, string id);
	int updateParcel(Parcel* parcel, string id);
	Parcel* selectParcel(string tracking_no);
	Parcel* userSelectParcel(string userID);
};

#endif // !PARCELMANAGER_H
