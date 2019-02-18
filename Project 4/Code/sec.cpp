#include <cstdlib>                
#include <iostream>                
#include <cstring>
#include<fstream>

using namespace std;
const int MAX = 8;

class Concordance
{
    public:
    // TYPEDEF
      typedef char Word[MAX+1];                   

    // CONSTRUCTOR
      Concordance( ) { first = NULL; } // Inline function

	//Destructor
	  ~Concordance( );
	  
    // MODIFICATION MEMBER FUNCTION
      void insert ( const Word& word );

    // CONSTANT MEMBER FUNCTIONS
      std::size_t length( ) const;
      std::size_t get_count(const Word& word);

    // FRIEND FUNCTION for the List class:
      friend std::ostream& operator << ( std::ostream& out_s,const Concordance& l );
      void readfile();

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
    Node* get_node ( const Word& word, int count, Node* link );
};

int main()
{
	Concordance c;
	ifstream in_f;
	char file[100];
	char arr[MAX+1];
	cout<<"Enter the filename: ";
	cin.getline(file,100);
	in_f.open(file);
	
	for(int i=0;i<100;++i)
	{
		in_f>>arr[i];
		cout<<arr[i]<<" ";
		in_f.close();
	}
	//c.readfile();
}

Concordance::~Concordance()
{
	Node *temp;
	temp=first;
	while(temp!=NULL)
	{
		temp = temp -> next;
	}
}

void readfile()
{

}


