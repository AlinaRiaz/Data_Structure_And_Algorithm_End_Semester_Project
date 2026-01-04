# Data Structures and Algorithms – End Semester Project  
## Library Management System: Array vs Hash Table Implementation

This project was developed as part of the **Data Structures and Algorithms (DSA)** course. The objective of the project is to compare the design and performance of a basic **Library Management System (LMS)** implemented using two different data structures: **arrays** and **hash tables**.

---

## Project Overview

The project consists of two implementations of a Library Management System.  
- The first implementation uses **arrays** to perform basic LMS operations.  
- The second implementation replaces arrays with a **hash table** to achieve better efficiency.

The comparison focuses on how different data structures affect **performance, scalability, and usability**.

---

## Basic LMS Operations Implemented

Both implementations support standard library management operations, including:
- Adding records  
- Deleting records  
- Searching for records  
- Updating existing records  

---

## Array-Based Implementation

In the array-based version, all LMS operations are implemented using arrays. This approach highlights the limitations of arrays, particularly in terms of **search efficiency** and **scalability** as the number of records increases.

---

## Hash Table–Based Implementation

The hash table–based LMS was implemented in **C++**, as required by the course instructor. This implementation improves performance by using hashing techniques, making record lookup and management significantly more efficient for larger datasets.

---

## Graphical User Interface (GUI)

To enhance usability and demonstrate practical application, a **Graphical User Interface (GUI)** was developed using **Python**.  
Although the GUI was not a course requirement, it was added to make the system more interactive and user-friendly.

---

## C++ and Python Integration

The core hash table logic is implemented in C++.  
To integrate the C++ backend with the Python GUI, a **Dynamic Link Library (DLL)** was created from the C++ source code. The DLL exposes the required LMS functions, which are then accessed from Python.

---

## Architecture and Compatibility

The DLL was compiled for a **32-bit architecture**.  
To ensure compatibility, a **32-bit Python interpreter** was used so that the Python GUI could correctly interact with the C++ DLL.

---

## Technologies Used

- **C++** – Core data structure and hash table implementation  
- **Python** – GUI development  
- **Dynamic Link Library (DLL)** – Cross-language integration  
- **32-bit Python Interpreter** – DLL compatibility  

---

## Conclusion

This project fulfills all academic requirements while also demonstrating advanced concepts such as **hash table optimization**, **cross-language integration**, and **GUI-based system design**. It highlights the advantages of hash tables over arrays for managing large datasets and showcases practical software engineering skills beyond a basic console-based implementation.
