//Pawan Dhungana
//CS-301 Project 2
//Prime factorization
//Due date: 09/13/2018

#include<iostream>

using namespace std;

int prime(int,int);

int main()
{
	int number;
	int x=2;
	cout<<"\nEnter the integer : "<<endl;
	cin>>number;
	cout<<"The prime factors are: ";
	cout<<prime(number,x);
}

int prime(int num,int div)
{
	if(num < 2)	//base case if number is equal to 1, return 1
		return 'a';
	else if(num%div==0) //check if the integer is divisible and print divisor
	{
		cout<<div<<" ";
		return prime(num/div,div);
	}
	else
	return prime(num,div+1); //increase the dividend and check if now divisible
}
