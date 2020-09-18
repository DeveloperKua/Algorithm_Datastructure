#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <list>
#include <string>

using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node<T> *next;
	Node<T> *prev;
public:
	Node(T _data);
	Node(Node<T>* _prev, Node* _next, T _data);
	~Node();
public:
	T getData() const;
	Node<T>* getPrev() const;
	Node<T>* getNext() const;

	void setData(const T _data);
	void setPrev(Node<T>* _node);
	void setNext(Node<T>* _node);
};

template <typename T>
class LinkedList {

private:
	int count = 0;
	Node<T> *first;
	Node<T> *last;

public:
	LinkedList();
	~LinkedList();

public:
	int size() const;
	int front() const;
	int back() const;
	
	void push_front(T push_data);
	void push_back(T push_data);
	void pop_front();
	void pop_back();
	void erase(int index);
	void insert(int index, T insert_data);
	Node<T>* SearchNode(int index);
	void clear();

};

#include "LinkedList.hpp"
