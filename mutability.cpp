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

	void add_years(int n); 	// add n years
};

int main()
{
	return 0;
}