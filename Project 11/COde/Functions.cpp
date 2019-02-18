/* Prashul Shrestha
   Project 2
   Section 2
   31st Jan, 2017 */

/* This is the listing of all the fucntions that are called from main() to 
carry out the command entered by the user*/

#include <iostream>
#include <cstdlib>   //provides size_t
#include <iomanip>   //provides setw()
#include <fstream>   
#include <cassert>   
#include <assert.h>  //provides assert() 

#include "BigO.cpp"
using namespace std;


namespace csci301_Bag

{



void Bag::Insert_item ( const Item& Entry) //Uses Cassert to insert items into the BAG
 { 
  
   
   assert(size() < CAPACITY ); //uses assert to input item
   
   data[Used_box] = Entry;
   ++Used_box;
   
   
 }

void Bag::Remove ( const Item& Search_item ) //Uses cstdlib 
{
	int index = 0;
	
	do
	{
		index++;
		
   	}while( (index < Used_box) && (data[index]!= Search_item));
   	
   	if ( index == Used_box) //If Search_Item in not in the bag
    	{
   		
   		cout<< " Sorry, the Item is not present in the BAG."<<endl;
   	
	   }
   	
   	//Remove the Search_item from the Bag
   	
   	Used_box--;
   	data[index] = data[Used_box];
   	
   	
}


bool Bag::Value_present ( const Item& Target) const

{ 

  bool is_there = false;
  
  for(int i = 0; i< Used_box; ++i)
  {
     if( data[i] == Target)
     {
     	is_there = true;
     	
	 }
      
  }
  return is_there;
}

  
  size_t Bag::Value_Search(const Item& Position) const //return the Kth element of the bag
  {
  	size_t Pos_value = data[Position];
  	return Pos_value;
  	
  }

void Bag::Sort()        //to sort the items in the bag
  { size_t Length;
    Length = Used_box; 
   	for ( int i = 0; i < Used_box; ++i)
   	   { 
   	    if ( data[i]>data[i=1])
   	      {
   	  	    size_t temp;
   	  	      temp = data[i];
   	  	      data[i] = data[i+1];
   	  	      data[i+1] = temp;
	      }
	 	 
	   }
  }


ostream& operator << ( ostream& out_s, const Bag& b ) //gives access to use << command
  // Uses iomanip.
  {
    out_s << "{ ";
    if ( b.Used_box > 1 )
      {
        for (int i=0; i< b.Used_box-1; ++i)
           {
             out_s << setw(1) << b.data[i] << ", "; 
            }
        }
            if ( b.Used_box > 0 )
           {
            out_s << setw(1) << b.data[b.Used_box-1] << ' ';
            out_s << "}";
        }
    return out_s;
  }
  
}
