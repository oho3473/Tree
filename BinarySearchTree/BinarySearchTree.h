#pragma once
#include<iostream>
#include<queue>
#include<stack>

namespace mysearchtree
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

	class BinarySearchTree
	{
	private:
		Node* mpRoot{};

	public:
		BinarySearchTree()
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

		Node* Insert(Node* node, int data)
		{
			if (node == nullptr)
				return CreateNode(data);

			if (data < node->mData)
				node->mLeft = Insert(node->mLeft, data);
			else if (data > node->mData)
				node->mRight = Insert(node->mRight, data);

			return node;
		}

	private:
		Node* EraseSquence(Node* node, int value)
		{
			if (node == nullptr)
				return node;
			else if (node->mData > value)
				node->mLeft = EraseSquence(node->mLeft, value);
			else if (node->mData < value)
				node->mRight = EraseSquence(node->mRight, value);
			else
			{
				Node* temp = node;

				if (node->mData == value)
				{
					//자식 2개
					if ((node->mLeft != nullptr) & (node->mRight != nullptr))
					{
						temp = SearchMaxNode(node->mLeft);
						node->mData = temp->mData;
						node->mLeft = EraseSquence(node->mLeft, temp->mData);
					}
					//자식 없음
					else if ((node->mLeft == nullptr) & (node->mRight == nullptr))
					{
						delete node;
						node = nullptr;
					}
					//오른쪽 자식
					else if (node->mLeft == nullptr)
					{
						node = node->mRight;
						delete temp;
					}
					//왼쪽 자식
					else if (node->mRight == nullptr)
					{
						node = node->mLeft;
						delete temp;
					}
				}
			}

			return node;
		}

		Node* SearchMaxNode(Node* node)
		{
			if (node == nullptr)
				return nullptr;
			while (node->mRight != nullptr)
			{
				node = node->mRight;
			}

			return node;
		}

		Node* SearchMinNode(Node* node)
		{
			if (node == nullptr)
				return nullptr;
			while (node->mLeft != nullptr)
			{
				node = node->mLeft;
			}

			return node;
		}

	public:
		void Visit(Node* node) { std::cout << node->mData << " -> "; }
		void BreadthFirst();
		void DepthFirst();
		void RecursiveDepthFirst(Node* pNode);
		void InOrder(Node* pNode);
		void PreOrder(Node* pNode);
		void PostOrder(Node* pNode);
		void Erase(int value);
		void Erase(Node* node, int data);

		int Sum(Node* node);

		bool FindData(int value);
		bool FindData(Node* node, int value);


	};
}
