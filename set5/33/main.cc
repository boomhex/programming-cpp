#include <vector>
#include <iostream>
#include <string>
#include "main.ih"


// Basic exercise
// Purpose: learn to use containers to solve complex tasks.
// Construct a program that prints a sorted list of all different words appearing at its standard input.
// In this exercise, use a liberal definition of a `word': a word is defined as any series of characters 
// not containing white space (i.e., you can simply extract std::string values from std::cin) to get the 
// `words'.

// Hint: This is an extremely simple exercise. It doesn't require you to call qsort() or a comparable function.

std::vector<std::string> &input()
{
    std::string str;
    std::vector<std::string> vec{};
    while (getline(std::cin, str))
    {
        //vec.insert(0, str);
    }
}

int main()
{
    std::vector<std::string> vec = input();
}
