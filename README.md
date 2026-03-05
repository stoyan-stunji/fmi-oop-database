# DATABASE
- This project was developed as part of the course “Object-Oriented Programming” at Sofia University, FMI. It demonstrates the design and implementation of a database system using object-oriented principles, focusing on structured data management, database schema design and SQL-like operations.

*This documentation is written according to the requirements, presented in the course “Object-Oriented Programming” at FMI.*

## 1. Introduction
### 1.1 Project Description and Idea
- The main idea of this project is to develop a program, whose purpose is to manage data within a database. The database consists of a series of tables, where each table is stored in its own file;
- The database itself is recorded in a main file called a catalog, which contains a list of all tables. Each individual table is built from arrays of data that are related to each other;
- The database is organized in such a way that it uses records and fields, allowing the data to be used more easily and efficiently.

### 1.2 Goal and Tasks of the Development
- The goal of this project is to implement a system that manages a database. The system must implement methods for:
    - importing a table into the database;
    - providing a list of the names of all tables;
    - displaying specific types of information about a given table;
    - showing rows from a table;
    - saving the contents of a table into a separate file;
    - selecting rows from a table that contain information specified by the user;
    - creating a new table containing user-specified data that originates from another table;
    - extending a specific table;
    - updating a table with user-provided information;
    - inserting or removing rows from particular tables.
- One of the main tasks of a database is to store large amounts of data in a structured format and to provide mechanisms for storing and organizing this data, allowing fast access and efficient searching and processing. The system also provides control over data access, protection of data from unauthorized access and ensures data integrity and consistency;
- Another important task is providing the ability to extract specific information from the database for analysis, reporting and decision-making. This enables the discovery of trends, generation of reports and making decisions based on the available data.

### 1.3 Documentation Structure
- The project documentation consists of the files necessary for compiling the project (`.cpp` and `.hpp`), a sample catalog along with the example tables contained within it and a text file containing the project documentation.
- The documentation begins with an analysis of the problem and the approach used for solving it. This is followed by a brief description of the classes created to implement the solution. The document concludes with ideas for future improvements.

## 2. Overview of the Subject Area
### 2.1 Main Definitions, Concepts and Algorithms Used
- The program uses the building blocks of object-oriented programming to implement the assigned tasks. It includes classes, which are data types that provide a framework for creating different objects. The data and functions of a class are called members. Objects, in turn, represent instances of given classes. They define specific properties and behavior for executing the code. The term "instance" refers to the relationship between an object and its class;
- The program also makes use of the concept of a method - a function that defines the behavior of a given class or its objects. Methods are specific to a class and specify how an object can use or modify data. Another important component is the constructor - a special type of method used to automatically create objects of a class. There are also special types of constructors, such as copy constructors, which create specific types of objects or follow certain rules for object creation;
- Other important concepts fundamental to the correct operation of this object-oriented program are selectors and mutators, which are used respectively for retrieving a value and modifying a member variable.
- Another valuable principle is abstraction. Through abstraction, the end user sees only the interface and not the entire internal code. The ideas of encapsulation, inheritance and polymorphism are also utilized. Through encapsulation, certain information within a class is protected from the rest of the code. By using inheritance, several classes are generalized under a common structure. Polymorphism refers to the ability of different subclasses in a hierarchy to respond to the same command in their own specific way.

### 2.2 Definition of Problems and Complexity of the Task
- The problem that needs to be solved is the creation of a database and the implementation of methods for processing the data within it. The program must support a number of operations, which the author has divided into four types:
    - `Interface-type` operations: opening a database and correctly reading information from several files - one main file containing the names of the individual tables and several other files containing the data of the individual tables; saving changes made by the user to the tables; saving a separate table to a path specified by the user; presenting a list of the different operations that can be performed; closing the program;
    - `Database-type` operations: presenting a list of the names of the tables in the database; inserting a new table into the database using a specified file name; displaying information by name about the data types of a table specified by the user through a dialog mode; writing the contents of a specific table by name formatted in a specific way;
    - `Table-type` operations: displaying all rows of a table specified by the user according to column, cell content, and name, where the information is presented in pages; creating a new table containing specific data that are included in another table according to columns and cell content; adding a new column with the largest number in a given table, where for all existing rows in the table the value of this column must be empty; updating a table according to columns and cell contents; deleting a row from a table containing information unwanted by the user; inserting a new row into a specific table with values provided by the user;
    - `Additional` operations: validations for vectors of strings, vectors of integers, and vectors of floating-point numbers; validation of the content of table cells; adding and removing a cell to a row; adding and removing a row to a table; adding a table to the database; transposing a table for row view; writing empty values for all existing rows in a table; checking the validity of a table name and the presence of duplicates;
- The complexity of the task can be divided into several aspects: working with the file system, where information is read from files and written back to them or new files are created; data processing - searching, filtering, and modifying, and managing the user interface. The implementation of all operations and the corresponding validation of data and commands can be challenging. Possible problems include incorrect data reading, memory overflow, errors during file writing and reading, errors in the user interface and etc.;
- To successfully solve the task, it is important to design an appropriate system architecture with a clear separation of responsibilities and good data organization. In addition, appropriate checks and validations of the data must be performed to ensure the correctness of the operations and the protection of the data.

### 2.3 Approaches and Methods for Solving the Given Problems
- To solve the given problems in the database and data processing program, various approaches and methods can be used. First, an object-oriented design will be used, as mentioned above. Applying the principles of object-oriented programming will help create more structured and modular code that is easier to understand, maintain and extend;
- For reading and writing data from and to files, the standard input/output of the C++ language will be used. It is important to note that proper opening, closing and processing of files must be ensured and appropriate checks for errors when working with the file system must be implemented;
- For storing data in the program and processing tables, structures such as arrays, lists, or trees can be used, but the author has chosen to use only arrays. Emphasis is placed on the organization of the data - it is necessary to ensure efficient access to and searching within it;
- To guarantee the correctness of the data, various validation methods will be applied. It is very important to perform checks for possible errors when the user enters data and to protect the program from unwanted operations and inconsistent states;
- A user interface must be designed that is intuitive and easy to use. Last but not least, in order to ensure the quality of the program, it is extremely important to perform systematic tests and checks. Debugging must be carried out carefully and systematically by analyzing the causes of errors and taking appropriate actions to eliminate them.

## 3. Design
### 3.1 General Architecture - OOP Design
- The foundations of the program are established through four main classes: class `Column`, class `Column_String`, class `Column_Int`, and class `Column_Double`. The first class represents a purely virtual class - a column, containing member data, a characteristic vector and a name. It also contains selectors and mutators, as well as methods for printing to the screen, writing the data to a file and methods for modifying the data - adding, replacing, and deleting data;
- The classes `Column_String`, `Column_Int` and `Column_Double` inherit from the `Column` class and interpret the above-mentioned functions in their own specific way depending on the task they perform. The `Column_String` class has a single vector containing strings from the standard library and represents one column of a specific table in the database. Since this class inherits from the Column class, it also possesses selectors and mutators, methods for printing to the screen, writing data to a file and methods for modifying the data;
- Similarly to `Column_String`, the `Column_Int` class also has a standard vector, but its data is of integer type. The `Column_Double` class contains data of floating-point type. Like `Column_String`, both classes have selectors and mutators, methods for printing to the screen, writing data to a file and methods for modifying the data;
- Having already become familiar with the foundation of the database system, it can now be seen how each table looks. Each file corresponding to a table is of type `.bin` and has the following structure:

![1.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_1.PNG) 

- Here, `Number_Of_Columns` represents the number of columns in the given table. After that comes `Type_A`, where `A` is between `1` and `N`. For the types of the specified columns, only `s`, `i` and `d` are valid, corresponding respectively to string, integer and floating-point number;
- Next is the name of each column - `Name_A`, followed by the number of elements in each vector, which is the same for every column and in this case is equal to `K`. Continuing in order, before each element there is a boolean value (`0` or `1`) indicating whether the element that follows it is valid or not.

### 3.2. Diagrams

![2.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_2.png)

## 4. Implementation and Testing
### 4.1 Implementation of Classes
- As mentioned above, the foundations of the program are established through the four main classes class `Column`, class `Column_String`, class `Column_Int` and class `Column_Double`. Class `Column` is a purely virtual class - a column, containing member data: a characteristic vector and a name. It also includes selectors and mutators, as well as methods for printing to the screen, writing data to a file and methods for modifying the data - adding, replacing and deleting data;
- The classes `Column_String`, `Column_Int` and `Column_Double` inherit from class Column and interpret the aforementioned functions in their own specific way depending on the task they perform. The `Column_String` class contains a single vector from the standard library that holds strings and represents a column of a specific table in the database. Because this class inherits from class Column, it also contains selectors and mutators, methods for printing to the screen, writing data to a file and methods for modifying the data;
- Similarly to `Column_String`, the `Column_Int` class also contains a vector, but its data is of integer type. The `Column_Double` class, in turn, contains data of floating-point type. Like `Column_String`, both classes have selectors and mutators, methods for printing to the screen, writing data to a file and methods for modifying the data;
- Next follows class `Table`. Its member data are a heterogeneous container of pointers to objects of class `Column`, as well as the name of the corresponding table for which it is responsible. It also includes mutators and selectors, a method for printing, a method for writing data to a file, methods for determining the different types of columns and checks and functionalities for modification that are required by higher-level classes to determine whether the column type is a string, an integer or a floating-point number. In addition, it contains a function that transforms a given table so that its cells become strings and then transposes it. This is necessary because several methods from higher-level classes require the table to be presented by rows, even though the tables in the system themselves are processed by columns;
- The next class is class `Database`. It contains an array of `Table`, i.e. an array of tables. Besides behaving like a vector and having mutators and selectors, it also contains a large set of methods necessary for the proper functioning of the program - importing a table into the database and updating the catalog with the new data, a function presenting all the names of the tables contained in the database, a descriptive method showing how many and what types of cells a given table has, a method that prints the rows of a specific table on the screen by pages, `export_base()`, which allows the user to create a copy of a table with a new name, a function for checking whether a table exists in the database and returning its index if it is present, a method for deleting a row, and last but not least a method for inserting a new row into a table based on the first row in the table, since it is always considered valid;
- The next class is class `Commands`. It contains as member data a Database object and the name of the currently opened catalog for work. It also has twenty methods. Together with the last class in the hierarchy, class Menu, which itself contains a class Commands, they enable the operation of this database system.
- Below, each function is highlighted individually:
    - `open()` - the user enters the file name - if such a file is not found, a new file with empty content is created;
    - `save()` - saves the changes made so far;
    - `save_as()` - allows the user to save a specific table by specifying the path to the new destination for saving;
    - `exit()` - asks the user whether they want to save the most recent changes and then closes the application;
    - `close()` - closes the current catalog and saves the changes made so far;
    - `help()` - displays a menu with the program’s functions;
    - `import()` - inserts into the system a table from a file whose name is specified by the user;
    - `showtables()` - displays the names of all tables in the system;
    - `describe()` - shows information about the types of the columns of a given table;
    - `print()` - displays the rows of a given table by pages;
    - `xport()` - writes the contents of a table into a new text file;
    - `select()` - according to a column specified by the user, a cell value in that column and a table name, the rows of the table are displayed by pages;
    - `select_onto()` - the user enters a new table name, the name of a table from the system, the number of columns and the column numbers - a new table with the initially entered name is created, containing only the columns with the specified numbers from the table in the system;
    - `add_column()` - adds a new column with the largest number in a given table, where for all existing rows in the table the value of this column is empty;
    - `update()` - based on table name, column number and cell value, modifies the table by column and cell value with new information chosen by the user;
    - `delete()` - based on table name, column number and cell value, deletes the row of the table containing the specified value;
    - `insert()` - inserts a new row into a given table based on table name and column;
    - `credits()` - shows information about the author of the project.
- The `Commands` class also contains two private methods related to the operation of `print()` and `select_onto()`:
    - `io_print_by_page()` - allows printing information from a table to the console by rows and by pages;
    - `io_print_by_page_special()` - allows saving information from a table by rows.
- Finally, there are two `.hpp` files that are required for the complete implementation of the database management program. In the first one, there is the `run()` function, which is used for entering commands from the user and the `generate_examples()` function, which generates several examples in order to demonstrate the functionality of the program properly.
- In addition, there is also a template class `Primitive_Pair`, which represents a very simple version of std::pair from the standard library and assists in the operation of the functions mentioned above.

### 4.2 Memory Management and Algorithms. Optimizations
- Good memory management is key to ensuring that the program works efficiently. There are two main aspects:
    - `allocation` (memory allocation, when a portion of memory is reserved during the execution of the program);
    - `deallocation` (memory deallocation, releasing memory that the program no longer needs).
- Due to the large number of identical actions that must be performed when working with the program, proper optimization is required.

### 4.3 Planning Description and Creation of Test Scenarios
- Everything that can be tested is a test scenario. Therefore, any software functionality that is being tested and can be divided into multiple smaller functionalities can be called a “test scenario.” Test scenarios help evaluate the software application according to real-life situations. In other words, testing is the process of executing the program in order to identify bugs, defects or errors.
- In order to demonstrate the correct functioning of the program, it is necessary to present different test scenarios.

![5.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_6.png)

    save_as()

![6.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_7.png)

    xport()

![7.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_8.png)

    open()

![8.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_9.png)

    describe()

![9.png](https://github.com/stoyan-stunji/fmi-oop-database/blob/main/files/pictures/figure_10.png)

    delete()

## 5. Conclusion
### 5.1 Summary of the Initial Goals Achieved
- In conclusion, the program successfully utilizes the building blocks of object-oriented programming through which it was developed, allowing it to efficiently manage data in a database. It provides the ability to extract specific information from the database, which is necessary for identifying trends, generating reports and making decisions based on the available data.

### 5.2 Directions for Future Development and Improvement
- For future development and enhancement of the project, possibilities include adding templates, optimizing data processing algorithms for higher efficiency, improving the program’s interface for easier use and adding additional security and data protection mechanisms. Another improvement could be enhancing the representation of each individual unit as an `std::pair` containing the data and a boolean value indicating its validity. Instead of a single characteristic vector present in the main file of a table, an additional file could be created to represent a boolean matrix, showing the validity of each cell. These improvements would increase the functionality and usability of the program, opening opportunities for extended usage and an enhanced user experience;
- Inclusion of `Command Pattern` instead of the current interface. 

## Literature
- Brian Overland - “C++ Without Fear”;
- ccpreference.com
