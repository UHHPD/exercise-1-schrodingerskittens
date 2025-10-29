#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

std::ifstream fin1("datensumme.txt");
std::ifstream fin2("datensumme.txt");
std::ifstream fin3("datensumme.txt");
std::ifstream fin4("datensumme.txt");
std::ofstream fout1("mittelwerte.txt");
std::ofstream fout2("varianzen.txt");
std::ofstream fout3("varianzen_bessels_corr.txt");



double a;


void calculate_nine_numbers() {
    
    double count = 0.0;
    double sum = 0.0;
    double mean = 0.0;
    double diff = 0.0;

    for(int i=0; i < 9; i++) {
        fin1 >> a;
        sum += a;
        count += 1;
    }
    mean = sum / count;
    fout1  << mean << std::endl;
    count = 0.0;
    
    for(int i=0; i < 9; i++){
        fin2 >> a;
        diff += std::pow(a - mean, 2);
        count += 1;
    }
    double variance = diff / count;
    fout2  << variance << std::endl;
}

void calculate_nine_numbers_with_bessels_corr() {
    
    double count = 0.0;
    double sum = 0.0;
    double mean = 0.0;
    double diff = 0.0;

    for(int i=0; i < 9; i++) {
        fin3 >> a;
        sum += a;
        count += 1;
    }
    mean = sum / count;
    count = 0.0;
    
    for(int i=0; i < 9; i++){
        fin4 >> a;
        diff += std::pow(a - mean, 2);
        count += 1;
    }
    double variance = diff / (count - 1);
    fout3  << variance << std::endl;
}

double compute_mean(std::string name) {
    double sum = 0.0;
    double count = 0.0;
    double mean = 0.0;
    std::ifstream fin(name);
    while(fin >> a){
        sum += a;
        count += 1;
    }
    return mean = sum / count;
}

int main(){

    for (int i = 0; i < 26; i++) {
        calculate_nine_numbers();
        calculate_nine_numbers_with_bessels_corr();
    }

    double mean_of_means = compute_mean("mittelwerte.txt");
    std::cout << "Overall Mean of Means: " << mean_of_means << std::endl;

    double mean_of_variances = compute_mean("varianzen.txt");
    std::cout << "Overall Mean of Variances: " << mean_of_variances << std::endl;

    double mean_of_variances_corr = compute_mean("varianzen_bessels_corr.txt");
    std::cout << "Overall Mean of corrected Variances: " << mean_of_variances_corr << std::endl;

}