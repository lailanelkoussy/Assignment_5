//
// Created by Laila Nasser ElKoussy 900160812 on 11/19/17.
//

#ifndef ASSIGNMENT_5_BST_H
#define ASSIGNMENT_5_BST_H

#include <fstream>

template <class keyType, class dataType>
class BST {

public:

    BST();
    bool insert(const keyType&, const dataType&);
    bool search(const keyType&) const;
    dataType retrieve(const keyType &);
    bool empty();
    void traverse()const;
    void level_order()const;
    void preorder()const;
    bool Remove(const keyType&);
    typedef node * nodepointer;
    void update (const keyType&, int &count);
    void store(std::ofstream &file);


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
    typedef node * nodepointer;
    nodepointer root;
    bool insert2(nodepointer&, const keyType &, const dataType &);
    bool search2(nodepointer, const keyType&) const;
    void level_order2(nodepointer)const;
    void preorder2(nodepointer)const;
    bool Remove2(nodepointer,const keyType &);
    void traverse2(nodepointer)const;
    void store2(std::ofstream &file, nodepointer&);
    void update2 (const keyType&, int &count, nodepointer &);
    dataType retrieve2(nodepointer , const keyType &) const;

};


#endif //ASSIGNMENT_5_BST_H
