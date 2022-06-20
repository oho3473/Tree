#pragma once
#include<iostream>
#include<queue>
#include<stack>

namespace mytree
{
	struct Node
	{
		int mData;
		Node* mRight;
		Node* mLeft;

		Node(int data, Node* right, Node* left) : mData{ data }, mRight{ right }, mLeft{ left }
		{

		}

	};

	class BinaryTree
	{
	private:
		Node* mpRoot{};

	public:
		BinaryTree()
		{
			mpRoot = CreateNode(0);
		}

		Node* GetNode()
		{
			return mpRoot;
		}

		Node* CreateNode(int data)
		{
			return new Node(data, nullptr, nullptr);
		}

		Node* InsertLeft(Node* parent, int data)
		{
			parent->mLeft = CreateNode(data);

			return parent->mLeft;
		}

		Node* InsertRight(Node* parent, int data)
		{
			parent->mRight = CreateNode(data);

			return parent->mRight;
		}

		void Visit(Node* node) { std::cout << node->mData << " -> "; }

		void BreadthFirst();
		void DepthFirst();
		void RecursiveDepthFirst(Node* pNode);
		void InOrder(Node* pNode);
		void PreOrder(Node* pNode);
		void PostOrder(Node* pNode);


		int Sum(Node* node);

		bool FindData(Node* pNode, int value);
	};
}