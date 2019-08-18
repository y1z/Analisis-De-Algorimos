#include "BinaryTree.h"
#include "Node.h"

namespace DS {
	// to know if to go right node 
	auto GoToRightNode = [](Node* node, int Value) -> bool
	{
		if (*node->m_Value < Value)
		{
			return true;
		}
		return false;
	};

	auto CheckIsNull = [](Node *node) -> bool
	{
		if (node != nullptr) { return false; }
		return true;
	};

	BinaryTree::BinaryTree()
	{
		m_RootNode = new Node();
	}


	BinaryTree::~BinaryTree()
	{
		m_RootNode->TerminateAllNodes();
	}

	void BinaryTree::SetRootNodeValue(int *value)
	{
		m_RootNode->SetValue(value);
	}

	void BinaryTree::AddNode(int * Value)
	{
		bool SearchingNode = true;

		Node *CurrentNode = m_RootNode;
		// find a place to put the values in the tree 
		while (SearchingNode)
		{
			// check if the value is greater 
			if (CheckIsNull(CurrentNode->GetRightNode()) && GoToRightNode(CurrentNode, *Value))
			{
				CurrentNode->SetRightNode(Value);
				totalNode++;

				break;
			}
			if (CheckIsNull(CurrentNode->GetLeftNode()) && !GoToRightNode(CurrentNode, *Value))
			{
				CurrentNode->SetLeftNode(Value);
				totalNode++;

				break;
			}
			else
			{
				if (GoToRightNode(CurrentNode, *Value))
				{
					CurrentNode = CurrentNode->GetRightNode();
				}
				else
				{
					CurrentNode = CurrentNode->GetLeftNode();
				}
			}
		}
	}

	void BinaryTree::AddNode(Node * node)
	{
		bool SearchingNode = true;

		Node *CurrentNode = m_RootNode;
		// find a place to put the values in the tree 
		while (SearchingNode)
		{
			// check if the value is greater 
			if (CheckIsNull(CurrentNode->GetRightNode()) && GoToRightNode(CurrentNode, node->GetValue()))
			{
				CurrentNode->SetRightNode(node);
				totalNode++;

				break;
			}
			if (CheckIsNull(CurrentNode->GetLeftNode()) && !GoToRightNode(CurrentNode, node->GetValue()))
			{
				CurrentNode->SetLeftNode(node);
				totalNode++;

				break;
			}
			else
			{
				if (GoToRightNode(CurrentNode, node->GetValue()))
				{
					CurrentNode = CurrentNode->GetRightNode();
				}
				else
				{
					CurrentNode = CurrentNode->GetLeftNode();
				}
			}
		}
	}

	void BinaryTree::PrintTree()
	{
		m_RootNode->PrintAll();
	}

	Node * BinaryTree::SearchNode(int Value)
	{
		Node * CurrentNode = m_RootNode;
		while (true)
		{
			if (CurrentNode->GetValue() == Value)
			{
				return CurrentNode;
			}
			else if (GoToRightNode(CurrentNode, Value))
			{
				if (!CheckIsNull(CurrentNode->GetRightNode()))
				{
					CurrentNode = CurrentNode->GetRightNode();
				}
				else
				{
					return nullptr;
				}
			}
			else
			{
				if (!CheckIsNull(CurrentNode->GetLeftNode()))
				{
					CurrentNode = CurrentNode->GetLeftNode();
				}
				else
				{
					return nullptr;
				}
			}

		}

		return nullptr;
	}

	bool BinaryTree::RemoveNode(int Value)
	{
		Node *ptr_TempRight = nullptr;
		Node *ptr_TempLeft = nullptr;

		// find the node in question
		Node *CurrentNode = this->SearchNode(Value);
		if (!CheckIsNull(CurrentNode))
		{
			// Get the child nodes 
			if (CurrentNode->GetLeftNode() != nullptr)
			{
				ptr_TempLeft = CurrentNode->GetLeftNode();
			}
			if (CurrentNode->GetRightNode() != nullptr)
			{
				ptr_TempRight = CurrentNode->GetRightNode();
			}
		}
		else
		{
			return false;
		}

		Node* Parent = CurrentNode->mptr_Prev;
		if (Parent->GetLeftNode() == CurrentNode)
		{
			Parent->mptr_Left = nullptr;
		}
		else if (Parent->GetRightNode() == CurrentNode)
		{
			Parent->mptr_Right = nullptr;
		}


		delete CurrentNode;

		if (!CheckIsNull(ptr_TempLeft))
		{
			this->AddNode(ptr_TempLeft);
		}
		if (!CheckIsNull(ptr_TempRight))
		{
			this->AddNode(ptr_TempRight);

		}
		return true;
	}

}