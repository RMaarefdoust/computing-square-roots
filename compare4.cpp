#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>
#include <limits>

// Function to calculate the square root using the Newton-Raphson method
template<typename Real>
std::pair<Real, int> newtonRaphsonSqrt2(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function is not allowed." << std::endl;
        return {-1, -1};
    }

    if (number == 0) {
        return {0, 0}; // The square root of 0 is 0
    }

    Real x0 = number / 2.0;  // Initial guess
    Real x1 = (x0 + number / x0) / 2.0;  // Improved guess using the Newton-Raphson formula
    int iterations = 0;

    while (std::abs(x1 - x0) > tolerance && iterations < maxIterations) {
        x0 = x1;
        x1 = (x0 + number / x0) / 2.0;
        iterations++;
    }

    return {x1, iterations};
}
template<typename Real>
std::pair<Real, int> newtonRaphsonSqrt(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return {-1, -1};
    }

    Real x0 = number / 2.0;  // Initial guess
    Real x1 = (x0 + number / x0) / 2.0;  // Improved guess using the Newton-Raphson formula
    int iterations = 0;

    while (std::abs(x1 - x0) > tolerance && iterations < maxIterations) {
        x0 = x1;
        x1 = (x0 + number / x0) / 2.0;
        iterations++;
    }

    return {x1, iterations};
}

// Function to compare two versions of the square root calculation function
template<typename Real>
void compareSqrtFunctions(const std::vector<Real>& numbers) {
    std::ofstream outFile("comparison_results.csv");
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    outFile << "Number,Result (Original),Result (Improved),Iterations (Original),Iterations (Improved)\n";

    for (Real number : numbers) {
        auto [sqrtResultOrig, iterationsOrig] = newtonRaphsonSqrt<Real>(number);
        auto [sqrtResultImp, iterationsImp] = newtonRaphsonSqrt2<Real>(number);

        outFile << std::scientific << number << ","
                << std::fixed << std::setprecision(10) << sqrtResultOrig << ","
                << std::fixed << std::setprecision(10) << sqrtResultImp << ","
                << iterationsOrig << ","
                << iterationsImp << "\n";
    }

    outFile.close();
    std::cout << "Results written to comparison_results.csv\n";
}

int main() {
    using Real = double;

    // Numbers between 0 and 1 for comparison
    std::vector<Real> numbers;
    for (int i = -100; i <= 0; ++i) {
        Real number = std::pow(10.0, i);
        if (number < 1.0)
            numbers.push_back(number);
    }

    compareSqrtFunctions(numbers);

    return 0;
}
