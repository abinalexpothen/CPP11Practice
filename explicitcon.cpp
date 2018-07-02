// an example of a source of confusion in implicit conversion
struct{
	int d, m, y;
}today{2,7,2018};

class Date{
	int d, m, y;
public:
	explicit Date(int dd = 0, int mm = 0, int yy=0);
};

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
}
// This is obscure as there's no logical connection between 
// 15 and Date independently of the intricacies of our code
// Solution: specify that a constructor is not used as an 
// implicit conversion

int main()
{
	return 0;
}