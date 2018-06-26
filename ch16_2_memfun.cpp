// consider implementing the concept of date using struct
struct Date{
	int d,m,y;

	// an explicit connection between the data type Date and these
	// functions can be established by using member functions
	void init(int dd, int mm, int yy); // initalize date
	void add_year(int n);			// add n years to d
	void add_month(int n); 			// add n months to d
	void add_day(int n);			// add n days to d
};

// functions defined within a class definition are member functions.
// Invoked using the standard structure member access for a specific
// variable.

Date my_birthday;

int main()
{
	Date today;
	today.init(25,06,2018);
	my_birthday.init(07,07,1994);

	Date tomorrow = today;
	tomorrow.add_day(1);

	return 0;
}

// Now, different structures can have member functions with the same
// name. Therefore, we must specify structure name when defining a
// member function.

void Date::init(int dd, int mm, int yy) // member function definition 
{
	d = dd; // note that we need not reference the variable d to a specific
	//object in the member function definition.     
	m = mm;
	y = yy; 
}
// Learning: A class member function "knows" for which object it was
// invoked.
void Date::add_day(int n)
{
	d = d+n;
}