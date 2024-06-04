#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include <fstream>

// Original Bakhshali method
template<typename Real>
Real bakhshaliSqrtOriginal(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    // Initial guess
    Real guess = number / 2.0;
    Real difference, nextGuess;
    int iterations = 0;

    do {
        Real a = (number - guess * guess) / (2.0 * guess);
        nextGuess = guess + a - (a * a) / (2.0 * (guess + a));
        difference = std::abs(nextGuess - guess);
        guess = nextGuess;
        iterations++;
    } while (difference > tolerance && iterations < maxIterations);

    return nextGuess;
}

// Improved Bakhshali method
template<typename Real>
Real bakhshaliSqrtImproved(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    if (number == 0) {
        return 0;
    }

    // Initial guess
    Real guess = number / 2.0;
    Real difference, nextGuess;
    int iterations = 0;

    do {
        Real guessSquared = guess * guess;
        Real a = (number - guessSquared) / (2.0 * guess);
        Real guessPlusA = guess + a;
        nextGuess = guessPlusA - (a * a) / (2.0 * guessPlusA);
        difference = std::abs(nextGuess - guess);
        guess = nextGuess;
        iterations++;
    } while (difference > tolerance * (nextGuess + guess) && iterations < maxIterations);

    return nextGuess;
}

int main() {
    using Real = double;
    // Numbers between 0 and 1 for comparison
    std::vector<Real> numbers;
    for (int i = -100; i <= 100; ++i) {
        Real number = std::pow(10.0, i);
        if (number < 1.0)
            numbers.push_back(number);
    }
    
    std::vector<Real> resultsOriginal;
    std::vector<Real> resultsImproved;
    std::vector<double> timesOriginal;
    std::vector<double> timesImproved;

    std::cout << std::setw(15) << "Number"
              << std::setw(20) << "Original Result"
              << std::setw(20) << "Improved Result"
              << std::setw(20) << "Original Time (s)"
              << std::setw(20) << "Improved Time (s)"
              << "\n";

    for (Real number : numbers) {
        // Measure time and result for the original method
        auto start = std::chrono::high_resolution_clock::now();
        Real sqrtResultOriginal = bakhshaliSqrtOriginal(number);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationOriginal = end - start;

        // Measure time and result for the improved method
        start = std::chrono::high_resolution_clock::now();
        Real sqrtResultImproved = bakhshaliSqrtImproved(number);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationImproved = end - start;

        // Store results and times
        resultsOriginal.push_back(sqrtResultOriginal);
        resultsImproved.push_back(sqrtResultImproved);
        timesOriginal.push_back(durationOriginal.count());
        timesImproved.push_back(durationImproved.count());

        // Print results in tabular format
        std::cout << std::setw(15) << number
                  << std::setw(20) << sqrtResultOriginal
                  << std::setw(20) << sqrtResultImproved
                  << std::setw(20) << durationOriginal.count()
                  << std::setw(20) << durationImproved.count()
                  << "\n";
    }

    // Write results to CSV file
    std::ofstream outFile("comparison_results.csv");
    outFile << "Number,Original Result,Improved Result,Original Time (s),Improved Time (s)\n";
    for (size_t i = 0; i < numbers.size(); ++i) {
        outFile << numbers[i] << ","
                << resultsOriginal[i] << ","
                << resultsImproved[i] << ","
                << timesOriginal[i] << ","
                << timesImproved[i] << "\n";
    }
    outFile.close();

    std::cout << "\nResults written to comparison_results.csv\n";

    return 0;
}
