// Created on 18/11/17 by
// Laila Nasser ElKoussy 900160812
// Azza Al Awady 900152287
// Hebatallah Farid 900160023

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include "BST.h"
using namespace std;

template <class keyType, class dataType>
BST<keyType, dataType>::BST()
{
    root = NULL;
    csize = 0;
}
template <class keyType, class dataType>
void BST<keyType, dataType>::store(std::ofstream &file) {
    store2(file, root);
}

template <class keyType, class dataType>
void BST<keyType, dataType>::store2(std::ofstream &file, node*& pointer){
    if (pointer!= nullptr)
    {file<<pointer->key<<endl<<pointer->data<<endl;
    store2(file, pointer->left);
    store2(file, pointer->right);
    }
    else return;
};



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
dataType BST<keyType, dataType>::retrieve(const keyType &k)
{
    return retrieve2(root, k);
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::insert2(node*& aRoot, const keyType & k, const dataType & d)
{
    node* temp;
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
bool BST<keyType, dataType>::search2(node* aRoot, const keyType& k) const
{
    if (csize==0)
        return false;
    if (k == aRoot->key)
        return true;
    else if (k < aRoot->key)
        return search2(aRoot->left, k);
    else if (k > aRoot->key)
        return search2(aRoot->right, k);
    else
        return false;
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::empty()
{   if (root == nullptr)
    return true;
    else return false;
}

template <class keyType, class dataType>
dataType BST<keyType, dataType>::retrieve2(node* aRoot, const keyType & k) const
{
    if (search(k))
    {
        if (k == aRoot->key)
            return aRoot->data;
        else if (k < aRoot->key)
            return retrieve2(aRoot->left, k);
        else
            return retrieve2(aRoot->right, k);
    }
    else
    {
        cout << "not found" << endl;
        return -1;
    }
}
template<class keyType,class dataType>
void BST<keyType, dataType>::update(const keyType &word, int &count) {
    update2(word, count, root);
}

template<class keyType,class dataType>
void BST<keyType, dataType>::update2(const keyType &word, int &count, node*& aRoot){
    if (aRoot == nullptr)
        return;
    if (word == aRoot->key)
    {aRoot->data += count;
        return;}

    update2(word, count, aRoot->left);
    update2(word, count, aRoot->right);

};


template<class keyType,class dataType>
void BST<keyType, dataType>::level_order()const
{
    traverse2(root);
}
template <class keyType, class dataType>
void BST<keyType, dataType>::level_order2(node* root) const
{
    node* t;
    queue<node*> q;

    t = root;
    q.push(t);
    while (!q.empty())
    {
        t=q.front();
        q.pop();
        cout << t->data<<"      ";
        if (t->left!=NULL)
            q.push(t-> left);
        if (t->right != NULL)
            q.push(t->right);
    }


}

template<class keyType,class dataType>
void BST<keyType, dataType>::preorder() const
{
    preorder2( root);
}

template<class keyType, class dataType>
void BST<keyType, dataType>::preorder2(node* root)const
{
    node* t;
    stack<node*> S;

    S.push(t);
    while (!S.empty())
    {
        t= S.top();
        S.pop();
        cout << t->data<<"     ";
        if (t->right != NULL)
            S.push(t->right);
        if (t->left != NULL)
            S.push(t->left);


    }
}