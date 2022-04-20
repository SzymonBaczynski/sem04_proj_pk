#pragma once
class element
{
private:
	double value_;
	element* upperNeighbour_;
	element* rightNeighbour_;
	element* downNeighbour_;
	element* leftNeighbour_;

public:
	element(double value);
	element(double value, element* up, element* right, element* down, element* left);

	double getVal();

	element* getUpper();
	element* getRight();
	element* getDown();
	element* getLeft();

	void setUpper(element* upperNeighbour);
	void setRight(element* rightNeighbour);
	void setDown(element* downNeighbour);
	void setLeft(element* leftNeighbour);
	
};

