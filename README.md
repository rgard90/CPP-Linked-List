 Purpose

To build a single-linked list with the use of templates while 
handling memory management.

Key Reading

4.1, 4.5-4.6, 4.10
Background

Develop a Linked List that performs several standard operations. 
Linked Lists are common data structures in all object-oriented 
languages, and will play a vital role in your activities as a 
programmer.

Requirements

This lab must be completed on the Linux OS.

You are required to use template classes that accept various 
types including ints, doubles, strings, etc.

Part 1 - Insertion Tests (10 points)

Construct a Single-Linked List that can be used with template 
classes and that passes all of the Test Driver's insertion 
tests (through Test 5).
These will test your insertHead, insertTail, and insertAfter 
functions.

Part 2 - Remove (6 points)
Pass Test 6 of the Test Driver. This will test your remove function.

Part 3 - Comprehensive Tests (6 points)

Pass Tests 7 & 8 of the Test Driver. These more comprehensively 
test all the linked list's functions using both ints and strings.

Part 4 - No Leaks in the Hull (6 points)
Run and pass ValGrind on your program to ensure that you have no memory leaks.

UML design document. (2 points)
Refer to page 113 in the book for an example.
Please bring when asking TAs questions.
You must bring a hard copy when you come in to pass off.
Requirement Notes

General

You may not use the predefined C++ Standard Template Library (STL)
classes. This lab must run on the Linux machines. The test driver 
will work only on those machines.
For this lab only, due to the nature of template classes, you are 
strongly encouraged to implement the entire class in only a '.h'. 
All classes that are not templates must be implemented by a '.h' 
and a '.cpp'
Make sure that you pass all 8 tests before attempting to fix any 
memory leaks.  If anything causes the program to crash (or if 
the test driver is unable to finish testing your code) the test 
driver may terminate before it is able to delete your LinkedList, 
which will always result in memory leaks.