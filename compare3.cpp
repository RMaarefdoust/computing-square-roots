#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>

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
    std::vector<Real> numbers;
    for (int i = -100; i <= -1; ++i) {
        Real number = std::pow(10.0, i);
        numbers.push_back(number);
    }

    int precision = 10;
    std::vector<Real> resultsDigitByDigit;
    std::vector<double> timesDigitByDigit;

    std::cout << std::setw(15) << "Number"
              << std::setw(20) << "DigitByDigit Result"
              << std::setw(20) << "DigitByDigit Time (s)"
              << "\n";

    for (Real number : numbers) {
        // Measure time and result for the digit by digit method
        auto start = std::chrono::high_resolution_clock::now();
        Real sqrtResultDigitByDigit = digitByDigitSqrt(number, precision);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationDigitByDigit = end - start;

        // Store results and times
        resultsDigitByDigit.push_back(sqrtResultDigitByDigit);
        timesDigitByDigit.push_back(durationDigitByDigit.count());

        // Print results in tabular format
        std::cout << std::setw(15) << number
                  << std::setw(20) << sqrtResultDigitByDigit
                  << std::setw(20) << durationDigitByDigit.count()
                  << "\n";
    }

    // Write results to CSV file
    std::ofstream outFile("digit_by_digit_results.csv");
    outFile << "Number,DigitByDigit Result,DigitByDigit Time (s)\n";
    for (size_t i = 0; i < numbers.size(); ++i) {
        outFile << numbers[i] << ","
                << resultsDigitByDigit[i] << ","
                << timesDigitByDigit[i] << "\n";
    }
    outFile.close();

    std::cout << "\nResults written to digit_by_digit_results.csv\n";

    return 0;
}
