//
// Created by Laila Nasser ElKoussy 900160812 on 11/21/17.
//

#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary() {
    dPath = "default.txt";
    size = 0;

}
Dictionary::~Dictionary() {
    for (int i = 0; i<36; i++)
        delete Table[i];
}

void Dictionary::setdPath(std::string &s) {

    dPath = s;
}

void Dictionary::insert(std::string &s) {

    int index, one =1;

    if ((!isalpha(s[0]) && (!isdigit(s[0]))))
        return;

    else {
        index = getIndex(s);

        if (!Table[index].search(s))
        {Table[index].insert(s,one);
        size++; }

        else Table[index].update(s,one);
}}

void Dictionary::insert(std::string &word, int &count) {
    toLowerCase(word);
    removeSymbols(word);
    int index = getIndex(word);

    if (Table[index].search(word))
        Table[index].update (word, count);
    else {Table[index].insert(word, count);
    size++; }

}
void Dictionary::storeDictionary() {
    ofstream file;
    opening (file, dPath);

    for (int i =0; i<36; i++)
        Table[i].store(file);
}

void Dictionary::read(std::string & filename) {
    ifstream file;
    opening(file,filename);
    string word;

    while (file.good()) {
        file>>word;
        insert(word);
    }
}

void Dictionary::import(std::string &filename) {
    ifstream file;
    opening(file, filename);
    string word,counts;
    int count;

    while (file.good()) {
        getline(file, word);
        getline(file,counts);
        count = stoi(counts);

        insert(word, count);
    }

    file.close();


}

void Dictionary::import(){
    import(dPath);
}

void Dictionary::opening(std::ifstream &file, const std::string &filename) {

    file.open(filename);
    if (file.is_open())
        return;

    else
        cout << "Could not open " << filename;

}

void Dictionary::opening(std::ofstream &file, const std::string &filename) {
    file.open(filename);
    if (file.is_open())
        return;

    else
        cout << "Could not open " << filename;

}

void Dictionary::toLowerCase (string& a){
    string temp="";
    for (int i =0; i<a.length(); i++){
        temp+= char(tolower(int(a[i])));
    }
    a = temp;
}

int Dictionary::getIndex(std::string &s) {
    char a = s[0];
    int index;

    if (isalpha(a)){
        index = int(a) - int('a');
    }
    else index = 25 + int(a);

    return index;

}

void Dictionary::removeSymbols(std::string &word) {

    for (int i = 0; i < word.size(); i++)
        if ((!isalnum(word[i])))
        {
            word.erase(i, 1);
            i--;
        }
}

void Dictionary::traverse() {
    for (int i = 0; i<36; i++)
        Table[i].traverse();
}

void Dictionary::search(string & word) {
    Table[getIndex(word)].search(word);
}

void Dictionary::max() {
    for (int i = 0; i<36; i++ )
     Table[i].max();
}

