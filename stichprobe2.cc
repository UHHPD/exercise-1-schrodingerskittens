<<<<<<< HEAD
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
    

    //exercise 2: 
    //a) snipping up datensumme in 26 seperate calculations --> each 9 values
    inputfile.close();
    inputfile.open("datensumme.txt");
    std::ofstream mean_output("mittelwerte.txt");
    std::ofstream var_output("varianzen.txt");


    int sample_amount = 26;
    int sample_size = 9;
    double sample_mean[sample_amount];
    double sample_var[sample_amount];
    

    int x_matrix[sample_size][sample_amount];

    for (int i = 0; i < sample_amount; i++) //initializing the vectors
    {
        sample_mean[i] = 0;
        sample_var[i] = 0;
    }

    for (int i = 0; i < sample_amount; i++)//looping over 26 samples
    {
        for (int j = 0; j < sample_size; j++) //looping over each of nine entries of chunk
        {
            inputfile >> x_matrix[j][i];
            
            sample_mean[i] += x_matrix[j][i] /double(sample_size); //directly computing the mean by adding all 9 elements together and dividing by 9
        }
        //when code exits this loop, only then the ith entry of sample_mean is completed

        mean_output << sample_mean[i] << std::endl; //prints 26 mean values to new file "mittelwerte.txt"

        for (int j = 0; j < sample_size; j++) //compute ith element of the variance and print it to file
        {
            
            sample_var[i] += pow(x_matrix[j][i] - sample_mean[i], 2)/double(sample_size);
        }

        var_output << sample_var[i] << std::endl; //prints 26 variances to "varianzen.txt"

    }

    var_output.close();
    mean_output.close();

    //Exercise 2b) compute mean of both means and variances and compare 


    std::ifstream varianzen("varianzen.txt"); //same as var_output before but is now input file
    std::ifstream mittelwerte("mittelwerte.txt");
    
    double mean_sample_means[sample_amount];
    double mean_sample_vars[sample_amount];
    double means_sum = 0;
    double vars_sum = 0;


    for (int i = 0; i < sample_amount; i++)
    {
        mittelwerte >> mean_sample_means[i];
        means_sum += mean_sample_means[i];


        varianzen >> mean_sample_vars[i];
        vars_sum += mean_sample_vars[i];
        

    }

    //calculate mean of 26 means
    double mean_means = 1/double(sample_amount) * means_sum;

    //calculate mean of 26 variances
    double mean_vars = 1/double(sample_amount) * vars_sum;

    std::cout << "The mean of the 26 sample means is " << mean_means << std::endl;
    std::cout << "The mean of the 26 sample variances is " << mean_vars << std::endl;


    //result: the mean of the means are the same because it does not matter if we take total mean or first group measurements into pairs
    //however, the variances are different!
    return 0;


}
=======
#include<iostream>
#include<fstream>
#include<cmath>

double mean(double list[], int n)
{
    double count = 0, sum=0;
    double a, mean;
    for(int i=0; i<n; i++)
    {
        sum += list[i];
    }
    mean = sum /n;
    return mean;
}

double variance(double list[], int n, double mean, bool bessel=false)
{
    double var, diff, sum=0.0; 
    for (int i=0; i<n; i++)
    {
        diff = list[i] - mean;
        diff = diff*diff;
        sum += diff;
    }
    if(bessel)
    {
        var = sum/(n-1);
    }
    else
    {
        var = sum/n;
    }

    return var;
}



int main() {
    std::ifstream fin("datensumme.txt");
    double list[26][9], a;
    double mean_list[26], var_list[26], stddev_list[26], varB_list[26];

        for(int i=0; i<26; i++)
        {
            for(int j=0; j<9; j++)
            {
                fin>>a;
                list[i][j] = a;
            }
        }
    
    fin.close();
    std::ofstream fout1("mittelwerte.txt");
    std::ofstream fout2("varianzen.txt");
    for(int i=0; i<26; i++)
    {
        mean_list[i] = mean(list[i], 9);
        var_list[i] = variance(list[i], 9, mean_list[i]);
        varB_list[i] = variance(list[i], 9, mean_list[i], true);
        stddev_list[i] = std::sqrt(var_list[i]);
        fout1<< mean_list[i]<<std::endl;
        fout2<< var_list[i]<<std::endl;
    }
    fout1.close();
    fout2.close();
    double avg_mean, avg_var, avg_varB;
    avg_mean = mean(mean_list, 26);
    avg_var = mean(var_list, 26);
    avg_varB = mean(varB_list, 26);
    std::cout<<"Mean of 26 means : "<<avg_mean<<std::endl;
    std::cout<<"Mean of 26 variance : "<<avg_var<<std::endl;
    std::cout<<"Mean of 26 variance (Bessel's Correction) : "<<avg_varB<<std::endl;
    return 0;
}

>>>>>>> b48251b (Exercise sheet 2)
