#include <iostream>
#include <iomanip>
#include <cmath>

// Function to calculate the square root and reciprocal square root using Goldschmidt's algorithm
template<typename Real>
std::pair<Real, Real> goldschmidtSqrtAndReciprocalSqrt(Real S, int maxIterations = 10, Real tolerance = 1e-7) {
    if (S <= 0) {
        std::cerr << "Error: Non-positive input to sqrt function." << std::endl;
        return {-1, -1};
    }

    Real Y0 = 1.0 / sqrt(S);
    Real y = Y0;
    Real x = S * y;
    Real b = S;

    for (int n = 0; n < maxIterations; ++n) {
        Real Yn = 0.5 * (3 - b);
        Real xNew = x * Yn;
        Real yNew = y * Yn;
        
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
	using Real = double;
    Real number;
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
