#include <iostream>
using namespace std;

class Person {
    int age;
public:
	Person(int initialAge);
	void yearPasses();
	void amIOld();
};

Person::Person(int initialAge){
    if (initialAge < 0){
        cout << "Age is not valid, setting age to 0.\n";
        age = 0;
    }
    else		age = initialAge;
}

void Person::yearPasses(){
	++age;
}

void Person::amIOld(){
    if (age < 13)               cout << "You are young.\n";
    else if (age < 18)          cout << "You are a teenager.\n";
    else                        cout << "You are old.\n";
}

int main(){
    int t, age;
    cin >> t;
    for (int i = 0; i < t; i++){
    	cin >> age;
        Person p(age);
        p.amIOld();
        for (int j = 0; j < 3; j++)
        	p.yearPasses();
        p.amIOld();
		cout << endl;
    }
    return 0;
}
