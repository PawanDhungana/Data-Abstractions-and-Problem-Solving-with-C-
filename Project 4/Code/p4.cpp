#define CONCORDANCE_H_
const int MAX = 8;
typedef char Word[MAX + 1];
struct Node
{
Word wd;
int count;
Node *next;
};
class Concordance{
private:
Node *first;
public:
Concordance();
~Concordance();
void insert(const char* word);
int get_count(const char *word);
int length();
Node *get_node(const char *word, int count, Node *link);
void print();
};
#endif
------------------------------------
Corcordance.cpp Code is as follows and this is the class implementation file.
------------------------------------
#include <iostream>
#include <cstring>
#include "Concordance.h"
using namespace std;
Concordance::Concordance(){
first = NULL;
}
Concordance::~Concordance(){
// destructor
}
int Concordance::length(){
Node *temp = first;
int count = 0;
while (temp != NULL){
count++;
temp = temp->next;
}
return count;
}
Node *Concordance::get_node(const char *word, int count, Node *link){
Node *newnode = new Node;
strcpy_s(newnode->wd, word);
newnode->count = count;
newnode->next = link;
return newnode;
}
int Concordance::get_count(const char *word){
Node *temp = first;
int count = 0;
while (temp != NULL){
bool flag = true;
for (int i = 0; i < strlen(word); ++i){
if (tolower(temp->wd[i]) != tolower(word[i])){
flag = false;
break;
}
}
if (flag){
return temp->count;
}
temp = temp->next;
}
return 0;
}
void Concordance::insert(const char *word){
Node *temp = first;
while (temp != NULL){
bool flag = true;
for (int i = 0; i < strlen(word); ++i){
if (tolower(temp->wd[i]) != tolower(word[i])){
flag = false;
break;
}
}
if (flag){
temp->count++;
return;
}
temp = temp->next;
}
first = get_node(word, 1, first);
}
void Concordance::print(){
Node *temp = first;
while (temp != NULL){
cout << temp->wd << "\t" << temp->count << endl;
temp = temp->next;
}
}
------------------------------------
Source.cpp is the main program
------------------------------------
#include "Concordance.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
string getWord(string &line){
string word = "";
for (int i = 0; i < line.size(); ++i){
if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')){
line = line.substr(i);
break;
}
}
for (int i = 0; i < line.size(); ++i){
if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')){
word += (char)toupper(line[i]);
}
else{
line = line.substr(i);
for (int j = 0; j < line.size(); ++j){
if (((line[j] >= 'A' && line[j] <= 'Z') || (line[j] >= 'a' && line[j] <= 'z'))){
line = line.substr(j);
return word;
}
}
line = "";
return word;
}
}
line = "";
return word;
}
int main(){
ifstream infile;
string fileName, line, word;
Concordance c;
cout << "Enter a file name: ";
cin >> fileName;
infile.open(fileName);
if (infile.is_open()){
while (getline(infile, line)){
while (line != ""){
word = getWord(line);
if (word.size() > 8){
word = word.substr(0, 8);
}
if (word.size() != 0)
c.insert(word.c_str());
}
}
c.print();
}
else{
cout << "Can not open file " + fileName << endl;
}
return 0;
}
