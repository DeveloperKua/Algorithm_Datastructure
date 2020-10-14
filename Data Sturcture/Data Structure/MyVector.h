#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class MyVector
{
private:
	
	int _vectorSize;
	int _vectorCapacity;

	void VectorGrow();

public:

	T * Vector;

	// basic Constructor
	MyVector();

	// Constructor.
	MyVector(int capacity);

	// Copy constructor.
	MyVector(const MyVector& other);

	// Assignment operator.
	MyVector& operator=(const MyVector& other);

	// Destructor.
	~MyVector();

public:

	// Returns current capacity of this vector.
	int GetCapacity() const;

	// Returns current size of this vector.
	int GetSize() const;

	void Add(T id);

	void pop_back();

	void erase(int iter);

	T& operator[](int index);

	std::string ToString() const;

	void RemoveAll();
};