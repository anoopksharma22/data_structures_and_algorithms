#include<iostream>

int factorial(int n)
{
    if(n==1) return 1;
    return n * factorial(n-1);
}

int main()
{
    std::cout << "Factorial of first 10 numbers" << std::endl;
    for(int i=1; i<=10; i++)
    {
        std::cout << factorial(i);
        std::cout << std::endl;
    }
}