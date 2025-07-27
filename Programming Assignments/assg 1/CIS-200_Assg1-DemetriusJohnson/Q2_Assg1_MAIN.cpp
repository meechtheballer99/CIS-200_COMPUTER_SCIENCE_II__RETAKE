// CIS-200_Assg1-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Author: Demetrius E Johnson
//Date: 12 MAR 2021
//Last Modification Date: 12-03-2021
//Purpose: demonstrate the use of defining a class






#include <iostream>
#include <fstream>
using namespace std;


//Employee class definition
class Employee
{
private:
    int age;
    int id;
    float salary;
public:
    //You need to provide the definition of the default constructor and 
    //the first three member functions(setAge, setId and setSalary) 
    //inside the scope defined by the brackets of class Employee

    Employee() { age = 0; id = 0; salary = 0; }  // default constructor: age=0, id=0, and salary=0
    void setAge(int x) { age = x; }    // let age = x
    void setId(int x) { id = x; }       //  let id = x
    void setSalary(float x) { salary = x; }  // salary = x


    void print();   // print out the values of attributes on computer screen
    void print(fstream& os);   // print out the values of attributes to a file
    Employee(Employee& x);   // copy constructor                    
    Employee& operator= (Employee& x); // equal sign operator
    int getAge();        // return age
    int getId();            // return id
    float getSalary();  //  return salary 
};


int main()
{
    cout << "---WELCOME to the Simple Class Construction Program ----By Demetrius Johnson\n\n";

   // create 4 Employee objects: a, b, c, d
    Employee a, b, c, d;

   // set the values of a, b and c according to the above table
    a.setAge(40);
    a.setId(111);
    a.setSalary(30000);

    b.setAge(41);
    b.setId(112);
    b.setSalary(31000);

    c.setAge(42);
    c.setId(113);
    c.setSalary(32000);

    cout << "\nOriginally assigned values of created objects a, b, c, and d : \n\n";
    cout << "Contents of Employee a: ";
    a.print();
    cout << endl;
    cout << "Contents of Employee d: ";
    b.print();
    cout << endl;
    cout << "Contents of Employee c: ";
    c.print();
    cout << endl;
    cout << "Contents of Employee d: ";
    d.print();
    cout << endl << endl;

   //  Use copy constructor to assign the content of object a to the content of object e
    Employee e(a);

   //  print out the contents of a and e to show they are the same
    cout << "Using copy constructor --> Employee e(a); : \n\n";
    cout << "Contents of Employee a: ";
    a.print();
    cout << endl;
    cout << "Contents of Employee e: "; 
    e.print();
    cout << endl << endl;


   //  Use “=” operator to assign the content of object b to the content of object d
    d = b;

   //  print out the contents of b and d to show they are the same
    cout << "Using =operator --> d = b; : \n\n";
    cout << "Contents of Employee b: ";
    b.print();
    cout << endl;
    cout << "Contents of Employee d: ";
    d.print();
    cout << endl;
   // create an output file name: “output.txt”
       
    fstream os("output.txt", ios::out);
    if (!os.is_open()) { cout << "~FILE NOT OPENED SUCCESSFULLY~"; }
    cout << "\nNow sending the contents of d and e to an output file called 'output.txt';\n  ~navigate to and open the file to check its contents." << endl << endl;

   // output the contents of d and e to the file, “output.txt”
    os << "Contents of Employee d: ";
    d.print(os);
    os << endl;
    os << "Contents of Employee e: ";
    e.print(os);
    os << endl;

    os.close();

    cout << "\n\n\n~....Program has finished execution...exiting....\n";
    system("pause");


    return 0;
}


//function defnitions below this line

//NOTE***: no mention was made in the assignment as to whether or not we must define print, copy constructor, and overloaded operator= 
//inside or outside declaration of class Employee, so I just defined them outside using scope operator.

void Employee::print() {
    
    cout << "age: " << age << " id: " << id << " salary: " << salary;

}   // print out the values of attributes on computer screen
void Employee::print(fstream& os) {

    os << "age: " << age << " id: " << id << " salary: " << salary;

}   // print out the values of attributes to a file
Employee::Employee(Employee& x) {

    this->age = x.age;
    this->id = x.id;
    this->salary = x.salary;

}  // copy constructor
Employee& Employee::operator=(Employee& x) {

    this->age = x.age;
    this->id = x.id;
    this->salary = x.salary;

    return *this;

}// equal sign operator

//define other three member functions(getAge, getId, and getSalary) outside the scope defined by the brackets of class Employee,

int Employee::getAge() { return age; }        // return age
int Employee::getId() { return id; }            // return id
float Employee::getSalary() { return salary; }  //  return salary

