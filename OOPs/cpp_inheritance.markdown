# Inheritance in C++

Inheritance in C++ allows a class to inherit properties and behaviors (data members and member functions) from another class, promoting code reuse and establishing relationships between classes.

## Key Concepts
- **Base Class (Parent Class)**: The class whose properties and methods are inherited.
- **Derived Class (Child Class)**: The class that inherits from the base class.
- **Syntax**:
  ```cpp
  class DerivedClass : access_specifier BaseClass {
      // Derived class members
  };
  ```
- **Access Specifiers**:
  - `public`: Public and protected members of the base class remain public and protected in the derived class.
  - `protected`: Public and protected members of the base class become protected in the derived class.
  - `private`: Public and protected members of the base class become private in the derived class.
- **Default Access**: If no access specifier is provided, it defaults to `private` for classes and `public` for structs.

## Types of Inheritance

### 1. Single Inheritance
One derived class inherits from one base class.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show" << endl;
    }
};

int main() {
    Derived d;
    d.display(); // Inherited from Base
    d.show();    // Defined in Derived
    return 0;
}
```

**Output**:
```
Base class display
Derived class show
```

### 2. Multiple Inheritance
A derived class inherits from more than one base class.

```cpp
#include <iostream>
using namespace std;

class Base1 {
public:
    void display1() {
        cout << "Base1 display" << endl;
    }
};

class Base2 {
public:
    void display2() {
        cout << "Base2 display" << endl;
    }
};

class Derived : public Base1, public Base2 {
};

int main() {
    Derived d;
    d.display1(); // From Base1
    d.display2(); // From Base2
    return 0;
}
```

**Output**:
```
Base1 display
Base2 display
```

### 3. Multilevel Inheritance
A class is derived from a class that is itself derived from another class.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base display" << endl;
    }
};

class Intermediate : public Base {
public:
    void show() {
        cout << "Intermediate show" << endl;
    }
};

class Derived : public Intermediate {
};

int main() {
    Derived d;
    d.display(); // From Base
    d.show();    // From Intermediate
    return 0;
}
```

**Output**:
```
Base display
Intermediate show
```

### 4. Hierarchical Inheritance
Multiple classes inherit from a single base class.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base display" << endl;
    }
};

class Derived1 : public Base {
};

class Derived2 : public Base {
};

int main() {
    Derived1 d1;
    Derived2 d2;
    d1.display(); // From Base
    d2.display(); // From Base
    return 0;
}
```

**Output**:
```
Base display
Base display
```

### 5. Hybrid Inheritance
A combination of two or more types of inheritance, which can lead to the **diamond problem** (ambiguity when a class inherits from two classes that have a common base class).

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base display" << endl;
    }
};

class Derived1 : public Base {
};

class Derived2 : public Base {
};

class Final : public Derived1, public Derived2 {
};

int main() {
    Final f;
    // f.display(); // Error: Ambiguous call to display()
    return 0;
}
```

To resolve the diamond problem, use **virtual inheritance**:

```cpp
class Derived1 : virtual public Base {
};

class Derived2 : virtual public Base {
};

class Final : public Derived1, public Derived2 {
};
```

Now `Final` inherits only one copy of `Base`, and `f.display()` works without ambiguity.

## Access Control and Visibility
- **Public Members**: Accessible everywhere.
- **Protected Members**: Accessible in the base and derived classes but not outside.
- **Private Members**: Accessible only within the base class (not inherited).

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int publicVar = 1;
protected:
    int protectedVar = 2;
private:
    int privateVar = 3;
};

class Derived : public Base {
public:
    void access() {
        cout << "Public: " << publicVar << endl;
        cout << "Protected: " << protectedVar << endl;
        // cout << privateVar; // Error: privateVar is inaccessible
    }
};

int main() {
    Derived d;
    d.access();
    cout << d.publicVar << endl; // Accessible
    // cout << d.protectedVar; // Error: protectedVar is inaccessible
    return 0;
}
```

**Output**:
```
Public: 1
Protected: 2
1
```

## Function Overriding
A derived class can redefine a base class’s virtual function to provide its own implementation using the `virtual` keyword for polymorphism.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base display" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived display" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->display(); // Calls Derived's display due to virtual function
    delete ptr;
    return 0;
}
```

**Output**:
```
Derived display
```

## Constructors and Destructors in Inheritance
- **Constructors**: Base class constructor is called before the derived class constructor.
- **Destructors**: Derived class destructor is called before the base class destructor. Use `virtual` for base class destructors to ensure proper cleanup in polymorphic scenarios.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    virtual ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}
```

**Output**:
```
Base constructor
Derived constructor
Derived destructor
Base destructor
```

## Key Points
- **Virtual Functions**: Enable runtime polymorphism. Use `override` to ensure correct overriding and `final` to prevent further overriding.
- **Abstract Classes**: Use pure virtual functions (`virtual void func() = 0;`) to make a class abstract (cannot be instantiated).
- **Diamond Problem**: Resolved using virtual inheritance.
- **Access Specifiers**: Control the visibility of inherited members.
- **Constructor Order**: Base class constructors are called before derived class constructors.