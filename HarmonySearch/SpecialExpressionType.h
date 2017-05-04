#pragma once

enum SpecialExpressionType
{
	none,			// bez specjalnej funkcji
	polynomial,		// wielomian - x^a
	exponential,	// e^x
	logaritmic,	    // log_a(x)
	naturalLog,		// ln(x)
	power,			// potêgowa - a^x
	sinus,			// sin(x)
	cosinus,		// cos(x)
	tangens,		// tan(x)
	cotangens		// ctan(x)
};