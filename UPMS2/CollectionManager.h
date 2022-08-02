//CollectionManager.h
#pragma once
#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

class CollectionManager
{
public:
	int insertCollection(Collection* collection);
	int updateCollection(Collection* collection, int input);
	Collection* selectCollection(string tracking_no);
	Collection* userSelectCollection(string id);
	int deleteCollection(string tracking_no);
};

#endif // !TRACKINGMANAGER_H