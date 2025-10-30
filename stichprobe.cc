#include <iostream> 
#include <fstream>
#include <cmath>

int main(){
    //a) Read in the N = 234 numbers ai from the file datensumme.txt and compute the mean.
    //Print out the result in the terminal.

    std::ifstream inputfile("datensumme.txt");

    //reading all sums into an array
    int x = 0;
    int pop_size = 234;
    int x_vector[pop_size];
    int sum = 0;

    for( int i = 0; i < pop_size; i++)
    {
        inputfile >> x_vector[i];
        sum += x_vector[i];
    }

    double x_mean;
    x_mean = 1/double(pop_size) * sum;


    std::cout << "The mean of all values x in datensumme.txt is " << x_mean << std::endl;


    //calculating the variance and printing it to the terminal

    double var_sum = 0;

    for (int i = 0; i < pop_size; i++)
    {
        double squared_difference = pow(x_vector[i] - x_mean, 2);
        var_sum += squared_difference;

    }

    double variance = 1/double(pop_size) * var_sum;

    std::cout << "The variance of the values in datensumme.txt is " << variance << std::endl;
    
    //computing the standard deviation and printing it to the terminal

    double std_dev = sqrt(variance);

    std::cout << "The standard deviation is therefore " << std_dev << std::endl;
    
    inputfile.close();
    return 0;
}