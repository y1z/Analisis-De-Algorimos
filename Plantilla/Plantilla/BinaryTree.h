#pragma once
class Node;
namespace DS {

	class BinaryTree
	{
	public:
		BinaryTree();
		~BinaryTree();

		// just for testing 
		void SetRootNodeValue(int *value);

		void AddNode(int *Value);
		// overload
		void AddNode(Node *node);

		void PrintTree();

		Node *SearchNode(int Value);

		bool RemoveNode(int Value);

	private:
		int totalNode = 0;
		Node * m_RootNode;
	};

}