#include "FileFactory.h"

FileFactory* FileFactory::instance;

FileFactory::FileFactory()
{
	mFreeTable = new FreeTable();
	mFreeTable->open();
}

FileFactory *FileFactory::getInstance()
{
	if (instance)
		return instance;
	instance = new FileFactory();
	return instance;
}

FileFactory::~FileFactory()
{
	if (mFreeTable)
		delete mFreeTable;
}

void FileFactory::onClose()
{
	if (!instance)
		return;
	mFreeTable->save();
	delete instance;
	return;
}

MyNode* FileFactory::createFile(int mLength, QString* mName)
{
	MyNode* mNode;
	if (mLength)
	{
		int base = mFreeTable->createFile(mLength);
		//mNode = new MyFile(mName, base, mLength);
		mNode = new MyNode(0, mName);
		mNode->setBaseAddr(base);
		mNode->setLength(mLength);
	}
	else
		mNode = new MyNode(1, mName);
	return mNode;
}

bool FileFactory::deleteFile(MyNode* mNode)
{
	if (mNode->getType())
	{
		delete mNode;
		return 1;
	}
	bool result = mFreeTable->deleteFile(mNode->getBaseAddr(), mNode->getLength());
	if (result)
		delete mNode;
	return result;
	//return mFreeTable->deleteFile(mBaseAddr, mLength);
}

