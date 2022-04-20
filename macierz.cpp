#include "macierz.h"


macierz::macierz(double firstElVal) : firstElement_(new element(firstElVal)),
										rowNumber_(1), colNumber_(1){}

void macierz::addRow()
{
	element* firstElOfLastRow = firstElement_;
	while (firstElOfLastRow->getDown() != nullptr)
		firstElOfLastRow = firstElOfLastRow->getDown();


	element* lastRowEl = firstElOfLastRow;
	element* newEl;
	element* lastNewEl = nullptr;

	for (int i = 0; i < colNumber_; i++)
	{
		newEl = new element(0); //wartosc do zmainy

		newEl->setUpper(lastRowEl);
		lastRowEl->setDown(newEl);

		if (i>0)
		{
			lastNewEl->setRight(newEl);
			newEl->setLeft(lastNewEl);
		}

		lastNewEl = newEl;
		lastRowEl = lastRowEl->getRight();
	}
	rowNumber_++;
}

void macierz::addRow(std::vector<double> const &newElVal)
{
	if (newElVal.size() != colNumber_)
		return;
	
	this->addRow();

	element* firstElOfLastRow = firstElement_;
	while (firstElOfLastRow->getDown() != nullptr)
		firstElOfLastRow = firstElOfLastRow->getDown();

	element* lastRowEl = firstElOfLastRow;

	for (double val : newElVal)
	{
		lastRowEl->setVal(val);
		lastRowEl = lastRowEl->getRight();
	}
	

}

void macierz::addColumn()
{
	element* firstElOfLastCol = firstElement_;
	while (firstElOfLastCol->getRight() != nullptr)
		firstElOfLastCol = firstElOfLastCol->getRight();

	element* lastColEl = firstElOfLastCol;
	element* newEl;
	element* lastNewEl = nullptr;

	for (int i = 0; i < rowNumber_; i++)
	{
		newEl = new element(0); // wartosc do zmainy

		newEl->setLeft(lastColEl);
		lastColEl->setRight(newEl);

		if (i > 0)
		{
			lastNewEl->setDown(newEl);
			newEl->setUpper(lastNewEl);
		}
		lastNewEl = newEl;
		lastColEl = lastColEl->getDown();
	}
	colNumber_++;
}

void macierz::addColumn(std::vector<double> const& newElVal)
{
	if (newElVal.size() != rowNumber_)
		return;

	this->addColumn();

	element* firstElOfLastCol = firstElement_;
	while (firstElOfLastCol->getRight() != nullptr)
		firstElOfLastCol = firstElOfLastCol->getRight();

	element* lastColEl = firstElOfLastCol;

	for (double val : newElVal)
	{
		lastColEl->setVal(val);
		lastColEl = lastColEl->getDown();
	}
}

void macierz::deleteRow()
{
	if (rowNumber_ == 1)
		return;

	element* firstElOfLastRow = firstElement_;
	while (firstElOfLastRow->getDown() != nullptr)
		firstElOfLastRow = firstElOfLastRow->getDown();

	element* elOfLastRow = firstElOfLastRow;
	element* nextEl;

	for (int i = 0; i < colNumber_; i++)
	{
		nextEl = elOfLastRow->getRight();
		(elOfLastRow->getUpper())->setDown(nullptr);
		delete elOfLastRow;
		elOfLastRow = nextEl;		
	}

	rowNumber_--;
}

void macierz::deleteCol()
{
	if (colNumber_ == 1)
		return;

	element* firstElOfLastCol = firstElement_;
	while (firstElOfLastCol->getRight() != nullptr)
		firstElOfLastCol = firstElOfLastCol->getRight();

	element* elOfLastCol = firstElOfLastCol;
	element* nextEl;

	for (int i = 0; i < rowNumber_; i++)
	{
		nextEl = elOfLastCol->getDown();
		(elOfLastCol->getLeft())->setRight(nullptr);
		delete elOfLastCol;
		elOfLastCol = nextEl;
	}

	colNumber_--;
}

void macierz::writeOut()
{
	element* firstElInRow = firstElement_;
	element* currentElement = firstElement_;

	while (firstElInRow != nullptr)
	{
		while(currentElement != nullptr )
		{
			std::cout << currentElement->getVal() << '\t';
			currentElement = currentElement->getRight();
		}
		std::cout << '\n';
		firstElInRow = firstElInRow->getDown();
		currentElement = firstElInRow;
	}
}

element* macierz::writeOutEl(int row, int col)
{
	element* tempEl = firstElement_;

	for (int r = 1; r < row; r++)
	{
		tempEl = tempEl->getDown();
	}

	for (int c = 1; c < col; c++)
	{
		tempEl = tempEl->getRight();
	}

	return tempEl;

}



