#ifndef __MYVECTOR_H
#define __MYVECTOR_H

#include <string>
#include <iostream>

using namespace std;

template <typename T>
class MyVector
{
private:
	
	int _vectorSize;
	int _vectorCapacity;

	void VectorGrow();

public: // ������, ���������, �Ҵ翬����, �Ҹ��ڸ� .cpp ���Ͽ� �����մϴ�.

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

public: // �Ʒ� ��� �Լ����� .cpp ���Ͽ� �����մϴ�.

	// Returns current capacity of this vector.
	int GetCapacity() const;

	// Returns current size of this vector.
	int GetSize() const;

	// Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
	void Add(T id);

	// Returns the first occurrence of MyObject instance with the given ID.
	// Returns nullptr if not found.
	T* FindById(int MyObjectId) const;

	// Trims the capacity of this vector to current size.
	void TrimToSize();

	// Returns the MyObject instance at the specified index.
	T& operator[](int index);

	// Returns string representation of the vector.
	std::string ToString() const;

	// Remove all MyObject instances with the given ID in this vector.
	void RemoveAll(int MyObjectId);

	// Returns a newly allocated array of MyVector objects,
	// each of whose elements have the same "_id" value of the MyObject struct.
	// The 'numGroups' is an out parameter, and its value should be set to
	// the size of the MyVector array to be returned.
	MyVector* GroupById(int* numGroups);
};

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
{//Capacity ��ŭ�� ũ�⸦ ���� ���͸� ����
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
	Vector = growVector;//���� ����
	//GrowVector.~MyVector();
	//return *this;
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
	if (_vectorSize >= _vectorCapacity) VectorGrow();//���� full�� ��� ���� ũ�� ����

	Vector[_vectorSize] = id;
	++_vectorSize;//���� ������ +1
}

template <typename T>
T* MyVector<T>::FindById(int MyObjectId) const
{
	for (int i = 0; i < _vectorSize; i++) {//���� ���� ������(�Ҵ�� ��)��ŭ �˻�
		if (MyObjectId == this->Vector[i]) {//ã����
			//printf("\n�˻��Ͻ� id�� ���� ������Ʈ�� �߰��Ͽ����ϴ�. \nid : [%d] \nVector[%d]���� ��ȯ��", Vector[i], i);
			return &Vector[i];
		}
	}
	//�� ã����
	return nullptr;
}

template <typename T>
void MyVector<T>::TrimToSize()//trim ���� �� add�� ���� �뷮 ���� ����� ���� �߻�
{
	if (this->_vectorSize < this->_vectorCapacity) {//���� ������ ������(�Ҵ�� ��)�� �� �뷮���� �۴ٸ�(�������� ���´ٸ�)
		MyVector tmpV(*this);//���� ���Ϳ� ���� ũ�⸦ ���� ���� �������
		tmpV._vectorCapacity = this->_vectorSize;//���� �� ũ�⸦ size ��ŭ �� ����
		this->operator=(tmpV);//���� ���Ϳ� �ӽ� ���� ����
		tmpV.~MyVector();
	}
}

template <typename T>
T& MyVector<T>::operator[](int index)
{
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
void MyVector<T>::RemoveAll(int MyObjectId)
{
	for (int i = 0; i < this->_vectorSize; i++) {
		if (this->Vector[i] == MyObjectId) {
			memmove(this->Vector + i, this->Vector + (i + 1), sizeof(T)*this->_vectorSize - i + 1);
			i--;
			this->_vectorSize--;
		}
	}
}

template <typename T>
MyVector<T> * MyVector<T>::GroupById(int * numGroups)
{
	int G_Num = 0;//�׷�ȭ ��Ų ���͵��� ���� �迭 ��
	MyVector * V = new MyVector[10];
	V[0].operator[](0);

	for (int i = 0; i < this->_vectorSize; i++) {//���� for���� ���͵��� �� ��Ҹ� ������ ��� ��ҵ�� ��
		this->Vector[i].isGroupSearch = true;//ù��° ��Ҵ� �˻縦 �Ͽ����� ���
		V[G_Num].Add(this->Vector[i]);//���� �׷쿡 ù��° ��Ҹ� ����

		for (int j = i + 1; j < this->_vectorSize; j++) {//������ ��Ҹ� ��� ��ҿ� ��
			if (!this->Vector[j].isGroupSearch) {//���� �˻��� ��Ұ� �˻簡 �ȵ� ��Ҷ��
				if (this->Vector[i] == this->Vector[j]) {//���� ������ ������ ��ҿ� ���� ��ġ���� ��Ұ� ���� ��(�׷�)�� ��
					V[G_Num].Add(this->Vector[j]);//�׷� ���Ϳ� �߰�
					this->Vector[j].isGroupSearch = true;//�� ��� ���� �˻簡 �������� ���
					i++;
				}
			}
		}
		G_Num++;
	}
	for (int i = 0; i < G_Num; i++) {
		for (int j = 0; j < V[i]._vectorSize; j++) {
			printf("|%d|", V[i].operator[](j));
		}
		printf("\n");
	}
	return nullptr;
}
#endif