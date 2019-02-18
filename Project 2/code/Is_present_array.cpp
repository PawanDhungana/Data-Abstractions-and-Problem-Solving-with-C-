//Pawan Dhungana
//CS-301 Project 2
//Check if the number is present in an array
//Due date: 09/13/2018

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

void readfile(int a[],int n, int k);
int present(int a[],int n,int k);

int main()
{
	int n=7;	//size of array
	int a[n];	//array declaration
	int k;		//the number that user enter
		
	readfile(a,n,k);
	cout<<"\nTest value -> ";
	cin>>k;
	if ( present(a,n,k) != false)
	cout<<"\nPresent"<<endl;
	
	else
	cout<<"\nNot Present";
}
		
void readfile(int a[],int n, int k)
{
	cout<<"Data file name ->  ";
	ifstream in_f;	
	char file[50];//takes input what file user want to open
	cin.getline(file,50);
	in_f.open(file);//opens file
	
	cout<<"\nThe array read from the file is : ";
	
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
