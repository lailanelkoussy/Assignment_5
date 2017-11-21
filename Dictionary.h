//
// Created by Laila Nasser ElKoussy 900160812 on 11/21/17.
//

#ifndef ASSIGNMENT_5_DICTIONARY_H
#define ASSIGNMENT_5_DICTIONARY_H

#include "BST.h"
#include <iostream>
#include <fstream>

class Dictionary {
public:
    Dictionary ();
    void storeDictionary(); // before exiting the file, saves all of the contents of the file onto
    void import(std::string& filename); //adds content of an old dictionary file into the dictionary
    void import();
    void insert(std::string& word); //when adding new words
    void setdPath(std::string&);
    void insert (std::string & word, int &count); //when importing from dictionary
    void read (std::string &filename); //takes a new file to add to the dictionary


private:
    BST<std::string, int> Table[36];
    std::string dPath;
    void toLowerCase (std::string & );
    int getIndex(std::string &);
    void opening (std::ifstream &file, const std::string& filename);
    void opening (std::ofstream &file, const std::string& filename);
    void removeSymbols(std::string&word);


};


#endif //ASSIGNMENT_5_DICTIONARY_H
