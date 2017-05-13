#pragma once
class VariableConstraints
{
public:
	VariableConstraints(double _min, double _max);
	~VariableConstraints();

    bool setConstraints(double _min, double _max);

	double getMin() const;
	double getMax() const;

	void setMin(double value);
	void setMax(double value);

private:
	double min;
	double max;
};

