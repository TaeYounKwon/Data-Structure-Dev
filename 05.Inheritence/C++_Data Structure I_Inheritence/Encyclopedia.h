#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book
{
public:
    void SetEdition(string bookEdition);
    void SetNumVolumes(int numV);

    string GetEdition();
    int GetNumVolumes();
    void PrintInfo();

protected:
    string edition;
    int numVolumes;
};

#endif