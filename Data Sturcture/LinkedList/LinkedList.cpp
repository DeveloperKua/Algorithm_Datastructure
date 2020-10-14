#include "LinkedList.h"
#pragma once

#pragma region NodeCode
template<typename T>
Node<T>::Node(T _data)
{
	prev = nullptr;
	next = nullptr;
	data = _data;
}

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
{ return data; }

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
	first = nullptr;
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
	return count;
}

template<typename T>
int LinkedList<T>::front() const
{
	if (count == 0) {
		cout << "List is Null";
		return 0;
	}
	return first->getData();
}

template<typename T>
int LinkedList<T>::back() const
{
	if (count == 0) {
		cout << "List is Null";
		return 0;
	}
	return last->getData();
}

template<typename T>
void LinkedList<T>::push_front(T push_data)
{
	if (count == 0) {//리스트가 없다면
		Node<T> * newNode = new Node<T>(push_data);
		first = last = newNode;
		++count;
		return;
	}
	Node<T> * newNode = new Node<T>(nullptr, first, push_data);
	first->setPrev(newNode);
	first = newNode;
	++count;
}

template<typename T>
void LinkedList<T>::push_back(T push_data)
{
	if (count == 0) {//리스트가 없다면
		Node<T> * newNode = new Node<T>(push_data);
		first = last = newNode;
		++count;
		return;
	}
	Node<T> * newNode = new Node<T>(last, nullptr, push_data);
	last->setNext(newNode);
	last = newNode;
	++count;
}

template<typename T>
void LinkedList<T>::pop_front()
{
	if (count == 0) return;
	Node<T>* TempNode = first;

	first = first->getNext();
	if(first != nullptr) first->setPrev(nullptr);
	delete TempNode;
	--count;
}

template<typename T>
void LinkedList<T>::pop_back()
{
	if (count == 0) return;
	Node<T>* TempNode = last;

	last = last->getPrev();
	if (last != nullptr) last->setNext(nullptr);
	delete TempNode;
	--count;
}

template<typename T>
void LinkedList<T>::erase(int index)
{
	if (index == 0) { pop_front(); }
	else if (index == count - 1) { pop_back(); }
	else
	{
		Node<T>* eraseNode = SearchNode(index);
		eraseNode->getPrev()->setNext(eraseNode->getNext());
		eraseNode->getNext()->setPrev(eraseNode->getPrev());
		--count;
	}
}

template<typename T>
void LinkedList<T>::insert(int index, T insert_data)
{
	//insert 위치가 양 끝 이라면 push 이용
	if (index == 0) { push_front(insert_data); }
	else if (index == count) { push_back(insert_data); }
	else
	{
		Node<T>* insertIndexNode = SearchNode(index);//현재 추가할 위치의 기존 노드
		Node<T> * insertNode = new Node<T>(insertIndexNode->getPrev() , insertIndexNode, insert_data);//새로 추가해줄 새 노드
		insertIndexNode->getPrev()->setNext(insertNode);
		insertIndexNode->setPrev(insertNode);
		++count;
	}
}

template<typename T>
Node<T>* LinkedList<T>::SearchNode(int index)
{
	int searchCount = 0;
	Node<T>* Temp = first;
	if (index < count / 2) {
		while (searchCount != index) {
			Temp = Temp->getNext();
			++searchCount;
		}
		return Temp;
	}
	else {
		searchCount = count - 1;
		Temp = last;
		while (searchCount != index) {
			Temp = Temp->getPrev();
			--searchCount;
		}
		return Temp;
	}
	return Temp;
}

template<typename T>
void LinkedList<T>::clear()
{
	while (count != 0) {
		pop_back();
	}
}
#pragma endregion