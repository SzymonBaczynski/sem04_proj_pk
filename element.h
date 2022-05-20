#pragma once
class Element
{
private:
	double value_;
	Element* upperNeighbour_;
	Element* rightNeighbour_;
	Element* downNeighbour_;
	Element* leftNeighbour_;

public:
	Element(double value);


	Element(double value, Element* up, Element* right, Element* down, Element* left);

	double getVal() const;
	void setVal(double newVal);

	Element* getUpper() const;
	Element* getRight() const;
	Element* getDown() const;
	Element* getLeft() const;

	void setUpper(Element* upperNeighbour);
	void setRight(Element* rightNeighbour);
	void setDown(Element* downNeighbour);
	void setLeft(Element* leftNeighbour);
	
};

