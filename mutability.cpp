// mutability - useful in a multi-threaded program
// we define functions that opeate on const objects 
// of user-defined data types

// constant member functions
class Date{
	int d, m, y;
public:
	int day() const {return d;}
	// const after the function name indicates that they don't
	// modify the state of a Date. Compiler catches accidental 
	// attempts that violate this.
	// int month() const {return ++m;} error: 'Date::month' is declared const here

	int year() const;

	void add_year(int n){y+=n;} 	// add n years
};

int Date::year() const // requires the const in the definition as
// it is declared const
{
	return y;
}
// a const member function can be invoked for both const
// and non-const objects, but a non-const mem fun can be 
// invoked only for non-conost objects
// Example:
void f(Date& d, const Date& cd)
{
	int i = d.year();
	d.add_year(1);

	int j = cd.year();
	// cd.add_year(1); // error: function is not marked const
}

int main()
{
	return 0;
}