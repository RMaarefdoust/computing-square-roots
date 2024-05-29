#include <iostream>
#include <cmath>
#include <complex>

// Function to compute the principal square root of a complex number
template<typename Real>
std::complex<Real> principalSquareRoot(std::complex<Real> S) {
    Real a = S.real();
    Real b = S.imag();
    Real absS = std::sqrt(a * a + b * b);

    if (a >= 0) {
        Real realPart = std::sqrt((absS + a) / 2);
        Real imagPart = (b >= 0) ? std::sqrt((absS - a) / 2) : -std::sqrt((absS - a) / 2);
        return std::complex<Real>(realPart, imagPart);
    } else {
        return std::complex<Real>(std::sqrt(absS), (b >= 0) ? std::sqrt(-a / 2) : -std::sqrt(-a / 2));
    }
}

int main() {
	using Real = double;
    std::cout << "Enter the real and imaginary parts of the complex number S: ";
    Real realPart, imagPart;
    std::cin >> realPart >> imagPart;

    std::complex<Real> S(realPart, imagPart);
    std::complex<Real> sqrtS = principalSquareRoot(S);

    std::cout << "Principal square root of S: " << sqrtS << std::endl;

    return 0;
}
