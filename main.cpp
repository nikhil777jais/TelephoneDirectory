#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <nikhil.h>
#include "tellist.h"
inline void go_on()
{
    cout << "\n\nGo on with return! ";
    cin.sync(); cin.clear(); // No previous input
    while( cin.get() != '\n');
}
using namespace std;
char getYesorNo()
{
    char c;
    do
    {
        cin.sync(); cin.clear();
        cin.get(c); c = toupper(c);
    }
    while(c != 'Y' && c != 'N');
    return c;
}
char askForSave()
{
    cout << "Do you want to save new data to file(y/n) :";
    char c;
    do
    {
        cin.sync(); cin.clear();
        cin.get(c); c = toupper(c);
    }
    while(c != 'Y' && c != 'N');
    return c;
}
int main()
{
    Tellist list1;
    string name1, nr1, fname;
    char choice;
    while(choice != 'Q')
    {
        cls;
        setcolor(10);
        cout << "\n\t***** Telephone List Menu *****\n\n\n";
        cout << "\t\tD = Display all entries    \n\n"
             << "\t\tF = Find a telephone number\n\n"
             << "\t\tA = Append an entry        \n\n"
             << "\t\tE = Erase an entry         \n\n"
             << "\t\tQ = Quit the program       \n\n"
             << "\t\tO = Open a file            \n\n"
             << "\t\tW = Save in the file       \n\n"
             << "\t\tU = Save as                \n\n";
        cout << "       Your Choice :";
        setcolor(7);
        cin.sync();cin.clear();
        cin.get(choice); choice = toupper(choice);
        switch(choice)
        {
            case 'D':
                    {
                        cls;
                        setcolor(11);
                        cout << "\n\t***** Displaying All Element *****\n\n\n";
                        list1.print();
                        setcolor(7);
                        go_on();
                        break;
                    }
            case 'F':
                    {
                        cls;
                        setcolor(13);
                        cout << "\n\t***** Searching Of An Entry *****\n\n\n";
                        cout << "\n\nEnter Name : "; cin.sync(); getline(cin,name1);
                        int loc = list1.print(name1);
                        cout << loc << " Matches are found !" << endl;
                        setcolor(7);
                        go_on();
                        break;
                    }
            case 'A':
                    {
                        cls;
                        char key = 'Y';
                        setcolor(12);
                        while(key == 'Y')
                        {
                            cls;
                            cin.sync();
                            cout << "\n\t***** Adding New Entry *****\n\n\n";
                            cout << "\t\tEnter Name      : ";   if(!getline(cin,name1)){return false;}
                            cout << "\n\t\tEnter Number    : ";   if(!getline(cin,nr1))  {return false;}
                            if(list1.append(name1,nr1))
                                cout << "\n  Entry " << name1 << " Added Successfully!" << endl;
                            else
                                cout << "\n  Name is already taken !" << endl;
                             cout << "\t" << (100 - list1.getcount()) << " Location are blank\n\n";
                            cout << "  Do you want to add more(Y/N)   : ";
                            key = getYesorNo();
                        }
                        setcolor(7);
                        break;
                    }
            case 'E':
                        cls;
                        setcolor(14);
                        cin.sync();
                        cout << "\n\t***** Deleting An Entry *****\n\n\n";
                        cout << "\t\tEnter Name   : ";   getline(cin,name1);
                        if(list1.erase(name1))
                            cout << "\n  Entry "<< name1 << " Erased successfully !" << endl;
                        else
                            cout << "\n  Entry Not found !" << endl;
                        setcolor(7);
                        go_on();
                        break;
            case 'O':
                    {
                        cls;
                        setcolor(13);
                        cout << "\n\t***** Reading Data from file *****\n\n\n";
                        if(list1.isDirty() && askForSave() == 'Y')
                            list1.save();
                        if( list1.load())
                            cout << "\t\tTelephone list read from file "
                                 << list1.getFilename() << "!"
                                 << endl;
                        else
                            cerr << "\n\t\tTelephone list not read!"
                                 << endl;
                        setcolor(7);
                        go_on();
                        break;
                    }
            case 'W':
                    {
                        cls;
                        setcolor(12);
                        cout << "\n\t***** Writing on A File *****\n\n\n";
                        if(list1.getFilename().empty())
                        {
                            cout << "\n\nEnter File Name : "; cin.sync(); getline(cin, fname);
                            if(!list1.setFilename(fname))
                                cerr << "File is not declared!";
                        }
                        if(list1.save())
                            cout << "Data written to file Successfully!" << endl;
                        setcolor(7);
                        go_on();
                        break;
                    }
            case 'U':
                    {
                        cls;
                        cout << "\n\t***** Writing on A new File *****\n\n\n";
                        setcolor(12);
                        if(list1.saveAs())
                            cout << "Data written to file Successfully!" << endl
                                 << "File Name  : " << list1.getFilename() << endl;
                        else
                            cout << "Data written to file Successfully!" << endl;


                        setcolor(7);
                        go_on();
                        break;
                    }
            case 'Q':
                        exit(0);
                        break;
            default:
                cout << "Invalid Input !" << endl;
                go_on;
        }
    }
    return 0;
}
