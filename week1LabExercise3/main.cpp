#include <string>
#include <iostream>
using namespace std;

int main()
{
    string target = "World";
    string message = "Hello " + target + "!";
    cout << message << endl;
    cout << message.length() << endl;
    cout << message[6] << endl;
    cout << message.find("W") << endl;
    message.replace(0, 5, "Goodbye");
    cout << message << endl << endl << endl;
    // other code :)
    string text = "hello world";
    int exitFlag=0;
    int size = text.length();
    while (exitFlag==0){
        cout << text.substr(0, size) << endl;
        size-=1;
        if (size<=0){
            exitFlag=1;
        }
    }
}
