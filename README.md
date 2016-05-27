# CMPT225 Algorithms
Assignments from CMPT225 at SFU
Assignment 1: (Grouping Symbol Checking)
You are to write a C++ program that reads a text file from "standard input", and checks that all occurrences of the grouping symbols (),{} and [] are correctly matched and nested. (The text file could be, for example, a C++ source code file.) If there is any incorrect matching or nesting, the program prints out a message, as described below, identifying where the first error was found and the nature of the error. Otherwise, it prints a line containing only the string "No Errors Found".


Assignment 2: Dynamic Queue Implementation
1. Use the provided header file queue.h. Do not make changes to any public part of the queue class declaration. (You may change the private declarations if you want, but I strongly encourage you not to.)
2. Implement the functions for the queue class in a file "queue.cpp".
3. The functions are the standard operations on a queue, except for makeUnique, which functions as follows. Consider executing the line:
             int b = Q.makeUnique(k)
If k does not occur in Q, then no change is made to Q, and b is set to 0. If k occurs exactly once in Q, then no change is made to Q, and b is set to 0. If k occurs j times in Q, for j greater than 1, then all occurrences of k except the one nearest to nearest the front of the queue are removed from Q, and b is set to j-1. All remaining elements in Q (including one occurrence of k) remain in Q, and their relative order does not change.
4. You must implement the queue class using a linked list. Keep it simple, in the manner of my sample linked-list stack implementation(s).
5. You must delete nodes that are no longer used.
6. There is also a copy constructor and a destructor, which you should implement correctly (i.e., using deep copies and with no memory leaks).


Assignment 3: Heap Implementation
In class, we covered the algorithms for an array-based heap implementation, paying attention only to the keys in the heap. To use a heap to implement a priority queue, you also need to keep track of elements associated with each key. (We want extract_min to give us the element with the highest priority. We may or may not care what the priority value is.) For this assignment, you are to implement a C++ heap class, which stores pairs , where each element and priority value is an int.

Begin by getting the files heap.h, Makefile and test1.cpp. The implementation is incomplete, and your task is to complete it. Both the class declaration and the function implementations are in the .h file (as if we were making a template class, but this assignment does not involve a template class.)

-Do not make any changes to the given function declarations.
-Complete the implementations of all incompletely implemented functions.
-You may add private functions if you find it useful.
-The small test program test.cpp is provided for convenience only. You should extend it with further testing.
-You may extend the provided makefile if it is useful, but make sure that the provided one still works, because we will use it (or something similar) for testing your class.


Assignment 4: List Difference Application
This assignment is a small application problem exercise, which you are to solve using methods from this course.
Given: Two lists of integers L1 and L2;
Output: The largest number that occurs in L1 but does not occur in L2, or "None" if there is no such number.

