#include <iostream>
#include "money.h"
#include <math.h>
using namespace std;

#include<stdexcept>
Money::Money(int e, int c)
{
if (e < 0) {
           throw invalid_argument("invalid euros");
     }
     if (c < 0 || c > 99) {
           throw invalid_argument("invalid cents");
     }
     euros = e; cents = c;
}

int Money::getEuros() const
{
     return euros;
}
int Money::getCents() const
{
     return cents;
}
string Money::toString() const
{
        // to_string is a utility in the std namespace
     return "EUR " + to_string(euros) +'.' + to_string
(cents);
}

Money Money::plus(const Money& other) const
{
    int additionalEuro=0;
    if (cents + other.cents > 100){
        additionalEuro +=1;
    }

    return Money(euros + other.euros + additionalEuro, cents + other.cents - additionalEuro*100);
}

Money operator+ (const Money& m1, const Money& m2)
{
     int e = m1.getEuros() + m2.getEuros();
     int c = m1.getCents() + m2.getCents();
     return Money(e + c/100, c % 100);
}

Money operator+ (const Money& m1, const int value){
    int e = m1.getEuros();
    int c = m1.getCents();
    return Money(e+ value + c/100, c % 100);
}

Money operator+ (const Money& m1, const double value){
    int e = m1.getEuros() + floor(value);
    int c = m1.getCents() + ((value-floor(value))*100);
    cout << ((value-floor(value))*100) << endl;
    return Money(e + c/100, c % 100);
}
int main() {
     Money m1(2, 50);
     Money m2(0, 52);
     Money sum = m1+m2;
     cout << "Sum = " << sum.toString() << endl;
     Money m3(2, 50);
     cout << ( m3 + 1 ).toString() << endl;
     Money m4(2, 80);
     double x = 2.80;
     cout << ( m4 + x ).toString() << endl;
     Money m10 (23, 101);
     return 0; // everything went as planned
}


