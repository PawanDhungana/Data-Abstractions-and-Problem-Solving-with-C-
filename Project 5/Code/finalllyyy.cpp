#include <cstdlib>                
#include <iostream>                
#include <cstring>
#include<fstream>
#include<iomanip>

using namespace std;
const int MAX = 8;
void readword(ifstream& in_f, char array[MAX+1]);
void buildlist(ifstream& in_f, char array[MAX+1]);

class Concordance
{
    public:
    // TYPEDEF
      typedef char Word[MAX+1];                   

    // CONSTRUCTOR
      Concordance( ) { first = NULL; } // Inline function
      
    //Destructor
      ~Concordance();

    // MODIFICATION MEMBER FUNCTION
      void insert (Word word, int c );

    // CONSTANT MEMBER FUNCTIONS
      std::size_t length( );
      std::size_t get_count(Word word);

    // FRIEND FUNCTION for the List class:
      friend std::ostream& operator << ( std::ostream& out_s,const Concordance& c );

    private:
    // DATA MEMBERS
	struct Node
    {
    	Word wd;
        int count;
        Node *next;
    };
    Node *first;
    
    // PRIVATE FUNCTION
    Node* get_node (Word word, int count, Node* link );
};


Concordance::Node* Concordance::get_node(Word word, int count, Node* link)
{
	Node* temp;
	temp=new Node;
	strcpy(temp->wd,word);
	temp->next=link;
	temp->count=count+1;
	return temp;
}

Concordance::~Concordance()
{
	Node *temp;
	while(first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}

//retuns how many times the repeats in the list
size_t Concordance::get_count( Word word)
{
	while(strcmp(first->wd,word) != 0)
		first=first->next;
	return first->count;
}

//returns the length of the list
size_t Concordance::length()
{
	int l=0;
	Node *temp;
	for(temp=first; temp != NULL; temp = temp->next)
		l++;
	return l;
}

//to insert the given words into concordance
//also checks if the word is already in the list
//if not increase the count of the word in the concordance
void Concordance::insert(Word word, int c)
{
	Node *temp;
	if(first==NULL || strcmp(first->wd, word) > 0)
		first = get_node(word,c,first);
	
	else
	{
		temp = first;
		while(temp->next != NULL && strcmp(temp->next->wd,word) > 0)
		temp = temp->next;
		temp->next = get_node(word,c,temp->next);
	}
} 

std::ostream& operator << ( std::ostream& out_s,const Concordance& c )
{
	Concordance::Node *temp;
	out_s<<"Word"<<setw(10)<<" "<<"Count"<<endl;
	out_s<<"---------------------"<<endl;
	for(temp=c.first; temp!=NULL && temp->next != NULL; temp=temp->next)
	out_s<<temp->wd<<setw(10)<<" "<<temp->count<<endl;
	if(temp!=NULL)
	out_s<<temp->wd<<setw(10)<<" "<<temp->count<<endl;
	out_s<<"---------------------"<<endl;
	return out_s;
}
//main function
int main(int argc, char *argv[])
{
	Concordance c;
	char file[100];
	ifstream in_f;
	char array[MAX+1];
	cout<<"File name: ";
	cin>>file;
	in_f.open(file);
	buildlist(in_f,array);
	in_f.close();
}

//read the characters in the file to make a word 
void readword(ifstream& in_f, char array[MAX+1])
{
	char ch;
	int i=0;
	/*
	while(isalpha(ch) && !isspace(ch))
	{
		if(i > MAX-1)
		{
			while(!isspace(ch))
			in_f.get(ch);
			break;
		}		
		ch=toupper(ch);//converts lowercase to uppercase
		array[i] = ch;
		i++;
		in_f.get(ch);
	}
	
	for(int j=0; j<i; j++)
		cout<<array[j];
		cout<<endl;
		*/
 } 
 
 void buildlist(ifstream &in_f, char array[MAX+1])
 {
 	Concordance c;
 	int x=0;
 	while(!in_f.eof())
 	{
 		readword(in_f,array);
 		c.insert(array,x);
	}
	cout<<x;
 }
