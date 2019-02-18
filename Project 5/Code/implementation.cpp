#include <iostream>
#include <fstream>
#include<cstdlib>
#include <iomanip>
#include <string.h>
#include "list.h"

using namespace std;

void Concordance::insert(ifstream& in_File)
{   Word fileacc;
     
     
    //Sending each string cHAR Array to the Insert Function
    in_File>>fileacc;
	help_insert(first, fileacc);
	
	while(!in_File.eof())
	{
		help_insert(first, fileacc);
		in_File>>fileacc;
	}
	
} 
	
	
//PRIVATE FUNCTION
void Concordance::help_insert(node *&p, Word& entry ) 
{
	           
	int count = 1;
	
	if (p == NULL)
	{
		p=get_node(entry,p,count);
	}
	
	else if (strcmp(entry, p->wd)<0 || p == NULL )
	  {
		   p =get_node(entry,p,count); 	
	  }
	  
	else if(strcmp(entry, p-> wd) == 0)
	  { node *temp;
	  	p =get_node(entry,p,++count);
	  	temp = p -> next;
	  	p -> next = p -> next -> next;
	  	delete temp;
	  }
	  
	else
	{
		help_insert(p->next,entry);
	}
	
}


int Concordance:: get_count(Word& Target)
{
	int Count;
	for(node* p = first; p != NULL; p = p-> next)
	{
		if( strcmp( Target, p -> wd)== 0)
		{    
		    Count = p -> count;
			return Count;
		}
	}
}

 int Concordance::length()
{  int length = 0;
	for(node* cursor = first; cursor != NULL; cursor = cursor -> next)
    {
	++length;
   }
   return length;
}


  
//FRIEND FUNCTION
ostream& operator << ( ostream& out_s, const Concordance &list )
  {
    Concordance::node *cursor;

    out_s << "Word"<<setw(15)<<"Count"<<endl;
    out_s << "------------------------"<<endl;
    for ( cursor=list.first;
          cursor != NULL && cursor->next != NULL;
          cursor=cursor->next )
          {
              out_s << cursor->wd <<"\t \t"<<cursor->count<<endl;
         }
    if ( cursor != NULL )
    {
      out_s << cursor->wd<<"\t \t"<<cursor->count<<endl;
    }
    out_s << "------------------------"<<endl;
    return out_s;
  }
  



//PRIVATE FUNCTION
Concordance::node* Concordance::get_node(Word& data, node* link,int& count)
{   
	node* temp;
	temp =new node;
	strcpy(temp->wd, data);       //uses strcpy to copy array of characters to the Node.
	temp->count = count;
	temp->next =link;
	return temp;
}
