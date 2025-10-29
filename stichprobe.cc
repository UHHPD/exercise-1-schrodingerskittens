#include <iostream>
#include <fstream>
#include <cmath>

int main(){
    double a;
    double count = 0.0;
    double sum = 0.0;
    double mean;
    double diff = 0.0;
    std::ifstream fin("datensumme.txt");
    while (fin >> a) {
        sum += a;
        count += 1;
    }
    mean = sum / count;
    std::cout << "Mean: " << mean << std::endl;
    fin.close();
    count = 0.0;
    fin.open("datensumme.txt");
        while (fin >> a) {
        diff += std::pow(a - mean, 2);
        count += 1;
    }
    double variance = diff / count;
    std::cout << "Variance: " << variance << std::endl;

    double stddev = std::sqrt(variance);
    std::cout << "Standard Deviation: " << stddev << std::endl;
}