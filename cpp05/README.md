# C++ Module 05 - Exercises Overview

## Introduction to Repetition and Exceptions

Module 05 explores handling exceptions and repetitive operations in C++, crucial for developing robust applications that manage errors gracefully and perform repeated tasks efficiently.

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

### Purpose

The objective is to implement a `Bureaucrat` class that throws exceptions when trying to instantiate or modify its state outside of the allowed bounds. This exercise introduces exception handling in conjunction with class design to ensure data integrity.

### Key Concepts

- Exception handling
- Class invariants
- Custom exception classes

## Exercise 01: Form up, maggots!

### Purpose

Building on the `Bureaucrat` class, this exercise introduces a `Form` class that bureaucrats can sign if they have a high enough grade. The form throws exceptions if the grade requirements aren't met, reinforcing exception handling in a more complex scenario.

### Key Concepts

- Inter-class interactions
- More advanced exception handling
- Implementing conditions that must be met for state changes

## Exercise 02: No, you need form 28B, not 28C...

### Purpose

Extend the functionality of forms by introducing several specific types of forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) that perform unique actions. This exercise dives deeper into abstract classes and the use of polymorphism to handle different form types dynamically.

### Key Concepts

- Abstract classes
- Polymorphism through inheritance
- Designing and implementing a system of related classes

## Exercise 03: At least this beats coffee-making

### Purpose

Introduce the `Intern` class capable of creating any form on request, demonstrating the factory pattern. This exercise highlights the use of dynamic creation of objects based on runtime decisions and further practices exception handling when unknown form types are requested.

### Key Concepts

- Factory pattern
- Managing dynamic object creation
- Further refining exception handling strategies

## Submission and Peer Evaluation

Ensure your implementations are robust, correctly handle exceptions, and follow the coding standards provided. Your understanding of these advanced C++ features will be tested during peer evaluations, not just for functionality but for code quality and error management.

**Push your C++ skills further by mastering these essential concepts, crucial for writing advanced, robust, and maintainable code.**
