#include <iostream>
#include <fstream>

void print_two_numbers() {
    int a;
    int b;
    std::ifstream fin("daten.txt");
    fin >> a >> b;
    std::cout << a << " " << b << std::endl;
    fin.close();

}
int main() {
    print_two_numbers();
    int a;
    int b;
    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");
    while(fin >> a >> b) {
        fout  << (a + b) << std::endl;
    }
    fin.close();
    fout.close();

}
