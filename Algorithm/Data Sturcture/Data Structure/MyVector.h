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

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.

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

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.

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
	if (_vectorSize >= _vectorCapacity) VectorGrow();//벡터 full일 경우 벡터 크기 증가

	Vector[_vectorSize] = id;
	++_vectorSize;//벡터 사이즈 +1
}

template <typename T>
T* MyVector<T>::FindById(int MyObjectId) const
{
	for (int i = 0; i < _vectorSize; i++) {//현재 벡터 사이즈(할당된 량)만큼 검색
		if (MyObjectId == this->Vector[i]) {//찾으면
			//printf("\n검색하신 id를 가진 오브젝트를 발견하였습니다. \nid : [%d] \nVector[%d]에서 반환됨", Vector[i], i);
			return &Vector[i];
		}
	}
	//못 찾으면
	return nullptr;
}

template <typename T>
void MyVector<T>::TrimToSize()//trim 실행 후 add를 통한 용량 증가 실행시 버그 발생
{
	if (this->_vectorSize < this->_vectorCapacity) {//현재 벡터의 사이즈(할당된 량)이 총 용량보다 작다면(여유분이 남는다면)
		MyVector tmpV(*this);//현재 벡터와 같은 크기를 지닌 벡터 복사생성
		tmpV._vectorCapacity = this->_vectorSize;//벡터 총 크기를 size 만큼 재 설정
		this->operator=(tmpV);//현재 벡터에 임시 벡터 대입
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
	int G_Num = 0;//그룹화 시킨 벡터들을 담을 배열 수
	MyVector * V = new MyVector[10];
	V[0].operator[](0);

	for (int i = 0; i < this->_vectorSize; i++) {//이중 for으로 벡터들의 각 요소를 벡터의 모든 요소들과 비교
		this->Vector[i].isGroupSearch = true;//첫번째 요소는 검사를 하였음을 명시
		V[G_Num].Add(this->Vector[i]);//벡터 그룹에 첫번째 요소를 대입

		for (int j = i + 1; j < this->_vectorSize; j++) {//벡터의 요소를 모든 요소와 비교
			if (!this->Vector[j].isGroupSearch) {//현재 검색한 요소가 검사가 안된 요소라면
				if (this->Vector[i] == this->Vector[j]) {//만약 지정된 벡터의 요소와 지금 서치중인 요소가 같은 수(그룹)일 때
					V[G_Num].Add(this->Vector[j]);//그룹 벡터에 추가
					this->Vector[j].isGroupSearch = true;//이 요소 또한 검사가 끝났음을 명시
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