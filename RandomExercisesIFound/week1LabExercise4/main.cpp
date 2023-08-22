#include <string>
#include <iostream>
#include <vector>

using namespace std;

double averageOfArray(vector<double> aList){
    double output=0;
    for (int i=0; i<(int)aList.size(); i++){
        output+=aList[i];
    }
    return output / (double) aList.size();
}


int main()
{
    int maxIterations=5;
    vector<double> aList(maxIterations, -1);
    for (int i=0; i<maxIterations; i++){
        cout << endl << "enter 5 numbers:" << endl << ">";
        cin >> aList[i];
    }
    cout << "The mean is: " << averageOfArray(aList) << endl;
    return 0;
}
