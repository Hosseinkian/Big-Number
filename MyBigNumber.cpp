#include "MyBigNumber.h"

using namespace std;

BigNumber MyBigNumber::unsignedMultiplyOneDigit(int coefficient) {
    MyBigNumber product;
    product.sign = true;
    product.numOfDigits = numOfDigits + 1;
    product.numArray = new int8_t [product.numOfDigits];
    int8_t carry = 0;
    int8_t m ;
    size_t i{0};

    for ( ; i < numOfDigits ; ++i){
        m = coefficient * numArray[i] + carry;
        product[i] = m % 10;
        carry = m / 10;
    }
    if ( carry == 0){
        product.numOfDigits -= 1;
    }
    else {
        product[i] = carry;
    }

    int numOfZerosOnLeft = 0;
    size_t j{numOfDigits-1};
    while ( product[j] == 0 && j > 0){
        ++numOfZerosOnLeft;
        --j;
    }
    MyBigNumber multi;
    multi.sign = true;
    multi.numOfDigits = product.numOfDigits - numOfZerosOnLeft;
    multi.numArray = new int8_t [multi.numOfDigits];
    for ( size_t i{0} ; i < multi.numOfDigits ; ++i){
        multi [i] = product [i];
    }
    return multi;
}

BigNumber MyBigNumber::multByOneDigit(int coefficient) {
    MyBigNumber product;
    if ( coefficient == 0 ){
      product = unsignedMultiplyOneDigit( 0 );
    }
    if ( sign && coefficient > 0){
        product = unsignedMultiplyOneDigit( coefficient );
    }
    if ( sign && coefficient < 0){
        product = unsignedMultiplyOneDigit( coefficient );
        product.sign = false;
    }
    if ( !sign && coefficient > 0){
        product = unsignedMultiplyOneDigit( coefficient );
        product.sign = false;
    }
    if ( !sign && coefficient < 0){
        product = unsignedMultiplyOneDigit( coefficient );
    }
    return product;
}


BigNumber MyBigNumber:: operator<<( unsigned shift ) {
    if (shift == 0 ){
        return *this;
    }
    else {
        MyBigNumber temp;
        temp.sign = sign;
        temp.numOfDigits = numOfDigits + shift;
        temp.numArray = new int8_t[temp.numOfDigits];
        for (size_t i{0}; i < shift; ++i) {
            temp[i] = 0;
        }
        for (size_t j {shift}; j < temp.numOfDigits ; ++j){
            temp [j] = numArray[j - shift];
        }
        return temp;
    }
}


