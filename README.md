### Build Instructions

This repository consists of coding examples from Stephan Roth's Clean C++20 book.
Implementation of the particular exercise does not need to be exactly the same as in the book.

Resources:
* https://github.com/Apress/clean-cpp20
* https://www.clean-cpp.com/

**Disclaimer**: I do not have any relation with the original author of the book or the book it self.

Prerequisite is to have g++ with the c++20 standard installed.

Build exercises with the following command:
'''
g++ -std=c++20 -o template_argument_fold.exe exercises/template_argument_fold.cpp
'''

Build design_pattern_exercises with the following commands:
'''
cd tdd_exercicses\<Exercise_folder>
mkdir build 
cd build
cmake ..
'''

Build tdd_exercices with the following commands:
'''
cd tdd_exercicses\<Exercise_folder>
mkdir build 
cd build
cmake ..
'''

Build tdd_exercices unit tests with the following commands:
'''
cd tdd_exercicses\<Exercise_folder>\tests
mkdir build 
cd build
cmake ..
'''