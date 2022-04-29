#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURITYCRITICAL_ATTRIBUTE
#include <iostream>
#include "macierz.h"


int main()
{
    std::cout << "Hello World!\n";

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
    m1.addRow({ 2 });
    m1.addRow({ 2 });
    m1.addColumn({ 2,2,0,2 });
    m1.addColumn({ 2,2,0,2 });
    m1.addColumn({ 2,2,0,2 });

    Macierz m2 = Macierz(11.43);
    m2.addRow({ 2 });
    m2.addRow({ 2 });
    m2.addRow({ 2 });
    m2.addColumn({ 2,2,2,12 });
    m2.addColumn({ 0,0,0,12 });
    m2.addColumn({ 2,6,2,12 });

    std::cout << "\n";
    m1.writeOut();

       
    std::cout << "\n";
    m2.writeOut();

    Macierz m3 = m1 * m2;

    std::cout << "\n";
    m3.writeOut();



    //element* e = m.writeOutEl(3, 4);
    //std::cout << "\n element:"  << e->getVal();

}
