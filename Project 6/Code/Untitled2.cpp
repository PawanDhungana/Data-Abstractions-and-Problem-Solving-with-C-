#include <iostream>
#include <fstream>
#include<cctype>
#include<stack>

using namespace std;

int eval(int a, int b, char symbol) {
switch (symbol) {
case '*': return b * a;
case '/': return b / a;
case '+': return b + a;
case '-': return b - a;
default : return 0;
}
}

int postFix(string postfix) {
stack<int> s;
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
int op1 = s.top();
s.pop();
int op2 = s.top();
s.pop();
val = eval(op1, op2, ch);
s.push(val);
}
i++;
}
return val;
}

int main()
{
ifstream file ("file.txt");
string temp;
int count = 0;
while (getline(file, temp)){
cout << "Expression: " << temp << endl;
cout << "Value = " << postFix(temp) << "." << endl << endl;
}
return 0;
}
