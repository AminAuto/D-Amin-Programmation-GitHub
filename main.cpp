#include <iostream>
#include "ZFraction.h"
using namespace std;
int main()
{

ZFraction a(3,12);
ZFraction b(1,6);
ZFraction c,d,e;
c = a-b;
d = a*b;
e=c+3;

cout << a << " - " << b << " = " << c << endl;
cout << a << " * " << b << " = " << d << endl;
cout << c << " + " << 3 << " = " << e << endl;
cout<<"a= "<<a.nbrReel()<<endl;
if(a > b)
cout << "a est plus grand que b" << endl;
else if(a==b)
cout << "a est egal a b." << endl;
else
cout << "a est plus petit que b" << endl;
if(a!=b){cout<<"a est diff de b"<<endl;}

return 0;
}
