//
// Created on 18/11/17 by
// Laila Nasser ElKoussy 900160812
// Azza Al Awady 900152287
// Hebatallah Farid 900160023
//

#ifndef ASSIGNMENT_5_BST_H
#define ASSIGNMENT_5_BST_H

#include <iostream>


template <class keyType, class dataType>
class BST {

public:

    BST();
    ~BST();
    bool insert(const keyType&, const dataType&);
    bool search(const keyType&);
    dataType retrieve(const keyType &);
    bool empty();
    void traverse();
    void level_order()const;
    void preorder()const;
    bool Remove(const keyType&);
    void update (const keyType&, int &count);
    void store(std::ofstream &file);
    void print(keyType &k);
    void max();


private:
    class node
    {
    public:
        keyType key;
        dataType data;
        node * left;
        node * right;
    };
    int csize;
    node * root;
    bool insert2(node*&, const keyType &, const dataType &);
    bool search2(node* & , const keyType&);
    void level_order2(node*&)const;
    void preorder2(node*&)const;
    bool Remove2(node* &,const keyType &);
    void traverse2( node*& )const;
    void store2(std::ofstream &file, node*&);
    void update2 (const keyType&, int &count, node* &);
    dataType retrieve2(node*& , const keyType &);
    void print2(node* &aRoot, keyType & k);
    void max2(node*& aRoot, keyType &k, dataType&d);
    void destruct(node* aRoot);


};


#endif //ASSIGNMENT_5_BST_H
