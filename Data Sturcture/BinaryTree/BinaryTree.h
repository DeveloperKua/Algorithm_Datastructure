#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

template <typename T>
class TreeNode {
private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
public:
	TreeNode(T initData, TreeNode<T>* Lchild = nullptr, TreeNode<T>* Rchild = nullptr);
	~TreeNode();

public:
	T getData() const;
	TreeNode<T>* getLeftChild() const;
	TreeNode<T>* getRightChild() const;

	void setData(const T _data);
	void setLeftChild(TreeNode<T>* Lchild);
	void setRightChild(TreeNode<T>* Rchild);

};

template <typename T>
class MyBinaryTree {
private:
	TreeNode<T>* Root;
	int nodeCount;

public:
	MyBinaryTree();
	~MyBinaryTree();

public:
	TreeNode<T>* getRootNode();

	TreeNode<T>* Search(T searchData, TreeNode<T>* Node);
	void insert(T insertData, TreeNode<T>* Node);
	TreeNode<T>* remove(T removeData, TreeNode<T>* Node);

	TreeNode<T>* searchSubNode(TreeNode<T>* deleteNode, TreeNode<T>* Node) {
		if (Node->getLeftChild() != nullptr) {
			Node->setLeftChild(searchSubNode(deleteNode, Node->getLeftChild()));
			return Node;
		}
		else {
			deleteNode->setData(Node->getData());
			return Node->getRightChild();
		}
	};
};
