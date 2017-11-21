#include <iostream>
#include "BST.h"
#include "BST.cpp"
#include "Dictionary.h"
#include "Dictionary.cpp"

using namespace std;

int main() {
    int casenum;
    Dictionary dict;
    string path;
    cout<<"Which case do you want to choose?"<<endl<<"Case 1: Initial run:"<<endl<<"No dictionary is available, this is "
            "the first time you're creating a dictionary."<<endl<<"Case 2: Cumulative run:"<<endl<<"There are previous"
            "dictionaries to import before adding a new one"<<endl<<"Case 3: Query run: "<<endl<<"Import from a previous"
            " dictionary and ask about it"<<endl<<"Insert wanted case number:  ";

    cin>>casenum;
    switch (casenum){
        case 1:
            cout<<"Enter the filename that you want to build the dictionary with: ";
            cin>>path;
            dict.setdPath;
            dict.read(path);

    }








    return 0;
}