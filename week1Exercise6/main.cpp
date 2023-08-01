#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Person {
public:
   string name;
   int age;
   Person(string n, int x) : name(n), age(x){}
   void printNameAndAge() {
      cout << name << " " << age << endl;
   }
};

int main(){
    int maxIterations=3, age;
    string name;
    vector<Person> aListOfPersonObjects;
    for (int i=0; i<maxIterations; i++){
        cout << "Name and age: ";
        cin >> name >> age;
        Person firstPerson(name,age);
        aListOfPersonObjects.push_back(firstPerson);
    }
    for (Person i: aListOfPersonObjects){
        i.printNameAndAge();
    }
    return 0;
}
