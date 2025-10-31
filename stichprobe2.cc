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

