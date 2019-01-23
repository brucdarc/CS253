#include <HashTable.h>
#include <iostream>
#include <string>
#include <Reader.h>
using std::endl;
using std::cout;

void pdeets(HashTable h)
{
cout << "obj : count " << h.Count() << " factor: " << h.Factor() << " size: " << h.Size() << endl;
}

int main(int argc, char* argv[])
{

char a = argv[1][0];
cout << a << endl;
switch(a)
{
case '1':
{
cout << "case 1" << endl;

HashTable h;

pdeets(h);

h.Add("ayylmay");

pdeets(h);

for(int i=98; i< 120;i=  i+1)
{
string a = "";
a.push_back((char)i);
h.Add(a); 
}

cout << "countains a: " << h.Contains("a") << endl;
cout << "countains j: " << h.Contains("j") << endl;
cout << "countains k: " << h.Contains("k") << endl;

break;
}
case '2':

Reader a("HEY HI BYE DOWN WITH SOCIETY HA HAHA HAHAHA AYY IM A");
cout << a.Compare("HEY HI BYE DOWN WITH SOCIETY HA HAHA HAHAHA AYY IM A DINOSAUR BURN SHIT") << endl;

HashTable h;
h.Add("Hello");
HashTable c(h);
c.Add("Hi");
HashTable b = c;
c.Add("Bye");
c=b;

}
}



