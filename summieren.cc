#include<iostream>
#include<fstream>
using namespace std;


int main() {
    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");
    int a, b;
    fin>>a>>b;
    std::cout<<"First two numbers :";
    std::cout <<a<<" and "<<b<<std::endl;
    
    fin.seekg(0, ios::beg);
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



