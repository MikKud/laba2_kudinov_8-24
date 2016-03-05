#include "stdafx.h"
#include <iostream>
#include "vklad.h"
using std::endl;
using namespace lab2;
int Vklad::count=0;
int Vklad::getCount()
{
	return count;
}

Vklad::Vklad(string Fname, string name,double sum, double proc, int sz)//constructor normal
	:ExactSum(sum),Procent(proc)
{
	size=(sz>0?sz:10);//10 default
	Noteptr=new int[size];
	for(int i=0;i<size;i++)
		Noteptr[i]=0;

	setFName(Fname);
	setName(name);
	count++;
	cout<<"\nNormal construktor\n"<<endl;
}
Vklad::Vklad(const Vklad &v1):ExactSum(v1.ExactSum),Procent(v1.Procent),size(v1.size)//copy construcor
{
	Noteptr=new int[size];
	for (int i=0; i<size;i++)
		Noteptr[i]=v1.Noteptr[i];
	FamilyName=v1.FamilyName;
	Name=v1.Name;
	count++;
	cout<<"\ncopy constructor\n"<<endl;
}
Vklad::~Vklad()//distructor
{
	cout<<"\n\nDistrucktor VERNITE MNE MOI 2007!!!!!\n\n"<<endl;
	--count;
	delete [] Noteptr;
}

void Vklad::setFName(string Fname)
	{
		FamilyName=Fname;
	}
void Vklad::setName(string name)
	{
		Name=name;
	}
void Vklad::setSum(double Sum)
{
	if(Sum>=0)
	ExactSum=Sum;
	else
	ExactSum=0;
}
void Vklad::setProc(double proc)
{
	if(proc>=0)
	Procent=proc;
	else
	Procent=0;
}
string Vklad::getName() const
{
	return Name;
}
string Vklad::getFName() const
{
	return FamilyName;
}
double Vklad::getSum() const
{
	return ExactSum;
}
double Vklad::getProc() const
{
	return Procent;
}
const Vklad &Vklad::operator=(const Vklad &v1)
{
	if(&v1!= this)
	{
		if(size!=v1.size)
		{
			delete [] Noteptr;
			size=v1.size;
			Noteptr=new int[size];
		}
		for(int i=0; i <size;i++)
			Noteptr[i]=v1.Noteptr[i];

		FamilyName=v1.FamilyName;
		Name=v1.Name;
		Procent=v1.Procent;
		ExactSum=v1.ExactSum;
	}
	return *this;//v1=v2=v3; 
}
int Vklad::operator==(const Vklad &v1) const
{
	if (ExactSum==v1.ExactSum)
		return 0;
	if (ExactSum>v1.ExactSum)
		return 1;
	if (ExactSum<v1.ExactSum)
		return -1;
}

ostream &lab2::operator<<(ostream &output,const Vklad &v1)
{
	output<<"Vklad\nName "<<v1.getName()<<"\nFamily Name "<<v1.getFName()<<"\nProcent "<<v1.getProc()<<"\nSum "<<v1.getSum()<<"\nyour code is ";
	for(int i=0;i<v1.getSize();i++)
	{
		output<<v1.Noteptr[i];
	}
	output<<endl;
	return output;
}

istream &lab2::operator>>(istream &input, Vklad &v1)//Fname,Name,Sum,Proc, massive of int length size
{
	input>>v1.FamilyName;
	input>>v1.Name;
	input>>v1.ExactSum;
	input>>v1.Procent;
	for(int i=0;i<v1.size;i++)
	{
		input>>v1.Noteptr[i];
	}

	return input;
}
