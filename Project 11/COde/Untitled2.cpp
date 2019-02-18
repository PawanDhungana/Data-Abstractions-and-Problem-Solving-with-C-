/* Full Name: Prashul Shrestha
   Section #: 2
   Project #: 9
   April 18, 2017
*/

#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;
/*
      This program is about Big-O which is fundamentally 
	  used in calculating the time taken by different 
	  sorting algorithms to graph their different time taken to sort arrays. 
	  In this project implements and exercises these algorithms and an earlier
	  algorithm whose time is O(n2). 
	  This investigation should confirm our theoretical observations about their behaviors.
	  
	  
	  Here, first the user is prompted to enter the size of the array,
	  then a random seed number to initialize elements into the dynamic array[]. 
	  After the elements have been initialized in the array, we call the first function 
	  Insertion_Sort and then after that we put the sorted array into another array named
	  Insertion Array[]. And, we delete the items in the dynamic array[] and reinitialize elements 
	  into it using the rand() and the step of Insertion_sort continues with Merge Sort and Quick Sort.
	  In this way, we get the returned count value of each algorithm. 
	  And later print the list if user wants to or not and print the count of the three algorithms.
*/



//Function Decleration


int Insertion_Sort(int Array[], int size);
//Pre-Condition: Array and the size must be passed.
//Post-Condition: Return an integer Count.


int Merge_Sort(int Array[], int low, int high);
void Merge(int Array[], int low, int mid, int high);
//Pre-Condition: Array, the low(Zero), and the size must be passed.
//Post-Condition: Return an integer Count.


int Quick_Sort(int Array[], int low, int high);
void Partition(int a[],int low,int high,int pivot,int &x,int &y);
//Pre-Condition: Array, the low (Zero) and the size must be passed.
//Post-Condition: Return an integer Count.


//Function to swap values in an Array
void swap(int& first_value, int& second_value);



//Global Variable Decleration
const int arr_size = 1000;
int Merge_count = 0;
int Quick_count = 0;
 
 
 
int main()
{ 
  //Variable Decleration
  int Insertion_Count = 0;
  int Quick_Count = 0;
  int Merge_Count = 0;
  int size;
  int seed;
  char ch, command;
  
    cout<<"Hello, Today we are going to find the BIG-O for three sorting algorithms."<<endl<<endl;
    
    
  
  
  	
	 do {   cout<<"-----------------------";
	 	  	cout<<"\nPress 'c' to continue and 'q' to Quit-> ";
            cin >> ch;
            cout<<"."<<endl;
            cout<<"."<<endl;
            cout<<"."<<endl;
    
  		  switch(ch)
  		  {
          
  		  case 'c': {
  		  				cout<<"\nEnter the number of values to generate and sort, between 1 and 5000: ";
  		 			    cin >> size;
  		 				cout << "Enter a random number seed: ";
  						cin >> seed;
  		  				srand(seed);
  
  						//decleration of Dynamic Array
  			 			int* Array = new int[size];
  			 			
  			 			
  			 			//Array Decleration for each Sorting algorithm
  			 			int* Insert = new int[size];
  			 			int* Merge = new int[size];
  			 			int* Quick = new int[size];
   
					   //intiliazing random numbers into the array
 					   for(int index = 0; index < size; ++index)
       	    			    {
   	      	    			  Array[index] = rand() % (5000-1) + 5000;
   	      	    			  Insert[index] = Array[index];
	   		    		    }	
	   
	                      		
	     				
	                       cout<<endl;
	                       
	                       
						//callingfunctions to sort the array[] and get the big-o efficiency number   
					    	Insertion_Count = Insertion_Sort(Array, size);
			                 int* Insertion_Array = new int[size];
			                 
			                 	for(int index = 0; index < size; ++index)
       				         	{
       				     	       Insertion_Array[index] = Array[index];
   	      			    	       delete Array;
	   					       }
			               
			                    
	     				
			              cout<<endl;
			              
			              
			              
						//Re-initializing the array to differnt numbers
						for(int index = 0; index < size; ++index)
       					    {
   	      			        	Array[index] = rand() % (5000-1) + 5000;
   	      			        	Merge[index] = Array[index];
	   					    }	
	   					    
	   					      				
	                   
	                   //Calling Merge sort to get the count
      					
						   Merge_Count = Merge_Sort(Array, 0, size);
      					 
      					 //Initialinzing array to store the sorted Array's
      					 
      					 int *Merge_Array = new int[size];
	  					for(int index = 0; index < size; ++index)
       					    { 
       					      Merge_Array[index] = Array[index];
   	      			    	  delete Array;
	   					    }		
	     				
	     				
						 
						 //Re-initializing the array to differnt numbers
						for(int index = 0; index < size; ++index)
       					    {
   	      			    	    Array[index] = rand() % (5000-1) + 5000;
   	      			    	    Quick[index] = Array[index];
   	      			    	 
	   					    }
	   					    
	   					    
	   					    
	   					    
	     				Quick_Count = Quick_Sort(Array, 0, size);
	     				
	     				    int* Quick_Array = new int[size];         //Declearing new array
	     				    
	  					for(int index = 0; index < size; ++index)
       					    { 
       					      Quick_Array[index] = Array[index];
   	      			    	 
	   					    }		
	     				      delete[] Array;
	     				
	     				
						
						
					cout<<"Print the List('y' for Yes and 'n' for No): ";
					cin >> command;
					
					if(command == 'y')
					{ 
					
					  //Printing the Insertion Sort
						cout<< "\n\nInsertion Sort: " << endl<<endl;
						cout<<"Unsorted Array:"<<endl;
						cout<<"{ ";
	   					   
	     					for(int index = 0; index < size; ++index)
       					      { 
       					        cout<<Insert[index]<<", ";
	   					      } 
	   					   cout<<"}"<<endl<<endl;; 
	   					   
	   					   cout<<"Sorted Array:"<<endl;
						cout<<"{ ";
						for(int index = 0; index < size; ++index)
       					    { 
       					      cout<<Insertion_Array[index]<<", ";
	   					    }	
						cout<<"}"<<endl;	   
							
							
							
							
							
					    //Printing Merge Sort Array		   	
	     				   cout<<"\n\n\nMerge Sort: "<<endl<<endl;
	     				   cout<<"Unsorted Array:"<<endl;
	     				   cout<<"{ ";
	   					   
	     					for(int index = 0; index < size; ++index)
       					      { 
       					        cout<<Merge[index]<<", ";
	   					      } 
	   					   cout<<"}"<<endl<<endl; 
	   					   
	   					   
	   					   cout<<"Sorted Array:"<<endl;
	     				   cout<<"{ ";
	     					for(int index = 0; index < size; ++index)
       					     { 
       					      cout<<Merge_Array[index]<<", ";
	   					     }	
	   					    cout<<"}"<<endl<<endl;
	   					    
	   					    
	   					    
	   					    
	   					    
	   					//Printing Quick Sort Array   
	   					   cout<<"\n\n\n Quick Sort:"<<endl<<endl;
						   cout<<"Unsorted Array: "<<endl;
						   
						   cout<<"{ ";
	   					   
	     					for(int index = 0; index < size; ++index)
       					      { 
       					        cout<<Quick[index]<<", ";
	   					      } 
	   					   cout<<"}"<<endl<<endl; 
						   
						   
						   
						   cout<<"Sorted Array:"<<endl;
	   					   cout<<"{ ";
	   					   
	     					for(int index = 0; index < size; ++index)
       					      { 
       					        cout<<Quick_Array[index]<<", ";
	   					      } 
	   					   cout<<"}"<<endl; 
	   					   
	   					   
	   					   
	   					   
	   					   	//emptying the dynamic arrays
     	  
     						  delete[] Insert;
     	 					  delete[] Merge;
     	  					  delete[] Quick;
	   					   
					}
					
				//Printing the Count of each Sorting Algorithms.
				    cout<<"\nInsertion Sort: "<<Insertion_Count<<endl;
					cout<<"\nMerge Sort: "<<Merge_Count<<endl;
					cout<<"\nQuick Sort: "<<Quick_Count<<endl;
							
	     			break;
		    }
	     }
     	}while(ch != 'q' );
     	
     	
        
	return 0;	
}








//Insertion Sorting Algorithm
int Insertion_Sort(int Array[], int size)
{   int index2;
    int count = 0;
	for(int index = 1; index <= size; ++index)
	 {
	 	index2 = index;
	 	while(index2 > 0 && Array[index2] < Array[index2 - 1])   //checking one by one
	 	  {  
	 	     
	 	  	swap(Array[index2], Array[index2 - 1]);
		     ++count;
	 	  	 --index2;
		  }
	 	
	 }
	 
  return count;	 
}











//Merge Sort Recursively
int Merge_Sort(int Array[], int low, int high)
{
	
	int mid;
	++Merge_count;
	if(low < high)
	{    
	   
		mid = (low + high)/2;
		
		Merge_Sort(Array, low, mid);
		
		Merge_Sort(Array, mid + 1, high);
    	
		Merge(Array, low, mid, high);
		 
	}
	return Merge_count;
}



void Merge(int a[], int low, int mid, int high)
{
  
  int* b = new int[arr_size];
  int i1, i2, index;
    for(index = low; index <= high; ++index)
     { 
      ++Merge_count;
      b[index] = a[index];                    //Copying the values
     }
     
     
  i1 = low;
  i2 = mid + 1;
  index = low;
  
  while( i1 <= mid && i2 <= high)                        
  {
  	 ++Merge_count;             
    if(b[i1] < b[i2])                        //checking the values and re-inserting into the original array
	    a[index++] = b[i1++];
	 
    
    else
        a[index++] = b[i1++];
 
}
   while(i1 <= low)
     a[index++] = b[i2++];
        
    
   while(i2 <= high)
      a[index++] = b[i2++];
 
	  
  
  delete[] b;
}










//Quick sort Implementation Recursively
int Quick_Sort(int Array[],int low,int high)
{
	int x, y;
	int pivot;
	++Quick_count;         //adding count
	
    if ( low < high )
    {
    	pivot =Array[low];
    	
      Partition ( Array, low, high, pivot ,x, y );
      Quick_Sort ( Array, low, x );
      Quick_Sort ( Array, y, high );
    }
    return Quick_count;
}


//Partition Implementation
void Partition(int a[],int low,int high,int pivot,int &x,int &y)
{
		
    int lastS1 = low - 1;
    int firstU = low;
    int firstS3 = high + 1;

    while ( firstU < firstS3 )
    {
     ++Quick_count;
      if ( a[firstU] < pivot )        // S1
      {
        ++lastS1;
        swap( a[firstU],a[lastS1] );
        ++firstU;
      }
      
      
      else if ( a[firstU] == pivot )  // S2
        ++firstU;
        
        
      else  // a[firstU] > pivot      // S3
      {
        --firstS3;
        swap ( a[firstU], a[firstS3] );
      }
      
     
    }
    x = lastS1;
    y = firstS3;
	
}





//Swap function to swap values in an array
void swap(int& first_value, int& second_value)
{    int temp;
	 temp = first_value;
     first_value = second_value;
	 second_value = temp;
		     
}


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
