#include "Macierz.h"


Macierz::Macierz(double firstElVal) : firstElement_(new Element(firstElVal)),
										rowNumber_(1), colNumber_(1){}

void Macierz::addRow()
{
	Element* firstElOfLastRow = firstElement_;
	while (firstElOfLastRow->getDown() != nullptr)
		firstElOfLastRow = firstElOfLastRow->getDown();


	Element* lastRowEl = firstElOfLastRow;
	Element* newEl;
	Element* lastNewEl = nullptr;

	for (int i = 0; i < colNumber_; i++)
	{
		newEl = new Element(0); //wartosc do zmainy

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

void Macierz::addRow(std::vector<double> const &newElVal)
{
	if (newElVal.size() != colNumber_)
		return;
	
	this->addRow();

	Element* firstElOfLastRow = firstElement_;
	while (firstElOfLastRow->getDown() != nullptr)
		firstElOfLastRow = firstElOfLastRow->getDown();

	Element* lastRowEl = firstElOfLastRow;

	for (double val : newElVal)
	{
		lastRowEl->setVal(val);
		lastRowEl = lastRowEl->getRight();
	}
	

}

void Macierz::addColumn()
{
	Element* firstElOfLastCol = firstElement_;
	while (firstElOfLastCol->getRight() != nullptr)
		firstElOfLastCol = firstElOfLastCol->getRight();

	Element* lastColEl = firstElOfLastCol;
	Element* newEl;
	Element* lastNewEl = nullptr;

	for (int i = 0; i < rowNumber_; i++)
	{
		newEl = new Element(0); // wartosc do zmainy

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

void Macierz::addColumn(std::vector<double> const& newElVal)
{
	if (newElVal.size() != rowNumber_)
		return;

	this->addColumn();

	Element* firstElOfLastCol = firstElement_;
	while (firstElOfLastCol->getRight() != nullptr)
		firstElOfLastCol = firstElOfLastCol->getRight();

	Element* lastColEl = firstElOfLastCol;

	for (double val : newElVal)
	{
		lastColEl->setVal(val);
		lastColEl = lastColEl->getDown();
	}
}

void Macierz::deleteRow()
{
	if (rowNumber_ == 1)
		return;

	Element* firstElOfLastRow = firstElement_;
	while (firstElOfLastRow->getDown() != nullptr)
		firstElOfLastRow = firstElOfLastRow->getDown();

	Element* elOfLastRow = firstElOfLastRow;
	Element* nextEl;

	for (int i = 0; i < colNumber_; i++)
	{
		nextEl = elOfLastRow->getRight();
		(elOfLastRow->getUpper())->setDown(nullptr);
		delete elOfLastRow;
		elOfLastRow = nextEl;		
	}

	rowNumber_--;
}

void Macierz::deleteCol()
{
	if (colNumber_ == 1)
		return;

	Element* firstElOfLastCol = firstElement_;
	while (firstElOfLastCol->getRight() != nullptr)
		firstElOfLastCol = firstElOfLastCol->getRight();

	Element* elOfLastCol = firstElOfLastCol;
	Element* nextEl;

	for (int i = 0; i < rowNumber_; i++)
	{
		nextEl = elOfLastCol->getDown();
		(elOfLastCol->getLeft())->setRight(nullptr);
		delete elOfLastCol;
		elOfLastCol = nextEl;
	}

	colNumber_--;
}

void Macierz::writeOut() const
{
	Element* firstElInRow = firstElement_;
	Element* currentElement = firstElement_;

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

Element* Macierz::writeOutEl(int row, int col) const
{
	Element* tempEl = firstElement_;

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

double Macierz::getElVal(int row, int col) const
{
	Element* tempEl = this->writeOutEl(row, col);
	return tempEl->getVal();
}

Macierz Macierz::operator+(const Macierz& ingredient) const
{
	if (rowNumber_ != ingredient.rowNumber_ && colNumber_ != ingredient.colNumber_)
		return Macierz(0);

	Macierz sum = Macierz(0);

	for (int r = 1; r < rowNumber_; r++)
	{
		sum.addRow();
	}
	for (int c = 1; c < colNumber_; c++)
	{
		sum.addColumn();
	}

	//std::cout << '\n';
	//sum.writeOut();
	//std::cout << '\n';

	Element* tempEl;

	for (int r = 1; r <= rowNumber_; r++) //wsp. elementów od 1 do rowNumber_
	{
		for (int c = 1; c <= colNumber_; c++) //wsp. elementów od 1 do colNumber_
		{
			tempEl = sum.writeOutEl(r, c);

			//std::cout << "row " << r << "col " << c << "element val: " << tempEl->getVal() << std::endl;

			tempEl->setVal((this->writeOutEl(r, c))->getVal() + (ingredient.writeOutEl(r, c))->getVal());

			//std::cout << "row " << r << "col " << c << "element val: " << tempEl->getVal() << "\n\n";
		}
	}
	return sum;

}

Macierz Macierz::operator-(const Macierz& ingredient) const
{
	if (rowNumber_ != ingredient.rowNumber_ && colNumber_ != ingredient.colNumber_)
		return Macierz(0);

	Macierz sum = Macierz(0);

	for (int r = 1; r < rowNumber_; r++)
	{
		sum.addRow();
	}
	for (int c = 1; c < colNumber_; c++)
	{
		sum.addColumn();
	}

	Element* tempEl;

	for (int r = 1; r <= rowNumber_; r++) //wsp. elementów od 1 do rowNumber_
	{
		for (int c = 1; c <= colNumber_; c++) //wsp. elementów od 1 do colNumber_
		{
			tempEl = sum.writeOutEl(r, c);
			tempEl->setVal((this->writeOutEl(r, c))->getVal() - (ingredient.writeOutEl(r, c))->getVal());
		}
	}
	return sum;
}

Macierz Macierz::operator*(const Macierz& ingredient) const
{
	if (this->colNumber_ != ingredient.rowNumber_)
		return Macierz(0);

	Macierz product = Macierz(0);

	for (int r = 1; r < rowNumber_; r++)
	{
		product.addRow();
	}
	for (int c = 1; c < ingredient.colNumber_; c++)
	{
		product.addColumn();
	}


	Element* tempEl;

	for (int r = 1; r <= product.rowNumber_; r++) //wsp. elementów od 1 do rowNumber_
	{
		for (int c = 1; c <= product.colNumber_; c++) //wsp. elementów od 1 do colNumber_
		{
			tempEl = product.writeOutEl(r, c);
			double elVal = 0;

			for (int i = 0; i < this->colNumber_; i++)
			{
				elVal += (this->getElVal(r, i + 1) * ingredient.getElVal(i + 1, c));
			}
			tempEl->setVal(elVal);
		}
	}
	return product;
}



