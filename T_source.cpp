#include <fstream>
#include <iostream>
#include <iomanip>
#include "tellist.h"
using namespace std;

// bool definition of append method
bool Tellist :: append(const string &t_name, const string &t_nr)
{
    if(t_name.length() > 1 && count < MAX && search(t_name) == PSEUDO)
    {
        element[count].name = t_name;
        element[count].nr   = t_nr;
        ++count;
        dirty = true;
        return true;
    }
    return false;
}
// function of search
int Tellist :: search(const string & a_name)
{
    for(int i = 0; i < count; i++)
        if(element[i].name == a_name)
            return i;
    return PSEUDO;
}
//method of erasing one elemnet
bool Tellist :: erase (const string& t_name)
{
    int loc = search(t_name);
    if(loc != PSEUDO)
    {
        element[loc].name = element[count-1].name;
        element[loc].nr   = element[count-1].nr;
        --count;
        dirty = true;
        return true;
    }
    else
        return false;
}
void Tellist :: print() const
{
    if(count == 0)
        cout << "\n\n\t\tThere is no Entry in the list \n";
    else
    {
        cout << "\t" << left << setw(22) << "Name" << left << setw(14) << "Telephone No."
             << "\n\t--------------------------------------" << endl;
        for(int i = 0; i < count; i++)
            printline(i);
    }
}
inline void Tellist :: printline(int &i) const
{
    cout << "\t" << left << setw(22) << element[i].name
         << "+91 " << setw(12) << element[i].nr << endl;
}

int Tellist :: print(string const &t_name)
{
    int matches = 0, len = t_name.length();
    for(int i = 0; i < count; i++)
    {
        if(element[i].name.compare(0, len, t_name) == 0)
        {
            if(matches == 0)
                cout << "\t" << left << setw(22) << "Name" << left << setw(14) << "Telephone No. "
                     << "\n\t--------------------------------------" << endl;
            ++matches; printline(i);
        }
    }
    if(matches == 0)
        cout << "No corresponding entry found!" << endl;
    return matches;
}
bool Tellist :: setFilename( const string& fn)
{
    if(fn.empty())
        return false;
    else
    { filename = fn; dirty = true; return true;}
}
const string& Tellist :: getFilename() const
{
    return filename;
}

bool Tellist :: isDirty() const
{
    return dirty;
}
bool Tellist :: load()
{
    if(filename.empty())
    {
        cout << "\t\t----- Enter file name to be read ----\n"
             << "\t\t File name :";
        string newfile;
        cin.sync(); cin.clear();
        getline(cin, newfile);
        setFilename(newfile);
    }

    if(filename.empty())
    {
        cerr << "\n\t\t** No file is declared **" << endl;
        return false;
    }
    ifstream infile(filename, ios::in | ios::binary );
    if(!infile)
    {
        cerr << "\n\t\tError in opening the File" << filename << endl;
        return false;
    }
    int i = 0;
    while(i < MAX)
    {
        getline(infile, element[i].name, '\0');
        getline(infile, element[i].nr, '\0');
        if(!infile)
            break;
        else
            ++i;
    }
    if(i == MAX)
    {
        cerr << "\n\t\tMaximum Capacity Reached!" << endl;
    }
    if(!infile.eof())
        cerr << "\n\t\tError in Reading complete file" << endl;
    count = i;
    dirty = false;
    return true;
}
bool Tellist :: saveAs()
{
    cout << "\t\t----- Enter new file name ----\n"
        << "\t\t File name :";
    string newfile;
    cin.sync(); cin.clear();
    getline(cin, newfile);
    if(!setFilename(newfile))
    {
        cerr << "\n\t\t** No file is declared **" << endl;
        return false;
    }
    else
    {
        return save();
    }
}
bool Tellist :: save()
{
    //filename should be already set before calling
    if(filename.empty())
    {
        return saveAs();
    }
    if(!dirty)
        return false;
    ofstream outfile(filename, ios :: out | ios :: binary);
    if(!outfile)
    {
        cerr << "\n\t\tError in opening the File  " << filename << endl;
        return false;
    }
    int i = 0;
    while( i < count)
    {
        outfile << element[i].name << '\0';
        outfile << element[i].nr << '\0';
        if(!outfile)
            break;
        else
            ++i;
    }
    if( i < count )
    {
        cerr << "\n\t\tError writing to file " << filename << endl;
        return false;
    }
    dirty = false;
    return true;
}
