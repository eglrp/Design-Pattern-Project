#include "FileIterator.h"

FileIterator::FileIterator(MyNode* mNode)
{
	mVector = new QVector<MyNode*>();
	if (mNode == NULL)
		return;
	rootNode = curNode = mNode;
	mVector->push_back(mNode);
}

bool FileIterator::hasNext()
{
	if (!mVector->isEmpty())
		return true;
	return false;
}

MyNode* FileIterator::next()
{
	if (mVector->isEmpty())
		return NULL;
	MyNode* result = mVector->last();
	mVector->pop_back();
	MyNode* ptr = result->getChild();
	while (ptr)
	{
		mVector->push_back(ptr);
		ptr = ptr->getNext();
	}
	curNode = result;
	return result;
}

MyNode* FileIterator::getCurNode()
{
	return curNode;
}

bool FileIterator::remove()
{
	bool result = FileManager::getInstance()->deleteFile(curNode);
	return result;
}

bool FileIterator::operator==(const FileIterator& rhs)
{
	return curNode == rhs.curNode;
}

bool FileIterator::operator!=(const FileIterator& rhs)
{
	return curNode != rhs.curNode;
}

FileIterator& FileIterator::operator++()
{
	if (hasNext() && !mVector->isEmpty())
	{
		MyNode* result = mVector->last();
		mVector->pop_back();
		MyNode* ptr = result->getChild();
		while (ptr)
		{
			mVector->push_back(ptr);
			ptr = ptr->getNext();
		}
		curNode = result;
	}
	return *this;
}

