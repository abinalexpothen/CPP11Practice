// In-class initializers
// when several constructors are used, member init become
// repititive.
struct{
	int d, m, y;
}today{2,7,2018};

class Date {
	int d {today.d};
	int m {today.m};
	int y {today.y};
public:
	Date(int, int, int);	// day, month, year
	Date(int, int);			// day, month, today's year
	Date(int);				// day, today's month and year
	Date();					// default Date: today
	Date(const char*);		// default string representation
};
// now, each constructor has d, m, and y initialized unless
// it does itself.
Date::Date(int dd)
:d{dd}
{
	// check validity
}
// same as
// Date::Date(int dd)
// :d{dd}, m{today.m}, y{today.y}
// {
// 	// check validity
// }
int main()
{
	return 0;
}