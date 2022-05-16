#include "Element.h"
#include <iostream>

Element::Element(double value) : value_(value), upperNeighbour_(nullptr), rightNeighbour_(nullptr),
                                 downNeighbour_(nullptr), leftNeighbour_(nullptr) {}

Element::~Element()
{
	std::cout << " <del-el> ";
}


Element::Element(double value, Element* up, Element* right, Element* down, Element* left) : value_(value),
                                                                                            upperNeighbour_(up), rightNeighbour_(right), downNeighbour_(down), leftNeighbour_(left) {}

double Element::getVal() const
{
	return value_;
}

void Element::setVal(double newVal)
{
	value_ = newVal;
}

Element* Element::getUpper() const
{
	return upperNeighbour_;
}

Element* Element::getRight() const
{
	return rightNeighbour_;
}

Element* Element::getDown() const
{
	return downNeighbour_;
}

Element* Element::getLeft() const
{
	return leftNeighbour_;
}

void Element::setUpper(Element* upperNeighbour)
{
	upperNeighbour_ = upperNeighbour;
}

void Element::setRight(Element* rightNeighbour)
{
	rightNeighbour_ = rightNeighbour;
}

void Element::setDown(Element* downNeighbour)
{
	downNeighbour_ = downNeighbour;
}

void Element::setLeft(Element* leftNeighbour)
{
	leftNeighbour_ = leftNeighbour;
}

