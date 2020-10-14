#pragma once
#include "MyVector.h"
#pragma region Constructor

template <typename T>
MyVector<T>::MyVector()
{
	_vectorCapacity = 1;
	_vectorSize = 0;
	Vector = new T[_vectorCapacity];
}

template <typename T>
MyVector<T>::MyVector(int capacity)
{//Capacity 만큼의 크기를 가진 벡터를 생성
	_vectorCapacity = capacity;
	_vectorSize = 0;
	Vector = new T[_vectorCapacity];
}

template <typename T>
MyVector<T>::MyVector(const MyVector & other)
{
	_vectorCapacity = other._vectorCapacity;
	_vectorSize = other._vectorSize;
	Vector = new T[_vectorCapacity];
	for (int i = 0; i < other.GetSize(); i++) {
		Vector[i] = other.Vector[i];
	}
}
#pragma endregion

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector & other)
{
	delete[] Vector;
	Vector = new T[other._vectorCapacity];
	for (int i = 0; i < other.GetSize(); i++) {
		Vector[i] = other.Vector[i];
	}
	_vectorSize = other._vectorSize;
	if (_vectorSize > _vectorCapacity) _vectorCapacity = other._vectorCapacity;
	return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
	_vectorCapacity = 0;
	_vectorSize = 0;
	delete[] Vector;
}

template <typename T>
void MyVector<T>::VectorGrow()
{
	this->_vectorCapacity *= 2;
	T * growVector = new T[_vectorCapacity];
	for (int i = 0; i < GetSize(); ++i) {
		growVector[i] = Vector[i];
	}
	delete[] Vector;
	Vector = growVector;//대입 연산
}

template <typename T>
int MyVector<T>::GetCapacity() const
{
	return _vectorCapacity;
}

template <typename T>
int MyVector<T>::GetSize() const
{
	return _vectorSize;
}

template <typename T>
void MyVector<T>::Add(T id)
{
	if (_vectorSize >= _vectorCapacity) VectorGrow();//벡터 full일 경우 벡터 크기 증가

	Vector[_vectorSize] = id;
	++_vectorSize;//벡터 사이즈 +1
}

template<typename T>
void MyVector<T>::pop_back()
{
	Vector[_vectorSize] = 0;
	--_vectorSize;
}

template<typename T>
void MyVector<T>::erase(int iter)
{
	for (int i = iter; i < _vectorSize - 1; i++) {
		Vector[i] = Vector[i + 1];
	}
	Vector[_vectorSize] = 0;
	--_vectorSize;
}

template <typename T>
T& MyVector<T>::operator[](int index)
{
	if (index >= _vectorSize) throw out_of_range("index가 vector size를 초과함");
	return Vector[index];
}

template <typename T>
std::string MyVector<T>::ToString() const
{
	string VectorStr;
	for (int i = 0; i < this->_vectorSize; i++) {
		VectorStr += to_string(Vector[i]);
		VectorStr += ", ";
	}
	return VectorStr;
}

template <typename T>
void MyVector<T>::RemoveAll()
{
	for (int i = 0; i < _vectorSize; i++) {
		Vector[i] = 0;
	}
	_vectorSize = 0;
}