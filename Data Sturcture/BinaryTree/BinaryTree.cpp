#pragma once
#include "BinaryTree.h"

#pragma region NodeCode
template<typename T>
TreeNode<T>::TreeNode(T initData, TreeNode<T>* Lchild, TreeNode<T> * Rchild)
{
	data = initData;
	leftChild = Lchild;
	rightChild = Rchild;
}

template<typename T>
TreeNode<T>::~TreeNode()
{
	data = 0;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
T TreeNode<T>::getData() const
{ return data; }

template<typename T>
TreeNode<T>* TreeNode<T>::getLeftChild() const
{ return leftChild; }

template<typename T>
TreeNode<T>* TreeNode<T>::getRightChild() const
{ return rightChild; }

template<typename T>
void TreeNode<T>::setData(const T _data)
{
	data = _data;
}

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode<T>* Lchild)
{
	leftChild = Lchild;
}

template<typename T>
void TreeNode<T>::setRightChild(TreeNode<T>* Rchild)
{
	rightChild = Rchild;
}
#pragma endregion

template<typename T>
MyBinaryTree<T>::MyBinaryTree()
{
	nodeCount = 0;
}

template<typename T>
MyBinaryTree<T>::~MyBinaryTree()
{
	
}

template<typename T>
TreeNode<T>* MyBinaryTree<T>::getRootNode()
{
	return this->Root;
}

template<typename T>
TreeNode<T>* MyBinaryTree<T>::Search(T searchData, TreeNode<T>* Node)
{
	if (Node->getData() == searchData) return Node;

	else if (searchData < Node->getData())
		return Search(searchData, Node->getLeftChild());

	else
		return Search(searchData, Node->getRightChild());

}

template<typename T>
void MyBinaryTree<T>::insert(T insertData, TreeNode<T>* Node)
{
	if (Node == nullptr) {
		Root = new TreeNode<T>(insertData);
		++nodeCount;
		return;
	}
	if (insertData < Node->getData()) {

		if (Node->getLeftChild() == nullptr)
		{
			TreeNode<T> * newNode = new TreeNode<T>(insertData);
			Node->setLeftChild(newNode);
			++nodeCount;
		}
		else insert(insertData, Node->getLeftChild());
	}

	else if (insertData > Node->getData()) {

		if (Node->getRightChild() == nullptr)
		{
			TreeNode<T> * newNode = new TreeNode<T>(insertData);
			Node->setRightChild(newNode);
			++nodeCount;
		}
		else insert(insertData, Node->getRightChild());
	}
}

template<typename T>
TreeNode<T>* MyBinaryTree<T>::remove(T removeData, TreeNode<T>* Node)
{
	if (Node == nullptr)
		return nullptr;

	//현재 노드 값보다 삭제하고자 하는 값이 작고 큼에 따라
	//하위 자식을 재귀 반환값으로 오른쪽, 왼쪽 자식에 대입
	else if (Node->getData() > removeData) {
		Node->setLeftChild(remove(removeData, Node->getLeftChild()));
		return Node;
	}

	else if (Node->getData() < removeData) {
		Node->setRightChild(remove(removeData, Node->getRightChild()));
		return Node;
	}
	
	//제거하고자 하는 값이 현재 노드면
	else if (Node->getData() == removeData) {

		//자식이 1개 - 오른쪽 자식이면 반환하여
		//오른쪽 자식을 현재 부모의 하위에 대입
		if (Node->getLeftChild() == nullptr)
			return Node->getRightChild();

		//자식이 1개 - 왼쪽 자식이면 반환하여
		//왼쪽 자식을 현재 부모의 하위에 대입
		else if (Node->getRightChild() == nullptr)
			return Node->getLeftChild();

		//하위 자식이 2개라면
		else {
			Node->setRightChild(searchSubNode(Node, Node->getRightChild()));
			return Node;
		}

	}
}