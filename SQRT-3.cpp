#include <iostream>
#include <iomanip>
#include <cmath>
// Digit by digit calculation
template<typename Real>
Real digitByDigitSqrt(Real number, int precision) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    Real result = 0;  
    Real remainder = number;  // Remainder of the division process
    Real divisor = 0;  // Current divisor
    Real place = 1;  // Current decimal place

    // Find the integer part
    while (remainder >= place * place) {
        place *= 10;
    }
    place /= 10;


    for (int i = 0; i < precision + 1; ++i) {
        for (int digit = 9; digit >= 0; --digit) {
            Real trialDivisor = divisor * 10 + digit;
            Real trialResult = result * 10 + digit;
            if (trialDivisor * trialResult <= remainder) {
                divisor = trialDivisor;
                result = trialResult;
                remainder -= trialDivisor * trialResult;
                break;
            }
        }
        remainder *= 100;
    }

    return result / place;
}

int main() {
	using Real = double;
    Real number;
    int precision;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;
    std::cout << "Enter the precision (number of decimal places): ";
    std::cin >> precision;

    Real sqrtResult = digitByDigitSqrt(number, precision);
    if (sqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is " 
                  << std::fixed << std::setprecision(precision) << sqrtResult << std::endl;
    }

    return 0;
}
