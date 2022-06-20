#include"BinaryTree.h"

void mytree::BinaryTree::BreadthFirst()
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

void mytree::BinaryTree::DepthFirst()
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

void mytree::BinaryTree::RecursiveDepthFirst(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	Visit(pNode);
	RecursiveDepthFirst(pNode->mLeft);
	RecursiveDepthFirst(pNode->mRight);
}

void mytree::BinaryTree::InOrder(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	InOrder(pNode->mLeft);
	Visit(pNode);
	InOrder(pNode->mRight);
}

void mytree::BinaryTree::PreOrder(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	Visit(pNode);
	PreOrder(pNode->mLeft);
	PreOrder(pNode->mRight);
}

void mytree::BinaryTree::PostOrder(Node* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	PostOrder(pNode->mLeft);
	PostOrder(pNode->mRight);
	Visit(pNode);
}

int mytree::BinaryTree::Sum(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return Sum(node->mLeft) + node->mData + Sum(node->mRight);
}

bool mytree::BinaryTree::FindData(Node* pNode, int value)
{
	if (pNode == nullptr)
	{
		return false;
	}

	return (pNode->mData == value) || FindData(pNode->mLeft, value) || FindData(pNode->mRight, value);
}

