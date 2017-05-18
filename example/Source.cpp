#include "testclass.hpp"
int main() {
	Complex<int> x { 10, 15 };
	Complex<int> y { 2 , 5 };
	Complex<int> comp{};

	cout << "Addition:\n";
	comp.add(x, y);
	cout << comp << endl;
	
	cout << "Substraction:\n";
	comp.sub(x, y);
	cout << comp << endl;

	cout << "Division by number:\n";
	comp.div(x, 5);
	cout << comp << endl;

	cout << "Division by zero:\n";
	comp.div(x, 0);
	cout << comp << endl;
	
	cout << "Multiplication by number:\n";
	comp.mult(x, 2);
	cout << comp << endl;

	cout << "Multiplication by complex number:\n";
	comp.multC(x, y);
	cout << comp << endl;

	system("pause");
	return 0;
}