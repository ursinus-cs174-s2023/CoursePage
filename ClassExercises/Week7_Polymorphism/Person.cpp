#include <iostream>
#include <string>
#include <stdlib.h>
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

int main(int argc, char** argv) {
    Person chris("Chris", 34, 6);

    Student elijah("Elijah", 100, 9001, 1);

    StudentAthlete eric("Eric", 95, 511, 2, "track");

    StudentAthlete aj("AJ", 19, 10000, 1, "track");
    
    Person* people[3] = {&chris, &elijah, &eric};
    
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
    for (int i = 0; i < 3; i++) {
        people[i]->printInfo();
        cout << "\n";
    }

    return 0;
}