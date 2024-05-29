#include <iostream>
#include <cmath>
#include <vector>

// Function to compute the continued fraction expansion of the square root
template<typename Real>
std::vector<int> continuedFractionExpansion(int S, Real& decimalApproximation, int maxIterations = 10) {
    std::vector<int> coefficients;
    int a = std::sqrt(S);
    int r = S - a * a;

    coefficients.push_back(a); // Add integer part to coefficients

    // Compute continued fraction expansion
    for (int i = 0; i < maxIterations; ++i) {
        if (r == 0) {
            break; // Square root is exact
        }
        int nextTerm = (a + std::sqrt(S)) / r;
        coefficients.push_back(nextTerm);
        r = (S - a * a) / r;
        a = nextTerm * r - a;
    }

    // Calculate decimal approximation
    decimalApproximation = std::sqrt(S);

    return coefficients;
}

int main() {
	using Real = double;
    int S;
    std::cout << "Enter a positive integer S to find the continued fraction expansion of sqrt(S): ";
    std::cin >> S;

    Real decimalApproximation;
    std::vector<int> expansion = continuedFractionExpansion(S, decimalApproximation);
    
    std::cout << "Decimal approximation of sqrt(" << S << "): " << decimalApproximation << std::endl;
    std::cout << "Continued fraction expansion of sqrt(" << S << "): [";
    for (size_t i = 0; i < expansion.size(); ++i) {
        std::cout << expansion[i];
        if (i < expansion.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
