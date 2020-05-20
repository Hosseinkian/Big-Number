#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"
#include <string>

class MyBigNumber : public BigNumber{
    friend MyBigNumber operator* ( MyBigNumber& bigNum1 , MyBigNumber & bigNum2);
private :
    MyBigNumber unsignedMultiplyOneDigit( int coefficient );
public:
    MyBigNumber() : BigNumber(){};
    MyBigNumber(const std::string str) : BigNumber( str ){};
    MyBigNumber( const char * myCharArray ) : BigNumber( myCharArray ) {}
    MyBigNumber(const long & intNum ) : BigNumber ( intNum ){};
    MyBigNumber ( const BigNumber & myBig ) : BigNumber ( myBig ){};   // copy constructor
    MyBigNumber ( BigNumber && myBig ) noexcept : BigNumber ( myBig ){};  // move constructor
    MyBigNumber operator<<( unsigned shift );
    MyBigNumber multByOneDigit( int coefficient );
};

#endif
