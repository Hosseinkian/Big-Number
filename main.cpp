#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    MyBigNumber myBig = "0";
    MyBigNumber myBig2 = "-11";
    cout << myBig * myBig2 << endl;
    return 0;
}
