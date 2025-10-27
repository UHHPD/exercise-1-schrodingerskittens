#include<iostream>
#include<fstream>

int main() {
    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");
    int a, b;
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