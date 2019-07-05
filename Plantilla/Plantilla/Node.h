#pragma once
#ifndef CLASS_NODE_H
#define CLASS_NODE_H
template<class T> class Node
{
public:
	Node()
		:m_Height(0),m_Key(0), m_Value(nullptr), mptr_Left(nullptr), mptr_Right(nullptr)
	{};
	~Node()
	{


	};

	int m_Height;
	int m_Key;
	T *m_Value;
	Node<T> *mptr_Left;
	Node<T> *mptr_Right;
};

template<class T>
inline Node<T>::Node()
{}

#endif // CLASS_NODE_H