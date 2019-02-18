//Pawan Dhungana
//CS-301 Project 2
//Print integer backwards
//Due date: 09/13/2018

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int backwards(int);

int main()
{
	int number;
	int x=2;
	cout<<"\nEnter the integer : "<<endl;
	cin>>number;	//takes in the integer
	cout<<"The number printed backwards is: ";
	cout<<backwards(number);
}

int backwards(int a)
{
	if(a < 10) //base/basic case i.e if number is less than 10 the problem is already solved, nothing to do, so simply return
        return a;
    else{
        cout << a % 10; // print that last digit, e.g 103%10 == 3 
        return backwards(a/10); //solve the same problem but with smaller number, i.e make the problem smaller by dividing it by 10,  initially we had 103, now 10 
	}
}
