#ifndef LAB2_MONEY_H
#define LAB2_MONEY_H
#include <string>
using namespace std;
class Money {
     public:
           Money(int, int);
           int getEuros() const;
           int getCents() const;
           string toString() const;
           Money plus(const Money&) const;
     private:
           int euros, cents;
};
#endif //LAB2_MONEY_H


