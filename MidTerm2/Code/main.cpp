#include <Quagga.h>
#include <ZooProperty.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int ID::global_identifier = 0;
int Animal::animal_ctr = 0;
int Mammal::mammal_ctr = 0;
bool Animal::debug_flag = false;

int main(int argc, char** argv)
{

Equine* eptr = new Equine;
Mammal* mptr = reinterpret_cast<Mammal*>(eptr);
Quagga* qptr = reinterpret_cast<Quagga*>(eptr);
if(mptr) cout << mptr->WarmUp() << endl;
else cout << "mptr is null" << endl;
if(qptr) cout << qptr->WarmUp() << endl;
else cout << "qptr is null" << endl;

return 0;


}


