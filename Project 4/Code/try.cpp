#include <iostream>
#include <cstring>
#include<string>
#include <fstream>


using namespace std;

const int MAX = 8;

//Concordance list

class Concordance

{

public:

     typedef char Word[MAX+1];

     struct Node

      {

        Word wd;

        int count;

        Node *next;

      };

     Node *first;

     Concordance();

     void insert(Word);

     int length();

     int get_count(Word);

private:

          Node* getnode(Word s,int c ,struct Node* st);

};


Concordance::Concordance()

{

}

Concordance::Node * Concordance::getnode(Concordance::Word s,int c,Concordance::Node * nextPtr)

{

     Concordance::Node * newNode= new Node;

     newNode->count=c;

     newNode->next=nextPtr;

     strcpy(newNode->wd,s);

     return newNode;

}

//returns the frequncy of a word in the list

int Concordance::get_count(Word str)

{

     Node * newNode,*temp,*prev;

     if(first ==NULL)

              return 0;

     else

     {

          temp=first;

          while(temp!=NULL)

          {

              if(strcmp(temp->wd,str)==0)

                   return temp->count;

              temp=temp->next;

          }

     }

     return 0;

}

//prints the words in the concordance

//and returns the length of the list(number of words in the concordance)

int Concordance::length()

{

     int l=0;

     Node * newNode,*temp,*prev;

     cout<<"word"<<"\t"<<"Count"<<endl;

     cout<<"--------------------"<<endl;

     if(first ==NULL)

              return 0;

     else

     {

          temp=first;

          while(temp!=NULL)

          {

              //print the word

              cout<<temp->wd<<"\t"<<temp->count<<endl;

              temp=temp->next;

              l++;

          }

     cout<<"--------------------"<<endl;

          return l;

     }

}

//inserts the given word into the concordance

//according to lexicographic order, if the word is

//not already in the concordance.

//otherwise, increases the count of the word in the concordance

void Concordance::insert(Word w)

{

     Node * newNode,*temp,*prev;

     //if there are no words in the list

     if(first==NULL)

     {

          first=getnode(w,1,NULL);

     }

     //if the list is not empty

     else

     {

          prev=temp=first;

          //loop until find a suitable position for new word or the word

          //is matched with existing word

          while(strcmp(temp->wd,w)<=0 && temp->next!=NULL)

          {

              prev=temp;

              if(strcmp(temp->wd,w)==0)

              {

                   temp->count=temp->count+1;

                   return;

              }

              temp=temp->next;

          }

          //inserting possibilities

          if( temp==first && strcmp(temp->wd,w)>0 )

          {

              newNode=getnode(w,1,first);

              first=newNode;

          }

          else if( temp==first && strcmp(temp->wd,w)<0 )

          {

              newNode=getnode(w,1,NULL);

              first->next=newNode;

          }

          else

          {

              if(temp->next==NULL)

              {

                   if(strcmp(temp->wd,w)<0 )

                   {

                        newNode=getnode(w,1,NULL);

                        temp->next=newNode;

                   }

                   else

                   {

                        newNode=getnode(w,1,temp);

                        prev->next=newNode;

                   }

              }

              else

              {

                   newNode=getnode(w,1,temp);

                   prev->next=newNode;

              }

          }

     }

}



void read_word();

fstream ifs;

Concordance c;

//main

int main()

{

     ifs.open("input.txt");

     read_word();

     cout<<"The file contains "<<c.length()<<" distinct words."<<endl;

     cout<<"Count of SMALL : "<<c.get_count("SMALL")<<endl;

     system("pause");

     return 0;

}

//reads the file character by character to make a word.

//and inserts the word into list, by calling the insert()

void read_word()

{

     char ch;

     char w[9];

     int i=0;

     while(ifs.get(ch))

     {

          ch=toupper(ch);

          //enter , only if the character is alphabet

          if(ch>=65 && ch<=90)

          {

              //saves only up to 8 characters

              if(i<8)

                   w[i]=ch;

              i++;

          }

          else

          {

              if(i>=8)

                   w[8]='\0';

              else

                   w[i]='\0';

              //insert the word

              if(i!=0)

              c.insert(w);

              //clear the temparary variable w

              w[0]=w[1]=w[2]=w[3]=w[4]=w[5]=w[6]=w[7]=w[8]=' ';

              i=0;

          }

     }

    

     return;

}
