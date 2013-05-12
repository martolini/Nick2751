#include <iostream>

using namespace std;


class cSales {
    
    friend bool operator == (const cSales &, const cSales &);
    // equal if same number of cells and all corresponding cells are equal
    
public:
	cSales(void);                           // Default Constructor - all cells set to 0
	cSales(const cSales &);           // Copy Constructor
    cSales operator+(const cSales &) const;   // Answerâ€™s cells are the sum of corresponding cells
    //  use the smaller value of cellsUsed for the return value
    ~cSales(void);
private:
	int * info;
    int  cellsUsed;
};

cSales::cSales() : info(NULL), cellsUsed(0) {}

cSales::cSales(const cSales &c) : cellsUsed(c.cellsUsed) {
    info = new int[cellsUsed];
    for (int i=0; i<cellsUsed; ++i) {
        info[i] = c.info[i];
    }
}

cSales cSales::operator+(const cSales &c) const {
    cSales output;
    output.cellsUsed = cellsUsed<c.cellsUsed? cellsUsed : c.cellsUsed;
    output.info = new int[output.cellsUsed];
    for (int i=0; i<output.cellsUsed; ++i) {
        output.info[i] = info[i]+c.info[i];
    }
    return output;
}

cSales::~cSales() {
    delete [] info;
}

bool operator == (const cSales &lhs, const cSales &rhs) {
    if (lhs.cellsUsed == rhs.cellsUsed) {
        for (int i=0; i<lhs.cellsUsed; ++i) {
            if (lhs.info[i] != rhs.info[i])
                return false;
        }
        return true;
    }
    return false;
}
