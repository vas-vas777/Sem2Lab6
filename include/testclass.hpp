#include <iostream>
using namespace std;

template <typename T>
class Complex {
	T Real_;
	T Im_;

	Complex<T> addComp(Complex<T> comp1, Complex<T> comp2);
	Complex<T> subComp(Complex<T> comp1, Complex<T> comp2);
	Complex<T> multNum(Complex<T> comp1, T num);
	Complex<T> divNum(Complex<T> comp1, T num);
	Complex<T> multComp(Complex<T> comp1, Complex<T> comp2);
public: 
	Complex<T>() : Real_(0), Im_(0) {};
	Complex<T>(T Real, T Im) : Real_(Real), Im_(Im) {};
	
	T getReal() {return Real_;}
	T getIm() {return Im_;}

	Complex<T> add(Complex<T> comp1, Complex<T> comp2);
	Complex<T> sub(Complex<T> comp1, Complex<T> comp2);
	Complex<T> mult(Complex<T> comp1, T num);
	Complex<T> div(Complex<T> comp1, T num);
	Complex<T> multC(Complex<T> comp1, Complex<T> comp2);

	void print(ostream&) {
		cout << Real_ << " + i*(" << Im_ << ')' << endl;
	}

	friend ostream& operator << (ostream&, const Complex<T>&);
};

template<typename T>
Complex<T> Complex<T>::addComp(Complex<T> comp1, Complex<T> comp2)
{
	this->Real_ = comp1.getReal() + comp2.getReal();
	this->Im_ = comp1.getIm() + comp2.getIm();
	return *this;
}

template<typename T>
Complex<T> Complex<T>::add(Complex<T> comp1, Complex<T> comp2)
{
	return addComp(comp1, comp2);
}

template<typename T>
Complex<T> Complex<T>::sub(Complex<T> comp1, Complex<T> comp2)
{
	return subComp(comp1,comp2);
}

template<typename T>
Complex<T> Complex<T>::mult(Complex<T> comp1, T num)
{
	return multNum(comp1, num);
}

template<typename T>
Complex<T> Complex<T>::div(Complex<T> comp1, T num)
{
	return divNum(comp1, num);
}

template<typename T>
Complex<T> Complex<T>::multC(Complex<T> comp1, Complex<T> comp2)
{
	return multComp(comp1, comp2);
}

template<typename T>
Complex<T> Complex<T>::subComp(Complex<T> comp1, Complex<T> comp2)
{
	this->Real_ = comp1.getReal() - comp2.getReal();
	this->Im_ = comp1.getIm() - comp2.getIm();
	return *this;
}

template<typename T>
Complex<T> Complex<T>::multNum(Complex<T> comp1, T num)
{
	this->Real_ = comp1.getReal() * num;
	this->Im_ = comp1.getIm() * num;
	return *this;
}

template<typename T>
Complex<T> Complex<T>::divNum(Complex<T> comp1, T num)
{
	try {
		if (num != 0) {
			this->Real_ = comp1.getReal() / num;
			this->Im_ = comp1.getIm() / num;
		}
		else throw "Division by zero!\n";
	}
	catch (char *msg) {
		cout << "Error: " << msg;
		return comp1;
	}
	return *this;
}

template<typename T>
Complex<T> Complex<T>::multComp(Complex<T> comp1, Complex<T> comp2)
{
	this->Real_ = comp1.getReal()*comp2.getReal() - comp1.getIm()*comp2.getIm();
	this->Im_ = comp1.getReal()*comp2.getIm() + comp1.getIm()*comp2.getReal();
	return *this;
}

template<typename T>
ostream & operator<<(ostream & out, Complex<T> &c)
{
	c.print(out);
	return out;
}