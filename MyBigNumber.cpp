#include "MyBigNumber.h"

using namespace std;

MyBigNumber MyBigNumber::unsignedMultiplyOneDigit(int coefficient) {
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

MyBigNumber MyBigNumber::multByOneDigit(int coefficient) {
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


MyBigNumber MyBigNumber:: operator<<( unsigned shift ) {
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

MyBigNumber operator*( MyBigNumber &bigNum1, MyBigNumber & bigNum2) {
    MyBigNumber Product="0";
    if(bigNum1=="0" || bigNum2=="0" || (bigNum1 == "0" && bigNum2 == "0")){
        Product="0";
        Product.sign=true;
    }

    if(bigNum1.sign==bigNum2.sign){
        unsigned int i = 0;
        for(; i < bigNum2.numOfDigits; i++){
            Product= Product + (bigNum1 << i).multByOneDigit(bigNum2[i]);
        }
        Product.sign=true;
    }

    if(!bigNum1.sign && bigNum2.sign){
        unsigned int j=0;
        for(; j < bigNum2.numOfDigits; j++){
            Product= Product + (bigNum1 << j).multByOneDigit(bigNum2[j]);
        }
        Product.sign=bigNum1.sign;
    }

    if(bigNum1.sign && !bigNum2.sign){
        unsigned int k=0;
        for(; k < bigNum2.numOfDigits; k++){
            Product= Product + (bigNum1 << k).multByOneDigit(bigNum2[k]);
        }
        Product.sign=bigNum2.sign;
    }

    return Product;
}


