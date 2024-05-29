#include <iostream>
#include <cmath>
#include <complex>

// Function to compute the principal square root of a complex number
std::complex<double> principalSquareRoot(std::complex<double> S) {
    double a = S.real();
    double b = S.imag();
    double absS = std::sqrt(a * a + b * b);

    if (a >= 0) {
        double realPart = std::sqrt((absS + a) / 2);
        double imagPart = (b >= 0) ? std::sqrt((absS - a) / 2) : -std::sqrt((absS - a) / 2);
        return std::complex<double>(realPart, imagPart);
    } else {
        return std::complex<double>(std::sqrt(absS), (b >= 0) ? std::sqrt(-a / 2) : -std::sqrt(-a / 2));
    }
}

int main() {
    std::cout << "Enter the real and imaginary parts of the complex number S: ";
    double realPart, imagPart;
    std::cin >> realPart >> imagPart;

    std::complex<double> S(realPart, imagPart);
    std::complex<double> sqrtS = principalSquareRoot(S);

    std::cout << "Principal square root of S: " << sqrtS << std::endl;

    return 0;
}
