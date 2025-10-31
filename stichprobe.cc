#include<iostream>
#include<fstream>
#include<cmath>

int main() {
    std::ifstream fin("datensumme.txt");
    double count = 0, sum=0;
    double a, mean;
    while (fin>> a)
    {
        sum +=a;
        count++;
    }
    mean = sum /count;
    std :: cout <<"Mean : "<< mean<<std::endl;

    double var, diff, stddev;
    sum =0.0;
    fin.close();
    fin.open("datensumme.txt");
    
    while(fin>>a)
    {
        diff = a - mean;
        diff = diff*diff;
        sum += diff;
    } 

    var = sum/count;
    std::cout<<"Variance : "<< var <<std::endl;

    stddev = std::sqrt(var);
    std::cout<<"Standard Deviation : "<< stddev <<std::endl;

    fin.close();

    return 0;
}