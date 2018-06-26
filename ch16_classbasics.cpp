// 16.2 Class basics - introduces basic facilities for defining class and its members
// Class is a user-defined type. Contains data members + member functions
// member functions define the meaning of initialization, copy, move and cleanup.
// data members are accessed using . for objects and -> for pointers
// +, !, [] operators can be defined for a class
// class is a namespace containing its members
// public mem - class interface; private mem - implementation details
// struct is a public class

// Example: 
class X{
private:		// implementation is private
	int m;
public:			// user interface is public
	X(int i=0) : m(i)	// a constructor (initialize data member m)
	{

	}	

	int mf(int i)		// a member function
	{
		int old =m;
		m = i;			// set a new value
		return old;		// return old value
	}

};

X var(7);	// a variable of type X, initialized with 7


int user(X var,X* ptr)
{
	int x = var.mf(7);	// access using dot
	int y = ptr->mf(9);	// access using arrow
	//int z = var.m;	// error: cannot access private member
	return 0;
}

int main()
{
	return 0;
}