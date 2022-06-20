#include<iostream>
#include"BinaryTree.h"



int main()
{
	mytree::BinaryTree myTree;

	auto pRoot = myTree.GetNode();
	pRoot->mData = 1;

	auto pNode = myTree.InsertLeft(pRoot, 2);
	myTree.InsertLeft(pNode, 4);
	myTree.InsertRight(pNode, 5);

	pNode = myTree.InsertRight(pRoot, 3);
	myTree.InsertLeft(pNode, 6);
	myTree.InsertRight(pNode, 7);

	std::cout << "----In Order----" << std::endl;
	myTree.InOrder(pRoot);
	std::cout << std::endl << "----Pre Order----" << std::endl;
	myTree.PreOrder(pRoot);
	std::cout << std::endl << "----Post Order----" << std::endl;
	myTree.PostOrder(pRoot);



}