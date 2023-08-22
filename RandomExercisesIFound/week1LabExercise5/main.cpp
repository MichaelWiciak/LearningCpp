#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
bool is_negative(int value) { return value < 0; }
double increase(double x){
    return x*2;
}
int main() {
    int maxSize=5;
    vector<double> aList(maxSize, -1);
    cout << "enter 5 numbers: " << endl;
    for (int i=0; i<maxSize; i++){
        cin >> aList[i];
    }
    std::sort(aList.begin(), aList.end()) ;
    cout << "Sorted List: ";
    for (double i: aList){
        if (i!=aList[aList.size()-1]){
            cout << i << ", ";
        }
        else{
            cout << i << endl;
        }
    }
    cout << "Multipled by two and reversed: ";
    std::transform(aList.begin(), aList.end(), aList.begin(), increase);
    std::reverse(aList.begin(), aList.end());
    for (double i: aList){
        if (i!=aList[aList.size()-1]){
            cout << i << ", ";
        }
        else{
            cout << i << endl;
        }
    }
    return 0;
}
