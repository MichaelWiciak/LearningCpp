#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool palindrome(string x){
    x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
    string copyX = x;
    std::reverse(x.begin(), x.end());
    cout << x << " <--> " << copyX << endl;
    if (x==copyX){
        return true;
    }
    return false;
}

int main()
{
    cout <<palindrome("wanna") << endl; // returns false
    cout <<palindrome("anna") << endl;  // returns true
    cout <<palindrome("hello") << endl; // returns false
    cout <<palindrome("are we not drawn onward to new era") << endl; // returns true

    cout << "Should be false true false true" << endl;
    return 0;
}
