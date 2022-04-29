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
	Macierz(double firstElVal);

	void addRow();
	void addRow(std::vector<double> const &newElVal);
	void addColumn();
	void addColumn(std::vector<double> const& newElVal);


	void deleteRow();
	void deleteCol();

	void writeOut();
	Element* writeOutEl(int row, int col);
	double getElVal(int row, int col);

	// operatory

	Macierz operator+(Macierz& ingredient);
	Macierz operator-(Macierz& ingredient);

	Macierz operator*(Macierz& ingredient); 

	// TODO: mno¿enie skalar macierz
};

