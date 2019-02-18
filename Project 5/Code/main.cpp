#include <iostream>
#include <fstream>
#include<string.h>
#include "implementation.cpp"
#include "list.h"
using namespace std;

int main()
{ 
	Concordance Cord;       //Class OBject
	//data Memebers
	int count = 1;

	ifstream from_f;
	
	//Opening a File
	from_f.open("content.txt");
	Cord.insert(from_f);
	from_f.close();
	
	//Printing the list of the Class
	cout<<Cord;
	
	//Printing the distinct length
	cout<<"The File contains" <<Cord.length()<<endl;
	
	//Getting the count of the word in the list
	Word sen;
	int word_count;
	cout << "\nEnter the word: " ;
	cin >> sen;
	word_count = Cord.get_count(sen);
	cout << "Count of the word " << sen << " = "<<word_count<<endl;
	
	return 0;
}
