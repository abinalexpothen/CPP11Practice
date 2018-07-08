// In-class function definitions
// used for small, rarely modified, frequently used func

class Date{
public:
	void add_month(int n){m+=n;}	// increment Date's m
	// ...
private:
	int d, m, y;
};
// function and data member declarations are order independent
// an alternate definition
class Date1{
public:
	void add_month(int n);
private:
	int d, m, y;
};

inline void Date1::add_month(int n) // add n months
{
	m+=n;	// increment month
}
// inline definition keeps class definition simple and 
// easy to read. Provides textual separation of class's
// interface and implementation detail.

int main()
{
	return 0;
}