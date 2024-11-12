# OOP Concepts with C++

**By: Makrious Ayman**

# Classes & Objects

## Classes and Objects

```cpp
class clsName {
public:
    // Data members => variables in the classes
    string firstname;
    string lastname;

    // Method(function) members => functions in the classes
    string fullname() {
        return firstname + " " + lastname;
    }
};

int main() {
    // Initializing an object
    clsName person1;

    // Accessing the variables of the class
    person1.firstname = "John";
    person1.lastname = "Doe";

    // Accessing the function we made in the class
    cout << person1.fullname() << endl;
}
```
## Memory

### In the Class Members

- **Data members**: We create new memory in each object to store the data.
- **Function members**: We share the same memory for the functions we made in the class for each object.
  
----------------------------------------------------------------

# Access Specifiers/Modifiers

### Access Modifiers

- **Default Access Modifier**: Private

1. **Private**: Accessible inside the class only.
2. **Protected**: Accessible inside the class and every class that inherits this class.
3. **Public**: Accessible to everyone.

----------------------------------------------------------------

# Properties

## Setters and Getters

- When creating private data members, we usually put an underscore (`_`) at the beginning of the variable to distinguish private variables from others.

- **Set function**: It is used to create a method that sets the variable to the private one we made and allows us to initialize it.

- **Get function**: It is used to create a method that gets the variable from the private one we set and allows us to use or access it.

#### Example:

```cpp
class clsPerson {
private:
    string _FirstName;
    string _LastName;
public:
    // Property Set
    void setFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    // Property Get
    string FirstName() {
        return _FirstName;
    }

    // Property Set
    void setLastName(string LastName) {
        _LastName = LastName;
    }
    // Property Get
    string LastName() {
        return _LastName;
    }

    string FullName() {
        return _FirstName + " " + _LastName;
    }
};

int main() {
    clsPerson Person1;

    Person1.setFirstName("Mohammed");
    Person1.setLastName("Abu-Hadhoud");

    cout << "First Name:" << Person1.FirstName() << endl;
    cout << "Last Name:" << Person1.LastName() << endl;
    cout << "Full Name:" << Person1.FullName() << endl;

    system("pause>0");
    return 0;
}
```

## Read-Only Property

- We create this property to prevent changes or updates to sensitive data (e.g., IDs, passcodes).

### How?

- By making a getter function only, without a setter for this data member.

#### Example:

```cpp
class clsPerson {
private:
    int _ID = 123;

public:
    // Property Get only
    int ID() {
        return _ID;
    }
};

int main() {
    clsPerson Person1;

    cout << "ID:" << Person1.ID() << endl;

    system("pause>0");
    return 0;
}
```
## Setters and Getters through "="

- We use the "declaration specification (declspec)" function to use `=` instead of the function name.

#### Example:

```cpp
class clsPerson {
private:
    string _FirstName;

public:
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    string GetFirstName() {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
};

int main() {
    clsPerson Person1;

    Person1.SetFirstName("Mohammed");
    cout << Person1.GetFirstName() << endl;

    // Instead of the above, we only write this
    Person1.FirstName = "Mohammed";
    cout << Person1.FirstName;

    system("pause>0");
    return 0;
}
```
----------------------------------------------------------------

# Encapsulation and Abstraction

## Encapsulation

- Encapsulation is the process of hiding the data and methods that manipulate the data inside a class.
- It is a way to protect the data and methods from being accessed from outside the class.

#### How?

- By making the data members private and providing public getter and setter methods.
- Variables + Methods => Class {Encapsulation}

## Abstraction

- Abstraction is a process of hiding the implementation details of an object that are not useful for the user.
- It is a way to represent an object in a simpler way.

#### How?

- By providing a public interface for accessing the data and methods of the class.
  
----------------------------------------------------------------

# Constructors & Destructors

## Constructor

- A function with the same name as the class and without any data type or `void` before the function name.
- It is used to initialize the data members of the class.
- It is called automatically when an object is created from the class.
- It doesn't have a return type.

#### Example:

```cpp
class clsAddress {
private:
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:
    // Parameterized constructor
    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode) {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }

    void SetAddressLine1(string AddressLine1) {
        _AddressLine1 = AddressLine1;
    }
    string GetAddressLine1() {
        return _AddressLine1;
    }

    void SetAddressLine2(string AddressLine2) {
        _AddressLine2 = AddressLine2;
    }
    string GetAddressLine2() {
        return _AddressLine2;
    }

    void SetPOBox(string POBox) {
        _POBox = POBox;
    }
    string GetPOBox() {
        return _POBox;
    }

    void SetZipCode(string ZipCode) {
        _ZipCode = ZipCode;
    }
    string GetZipCode() {
        return _ZipCode;
    }

    void Print() {
        cout << "\nAddress Details:\n";
        cout << "------------------------";
        cout << "\nAddressLine1: " << _AddressLine1 << endl;
        cout << "AddressLine2: " << _AddressLine2 << endl;
        cout << "POBox : " << _POBox << endl;
        cout << "ZipCode : " << _ZipCode << endl;
    }
};

int main() {
    clsAddress Address1("Queen Alia Street", "B 303", "11192", "5555");
    Address1.Print();

    system("pause>0");
    return 0;
}
```
## Copy Constructor

- When making a new object and assigning it to be equal to the first object, the compiler by default will copy the constructor of the first and put it in the second one.

#### Example:

```cpp
int main() {
    clsAddress Address1("Queen Alia Street", "B 303", "11192", "5555");
    Address1.Print();

    clsAddress Address2 = Address1; // Copy constructor called here
    Address2.Print();
}
// The output of the second object will be the same as the first one.
```

## Destructor

- A function with the same name as the class and a `~` before the name.
- A special function that is called when an object is destroyed.
- It is used to release the memory allocated to the object.
- It is called automatically when the object goes out of scope.

#### Example:

```cpp
class clsPerson {
public:
    string FullName;

    // This constructor will be called when the object is built.
    clsPerson() {
        FullName = "Mohammed Abu-Hadhoud";
        cout << "\nHi, I'm Constructor";
    }

    // This destructor will be called when the object is destroyed.
    ~clsPerson() {
        cout << "\nHi, I'm Destructor";
    }
};

void Fun1() {
    clsPerson Person1;
    // After exiting from function, Person1 will be destroyed and destructor will be called.
}

void Fun2() {
    clsPerson* Person2 = new clsPerson;
    // Always use delete whenever you use new, otherwise object will remain in memory
    delete Person2;
}

int main() {
    Fun1();
    Fun2();

    system("pause>0");
    return 0;
}
```
- After Fun1 is finished, the object will be destroyed and the destructor will be called.
- After Fun2 is finished, the object won’t be destroyed because we used a pointer to create the object. To destroy it, we must use the delete function.

## Function Overloading

- Two functions with the same name but with different parameters.

#### Example:

```cpp
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
```
------------------------------------------------------------------------------------------

# Static Members & Methods

## Static Members

- Shared variable to all objects.
- Declared using the `static` keyword.
- Declared inside the class but initialized outside the class.
- Can be accessed using the class name or object name.
- Static members are initialized only once, when the program starts.
- Static members are not inherited.
- When changed from a certain object, the change is made to all other objects as well.

#### Example:

```cpp
class clsA {
public:
    int var;
    static int counter;

    clsA() {
        counter++;
    }

    void Print() {
        cout << "\nvar = " << var << endl;
        cout << "counter = " << counter << endl;
    }
};

int clsA::counter = 0; // Static variable initialization outside the class

int main() {
    clsA A1, A2, A3;

    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    A1.Print();
    A2.Print();
    A3.Print();

    A1.counter = 500;
    cout << "\nAfter changing the static member counter in one object:\n";

    A1.Print();
    A2.Print();
    A3.Print();
}
```

## Static Methods

- Static methods can only access static members.
- They can be called directly from the class or from an object.
- Declared using the `static` keyword.

#### Example:

```cpp
class clsA {
public:
    static int Function1() {
        return 10;
    }
    int Function2() {
        return 20;
    }
};

int main() {
    // The following line calls the static function directly via the class, not through the object.
    // At the class level, you can call only static methods and static members.
    cout << clsA::Function1() << endl;

    // Static methods can also be called through the object.
    clsA A1, A2;
    cout << A1.Function1() << endl;
    cout << A1.Function2() << endl;
    cout << A2.Function1() << endl;
}
```
----------------------------------------------------------------------------

# Inheritance

## Concept of Inheritance
``` cpp
                          inherits
 Super / Base class <------------------- Sub / Derived class
```

- Inheritance allows a class to inherit the methods and data members of another class, avoiding the need to rewrite these members and functions.
- If a function is updated or added in the superclass, the changes will be reflected in all subclasses.

#### How?
```cpp
// Super class
class clsSuper {
    // ...
};

// Sub class which inherits from Super class (clsSuper)
class clsSub : public clsSuper {
    // ...
};
```
- The subclass also inherits the constructors and destructors.
- Only public and protected members are inherited; private members are not.


## Inherit Constructors
- We can link the constructor of the Sub Class to the Super Class to share the data between them.

#### Example:

```cpp
class clsSuper {
private:
    string _Name;
    int _Age;
    string _Address;
public:
    clsSuper(string Name, int Age, string Address) {
        _Name = Name;
        _Age = Age;
        _Address = Address;
    }

    // Then setters and getters
};

class clsSub : public clsSuper {
private:
    int _salary;
    string _JobTitle;

public:
    clsSub(string Name, int Age, string Address, int salary, string JobTitle)
        : clsSuper(Name, Age, Address) {
        _salary = salary;
        _JobTitle = JobTitle;
    }
};
```


## Function Overriding
- A function with the same name and task, but when created in the subclass, it overrides the function with the same name in the superclass.
- The overriding function must have the same return type, same parameters, and same access modifier.

#### Example:

```cpp
class clsSuper {
private:
    string _Name;
    int _Age;
    string _Address;
public:
    clsSuper(string Name, int Age, string Address) {
        _Name = Name;
        _Age = Age;
        _Address = Address;
    }

    // Then setters and getters

    void print() {
        cout << "Name: " << _Name << endl;
        cout << "Age: " << _Age << endl;
        cout << "Address: " << _Address << endl;
    }
};

class clsSub : public clsSuper {
private:
    int _salary;
    string _JobTitle;

public:
    clsSub(string Name, int Age, string Address, int salary, string JobTitle)
        : clsSuper(Name, Age, Address) {
        _salary = salary;
        _JobTitle = JobTitle;
    }

    void print() {
        clsSuper::print();

        cout << "\nSalary: " << _salary << endl;
        cout << "Job Title: " << _JobTitle << endl;
    }

    // We inherited the print function from the superclass and override it
    // with the subclass print function.
};
```


## Multi-Level Inheritance

``` cpp
super class for B & C                   super class for C & sub class for A                   sub class for A & B
        |                inherits  A                  |                inherits A & B             |
        A    <------------------------------------    B    <------------------------------------    C
```

#### Example:
```cpp
class clsA {
private:
    string _Name;
    int _Age;
    string _Address;
public:
    clsA(string Name, int Age, string Address) {
        _Name = Name;
        _Age = Age;
        _Address = Address;
    }

    // Then setters and getters
};

class clsB : public clsA {
private:
    int _salary;
    string _JobTitle;

public:
    clsB(string Name, int Age, string Address, int salary, string JobTitle)
        : clsA(Name, Age, Address) {
        _salary = salary;
        _JobTitle = JobTitle;
    }
};

class clsC : public clsB {
private:
    string _CompanyName;
    int _YearsOfExperience;

public:
    clsC(string Name, int Age, string Address, int salary, string JobTitle, string CompanyName, int YearsOfExperience)
        : clsB(Name, Age, Address, salary, JobTitle) {
        _CompanyName = CompanyName;
        _YearsOfExperience = YearsOfExperience;
    }
};
```


## Protected Access Modifier in Inheritance
- For sharing members with derived classes only.

#### Example:

```cpp
class clsA {
private:
    // Only accessible inside this class, neither derived classes nor outside class.
    int _Var1;
    void _Fun1() {
        cout << "Function 1";
    }
protected:
    // Only accessible inside this class and all derived classes, but not outside class.
    int Var2;
    void Fun2() {
        cout << "Function 1";
    }
public:
    // Accessible inside this class, all derived classes, and outside class.
    int Var3;
    void Fun3() {
        cout << "Function 1";
    }
};

class clsB : public clsA {
public:
    void Func1() {
        // Calling a protected variable in a derived class
        cout << clsA::Var2;
    }
};
```


## Visibility Mode of Inheritance
``` cpp
                          |       private members       |       protected members       |         public members         |
    ---------------------------------------------------------------------------------------------------------------------|
    public inheritance    |        inaccecible         |            protected           |              public            |
    private inheritance   |        inaccecible         |             private            |             private            |
    protected inheritance |        inaccecible         |            protected           |            protected           |
```


## Up Casting
``` cpp
                          inherite
    Person Class     <------------------     Employee Class
```

- **Up casting**: An Employee can be converted to a Person.
- **Sub Class** can be converted to **Super Class**.
  
------------------------------------------------------------------------------------------

# Polymorphism

## Concept of Polymorphism
``` cpp
                                  overrides
    Func. in Super class     <-------------------     Func. in Sub class
```

- Polymorphism allows performing different actions based on the object type.
- Polymorphism is achieved through:
  - **Overriding**
  - **Overloading**

## Abstract Class

- An abstract class is an interface or a contract that includes some pure virtual methods.
- When inheriting from an abstract class, all the methods written in it must be overridden in the subclass, or the object of the subclass won't work.

#### Example:

```cpp
// Abstract Class
class clsMobile {
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;
};

// By inheriting the subclass, we will have to implement all the methods in it
class clsiPhone : public clsMobile {
public:
    void Dial(string PhoneNumber) {
        // Implementation
    }
    void SendSMS(string PhoneNumber, string Text) {
        // Implementation
    }
    void TakePicture() {
        // Implementation
    }
    void MyOwnMethod() {
        // Implementation
    }
};

int main() {
    clsiPhone iPhone1;

    system("pause>0");
    return 0;
}
```
------------------------------------------------------------------------------------------

# Friend Classes & Friend Functions

## Friend Class

- When making a friend class, we can share private and protected members with it.

#### Example:

```cpp
class clsA {
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA() {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    friend class clsB; // Friend class
};

class clsB {
public:
    void display(clsA A1) {
        cout << endl << "The value of Var1=" << A1._Var1;
        cout << endl << "The value of Var2=" << A1.Var2;
        cout << endl << "The value of Var3=" << A1._Var3;
    }
};

int main() {
    clsA A1;
    clsB B1;
    B1.display(A1);

    system("pause>0");
    return 0;
}
```


## Friend Functions
- When making a friend function, we can share private and protected members with it.

#### Example:

```cpp
class clsA {
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA() {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    friend int MySum(clsA A1); // Friend function
};

// This function is a normal function and not a member of any class
int MySum(clsA A1) {
    return A1._Var1 + A1.Var2 + A1._Var3;
}

int main() {
    clsA A1;

    cout << MySum(A1);

    system("pause>0");
    return 0;
}
```
------------------------------------------------------------------------------------------

# Nesting

## Structure Inside Class

- A structure can be declared inside a class as a data type.

#### Example:

```cpp
class clsPerson {
private:
    struct stAddress {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

public:
    string FullName;
    stAddress Address;

    clsPerson() {
        FullName = "Mohammed Abu-Hadhoud";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Queen Rania Street";
        Address.City = "Amman";
        Address.Country = "Jordan";
    }

    void PrintAddress() {
        cout << "\nAddress:\n";
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }
};

int main() {
    clsPerson Person1;
    Person1.PrintAddress();

    system("pause>0");
    return 0;
}
```

## Nested Classes

- A class can be declared inside another class.

#### Example:

```cpp
class clsPerson {
    string _FullName;

    class clsAddress {
    private:
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:
        clsAddress(string AddressLine1, string AddressLine2, string City, string Country) {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }

        void setAddressLine1(string AddressLine1) {
            _AddressLine1 = AddressLine1;
        }
        string AddressLine1() {
            return _AddressLine1;
        }

        void setAddressLine2(string AddressLine2) {
            _AddressLine2 = AddressLine2;
        }
        string AddressLine2() {
            return _AddressLine2;
        }

        void setCity(string City) {
            _City = City;
        }
        string City() {
            return _City;
        }

        void setCountry(string Country) {
            _Country = Country;
        }
        string Country() {
            return _Country;
        }

        void Print() {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };

public:
    void setFullName(string FullName) {
        _FullName = FullName;
    }
    string FullName() {
        return _FullName;
    }

    clsAddress Address = clsAddress("", "", "", "");

    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country) {
        _FullName = FullName;
        // Initiate address class by its constructor
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }
};

int main() {
    clsPerson Person1("Makrious", "Building 10", "Mohram Bek", "Alexandria", "Egypt");
    Person1.Address.Print();

    system("pause>0");
    return 0;
}
```
-------------------------------------------------------------------------------------

# Passing Objects to Functions

## Passing by Reference/Value

```cpp
class clsA {
public:
    int x;
    void Print() {
        cout << "The value of x=" << x << endl;
    }
};

// Object sent by value, any updates will not be reflected on the original object
void Fun1(clsA A1) {
    A1.x = 100;
}

// Object sent by reference, any updates will be reflected on the original object
void Fun2(clsA &A1) {
    A1.x = 200;
}

int main() {
    clsA A1;
    A1.x = 50;
    cout << "\nA.x before calling function1: \n";
    A1.Print();

    // Pass by value, object will not be affected.
    Fun1(A1);
    cout << "\nA.x after calling function1 by value: \n";
    A1.Print();

    // Pass by reference, object will be affected.
    Fun2(A1);
    cout << "\nA.x after calling function2 by reference: \n";
    A1.Print();

    system("pause>0");
}
```
-------------------------------------------------------------------------------------

# Separate Classes in Libraries

### If Using Visual Studio Code

1- Download the "C++ Class Creator" Extension.
2- Press `ALT + X` to create a new class.
3- Type the name of your class.
4- Write your code in the file named `name.h`.
5- In your main file, include the header file: `#include "name.h"`.
6- If you inherit a class, include the header file in the subclass: `#include "name.h"`.
7- For each class, use `#pragma once`.

-------------------------------------------------------------------------------------

# Objects and Vectors

## Inserting Various Numbers of Objects through Vector

```cpp
class clsA {
public:
    int x;

    // Parameterized Constructor
    clsA(int value) {
        x = value;
    }

    void Print() {
        cout << "The value of x=" << x << endl;
    }
};

int main() {
    vector<clsA> v1;
    short NumberOfObjects = 5;

    // Inserting object at the end of vector
    for (int i = 0; i < NumberOfObjects; i++) {
        v1.push_back(clsA(i));
    }

    // Printing object content
    for (int i = 0; i < NumberOfObjects; i++) {
        v1[i].Print();
    }

    system("pause>0");
}
```

## Initializing Objects and Storing Them Using Arrays

#### Example:

```cpp
class clsA {
public:
    int x;

    // Parameterized Constructor
    clsA(int value) {
        x = value;
    }

    void Print() {
        cout << "The value of x=" << x << endl;
    }
};

int main() {
    // Initializing 3 array objects with function calls of
    // parameterized constructor as elements of that array
    clsA obj[] = { clsA(10), clsA(20), clsA(30) };

    // Using print method for each of the three elements.
    for (int i = 0; i < 3; i++) {
        obj[i].Print();
    }

    return 0;
    system("pause>0");
}
```
-------------------------------------------------------------------------------------

Happy Learning!
