#include <iostream>
using namespace std;

/*========================================================================================================*/
/*=================================|   " OOP Concepts with C++ "   |======================================*/
/*======================================== By:Makrious Ayman =============================================*/
/*========================================================================================================*/

//------------------------ Classes & Objects --------------------------

//Classes and Objects
/*  

class clsName
{
public:
    // Data members => variables in the classes
    string firstname;
    string lastname;

    // Method(function) members => functions in the classes
    string fullname(){
        return firstname + " " + lastname;
    }
};

int main(){
    // intializion an object
    clsName person1;

    // Accessing the variables of the class
    person1.firstname = "John";
    person1.lastname = "Doe";

    // Accessing the function we made in the class
    cout << person1.fullname() << endl;
}

*/

//Memory
/*  
=> in the Class Members
- Data members => we create new memory in each object to store the data
- Func. members => we share the same memory for the func. we made in the class for each object
*/

//------------------ Access Specifiers/Modifiers ---------------------

//Access Modifiers
/*  
    -Default Access Modifier -> Private

    1- Private => Accessable inside the class only
    2- Protected => Accessable inside the class and every class inherites this class
    3- Public => Accessable to every one
*/

//------------------------- Properties -------------------------------

//Setters and Getters
/*  
    - When creating private data members we usually put '_' (under score) in the beginng
    of the variable to outstand the private variables from the other ones.

    - set func :
    it is used to make a method that sets the variable to the private one we made
    and be able to initialize it.

    - get func :
    it is used to make a method that gets the variable from the private one we set
    and use or access it.

Example:-
---------

class clsPerson{

private:
    string _FirstName;
    string _LastName;
public:
    //Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    //Property Get
    string FirstName()
    {
        return _FirstName;
    }

    //Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }
    //Property Get
    string LastName()
    {
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
};

int main(){
    clsPerson Person1;

    Person1.setFirstName("Mohammed");
    Person1.setLastName("Abu-Hadhoud");

    cout << "First Name:" << Person1.FirstName() << endl;
    cout << "Last Name:" << Person1.LastName() << endl;
    cout << "Full Name:" << Person1.FullName() << endl;

    system("pause>0");
    return 0;
}

*/

//Read only property
/*  
    - we make this property in order not to be able to
    change or update it like sensitive datas (IDs , passcode, etc..)

    HOW ??
    -By making a getter func only without a setter to this data member

Example:-

class clsPerson{

private:
    int _ID = 123;

public:
    //Property Get only
    int ID(){
        return _ID;
    }
};

int main(){
    clsPerson Person1;

    cout << "ID:" << Person1.ID() << endl;

    system("pause>0");
    return 0;
}

*/

//Setters and Getters through "="
/*  
    - we use "declaration specification (declspec)" function to put "=" instead of
    the name of the function.

Example:-
---------

class clsPerson{

private:
    string _FirstName;

public:
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    string GetFirstName() {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName))   string FirstName;
};

int main(){
    clsPerson Person1;

    Person1.SetFirstName("Mohammed");
    cout << Person1.GetFirstName() <<endl;

    //instead of the above we only write this
    Person1.FirstName = "Mohammed";
    cout << Person1.FirstName;

    system("pause>0");
    return 0;
};
*/

//----------------- Encapsulation and Abstraction --------------------

//Encapsulation
/*  
    - Encapsulation is the process of hiding the data and methods that
    manipulate the data inside a class.

    - It is a way to protect the data and methods from being accessed from
    outside the class.

    HOW??
    - By making the data members private and providing public getter and setter methods.
    Variables + Methods => Class  {Encapsulation}
*/

//Abstraction
/*  
    - Abstraction is a process of hiding the implementation details of an object
    that is not useful for the user.
    - It is a way to represent an object in a simpler way.

    HOW??
    - By providing a public interface for accessing the data and methods of the class.
*/

//----------------- Constructors & Destructors -----------------------

//Constructor
/*  
    - A function with the same name of the class and there isn't any
    data type or void before this fuction name.
    - It is used to initialize the data members of the class.
    - It is called automatically when an object is created from the class.
    - Doesn't have a return type.

Example:-
---------
class clsAddress{

private:

    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public :

    // parametrized constructor
    clsAddress(string AddressLine1, string AddressLine2, stringPOBox, string ZipCode)
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }

    void SetAddressLine1(string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }
    string GetAddressLine1()
    {
        return _AddressLine1;
    }

    void SetAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }
    string GetAddressLine2()
    {
        return _AddressLine2;
    }

    void SetPOBox(string POBox)
    {
        _POBox = POBox;
    }
    string GetPOBox()
    {
        return _POBox;
    }

    void SetZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }
    string GetZipCode()
    {
        return _ZipCode;
    }

    void Print(){
        cout << "\nAddress Details:\n";
        cout << "------------------------";
        cout << "\nAddressLine1: " << _AddressLine1 <<endl;
        cout << "AddressLine2: " << _AddressLine2 << endl;
        cout << "POBox : " << _POBox << endl;
        cout << "ZipCode : " << _ZipCode << endl;
    }
};

int main(){
    clsAddress Address1("Queen Alia Street","B 303","11192","5555");
    Address1.Print();

    system("pause>0");
    return 0;
}

*/

//Copy Constructor
/*  
    => when making a new object and assigning it to be equal to the first object
    the compiler by default will copy the constructor of the first and put it in
    the second one.

Example:-
---------

int main(){
    clsAddress Address1("Queen Alia Street","B 303","11192","5555");
    Address1.Print();

    clsAddress Address2 = Address1; //copy constructor called here
    Address2.Print();
}
    => The output of the second object will be the same of the first one.
*/

//Destructor
/*  
- A function with the same name of the class and there is '~' before the name.

    => a special function that is called when an object is destroyed.
    - It is used to release the memory allocated to the object.
    - It is called automatically when the object goes out of scope.

Example:-
---------

class clsPerson
{
public:
    string FullName;

    //This is Instructor will be called when object is built.
    clsPerson(){
        FullName = "Mohammed Abu-Hadhoud";
        cout << "\nHi, I'm Constructor";
    }

    //This is destructor will be called when object is destroyed.
    ~clsPerson(){
        cout << "\nHi, I'm Destructor";
    }
};

void Fun1()
{
    clsPerson Person1;
    // after exiting from function, person1 will be destroyed and destructor will be called.
}

void Fun2()
{
    clsPerson* Person2 = new clsPerson;
    //always use delete whenever you use new, otherwise object will remain in memory
    delete Person2;
}

int main()
{
    Fun1();
    Fun2();

    system("pause>0");
    return 0;
}

=> After Func1 is finished the object will be destroyed and destructor will be called.
=> After Fun2 is finished the object wont be destroyed because we used pointer to make
the object , if we want to destroy it we must use the delete function.

*/

//Function Overloading
/*  
    => Two functions with the same name but with different parameters.

Example:-
---------

double MySum2DoubleNumbers(double a, double b) {
    return (a + b);
}
int MySum2IntegerNumbers(int a, int b) {
    return (a + b);
}
int MySum3IntegerNumbers(int a, int b, int c) {
     return (a + b + c);
}
int MySum4IntegerNumbers(int a, int b, int c, int d) {
     return (a + b + c + d);
}

int main() {
    cout << MySum2IntegerNumbers(10, 20) << endl;
    cout << MySum2DoubleNumbers(10.1, 20.1) << endl;
    cout << MySum3IntegerNumbers(10, 20, 30) << endl;
    cout << MySum4IntegerNumbers(10, 20, 30, 40) << endl;
    return 0;
} 
*/

//----------------- Static Members & Methods ------------------------

//Static Members
/*  
    => shared variable to all objects.

    - declared using the 'static' keyword.
    - declared inside the class but intialized outside the class.
    - can be accessed using class name or object name.
    - Static members are initialized only once, when the program starts.
    - static members are not inherited.
    - when doing any change to it from a certain object the change is made
    to all other objects also.

Example:-
---------

class clsA{

public:
    int var;
    static int counter;

    clsA(){
        counter++;
    }

    void Print(){
        cout << "\nvar = " << var <<endl;
        cout << "counter = " << counter << endl;
    }
};

int clsA::counter = 0; //static variable initialisation outside the class

int main(){

    clsA A1, A2,A3;

    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    A1.Print();
    A2.Print();
    A3.Print();

    A1.counter = 500;
    cout << "\nafter chaning the static member counter in oneobject:\n";

    A1.Print();
    A2.Print();
    A3.Print();
}
*/

//Static Methods
/*  
    - static methods can only access static members.
    - it can be called directly from the class or from an object.
    - declared using the 'static' keyword.

Example:-
---------

class clsA
{
public:
    static int Function1()
    {
        return 10;
    }
    int Function2()
    {
        return 20;
    }
};

int main(){

    //The following line calls static function directly via class not through the object.
    //At class level you can call only static methods and static members.
    cout << clsA::Function1() <<endl;

    //static methods can also be called throught the object.
    clsA A1, A2;
    cout << A1.Function1() << endl;
    cout << A1.Function2() << endl;
    cout << A2.Function1() << endl;
}
*/

//------------------------- Inheritance -----------------------------

//Concept Of Inheritance
/*  
                                inherits
    Super / Base class     <-------------------     Sub / Derived class

    - inheritance is to inherit the methods and the data members of the class
    we inherited from in order not to write again this members and function.

    - in case of updating a function or adding one i will have to update it from the
    super one only and changes will be updates through all the sub classes.

    HOW ?!

    // Super class
    class clsSuper{
        .....
    };

    // Sub class which inherits from Super class (clsSuper)
    class clsSub : public clsSuper{
        .....
    };

    - The sub class also inherites the constructors and destructors

    - We only inherit Public and Protected members , pivate arenot inherited.
*/

//Inherit Constructors
/*  
    - we can link the constructor of the Sub Class to the Super Class to
    share the data between them.

Example :-
-----------
class clsSuper{

private:
    String _Name;
    int _Age;
    String _Adress;
public:
    clsSuper(string Name, int Age, String Adress){
        _Name = Name;
        _Age = Age;
        _Adress = Adress;
    }

    // then setters and getters
};

class clsSub : public clsSuper{

private:
    int _salary;
    String _JobTitle;

public:
    clsSub(string Name, int Age, String Address, int salary, string JobTitle)
        : clsSuper(Name, Age, Adress)
    {
        _salary = salary;
        _JobTitle = JobTitle;
    }
};

- The parameters of the super class constructor is inherited in the sub class constructor
*/

//Function Overriding
/*  
    => Function with the same name and Task but when we make in the sub class it
    overrides the function with its same name in the super class.

    - The overriding function must have the same return type, same parameters and
    same access modifier.

Example:-
---------

class clsSuper{

private:
    String _Name;
    int _Age;
    String _Adress;
public:
    clsSuper(string Name, int Age, String Adress){
        _Name = Name;
        _Age = Age;
        _Adress = Adress;
    }

    // then setters and getters

    void print(){
        cout<<"Name: "<<_Name<<endl;
        cout<<"Age: "<<_Age<<endl;
        cout<<"Adress: "<<_Adress<<endl;
    };
};

class clsSub : public clsSuper{

private:
    int _salary;
    String _JobTitle;

public:
    clsSub(string Name, int Age, String Address, int salary, string JobTitle)
        : clsSuper(Name, Age, Adress)
    {
        _salary = salary;
        _JobTitle = JobTitle;
    };

    void print(){
        clsSuper::print();

        cout << "\nSalary: " << _salary << endl;
        cout << "Job Title: " << _JobTitle << endl;
    };

    // we inherited the print function from the super class and overrides it
    with the sub class print func.
};

*/

//Multi Level Inheritance
/*  

    super class for B & C                   super class for C & sub class for A                   sub class for A & B
            |                inherites  A                  |                inherites A & B             |
            A    <------------------------------------    B    <------------------------------------    C

Example:-
---------

class clsA{
private:
    String _Name;
    int _Age;
    String _Adress;
public:
    clsA(string Name, int Age, String Adress){
        _Name = Name;
        _Age = Age;
        _Adress = Adress;
    }

    // then setters and getters
};

class clsB : public clsA{
private:
    int _salary;
    string _JobTitle;

public:
    clsB(string Name, int Age, string Address, int salary, string JobTitle)
        : clsA(Name, Age, Address)
    {
        _salary = salary;
        _JobTitle = JobTitle;
    }
};

class clsC : public clsB{
private:
    string _CompanyName;
    int _YearsOfExperience;

public:
    clsC(string Name, int Age, string Address, int salary, string JobTitle, string CompanyName, int YearsOfExperience)
        : clsB(Name, Age, Address, salary, JobTitle){
        _CompanyName = CompanyName;
        _YearsOfExperience = YearsOfExperience;
    }
};
*/

//Protected access modifier in inheritance
/*  
    => For sharing members to derived classes only.

Example:-
---------

class clsA
{
private:
    //only accessible inside this class, neither derived classes nor outside class.
    int _Var1;
    void _Fun1()
    {
        cout << "Function 1";
    }
protected:
    //only accessible inside this class and all derived classes, but not outside class
    int Var2;
    void Fun2()
    {
        cout << "Function 1";
    }
public:
    // Accessible inside this class, all derived classes, and outside class
    int Var3;
    void Fun3()
    {
        cout << "Function 1";
    }
};

class clsB : public clsA
{
public:
    void Func1()
    {
        //calling a protected variable in a derived class
        cout << clsA::Var2;
    }
};

*/

//Visibility Mood of inheritance
/*  

                          |       private members       |       protected members       |         public members         |
    ---------------------------------------------------------------------------------------------------------------------|
    public inheritance    |        inaccecible         |            protected           |              public            |
    private inheritance   |        inaccecible         |             private            |             private            |
    protected inheritance |        inaccecible         |            protected           |            protected           |
*/

//Up casting
/*  
                          inherite
    Person Class     <------------------     Employee Class

    - up casting => Employee can be converted to Person.
                 => Sub Class can be converted to Super Class.
*/

//--------------------------- Polymerphism ----------------------------

//Concept Of Polymorphism
/*  
                                  overrides
    Func. in Super class     <-------------------     Func. in Sub class

    - Polymorphism is to perform different actions based on the object type.

    - polymorphism is achieved through
        => Overriding
        => Overloading

*/

//Abstract Class
/*  
    - It is an interface class or a contracts which implemented in it some void methods.
    - When inheriting from an Abstract class , all the methods written in it must be
    overridden in the subclass or the object of the sub class wont work.

Example:-
---------

//Abstract Class
class clsMobile
{
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber,string Text) = 0;
    virtual void TakePicture() = 0;
};

//By inheriting the sub class we will have to implement all the methods in it
class clsiPhone : public clsMobile
{
public:
    void Dial(string PhoneNumber){

    };
    void SendSMS(string PhoneNumber, string Text){

    };
    void TakePicture(){

    };
    void MyOwnMethod(){

    };
};

int main()
{
    clsiPhone iPhone1;

    system("pause>0");
    return 0;
}

*/

//------------------ Friend Classes & Friend Functions ------------------

//Friend Class
/*  
    => when making a friend class we can share private and protected members with it.

Example:-
---------

class clsA
{
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    friend class clsB; //friend class

};

class clsB
{
public:
    void display(clsA A1)
    {
        cout << endl << "The value of Var1=" << A1._Var1 ;
        cout << endl << "The value of Var2=" << A1.Var2 ;
        cout << endl << "The value of Var3=" << A1._Var3 ;
    }
};

int main()
{
    clsA A1;
    clsB B1;
    B1.display(A1);

    system("pause>0");
    return 0;
};
*/

//Friend Functions
/*  
    => when making a friend function we can share private and protected members with it.

Example:-
---------

class clsA{
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    friend int MySum(clsA A1); //friend function

};

//this function is a normal function and not a member of any class
int MySum(clsA A1)
{
    return A1._Var1 + A1.Var2 + A1._Var3 ;
}

int main()
{
    clsA A1;

    cout << MySum(A1);

    system("pause>0");
    return 0;
};
*/

//-------------------------------- Nesting --------------------------------

//Structure Inside Class
/*  
    => A structure can be declared inside a class as a data type.

Example:-
---------

class clsPerson {

private:
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

public:
    string FullName;
    stAddress Address;

    clsPerson()
    {
        FullName = "Mohammed Abu-Hadhoud";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Queen Rania Street";
        Address.City = "Amman";
        Address.Country = "Jordan";
    }

    void PrintAddress()
    {
        cout << "\nAddress:\n";
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }
};

int main(){
    clsPerson Person1;
    Person1.PrintAddress();

    system("pause>0");
    return 0;
}
*/

//Nested Classes
/*  
    => Make a class inside another class.

Example:-
---------

class clsPerson {
    string _FullName;

    class clsAddress{

    private :
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:

        clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country= Country;
        }

        string setAddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }
        string AddressLine1()
        {
            return _AddressLine1 ;
        }

        string setAddressLine2(string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }
        string AddressLine2()
        {
            return _AddressLine2;
        }

        string setCity(string City)
        {
            _City = City;
        }
        string City()
        {
            return _City;
        }

        string setCountry(string Country)
        {
            _Country = Country;
        }
        string Country()
        {
            return _Country;
        }

        void Print()
        {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };

public:

    string setFullName(string FullName)
    {
        _FullName = FullName;
    }
    string FullName()
    {
        return _FullName ;
    }

    clsAddress Address = clsAddress("", "","","");

    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
    {
        _FullName = FullName;

        //initiate address class by it's constructor
        Address = clsAddress (AddressLine1, AddressLine2, City, Country);
    }
};

int main()
{
    clsPerson Person1("Makrious", "Building 10","Mohram Bek", "Alexandria", "Egypt");
    Person1.Address.Print();

    system("pause>0");
    return 0;
}
*/

//-------------------- Passing Objects to Functions -----------------------

//Passing by (ref/val)
/* 

class clsA
{
public:
    int x;
    void Print()
    {
        cout << "The value of x=" << x <<endl;
    }
};

//object sent by value, any updated will not be reflected
// on the original object
void Fun1(clsA A1)
{
    A1.x = 100;
}

//object sent by reference, any updated will be reflected
// on the original object
void Fun2(clsA &A1)
{
    A1.x = 200;
}

int main()
{
    clsA A1;
    A1.x = 50;
    cout << "\nA.x before calling function1: \n";
    A1.Print();

    //Pass by value, object will not be afected.
    Fun1(A1);
    cout << "\nA.x after calling function1 byval: \n";
    A1.Print();

    //Pass by value, object will be afected.
    Fun2(A1);
    cout << "\nA.x after calling function2 byref: \n";
    A1.Print();

    system("pause>0");
}

*/

//-------------------- Separate Classes In Libraries -----------------------

//If using Visual Studio Code
/* 
    - Download "C++ Class Creator" Extension.
    - Press ALT + X to create new class.
    - Type the name of your class.
    - You will write your code in the file which called "name.h".
    - Then you will write in your main file (include "name.h").
    - Also if you inherited a class you will write in the Sub Class (include "name.h").
    - Each class you mut write (#pragma once)
*/

//-------------------------- Objects and Vectors ---------------------------

//Inserting Various Number Of Objects through Vector
/*  

class clsA{
public:
    int x;

    //Parametarized Constructor
    clsA(int value){
        x = value;
    }

    void Print()
    {
        cout << "The value of x=" << x <<endl;
    }
};

int main()
{
    vector <clsA> v1;
    short NumberOfObjects=5;

    // inserting object at the end of vector
    for (int i = 0; i < NumberOfObjects; i++)
    {
        v1.push_back(clsA(i));
    }

    // printing object content
    for (int i = 0; i < NumberOfObjects; i++)
    {
        v1[i].Print();
    }

    system("pause>0");
}
*/

//Intializing Objects and Storing it using Arrays
/*  

class clsA{

public:
    int x;

    //Parametarized Constructor
    clsA(int value)
    {
        x = value;
    }

    void Print()
    {
        cout << "The value of x=" << x <<endl;
    }
};

int main(){

    // Initializing 3 array Objects with function calls of
    // parameterized constructor as elements of that array
    clsA obj[] = { clsA(10), clsA(20), clsA(30) };

    // using print method for each of three elements.
    for (int i = 0; i < 3; i++) {
        obj[i].Print();
    }

    return 0;
    system("pause>0");
}

*/

//-----------------------------------------------------------------------------


/*=======================================================================================================*/
/*=============================================== THE END ===============================================*/
/*=======================================================================================================*/