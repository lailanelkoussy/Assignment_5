//
// Created on 18/11/17 by
// Laila Nasser ElKoussy 900160812
// Azza Al Awady 900152287
// Hebatallah Farid 900160023
//

#include "BST.h"
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>


using namespace std;


template <class keyType, class dataType>
BST<keyType, dataType>::BST()
{
    root = nullptr;
    csize = 0;
}

template <class keyType, class dataType>
BST<keyType, dataType>::~BST() {

    destruct(root);
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
bool BST<keyType, dataType>::search(const keyType& k)
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
    if (aRoot == nullptr)
    {aRoot = new node;
        aRoot->left = nullptr;
        aRoot->right = nullptr;
        aRoot->key = k;
        aRoot->data = d;
        csize++;
        return true;}

    else if (k == aRoot->key)
        return false;
    for (int i = 0; ((i<k.length()) || (i<aRoot->key.length())) ; i++){
        if (int(k[i]) > int(aRoot->key[i])) {

            if(aRoot->right == nullptr){
                temp = aRoot->right;
                temp->left = nullptr;
                temp->right = nullptr;
                temp->key = k;
                temp->data = d;
               return true;
            }
            else return insert2(aRoot->right, k, d);
        }
        else if (int(k[i]) < int(aRoot->key[i])){
            if (aRoot->left == nullptr){
                temp = aRoot->left;
                temp->left = nullptr;
                temp->right = nullptr;
                temp->key = k;
                temp->data = d;
                return true;
            }

            else return insert2(aRoot->left, k, d);
        }

    }

}


template <class keyType,class dataType>
bool BST<keyType, dataType>::Remove(const keyType& k)
{
    return Remove2(root, k);
}
template <class keyType, class dataType>
bool BST<keyType, dataType>::Remove2(node* & root, const keyType& k)
{
    node* h, *f,*d,*s;
    dataType m;
    bool found = false, flag = true;

    if (root == nullptr)
    {
        cout << "not found";
        return false;
    }
    f = nullptr;
    h = root;
    m = retrieve2(root, k);
    while ((h->data != m) || (h==nullptr))
    {    for (int i = 0; (flag) && ((i<k.length()) || (i<h->key.length())) ; i++){
            if (int(k[i]) > int(root->key[i])) {
                flag = false;
                f = h;
                h = h->right;

            }
            else if (int(k[i]) < int(h->key[i])){
                flag = false;
                f = h;
                h = h->left;
            }

        }

    }

    if (h == nullptr)
    {
        cout << "not found";
        return false;
    }

    else
    {
        if ((h->left != nullptr) && (h->right != nullptr))
        {
            d = h;
            s = d->left;
            while (s->right != nullptr)
            {
                d = s;
                s = s->right;
            }
            d->right = nullptr;
            h->data = s->data;
            h->key = s->key;
            delete s;
            return true;
        }
        if (h->left == nullptr)
        {
            d = h->right;
            f->right = d;
            delete h;
            return true;
        }
        if (h->right == nullptr)
        {
            d = h->left;
            f->left = d;
            delete h;
            return true;
        }
        else
        {
            if (f->right == h)
            {
                f->right = nullptr;
                delete h;
                return true;
            }
            if (f->left == h)
            {
                f->left = nullptr;
                delete h;
                return true;
            }
        }
    }
}



template <class keyType, class dataType>
bool BST<keyType, dataType>::search2(node* & aRoot, const keyType& k)
{

 if (k == aRoot->key)
    return true;
 else if ((aRoot->left == nullptr) && (aRoot->right == nullptr))
    return false;
 else {
     for (int i = 0; ((i < k.length()) || (i < aRoot->key.length())); i++) {
         if (int(k[i]) > int(aRoot->key[i])) {
             return search2(aRoot->right, k);
         } else if (int(k[i]) < int(aRoot->key[i])) {
             return search2(aRoot->left, k);
         }

     }
 }
}

template <class keyType, class dataType>
bool BST<keyType, dataType>::empty()
{   if (root == nullptr)
        return true;
    else return false;
}

template <class keyType, class dataType>
dataType BST<keyType, dataType>::retrieve2(node* &aRoot, const keyType & k)
{ bool flag = true;
    if (search(k))
    {if (k == aRoot->key)
            return aRoot->data;
    for (int i = 0; (flag) && ((i<k.length()) || (i<aRoot->key.length())) ; i++){
        if (int(k[i]) > int(aRoot->key[i])) {
            flag = false;
            return retrieve2(aRoot->right, k);
        }
        else if (int(k[i]) < int(aRoot->key[i])){
            flag = false;
            return retrieve2(aRoot->left, k);
        }

    }
    }

    else
    {
        cout << "not found" << endl;
        return false;
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
void BST<keyType, dataType>::level_order2(node* &root) const
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
        if (t->left!= nullptr)
            q.push(t-> left);
        if (t->right != nullptr)
            q.push(t->right);
    }


}

template<class keyType,class dataType>
void BST<keyType, dataType>::preorder() const
{
    preorder2( root);
}

template<class keyType, class dataType>
void BST<keyType, dataType>::preorder2(node*& root)const
{
    node* t;
    stack<node*> S;

    S.push(t);
    while (!S.empty())
    {
        t= S.top();
        S.pop();
        cout << t->data<<"     ";
        if (t->right != nullptr)
            S.push(t->right);
        if (t->left != nullptr)
            S.push(t->left);


    }
}


template <class keyType, class dataType>
void BST<keyType, dataType>::traverse()
{
    traverse2(root);
}

template <class keyType, class dataType>
void BST<keyType, dataType>::traverse2(node*& t) const
{
    if (t != nullptr)
    {
        traverse2(t->left);
        cout <<t->key<<"   "<<t->data << "     ";
        traverse2(t->right);
    }
}
template <class keyType, class dataType>
void BST<keyType, dataType>::print(keyType &k) {
    print2(root, k);
}

template <class keyType, class dataType>
void BST<keyType, dataType>::print2(node* &aRoot, keyType &k)
{bool flag = true;
    {if (aRoot == nullptr)
            return;
    else if (k == aRoot->key) {
            cout << aRoot->key << "  " << aRoot->data << endl;
            return;
        }

    for (int i = 0; (flag) && ((i<k.length()) || (i<aRoot->key.length())) ; i++) {
            if (int(k[i]) > int(aRoot->key[i])) {
                flag = false;
                retrieve2(aRoot->right, k);
            }
            else if (int(k[i]) < int(aRoot->key[i])){
                flag = false;
                retrieve2(aRoot->left, k);
            }

        }
    }


}
template <class keyType, class dataType>
void BST<keyType, dataType>::max() {
    keyType count = 0;
    dataType word;

    max2(root, count, word);

    cout<<"The word with the highest count is: "<<word<<" with a count of: "<<count<<endl;


}

template <class keyType, class dataType>
void BST<keyType, dataType>::max2(node *&aRoot, keyType &k, dataType &d) {

    if (aRoot!= nullptr) {
        if (aRoot->data > d)
        {
            max2(aRoot->left, k, aRoot->data);
            max2(aRoot->right, k, aRoot->data);
        }
        else {
            max2(aRoot->left, k, d);
            max2(aRoot->right, k, d);
        }

    }

}

template <class keyType, class dataType>
void BST<keyType, dataType>::destruct(node* aRoot) {
    if (aRoot == nullptr)
        return;
    else {
        destruct(aRoot->left);
        destruct(aRoot->right);
        delete aRoot;
        return;
    }


}