#pragma once


class Node
{
public:
	Node()
		:m_Depth(0), m_Key(0), m_Value(nullptr), mptr_Left(nullptr), mptr_Right(nullptr)
	{};

	Node(int *Value, int height)
		:Node()
	{
		m_Depth = height;
		m_Value = Value;
	}
	~Node()
	{};
	//! to be control when i destroy the tree 
	void TerminateAllNodes();

	void SetValue(int *Value);

	void SetLeftNode(int * Value);
	void SetRightNode(int * Value);
	// overloads 
	void SetLeftNode(Node *node);
	void SetRightNode(Node *node);

	void PrintValue();
	// itself and children
	void PrintAll();

	Node *GetRightNode();
	Node *GetLeftNode();
	int GetValue() const;

	int m_Depth;
	int m_Key;
	int *m_Value;
	Node *mptr_Left;
	Node *mptr_Right;
	//! the parent node 
	Node *mptr_Prev;
};

