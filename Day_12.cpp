#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
	string firstName;
	string lastName;
	int id;

public:
	//	this also works fine
	//	: firstName(firstName), lastName(lastName), id(identification) {}
	Person(string firstName, string lastName, int identification){
		this->firstName = firstName;
		this->lastName = lastName;
		this->id = identification;
	}

	void printPerson(){
		cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << endl;
	}
};

class Student : public Person {
	vector<int> testScores;

public:
	Student(string firstName, string lastName, int id, const vector<int>& scores)
	: Person(firstName, lastName, id), testScores(scores.begin(), scores.end()){}

	char calculate(){
		float avg = 0;
		for (size_t i = 0; i < testScores.size(); i++)
			avg += testScores[i];
		avg /= testScores.size();

		if (avg < 40)               return 'T';
		else if (avg < 55)          return 'D';
		else if (avg < 70)          return 'P';
		else if (avg < 80)          return 'A';
		else if (avg < 90)          return 'E';
		else                        return 'O';
	}
};

int main(){
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for (int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student *s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << endl;
	return 0;
}
