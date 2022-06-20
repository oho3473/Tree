#include<iostream>
#include "BinarySearchTree.h"



int main()
{

	mysearchtree::BinarySearchTree bst;

	auto pBRoot = bst.Insert(nullptr, 8);
	bst.Insert(pBRoot, 3);
	bst.Insert(pBRoot, 10);
	bst.Insert(pBRoot, 1);
	bst.Insert(pBRoot, 6);


	bst.Erase(pBRoot, 8);
	bst.InOrder(pBRoot);
	std::cout << std::endl;


	bst.Insert(bst.GetNode(), 8);
	bst.Insert(bst.GetNode(), 3);
	bst.Insert(bst.GetNode(), 10);
	bst.Insert(bst.GetNode(), 1);
	bst.Insert(bst.GetNode(), 6);

	bst.InOrder(bst.GetNode());
	std::cout << std::endl;
	std::cout << std::boolalpha << bst.FindData(3);
	bst.Erase(1);
	bst.InOrder(bst.GetNode());

	

	

}