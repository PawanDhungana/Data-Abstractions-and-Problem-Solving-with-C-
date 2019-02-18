#include <cstdlib>
#include <iostream>
#include <cstring>
#include<fstream>
#include<iomanip>

using namespace std;
const int MAX = 8;
void readword(ifstream& in_f, char (&array)[MAX+1]);
void buildlist(ifstream& in_f, char(&array)[MAX+1]);

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
      void insert (Word& word);

    // CONSTANT MEMBER FUNCTIONS
      std::size_t length( );
      std::size_t get_count(Word& word);

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
    Node* get_node ( const Word& word, int& count, Node* link );
    void insert(Node* p, Word word);
    size_t length(Node *p);
    size_t get_count(Node *p, Word word);
    void write(ofstream &out_s, Concordance c);
};


Concordance::Node* Concordance::get_node(const Word& word, int& count, Node* link)
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

//to insert the given words into concordance
void Concordance::insert(Word& word)
{
	insert(first,word);
}

void Concordance::insert(Node *p, Word word)
{
	if(p==NULL)
	p=get_node(p,word);
	
	else
	insert(p->next,word);
}

//retuns how many times the repeats in the list
size_t Concordance::get_count( Node *p, Word& word)
{
	if(p==NULL)
	return 0;
	else
	{
		strcmp(p->wd,word);
		return get_count(p->count,word);
	}
}

size_t Concordance::get_count(Word& word)
{
	return get_count(first,word);
}

//recusive function
size_t Concordance::length(Node *p)
{
	if(p==NULL)
	return 0;
	else 
	return length(p->next);
}

//returns the length of the list
size_t Concordance::length()
{
	return length(first);
}

std::ostream& operator << ( std::ostream& out_s,const Concordance& c )
{
	c.write(out_s,first);
	return out_s;
}

void Concordance::write(ofstream &out_s, Node*p)
{
	if(p!=NULL)
	{
		out_s<<p->data;
		write(out_s,p->next);
	}
}

//read the characters in the file to make a word
void readword(ifstream& in_f, char (&array)[MAX+1])
{
	char ch;
	int i=0;
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

	for(int j=0; j<2; j++)
		cout<<array[j];
		cout<<endl;
		
 }

 void buildlist(ifstream &in_f, char (&array)[MAX+1])
 {
 	Concordance c;
 	int x=0;
 	while(!in_f.eof())
 	{
 		readword(in_f,array);
 		c.insert(array,x);
	}
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
	cout<<"Word"<<setw(10)<<" "<<"Count"<<endl;
	cout<<"---------------------"<<endl;
	cout<<c;		//write out the words in the concordance
	cout<<"---------------------"<<endl;
	in_f.close();
	return EXIT_SUCCESS;
}


