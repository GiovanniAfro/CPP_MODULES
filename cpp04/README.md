# C++ Module 04 - Exercises Overview

## Introduction to Subtype Polymorphism, Abstract Classes, and Interfaces

Module 04 of our C++ series explores advanced Object-Oriented Programming concepts such as subtype polymorphism, abstract classes, and the implementation of interfaces using pure abstract classes. These concepts are crucial for designing flexible, reusable, and maintainable code.

## Exercise 00: Polymorphism

### Purpose

Introduce subtype polymorphism through a simple hierarchy involving animals. You will implement base and derived classes (`Animal`, `Dog`, and `Cat`) to demonstrate how derived classes can override behaviors of their base class to perform actions differently.

### Key Concepts

- Base and derived class relationship
- Virtual functions and polymorphism
- Overriding member functions to provide specific implementations

## Exercise 01: I don’t want to set the world on fire

### Purpose

This exercise further explores polymorphism with a focus on memory management in polymorphic class hierarchies. You will add a `Brain` class to give `Dog` and `Cat` classes a more complex state, and manage deep copying issues when objects are copied.

### Key Concepts

- Composition (objects containing other objects)
- Deep copying vs. shallow copying
- Resource management in destructors to prevent memory leaks

## Exercise 02: Abstract class

### Purpose

Enhance the design by converting the `Animal` class into an abstract base class to prevent instantiation of base class objects, which conceptually don't make sense to instantiate. This exercise ensures you understand how to design and use abstract classes effectively.

### Key Concepts

- Abstract classes to enforce class hierarchies
- Pure virtual functions
- Designing non-instantiable base classes

## Exercise 03: Interface & recap

### Purpose

Synthesize the concepts learned in this module by implementing a simulation of interfaces through pure abstract classes. You will create a system involving multiple classes that interact polymorphically, demonstrating practical use of interfaces in C++.

### Key Concepts

- Interfaces represented by pure abstract classes
- Implementing complex interactions between objects using interfaces
- Advanced polymorphism and object-oriented design patterns

## Submission and Peer Evaluation

As always, ensure that your code is clean, well-commented, and adheres to the specified standards. Your ability to implement these advanced concepts correctly will be crucial for peer evaluations.

**Engage with these exercises to deepen your understanding of C++ and its powerful features for Object-Oriented Programming.**
