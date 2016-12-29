## Java Code:

The following Java code will create a class Coord and print 
out the (x,y) coordinate pair.  Once this runs, we will begin
the process of changing the code to work as a C++ program.

### Compile Java:
javac Coord.java

### Run Java:
java Coord

### Expected Output:
10.0, 4.2
4.2, 10.0

## Converting the Code:

1. Add a semicolon to the end of the class definition.

This is a tricky, but often missed part of C++.  It will lead 
to some particularly fun debugging.

2. Change the access permissions from per line to the C++ standard of grouping.

C++ groups access permissions by using the keywords 'public:' and 'private:' rather 
than the Java convention of specifying it per method and variable.

3. Separate declaration and definition.

C++ separates the declaration of variables and functions from the definition.  When 
using a class in other code, we only need to know the declaration, that is, the 
specification of the return types and arguments.  It is not necessarily important to 
know the details of how a function is implemented.  With **proper** documentation, we 
should not have to see the definition of a function!

Our 'class' construct is thus a declaration only, defintions are put elsewhere in the code. 
We then refer to this only as the **class** declaration. 

This class declaration is then moved into a file 'coord.h'.

#### What about definitions?!

The code we specified in 'coord.h' needs to be defined elsewhere.  Since multiple classes 
might have similar functions, we need to add a syntax operator called the **scope resolution operator**.  
The operator will link the function definitions with the given class.  We realize this by 
using the '::' operator prepended with the class name.  For example, 'Coord::Initialize'. 

4. Move Definition Code

Definition code typically goes into a separate file, in this case 'coord.c'.  Copy our scope resolved code 
to this file, and add the line '#include "coord.h"' to the top of the file.

#### Note: I/O

Print required a change, and an addition of an include in 'coord.c'.  See if you can locate the change.

## C++ Code:

With the completed C++ code, we can now build and run the class.  

### Compilation:

g++ Coord.cpp coord.c -o Coord

### Run C++:

./Coord

### Expected Output:
10.0, 4.2
4.2, 10.0
