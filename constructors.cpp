// Constructors - explicit purpose is to initialize objects. As it
// constructs values of a given type, they are called constructors.
// They have the same name as the class; Example: 
class DateConstructorDemo {
	int d, m, y;
public:
	DateConstructorDemo(int dd, int mm, int yy);	// constructor
	// ...
};
// arguments of a constructor must be supplied.
void constructordemo()
{
	DateConstructorDemo today = DateConstructorDemo(23,6,1983);
	DateConstructorDemo xmas(25,12,1990);	// abbreviated form
	// DateConstructorDemo my_birthday;	// error: no matching constructor
	// DateConstructorDemo release1_0(10,12); // error: no matching constructor
	// since a constructor defines initialization for a class, we could use {}-
	// initialization notation.
	DateConstructorDemo tomorrow = DateConstructorDemo{24,6,1983};
	DateConstructorDemo bday{25,12,1990};	// abbreviated form
	// Note: {}-form is recommended.
}
DateConstructorDemo::DateConstructorDemo(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}
// CONSTRUCTOR OVERLOADING
class Organism
{
	int h, b, l;
public:
	Organism(int hh, int bb, int ll)	// head, body, leg
	{
		h = hh;
		b = bb;
		l = ll;
	}	
	Organism(int hh, int ll)	// head, leg
	{
		h = hh;
		l = ll;
	}
	Organism(int ll)	// leg
	{
		l = ll;
	}
	Organism()	// default numbers
	{
		h = 1;
		b = 1;
		l = 2;
	}
	Organism(const char*);	// date in human in string representation
};

Organism::Organism(const char* ptr)
{
	
}

void cnstrctroverld()
{
	Organism cow{1,1,4};
	Organism alien{"Has a complex body"};
	Organism weirdanimal{1,1};
	Organism human;
	Organism chimp{};
}
// one way of reducing the number of related functions is to use
// default arguments. Let us pick the default as "today"
struct Dt{
	int d;
	int m;
	int y;
}today{2,7,2018};

class Date{
	int d, m, y;
public:
	Date(int dd=0,int mm=0, int yy=0);
};

Date::Date(int dd, int mm, int yy)
{
	d = dd?dd:today.d;
	m = mm?mm:today.m;
	y = yy?yy:today.y;

	// checks the validity of the date
}

// Alternately,
class Date1{
	int d, m, y;
public:
	Date1(int dd=today.d, int mm=today.m, int yy=today.y);
};

Date1::Date1(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}

int main()
{
	return 0;
}
