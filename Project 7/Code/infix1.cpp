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
      Item peek () const;

    private:
      // Data members
      struct Node
      {
        Item data;
        Node *next;
      };
      Node *first;
      int count;
};

int main()
{
    Stack Operand;
    Stack Operator;
    ifstream infile;
    
    int Operand1, Operand2, value;
	char ch, character;

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
    	cout << "Expression: "<<temp<<endl; //print the expression
    	
    	infile.get(ch);  // Read each character one by one
        while (!infile.eof() && ch > ' ' )    // While not a new line
        {   
    	    if(ch<='9' && ch >= '0')        // Single digit integers
            {
            	// Conversion of characters into integers
                Operand.push(ch-'0');        // push the integer into the stack
            }
            
            else if (ch == '(')
            {
                Operator.push(ch);
            }
               
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') // For all operators
            {
            	while( (!Operator.empty()) && (Operator.peek()!='(') && (Precedence(Operator.peek()) >= Precedence(ch)))
                {
                    Operand2 = Operand.pop();        // pop the top Operand
                    Operand1 = Operand.pop();        // pop the top Operand again
                       
                    character = Operator.pop();
                       
                    value = apply(character,Operand1,Operand2);    // Call the function to do appropriate calculation
                    Operand.push(value);    // Result is pushed back again
                }
				Operator.push(ch);
			}
            
			else if (ch == ')')
            {   
                ch= Operator.pop();
                while (ch != '(')
                {
                	Operand2 = Operand.pop();        // pop the top Operand
                    Operand1 = Operand.pop();        // pop the top Operand again
                    value = apply(ch,Operand1,Operand2);    // Call the function to do appropriate calculation
                        
                    Operand.push(value);    // Result is pushed back again
                   
                    ch = Operator.pop();
                }
            }
            infile.get(ch);
            
        }    
            while (!Operator.empty())
            {
                Operand2 = Operand.pop();        // pop the top Operand
                Operand1 = Operand.pop();        // pop the top Operand again
                ch = Operator.pop();
                value = apply(ch,Operand1,Operand2);    // Call the function to do appropriate calculation
                Operand.push(value);    // Result is pushed back again
            }           
            cout << endl;
		cout << " Value = " << Operand.peek() << endl;   // Display the remaining item from stack
	}
	infile.close();    // Close the file	
	return 0;
}

Stack::~Stack( ) //Destructor
{
	Node* temp;
	while ( first != NULL )
	{
	  temp = first;
	  first = first -> next;
	  delete temp;
	}
}
 
void Stack::push (const Item& entry) //pushes the item onto the top of the stack
{ 
	Node* temp;
	temp = new Node;
	temp->data = entry;
	temp->next = first;
	first = temp;
	++count;
}

int Stack::pop() //pops the item from the top of the stack
{ 
	Node* temp= first; 
	Item popped = first->data; 
	first = first->next; 
	delete temp; 
	--count; 
	return popped; 
}

int Stack::peek() const //returns the top value of the stack
{ 
	if (!empty());
		return first->data; 
} 

