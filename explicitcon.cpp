// an example of a source of confusion in implicit conversion
struct{
	int d, m, y;
}today{2,7,2018};

class Date{
	int d, m, y;
public:
	explicit Date(int dd = 0, int mm = 0, int yy=0);
};

// explicit Date::Date(int dd, int mm, int yy)
// error: explicit can only be specified inside the class definition
Date::Date(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}

void my_fct(Date d)
{

}

void f()
{
	Date d1 {15};	// plausible: becomes {15,today.m,today.y}
	Date d2 = Date{15};	// 
	//Date d3 = {15}; // error: explicit constructor defined here
	// Date d4 = 15;  // error: no viable conversion from int to Date
	// my_fct(15);	// error: candidate function not viable, no 
	// explicit conversion from int to Date
	// my_fct({15}); // error: candidate function not viable, cannot convert
	// initializer list argument to 'Date'
	my_fct(Date{15});

	// initialization with an = is a copy initialization.
	// a copy of the initializer is placed into the initialized object
	// a move operation may be used if the initializer is an rvalue
	// leaving out the = makes the init explicit and its a "direct init"


}
// This is obscure as there's no logical connection between 
// 15 and Date independently of the intricacies of our code
// Solution: specify that a constructor is not used as an 
// implicit conversion

// By default, declare a constructor that can be called with a single 
// argument explicit. Need a good reason NOT to do so. If you define an implicit
// constructor, it is best to document your reason.

// explicit can also be useful for constructors with 0 or more arg
struct X {
	explicit X()
	{

	}
	explicit X(int, int)
	{
		
	}
};

//X x1 = {};	// error: chosen constructor is explicit in copy-init
//X x2 = {1,2};	// error: chosen constructor is explicit in copy-init
X x3 {};	// direct init
X x4 {1,2};	// direct init

int f(X)
{
	return 0;
}

//int i1 = f({});	// error: cannot convert init list argument to 'X'
//int i2 = f({1,2});	// error: cannot convert init list argument to 'X'
int i3 = f(X{});	//
int i4 = f(X{1,2});	//

int main()
{
	return 0;
}