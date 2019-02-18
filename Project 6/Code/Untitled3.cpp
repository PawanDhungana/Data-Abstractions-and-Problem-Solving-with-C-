#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<cctype>
#include<stack>

using namespace std;

int apply(char optr, int opnd1, int opnd2)
//precondition: optr is binary arithmetic operator.
//postcondition: opnd1 and opnd2 are the operands evaluated by the optr and the result is returned
{
	if(optr == '+')
		return (opnd1+opnd2);
	else if (optr == '-')
		return (opnd1-opnd2);
	else if (optr == '*')
		return (opnd1*opnd2);
	else if(optr == '/')
		return(opnd1/opnd2);
}

class Stack
{
	public:
		typedef int Item;
		static const Item CAPACITY = 100;
		Stack(){used = 0;}//constructor
		
		//modification member functions
		void push(Item entry);
		Item pop();
		
		//constant member functions
		bool empty()const{return used == 0;}
		int size()const{return used;}
		int postFix(string postfix, Stack s);
	private:
		Item data[CAPACITY];
		int used;
};

int main()
{
	Stack s;
	ifstream infile;
	
	string temp;
	int pop1, pop2;
	int final;
	char ch;
		
	string filename;
	
	cout<<"Enter input file name : ";
	cin>>filename;
	infile.open(filename.c_str());
	
	if(!infile)
	{
		cout<<"Invalid! File not found."<<endl;
	}

	
	while (getline(infile, temp))
	{
		cout << "Expression: " << temp << endl;
		cout << "Value = " << s.postFix(temp,s) << "." << endl << endl;
	}
	
	infile.close();
	return 0;
}

int Stack::postFix(string postfix,Stack s) 
{
	int i = 0;
	char ch;
	int val;
	while (i < postfix.length()) {
	ch = postfix[i];
	if(ch != ' ')
	if (isdigit(ch)) {
	s.push(ch-'0');
	}
	else {
	int op1 = s.pop();
	int op2 = s.pop();
	val = apply(ch, op2, op1);
	s.push(val);
	}
	i++;
	}
	return val;
}

void Stack::push(Item entry)
{
	data[used] = entry;
	++used;

}

Stack::Item Stack::pop()
{
	return data[--used];
}

