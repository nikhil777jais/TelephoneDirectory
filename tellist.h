#ifndef TELLIST_H_INCLUDED
#define TELLIST_H_INCLUDED
#include <iomanip>
using namespace std;
#define MAX 100
#define PSEUDO -1
struct Elemnet
{
    string name, nr;
};
class Tellist
{
private:
    Elemnet element[MAX];
    int count = 0;
    bool dirty = false; // reminder for new data input
    string filename;
public:
    bool append(const string& t_name, const string& t_nr);
    int  search(const string&);
    bool erase (const string&);
    void print() const;
    void printline(int &) const;
    int print(string const &);
    int getcount()
    {
        return count;
    }
    //File handling Mehodes
    const string& getFilename() const;
    bool setFilename( const string& fn);
    bool isDirty() const;
    bool load(); // Read data from the file
    bool save(); // Save data.
    bool saveAs();
};

#endif // TELLIST_H_INCLUDED
