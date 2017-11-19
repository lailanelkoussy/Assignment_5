// Created on 18/11/17 by
// Laila Nasser ElKoussy 900160812
// Azza Al Awady 900152287
// Hebatallah Farid 900160023

#include <iostream>
#include <iomanip>
#include"QueueL.h";
#include"Stackt.h";
#include "BST.h"
using namespace std;

template <class keyType, class dataType>
BST<keyType, dataType>::BST()
{
    root = NULL;
    csize = 0;
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::insert(const keyType& k, const dataType& d)
{
    return insert2(root, k, d);
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::search(const keyType& k) const
{
    return search2(root, k);
}

template <class keyType, class dataType>
dataType BST<keyType, dataType>::retrieve(const keyType& k) const
{
    return retrieve2(root, k);
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::insert2(nodepointer& aRoot, const keyType & k, const dataType & d)
{
    nodepointer temp;
    if (aRoot == NULL)
    {
        temp = new node;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->key = k;
        temp->data = d;
        csize++;
        return true;
    }
    else if (k == aRoot->key)
    {
        return false;
    }
    else if (k< aRoot->key)
    {
        insert2(aRoot->left, k, d);
    }
    else
    {
        insert2(aRoot->right, k, d);
    }
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::search2(nodepointer aRoot, const keyType& k) const
{
    if (empty)
        return false;
    if (k == aRoot->key)
        return true;
    else if (k < aRoot->key)
        search2(aRoot->left, k, d);
    else if (k > aRoot->key)
        search2(aRoot->right, k, d);
    else
        return false;
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::empty()
{
    return (root == NULL);
}

template <class keyType, class dataType>
dataType BST<keyType, dataType>::retrieve2(nodepointer aRoot, const keyType & k) const
{
    if (search(k))
    {
        if (k == aRoot->key)
            return aRoot->data;
        else if (k < aRoot->key)
            retrieve(aRoot->left, k);
        else
            retrieve(aRoot->right, k);
    }
    else
    {
        cout << "not found" << endl;
        return -1;
    }
}

template<class keyType,class dataType>
void BST<keyType, dataType>::level_order()const
{
    traverse2( root);
}
template <class keyType,dataType>
void BST<keyType, dataType>::level_order2(nodepointer root) const
{
    nodepointer t;
    QueueL q;

    t == root;
    q.enqueue(t);
    while (!q.queueIsEmpty())
    {
        q.dequeue(t);
        cout << t->data<<"      ";
        if (t->left!=NULL)
            q.enqueue(t-> left);
        if (t->right != NULL)
            q.enqueue(t->right);
    }


}

template<class keyType,class dataType>
void BST<keyType, dataType>::preorder() const
{
    preorder2( root);
}

template<class keyType, class dataType>
void BST<keyType, dataType>::preorder2(nodepointer root)const
{
    nodepointer t;
    Stackt(128) S;

    S.push(t);
    while (!S.stackIsEmpty())
    {
        S.pop(t);
        cout << t->data<<"     ";
        if (t->right != NULL)
            S.push(t->right);
        if (t->left != NULL)
            S.push(t->left);


    }
}

/*template <class keyType,class dataType>
bool BST<keyType, dataType>::Remove(const keyType&)
{
	return Remove2(root, k);
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::Remove2(nodepointer root, const keyType& k)
{
	if (root == NULL)
		return false;
	if (k == root->k)
	{
	}
}
*/

template <class keyType,class dataType>
void BST<keyType, dataTYpe>::void traverse()const
{
    traverse2(root);
}

template <class keyType, class dataType>
void BST<keyType, dataTYpe>::void traverse2()const
{
    nodepointer t;
    t = root;
    if (t != NULL)
    {
        traverse2(t->left);
        cout << t->data << "     ";
        traverse2(t->right);
    }
}