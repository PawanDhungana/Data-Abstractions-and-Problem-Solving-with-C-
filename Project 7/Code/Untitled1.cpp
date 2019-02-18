#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<cctype>
#include<stack>

using namespace std;

int apply(char optr, int opnd1, int opnd2)
//precondition: char optr is binary arithmetic operator.
//postcondition: opnd1 and opnd2 are evaluated by the optr and
//				 the result is returned.
{
	if(optr == '+')				//if operator is +, it adds them.
		return (opnd1+opnd2);
	else if(optr == '-')		//if operator is -, it substracts them.
		return (opnd1-opnd2);
	else if(optr == '*')		//if operator is *, it multiplies them.
		return (opnd1*opnd2);
	else if(optr == '/')		//if operator is /, it divides them.
		return (opnd1/opnd2);
}

int Precedence(char optr)
//postcondition: The level of the operator precedence level number is returned.
{
    int level;
    if (optr == '*' || optr == '/')
        level = 6; // Operator precedence level number in C++
    else if (optr == '+' || optr == '-')
        level = 5;
       
return level;   
}

class Stack
  {
    public:
    	typedef int Item;
      // Constructor
      Stack() { first = NULL; count = 0; }             // Inline

      // Destructor
      ~Stack();

		//modification member functions
      void push ( const Item& entry );
      Item pop ();

		//constant member functions
      size_t size () const { return count; }     // Inline
      bool empty () const { return first == NULL; }  // Inline
	  void make_empty();
     // Item peek () const;
     int inFix(string infix, Stack optr, Stack opnd);

    private:
      // Data members
      struct Node
      {
        Item data;
        Node *next;
      };
      Node *first;
      size_t count;
	  
	  Node* get_node(Item entry, Node* link);
};

int main()
{
    Stack Operand;
    Stack Operator;
    ifstream infile;

	string temp;
	string filename;
	
    cout << "Enter the input file name : ";
    cin >> filename;
    infile.open(filename.c_str());   // Opens the file

    if (!infile)             // If file fails to open, program terminates
    {
       cout << "Could not find input file"<<endl;
    }	
	
    while(getline(infile,temp))     // While file is not empty
    {
		cout << "Expression: "<<temp<<endl;
		cout<<"Value : "<<Operand.inFix(temp,Operand,Operator)<<"."<<endl;
	}
	infile.close();    // Close the file	
	return 0;
}

int Stack::inFix(string infix, Stack optr, Stack opnd)// to calculate infix expressions
{
	
}

Stack::~Stack( )
{
	Node* temp;
	while ( first != NULL )
	{
	  temp = first;
	  first = first -> next;
	  delete temp;
	}
}

void Stack::make_empty( )
{
	Node* temp;
	while ( first != NULL )
	{
	  temp = first;
	  first = first -> next;
	  delete temp;
	}
}
 
void Stack::push (const Item& entry) 
{ 
	first = get_node(entry, first);
	++count;
}

int Stack::pop() 
{ 
	Node* temp; 
	Item popped; 
	if (first!=NULL)
	{
		popped = first->data; 
		temp = first; 
		first = first->next; 
		delete temp; 
		--count; 
	return popped; 
	}
}
 
/*int Stack::peek() const
{ 
	if (!empty());
		return first->data; 
} 
*/

Stack::Node* Stack::get_node(Item entry, Node* link)
{
	Node* temp;
	temp = new Node;
	temp->data = entry;
	temp->next = link;
	return temp;
}

