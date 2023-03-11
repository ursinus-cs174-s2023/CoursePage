#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
using namespace std;


class Person {
    protected:
        string name;
        double height;
        string classType;
        int age;
        

    public:
        Person(string name, int age, double height) {
            classType = "Person";
            this->name = name;
            if (age < 120 && age >= 0) {
                this->age = age;
            }
            else {
                age = 0;
            }
            this->height = height;
        }
        void celebrateBirthday() {
            age++;
        }
        int getAge() {
            return age;
        }

        virtual void printInfo() {
            cout << classType << " ";
            cout << name << " is " << this->getAge() << " years old and height " << height;
        }

        string getClassType() {
            return classType;
        }

        string getName() {
            return name;
        }
};


class Student: public Person {
    private:
        int classYear;

    public:
        Student(string name, int age, double height, int classYear):Person(name, age, height) {
            classType = "Student";
            this->classYear = classYear;
        }
        bool tooTallForAFreshman() {
            return classYear == 1 && height > 9000;
        }
        virtual void printInfo() {
            Person::printInfo();
            cout << ", and class year " << classYear;
        }
};

class StudentAthlete: public Student {
    private:
        string sport;
    
    public:
        StudentAthlete(string name, int age, double height, int classYear, string sport):Student(name, age, height, classYear) {
            this->sport = sport;
            classType = "StudentAthlete";
        }

        void printInfo() {
            Student::printInfo();
            cout << ", plays " << sport;
        }
};

/**
* @param people: Array of people
* @param N: Length of the array
* @param person: Person I want to add
* @param i: Add at this index
*
* @param Reference to a new array that satisfies these properties
*/
Person** addPerson(Person** people, int N, Person* person, int i) {
    Person** newPeople = new Person*[N+1];
    for (int j = 0; j < N; j++) {
        if (j < i) {
            newPeople[j] = people[j];
        } else if (j >= i) {
            newPeople[j+1] = people[j];
        }
    }
    newPeople[i] = person;
    delete[] people;
    return newPeople;
}

int main(int argc, char** argv) {
    Person chris("Chris", 34, 6);

    Student elijah("Elijah", 100, 9001, 1);

    StudentAthlete eric("Eric", 95, 511, 2, "track");

    StudentAthlete aj("AJ", 19, 10000, 1, "track");
    
    Person** people = new Person*[3];
    people[0] = &chris;
    people[1] = &elijah;
    people[2] = &eric;

    people = addPerson(people, 3, &aj, 1);
    
    // The bad way of doing it!!!
    /*for (int i = 0; i < 3; i++) {
        if (people[i]->getClassType() == "Person") {
            Person* p = (Person*)people[i];
            p->printInfo();
        }
        else if(people[i]->getClassType() == "Student") {
            Student* s = (Student*)people[i];
            s->printInfo();
        }
        else if(people[i]->getClassType() == "StudentAthlete") {
            StudentAthlete* sa = (StudentAthlete*)people[i];
            sa->printInfo();
        }
        cout << "\n\n";
    }*/

    // 


    list<Person*> peopleList; // 
    peopleList.push_back(&chris);
    peopleList.push_back(&elijah);
    peopleList.push_back(&eric);
    peopleList.push_front(&aj);

    list<Person*>::iterator it;

    // Find and delete Chris
    for (it = peopleList.begin(); it != peopleList.end(); it++) {
        Person* p = (Person*)*it;
        if (p->getName() == "Chris") {
            // Delete Chris
            it = peopleList.erase(it);
        }
    }
    
    // Print out what's left
    for (it = peopleList.begin(); it != peopleList.end(); it++) {
        Person* p = (Person*)*it;
        p->printInfo();
        cout << "\n";
    }

    delete[] people;

    return 0;
}