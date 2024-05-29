#include <iostream>
#include <cmath>

// Function to approximate square root using Taylor series expansion
template<typename Real>
Real taylorSqrt(Real N, Real d, int terms = 2) {
    Real result = N;
    Real term = 1.0;
    Real power = 1.0;

    for (int n = 1; n <= terms; ++n) {
        term *= (-1) * (2 * n - 1) * d / (2 * n);
        power *= (2 * N * N);
        result += term / power;
    }

    return result;
}

int main() {
	using Real = double;
    Real N, d;
    std::cout << "Enter N and d (N^2 + d is the number to find square root of): ";
    std::cin >> N >> d;

    Real sqrtResult = taylorSqrt(N, d);
    std::cout << "The approximate square root of " << N * N + d << " is: " << sqrtResult << std::endl;

    return 0;
}
