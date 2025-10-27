#include<iostream>
#include<fstream>

int main() {
    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");
    int a, b;
    //first task: printing only the first two numbers to the terminal
    fin >> a >> b;
    std::cout << "First two numbers of daten.txt: " << a << ", " << b << std::endl;
    fin.seekg(0, std::ios::beg);


    while(fin >> a >> b)
    {
        int sum = a + b;
        std::cout << "(" << a << " , " << b << " ) =  " << sum << std::endl;
        fout << sum << std::endl;
    }

    fin.close();
    fout.close();

    return 0;


}



