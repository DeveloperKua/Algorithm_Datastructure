#pragma once

#pragma region NodeCode
template<typename T>
Node<T>::Node(Node<T>* _prev, Node * _next, T _data)
{
	prev = _prev;
	next = _next;
	data = _data;
}

template<typename T>
Node<T>::~Node()
{
	prev = nullptr;
	next = nullptr;
	data = 0;
}

template<typename T>
T Node<T>::getData() const
{ return data(); }

template<typename T>
Node<T>* Node<T>::getPrev() const
{ return prev; }

template<typename T>
Node<T>* Node<T>::getNext() const
{ return next; }

template<typename T>
void Node<T>::setData(const T _data)
{
	data = _data;
}

template<typename T>
void Node<T>::setPrev(Node<T>* _node)
{
	prev = _node;
}

template<typename T>
void Node<T>::setNext(Node<T>* _node)
{
	next = _node;
}
#pragma endregion

#pragma region ListCode
template<typename T>
LinkedList<T>::LinkedList()
{
	count = 0;
	filst = nullptr;
	last = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	this->clear();
}

template<typename T>
int LinkedList<T>::size() const
{
	return data;
}

template<typename T>
int LinkedList<T>::front() const
{
	return 0;
}

template<typename T>
int LinkedList<T>::back() const
{
	return 0;
}

template<typename T>
void LinkedList<T>::push_front(T push_data)
{
}

template<typename T>
void LinkedList<T>::push_back(T push_data)
{
}

template<typename T>
void LinkedList<T>::pop_front()
{
}

template<typename T>
void LinkedList<T>::pop_back()
{
}

template<typename T>
void LinkedList<T>::erase()
{
}

template<typename T>
void LinkedList<T>::insert()
{
}

template<typename T>
void LinkedList<T>::clear()
{
}

template<typename T>
void LinkedList<T>::push_back(T push_data)
{
}
#pragma endregion