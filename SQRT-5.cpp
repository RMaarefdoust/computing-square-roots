#include <iostream>
#include <cmath>
#include <iomanip>

double sqrtUsingExponentialIdentity(double number) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }
    
    // Calculate the square root using the exponential identity
    double result = exp(0.5 * log(number));
    return result;
}

int main() {
    double number;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;

    double sqrtResult = sqrtUsingExponentialIdentity(number);
    if (sqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is " 
                  << std::fixed << std::setprecision(10) << sqrtResult << std::endl;
    }

    return 0;
}