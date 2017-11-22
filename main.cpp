#include <iostream>
#include "Dictionary.h"
#include "Dictionary.cpp"

using namespace std;

int main()
{
    int casenum, num;
    Dictionary dict;
    string path, word;
    cout<<"Which case do you want to choose?"<<endl<<"Case 1: Initial run:"<<endl<<"No dictionary is available, this is "
            "the first time you're creating a dictionary."<<endl<<"Case 2: Cumulative run:"<<endl<<"There are previous"
                " dictionaries to import before adding a new one"<<endl<<"Case 3: Query run: "<<endl<<"Import from a previous"
                " dictionary and ask about it"<<endl<<"Insert wanted case number:  ";
    cin>>casenum;

    switch (casenum){
        case 1:
        {cout<<"Enter the filename that you want to build the dictionary with: ";
            cin>>path;
            dict.read(path);
            dict.storeDictionary();
        }
            break;

        case 2:
        {
            cout<<"Importing files from default file"<<endl;
            dict.import();
        }
            break;

        default:
        {
            cout<<"Importing default dictionary"<<endl;
            dict.import();
        }
    }
    do {
        cout << "Your now available actions are: " << endl
             << "1: View the current dictionary in memory " << endl
             << "2: Add another file to the dictionary database" << endl
             << "3: Save the dictionary to the disk file" << endl
             << "4: Search and obtain the frequency of a given word" << endl
             << "5: List highest frequency for letter/digit tree"<<endl
             << "0: Exit program (this will automatically save the current dictionary to default file) "<<endl<<endl
             <<"Please enter the action number: "<<endl;
        cin>>num;

        switch (num){
            case 1:
                dict.traverse();
            break;

            case 2:
            {   cout<<"Please enter the filename you wish to add to the dictionary: ";
                cin>>path;
                dict.read(path);}
            break;
            case 3:
            {
                cout<<"Saving dictionary to disk file"<<endl;
                dict.storeDictionary();
            }
            break;
            case 4:
            {   cout<<"Please enter the word you want to search for: ";
                cin>>word;
                dict.search(word);
            }
            break;
            case 5:
                dict.max();
            break;
            default:
                dict.storeDictionary();


        }
    }while (num!=0);
    return 0;
}