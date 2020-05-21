#include <iostream>
#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    MyBigNumber myBig1 = "111111";
    MyBigNumber myBig2 = "123456789";
    MyBigNumber myBig3 = "-000136776";
    cout << ++myBig3 << endl;
    cout << myBig3-- << endl;
    cout << --myBig3 << endl;
    cout << myBig3++ << endl;
    cout << myBig3 << endl;
    cout << myBig1 + myBig2 << endl;
    cout << myBig2 - myBig1 << endl;
    cout << myBig1 * myBig2 << endl;
    cout << myBig1.power(5) << endl;
    cout << myBig2(4 , 2) << endl;
    cout << boolalpha << (myBig1 == myBig2) << endl;
    cout << boolalpha << (myBig1 != myBig2) << endl;
    cout << boolalpha << (myBig1 >= myBig2) << endl;
    cout << boolalpha << (myBig1 <= myBig2) << endl;
    cout << myBig1.multByOneDigit(3)<< endl;
    cout << (myBig2<<3) << endl;
    cout << (-myBig2) << endl;
    try {
        (myBig1>>8);
    }
    catch(invalid_argument e){
        cout << e.what() << endl;
    }

    return 0;
}
