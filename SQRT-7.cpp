#include <iostream>
#include <iomanip>
#include <cmath>

// Function to calculate the square root and reciprocal square root using Goldschmidt's algorithm
std::pair<double, double> goldschmidtSqrtAndReciprocalSqrt(double S, int maxIterations = 100, double tolerance = 1e-10) {
    if (S <= 0) {
        std::cerr << "Error: Non-positive input to sqrt function." << std::endl;
        return {-1, -1};
    }

    double Y0 = 1.0 / sqrt(S);
    double y = Y0;
    double x = S * y;
    double b = S;

    for (int n = 0; n < maxIterations; ++n) {
        double Yn = 0.5 * (3 - b);
        double xNew = x * Yn;
        double yNew = y * Yn;
        
        if (std::isnan(xNew) || std::isnan(yNew)) {
            std::cerr << "Error: Failed to converge. NaN encountered." << std::endl;
            return {-1, -1};
        }

        if (std::abs(xNew - x) < tolerance && std::abs(yNew - y) < tolerance) {
            return {xNew, yNew};
        }

        x = xNew;
        y = yNew;
        b *= Yn * Yn;
    }

    std::cerr << "Error: Failed to converge within the maximum number of iterations." << std::endl;
    return {-1, -1};
}

int main() {
    double number;
    std::cout << "Enter a number to find the square root and reciprocal square root of: ";
    std::cin >> number;

    auto [sqrtResult, reciprocalSqrtResult] = goldschmidtSqrtAndReciprocalSqrt(number);
    if (sqrtResult != -1 && reciprocalSqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is "
                  << std::fixed << std::setprecision(10) << sqrtResult << std::endl;
        std::cout << "The approximate reciprocal square root of " << number << " is "
                  << std::fixed << std::setprecision(10) << reciprocalSqrtResult << std::endl;
    }

    return 0;
}
