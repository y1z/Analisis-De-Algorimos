#include "Node.h"
#include <iostream>
// post-order 
void Node::TerminateAllNodes()
{
	// remove all the children first 
	if (mptr_Left != nullptr)
	{
		mptr_Left->TerminateAllNodes();
		mptr_Left = nullptr;
	}

	if (mptr_Right != nullptr)
	{
		mptr_Right->TerminateAllNodes();
		mptr_Right = nullptr;
	}
	// remove the value 
	if (m_Value != nullptr)
	{
		delete m_Value;
		m_Value = nullptr;
	}
	// 
	delete this;
}

void Node::SetValue(int * Value)
{
	this->m_Value = Value;
}

void Node::SetLeftNode(int * Value)
{
	Node *NewNode = new Node(Value, this->m_Depth + 1);

	NewNode->mptr_Prev = this;

	mptr_Left = NewNode;
}

void Node::SetRightNode(int * Value)
{
	Node *NewNode = new Node(Value, this->m_Depth + 1);

	NewNode->mptr_Prev = this;

	mptr_Right = NewNode;
}

void Node::SetLeftNode(Node * node)
{
	mptr_Left = node;
	mptr_Left->mptr_Prev = this;
}

void Node::SetRightNode(Node * node)
{
	mptr_Right = node;
	mptr_Right->mptr_Prev = this;
}

void Node::PrintValue()
{
	std::cout <<'{'<< *m_Value << '}';
}

void Node::PrintAll()
{
	if (mptr_Left != nullptr)
	{
		mptr_Left->PrintAll();
	}
	std::cout <<'{'<<*m_Value << '}';
	
	if (mptr_Right != nullptr)
	{
		mptr_Right->PrintAll();
	}


}

Node * Node::GetRightNode()
{
	return mptr_Right;
}

Node * Node::GetLeftNode()
{
	return mptr_Left;
}

int Node::GetValue() const
{
	return *m_Value;
}
