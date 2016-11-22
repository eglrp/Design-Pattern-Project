#ifndef FILEFACTORY_H_
#define FILEFACTORY_H_

#include "FreeTable.h"
#include "MyFile.h"
#include "MyNode.h"
#include "MyFolder.h"

class FileFactory
{
private:
	FreeTable *mFreeTable;
	static FileFactory* instance;

public:
	FileFactory();
	~FileFactory();
	void onOpen();
	// void initialize();
	static FileFactory* getInstance();
	MyNode* createFile(int mLength,QString *mName);
	bool deleteFile(MyNode* mNode);
	void onClose();

};

#endif // !1
