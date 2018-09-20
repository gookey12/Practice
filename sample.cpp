#include <iostream>
#include <string>

using namespace std;

typedef (int) (*funcPt) (int, int);

void pterManip() {
    char *charVal = new char();
    int *val = new int();

    cout << "start of pterManip" << endl;
    // val = 0x41424344
    *val = 1094861636;
    cout << "\t" << "val is " << *val << " address is " << val << endl;
    cout << "\t" << "size of val " << sizeof(*val) << " size of charVal " << sizeof(*charVal) << endl;
    // intel is big endian encoding, less significant becomes most significant
    charVal = (char *) val + sizeof(*val) - 1;
    cout << "\t" << "address of val " << val << " address of charVal " << (void *) charVal << endl;
    cout << "\t\t" << "charVal = " << *charVal << endl;
    charVal--; cout << "\t\t" << "charVal = " << *charVal << endl;
    charVal--; cout << "\t\t" << "charVal = " << *charVal << endl;
    charVal--; cout << "\t\t" << "charVal = " << *charVal << endl;
    cout << "\t" << "address of val " << val << " address of charVal " << (void *) charVal << endl;
    cout << "end of pterManip" << endl;
}

int main(int argc, char *argv[]) {
    pterManip();
    return 0;
}