#ifndef MYTREE_H_
#define MYTREE_H_

#include <QString>
#include <QVector>

#include "MyNode.h"
#include "MyFolder.h"
#include "MyFile.h"

class MyTree
{
private:
	MyNode* rootNode;  // Zhe Ke Shu de Gen Jie Dian
	MyNode* currentNode;
	QVector<QString*>* currentPath;  // lu jing

public :
	MyTree();
	MyTree(MyNode *mRoot);
	~MyTree();
	MyNode *getCurNode();  //

	// ji de delete !!!!!
	// ji de delete  !!!
	//                !
	// ���ص�vectorҪɾ��������
	QVector<MyNode*> *getCurChild();  // huo de dang qian lu jing xia zi jie dian 

	bool goBack();         // ������һ��·��

	QVector<QString*> *getCurPath()const;  // ���ص�ǰ·��

	bool enterCD(QVector<QString*> *mPath);  //cd: root/...

	bool enterChild(MyNode *node);  // jin ru xia yi ji lu jing

	bool insertNode(MyNode* node);  // zai dang qian lu jing xia zeng jia jie dian

	bool deleteNode(QString* mName); // zai dang qian lu jing xia shan chu jie dian


	// Hai Wei Shi Xian !!!!!!!!!!!
	bool copyNode(MyNode* target, MyNode pasteFather);  // ��target���Ƶ�pasteFather·���� ��ûд������

};

#endif