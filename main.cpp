#include <iostream>
#include <cstdint>

#include "BigNumber.h"

using namespace std;

int main() {
    BigNumber myBig = "12340";
    cout << myBig++ << endl;
    cout << myBig-- << endl;
    cout << --myBig << endl;
    cout << ++myBig << endl;
    return 0;
}
