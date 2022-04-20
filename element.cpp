#include "element.h"

element::element(double value) : value_(value), upperNeighbour_(nullptr), rightNeighbour_(nullptr),
                                 downNeighbour_(nullptr), leftNeighbour_(nullptr) {}

element::element(double value, element* up, element* right, element* down, element* left) : value_(value),
	upperNeighbour_(up), rightNeighbour_(right), downNeighbour_(down), leftNeighbour_(left) {}

double element::getVal()
{
	return value_;
}

void element::setVal(double newVal)
{
	value_ = newVal;
}

element* element::getUpper()
{
	return upperNeighbour_;
}

element* element::getRight()
{
	return rightNeighbour_;
}

element* element::getDown()
{
	return downNeighbour_;
}

element* element::getLeft()
{
	return leftNeighbour_;
}

void element::setUpper(element* upperNeighbour)
{
	upperNeighbour_ = upperNeighbour;
}

void element::setRight(element* rightNeighbour)
{
	rightNeighbour_ = rightNeighbour;
}

void element::setDown(element* downNeighbour)
{
	downNeighbour_ = downNeighbour;
}

void element::setLeft(element* leftNeighbour)
{
	leftNeighbour_ = leftNeighbour;
}

