#ifndef VKLAD_H
#define VKLAD_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
namespace lab2{
class Vklad
{
	friend ostream& operator<<(ostream &, const Vklad &);//cout
	friend istream& operator>>(istream &, Vklad &);//cin
	friend void printMe(Vklad &v1)
	{
		cout<<"Vklad\nName "<<v1.getName()<<"\nFamily Name "<<v1.getFName()<<"\nProcent "<<v1.getProc()<<"\nSum "<<v1.getSum()<<"\nyour code is ";
	for(int i=0;i<v1.getSize();i++)
	{
		cout<<v1.Noteptr[i];
	}
	cout<<endl;
	}
	friend double retSum(Vklad &, int);
	friend class printer;
public:
	Vklad(string ="Default", string ="Default", double = 0, double = 0,int=0);//default constructor
	Vklad(const Vklad &);//copy constructor
	~Vklad();//destructor
	const Vklad& operator=(const Vklad&);//operator prisvaivaniya
	int operator==(const Vklad&) const;//operator to compare
	void setName(string);
	void setFName(string);
	void setSum(double);
	void setProc(double);
	string getName() const;
	string getFName() const;
	double getSum() const;
	double getProc() const;
	static int getCount();//return the amount of objects

	int getSize() const
	{return size;}
	void printMe()
	{
		cout<<"Vklad\nName "<<Name<<"\nFamily Name "<<FamilyName<<"\nProcent "<<Procent<<"\nSum "<<ExactSum<<"\nyour code is ";
	for(int i=0;i<size;i++)
	{
		cout<<Noteptr[i];
	}
	cout<<endl;
	}
private:
	static int count;//amount of objects
	string FamilyName;
	string Name;
	double ExactSum;
    double Procent;
	int size;//size of massive
	int *Noteptr;//pointer to the first element of a massive of chars specially made for creating dynamic memory
};
class printer
{
	public:
	static void printmeclassplz(Vklad &v1) 
	{
	cout<<"Vklad\nName "<<v1.getName()<<"\nFamily Name "<<v1.getFName()<<"\nProcent "<<v1.getProc()<<"\nSum "<<v1.getSum()<<"\nyour code is ";
	for(int i=0;i<v1.getSize();i++)
	{
		cout<<v1.Noteptr[i];
	}
	cout<<endl;
	}
};
}


#endif
