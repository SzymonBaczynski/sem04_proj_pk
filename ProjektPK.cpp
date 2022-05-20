#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURITYCRITICAL_ATTRIBUTE
#include <iostream>
#include "macierz.h"


int main()
{

    Macierz m = Macierz(10.8);
    m.addColumn();
    m.addColumn({34});
    m.addColumn({65});

    std::vector<double> row01{ 34.9, 12, 43.45, 98.99 };
    m.addRow(row01);
    m.addRow({ 30.9, 13, 52.45, 11.99 });
    m.addRow();
    m.addRow();

    m.writeOut();
    std::cout << "\n";

    m.deleteRow();
	m.deleteRow();
    m.deleteCol();
    m.deleteCol();

    m.writeOut();
    std::cout << "\n";

    m.addColumn();
    m.addRow();

    m.writeOut();    
    std::cout << "\n";

    Macierz m1 = Macierz(11);
    m1.addRow({ 2 });
    m1.addColumn({ 2,8.45});
    m1.addColumn({ 2.34,2});
    m1.addColumn({ 2,0});

    Macierz m2 = Macierz(11.43);
    m2.addRow({ 4.89 });
    m2.addRow({ 2 });
    m2.addRow({ 2 });
    m2.addColumn({ 2,3.67,2,12 });
    m2.addColumn({ 0.1,0,0,12.45 });

    std::cout << "\nM1:\n";
    m1.writeOut();

    std::cout << "\nM2:\n";
    m2.writeOut();

    Macierz m3 =  m2 * m1;
    std::cout << "\nM3 = M2 * M1\n";
    m3.writeOut();

    m3 = m1 * m2;
    std::cout << "\nM3 = M1 * M2\n";
    m3.writeOut();

    m3 = m3 * 10.0;
    std::cout << "\nM3*10:\n";
    m3.writeOut();

    m3 = m1 + m1;
    std::cout << "\nM1 + M1:\n";
    m3.writeOut();

    m3 = m1 - m1;
    std::cout << "\nM1 - M1:\n";
    m3.writeOut();

	Macierz m4 = Macierz(0);
    m4 = m1;
    std::cout << "\nM4 = M1:\n";
    m4.writeOut();
    
}
