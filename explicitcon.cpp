// an example of a source of confusion in implicit conversion
struct{
	int d, m, y;
}today{2,7,2018};

class Date{
	int d, m, y;
public:
	Date(int dd = today.d, int mm = today.m, int yy=today.y);
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
	Date d {15};	// plausible: becomes {15,today.m,today.y}
	my_fct(15);	// obscure
	d = 15;	// obscure
}
// This is obscure as there's no logical connection between 
// 15 and Date independently of the intricacies of our code
// Solution: specify that a constructor is not used as an 
// implicit conversion

int main()
{
	return 0;
}