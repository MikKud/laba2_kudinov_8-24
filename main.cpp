// laba2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::endl;
using namespace std;
#include "vklad.h"
using namespace lab2;


double lab2::retSum(Vklad &num,int n)
{
	
	double result=num.ExactSum*pow(num.Procent,(double) n);
	cout<<"\nresult in "<<n<<" years is "<<result;
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Vklad *item;
	cout<<"enter n plz guy"<<endl;
	int n;
	cin>>n;
	item = new Vklad[n];
	delete [] item;
	
	
	Vklad v1;
	cout<<v1;

	Vklad v2("Vasya","Fedorov", 123.0,1.2,5);
	cout<<v2;

	v1=v2;
	cout<<v1;

	cout<<Vklad::getCount();

	cout<<"\nenter Fname,Name,Sum,Proc, massive of int length size 10"<<endl;
	Vklad v3;
	cin>>v3;
	cout<<v3;
	cout<<"\ncheck v3 and v1\n";
	cout<<(v3==v1);
	cout<<"\n";
	Vklad v4(v2);
	cout<<v4;
	
	printer p1;
	cout<<"\nnow call class\n"<<endl;
	p1.printmeclassplz(v1);
	cout<<"\nend of class print\n"<<endl;

	cout<<"\nnow call friend\n"<<endl;
	printMe(v1);
	cout<<"\nend of friend\n"<<endl;

	cout<<"must be 4 variants of objects, so if then 4 is ok "<<Vklad::getCount();
	retSum(v1,2);
	system("pause");
	return 0;
}

