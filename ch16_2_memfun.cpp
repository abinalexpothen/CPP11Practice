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

// Reg. DEFAULT COPYING
// by default, the class objects can be copied
Date d1 = my_birthday;	// init by copy
Date d2{my_birthday};	// init by copy
// by default, the copy of a class object is a copy of each member
// a class object can by default be copied by assignment
void f(Date& d)
{
	d = my_birthday;	// again, default semantics is memberwise copy ... 
	//we can define an appropriate assignment operator is that is not the 
	//right choice.
}

// Reg. ACCESS CONTROL
class DateClass{
	int d,m,y;
public:
	void init(int dd, int mm, int yy);	// initialize
	void add_year(int n);	// add n years
	void add_month(int n);	// add n months
	void add_day(int n);	// add n days
};
// A struct is a class whose members are public by default
void DateClass::add_year(int n)
{
	y += n;
}
// Nonmember functions are barred from using private members of a class
void timewarp(Date& d)
{
	d.y -= 200;	// error: Date::y is private
}