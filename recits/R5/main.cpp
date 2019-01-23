#include <vector>
#include <iostream>
using namespace std;

class Test {
public:
	Test (int x) {p = new int(x);}
	Test (const Test& t) {p = new int(t.getValue());}
	~Test() {
		delete p;
	}
	int getValue () const {return *p;}
	int *p;
};

void test1 () {
	int *val = new int[1];
	val[0] = 1;
	delete[] val;
}

char* test2 () 
{
	char msg[100] = "Hello world!";	
	return msg;
}

char test3 ()
{
	char c = 'a';
	return c;
}

void test4 ()
{
	char *char_array = new char[3];
	char_array[0] = 'a';
	char_array[1] = 'b';
	char_array[2] = 'c';
	delete[] char_array;
}

void test5(Test t)
{
	cout << "test5: " << t.getValue() << endl;
}

int main (int argc, char* argv[]) 
{
	int i =0;
	cout << "i in main: " << i << endl;

	test1();
	
	char* p = test2();
	cout << "test2: " << p << endl;

	char c = test3();
	c = 'd';

	test4();

	Test x(5);
	test5(x);

}
