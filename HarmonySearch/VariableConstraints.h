#pragma once
class VariableConstraints
{
public:
	VariableConstraints(double _min, double _max);
	~VariableConstraints();

	double getMin();
	double getMax();

	void setMin(double value);
	void setMax(double value);

private:
	double min;
	double max;
};

