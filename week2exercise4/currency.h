#ifndef CURRENCY_H
#define CURRENCY_H


#include <string>
class Currency
{
public:
    Currency(int h, int w): super(w), sub(h){}
    virtual std::string toString()=0;
private:
    int super, sub;
};

#endif // CURRENCY_H
