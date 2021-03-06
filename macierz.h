#pragma once
#include <vector>
#include <iostream>
#include "Element.h"


class Macierz 
{
private:
	Element* firstElement_;
	int rowNumber_ = 0;
	int colNumber_ = 0;

public:
	Macierz();
	Macierz(double firstElVal);
	~Macierz();

	void addRow();
	void addRow(std::vector<double> const &newElVal);
	void addColumn();
	void addColumn(std::vector<double> const& newElVal);


	void deleteRow();
	void deleteCol();

	void writeOut() const;
	Element* writeOutEl(int row, int col) const;
	double getElVal(int row, int col) const;

	// operatory

	Macierz operator+(const Macierz& ingredient) const;
	Macierz operator-(const Macierz& ingredient) const;
	Macierz operator*(const Macierz& ingredient) const;
	Macierz operator*(const double d) const;
	Macierz& operator=(const Macierz& M);
	Macierz(const Macierz& M);
	
	// TODO: dekonstruktor


};

