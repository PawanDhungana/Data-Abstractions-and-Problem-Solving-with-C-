#ifndef LLIST_H
#define LLIST_H
#include <cstdlib>
#include <iostream>
#include "string.h"
using namespace std;

const int MAX = 7;
typedef char Word[MAX + 1];

class Binary_Search
{   

    private:
		//Definig Structure NODE
		struct node
		{
		
		char wd[MAX + 1];
		node *next;
		int count;
		
		};	
		node *first;
		
		 
		 //Member functions 
		 
		void help_insert(node *&p, Word& entry); 
		
		node* get_node(Word& data,node* link,int& count);
		
		
    public:
		
		Word entry;
		// CONSTRUCTORS
      	Concordance( ) { first = NULL; }           // Inline functins
		
	    //Member Functions
		void insert(ifstream& in_File);
	    int get_count(Word& target);               //Length Functions
	    int length();
	    
	    
		//Friend Function
		friend std::ostream & operator<<(std::ostream& out_s, const Concordance& l);

	
};
#endif
