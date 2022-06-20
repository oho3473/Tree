#include "BinarySearchTree.h"

void mysearchtree::BinarySearchTree::BreadthFirst()
{
	std::queue<Node*> queue;
	queue.push(mpRoot);

	while (!queue.empty())
	{
		auto node = queue.front();
		Visit(node);
		queue.pop();
		if (node->mLeft != nullptr)
		{
			queue.push(node->mLeft);
		}

		if (node->mRight != nullptr)
		{
			queue.push(node->mRight);
		}
	}
}

void mysearchtree::BinarySearchTree::DepthFirst()
{
	std::stack<Node*> stack;

	stack.push(mpRoot);

	while (!stack.empty())
	{
		auto node = stack.top();
		Visit(node);
		stack.pop();
		if (node->mRight != nullptr)
		{
			stack.push(node->mRight);
		}

		if (node->mLeft != nullptr)
		{
			stack.push(node->mLeft);
		}
	}
}

void mysearchtree::BinarySearchTree::RecursiveDepthFirst(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	Visit(pNode);
	RecursiveDepthFirst(pNode->mLeft);
	RecursiveDepthFirst(pNode->mRight);
}

void mysearchtree::BinarySearchTree::InOrder(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	InOrder(pNode->mLeft);
	Visit(pNode);
	InOrder(pNode->mRight);
}

void mysearchtree::BinarySearchTree::PreOrder(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	Visit(pNode);
	PreOrder(pNode->mLeft);
	PreOrder(pNode->mRight);
}

void mysearchtree::BinarySearchTree::PostOrder(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	PostOrder(pNode->mLeft);
	PostOrder(pNode->mRight);
	Visit(pNode);
}

int mysearchtree::BinarySearchTree::Sum(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return Sum(node->mLeft) + node->mData + Sum(node->mRight);
}

bool mysearchtree::BinarySearchTree::FindData(int value)
{
	auto node = this->GetNode();

	while (node != nullptr)
	{
		if (node->mData < value)
		{
			node = node->mRight;
		}
		else if (node->mData > value)
		{
			node = node->mLeft;
		}
		else if (node->mData == value)
		{
			std::cout << "값을 찾았습니다" << std::endl;
			return true;
		}
		else
		{
			break;
		}
	}
	std::cout << "값이 없습니다" << std::endl;
	return false;
}

bool mysearchtree::BinarySearchTree::FindData(Node* node, int value)
{
	//TODO

	while (node != nullptr)
	{
		if (node->mData < value)
		{
			node = node->mRight;
		}
		else if (node->mData > value)
		{
			node = node->mLeft;
		}
		else if (node->mData == value)
		{
			std::cout << "값을 찾았습니다" << std::endl;
			return true;
		}
		else
		{
			break;
		}
	}
	std::cout << "값이 없습니다" << std::endl;
	return false;
}

void mysearchtree::BinarySearchTree::Erase(int value)
{
	auto node = this->GetNode();
	EraseSquence(node, value);
}

void mysearchtree::BinarySearchTree::Erase(Node* node, int value)
{
	EraseSquence(node, value);
}




