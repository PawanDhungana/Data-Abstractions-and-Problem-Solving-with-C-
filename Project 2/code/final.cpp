//Pawan Dhungana
//CS-301 Project 2
//Due date: 09/13/2018

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int backwards(int);
int prime(int,int);

void readfile(int a[],int n, int k);
int present(int a[],int n,int k);

int main()
{
	int pawan;
	cout<<"Enter: \n1 to print the integer backwards"<<endl;
	cout<<"2 to check if the number entered is present in the array"<<endl;
	cout<<"3 to find the prime factorization of the integer entered"<<endl;
	cin>>pawan;
	
	int number;
	int x=2;
	
	switch(pawan)//ask the user what the wants to perform
	{
		case 1:
			cout<<"\nEnter the integer : "<<endl;
			cin>>number;
			cout<<"The number printed backwards is: ";
			cout<<backwards(number);
			break;
		
		case 3:
			cout<<"\nEnter the integer : "<<endl;
			cin>>number;
			cout<<"The prime factors are: ";
			cout<<prime(number,x);
			break;
			
		case 2:
			int n=50;
			int a[n];
			int k;
	
			cout<<"\nEnter the number you want to search for: "<<endl;
			cin>>k;
			
			readfile(a,n,k);
			
			if ( present(a,n,k) != false)
			cout<<"Is present"<<endl;
	
			else
			cout<<"Not present";
		
			break;
	}
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

int prime(int num,int div)
{
	if(num == 1)	//base case if number is equal to 1, return 1
		return num;
	else if(num%div==0) //check if the integer is divisible and print divisor
	{
		cout<<div<<" ";
		return prime(num/div,div);
	}
	else
	return prime(num,div+1); //increase the dividend and check if now divisible
}

void readfile(int a[],int n, int k){
	
	cout<<"Enter the filename you want to open including the extension: "<<endl;
	ifstream in_f;	
	char file[50];//takes input what file user want to open
	cin.getline(file,50);
	in_f.open(file);//opens file
	
	cout<<"The array read from the file is : ";
	
	for(int i=0;i<n;i++) //stores the numbers read from file into an array
	{
		in_f >> a[i];
		cout<<a[i]<<" ";
	}
	in_f.close();	//closes the file

}
	
int present(int a[],int n,int k)	//check if the number entered is present in the array
{	
	if(n<0)	//base case 
		return false;
	
	else if(a[n]==k)	// if the element is present
		return true;
	
	else	//recursion
		return present(a,n-1,k);	
}
