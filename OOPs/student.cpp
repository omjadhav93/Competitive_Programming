#include<iostream>
using namespace std;

class Student{
    private:
        string name;
        int age;
        int rollNumber;
    public:
        Student(string name, int age, int rollNumber){
            this->name = name;
            this->age = age;
            this->rollNumber = rollNumber;
        }
        void display(){
            cout<<"Name: "<<name<<", Age: "<<age<<", Roll Number: "<<rollNumber<<endl;
        }
};

int main(){
    Student s1("Alice", 20, 101);
    s1.display();
    return 0;
}