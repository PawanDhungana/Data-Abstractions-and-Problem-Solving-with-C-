#include <cstdlib>                
#include <iostream>                
#include <cassert>

using namespace std;

class List
  {
    public:
    // TYPEDEF
      typedef int Item;                   

    // CONSTRUCTORS
      List( ) { first = NULL; } // Inline function

    // DESTRUCTOR
      ~List( );

    // MODIFICATION MEMBER FUNCTIONS
      void menu();
	  void make_empty ( );
      void insert ( const Item& entry );
      void remove ( const Item& target );

    // CONSTANT MEMBER FUNCTIONS
      bool empty( ) const { return first == NULL; } // Inline function
      std::size_t length( ) const;
      bool present ( const Item& target ) const;
      Item kth ( std::size_t k ) const;

    // FRIEND FUNCTION for the List class:
      friend std::ostream& operator << ( std::ostream& out_s,const List& l );

    private:
    // DATA MEMBERS
      struct Node
      {
        Item data;
        Node *next;
      };
      Node *first;

    // PRIVATE FUNCTION
      Node* get_node ( const Item& entry, Node* link );
  };

int main()
{
	List l;
	l.menu();
	char x;
	do
	{
	cin>>x;
	switch(x)
	{
		case 'e':
			l.make_empty();
			cout<<"The list is now empty"<<endl;
			break;

		case 'i':
			int number;
			cin>>number;
			l.insert(number);
			cout<<number<<" is inserted in the list."<<endl;
			break;

		case 'r':
			int target;
			cin>>target;
			l.remove(target);
			cout<<target<<" is removed from the list."<<endl;
			break;
			
		case 'l':
			cout<<"The list contains "<<l.length()<<" values."<<endl;
			break;
			
		case 'p':
			int search;
			cin>>search;
			if(l.present(search)==true)
			cout<<"The value "<<search<<" is present in the list."<<endl;
			else
			cout<<"The value "<<search<<" is not present in the list."<<endl;
			break;
			
		case 'k':
			int pth;
			cin>>pth;
			if(pth > l.length())
			cout<<"The list does not contain "<<pth<<" values."<<endl;
			
			else
			cout<<"The "<<pth<<"th value of the list is: "<<l.kth(pth)<<endl;
			break;
			
		case 'w':
			cout<<"List: "<<l<<endl;
			break;
			
		case 'h':
			l.menu();
			break;
			
		case 'q':
			cout<<"The program exited.";
			return 0;
	}
	}while(x!='q' || x!='Q');
}


void List::menu()
{
	cout<<"This program responds to commands the user enters to";
	cout<<"manipulate an ordered list of integers, which is initially empty. ";
	cout<<"In the following commands, v is any integer, and p is a position in the list"<<endl;
	cout<<"e -- Re-initialize the list to be empty."<<endl;
    cout<<"i v -- Insert the value v into the list."<<endl;
    cout<<"r v -- Remove the value v from the list."<<endl;
    cout<<"l -- Report the length of the list."<<endl;
    cout<<"p v-- Is the value v present in the list?"<<endl;
    cout<<"k p -- Report the pth value of the list."<<endl;
    cout<<"w -- Write out the list."<<endl;
    cout<<"h -- See this menu."<<endl;
    cout<<"q -- Quit."<<endl;
}

  // Destructor
List::~List( )
  {
    Node* temp;

    while ( first != NULL )
    {
      temp = first;
      first = first -> next;
      delete temp;
    }
  }

  // Modification member functions
void List::make_empty ( )//makes the list empty
  {
    Node* temp;

    while ( first != NULL )
    {
      temp = first;
      first = first -> next;
      delete temp;
    }
  }

void List::insert ( const Item& entry )//insert value in the list
  {
    Node *prev;
	
	//assert makes sure the entered value is not already present in the list
    assert ( ! present(entry) );

    if ( first == NULL || entry < first->data )//to insert in the first node
      first = get_node(entry,first);
    else
    {
      prev = first;
      while ( prev->next != NULL && prev->next->data < entry )
        prev = prev->next;
      prev->next = get_node(entry,prev->next);
    }
  }

void List::remove ( const Item& target )//remove value from the list
  {
    Node *temp;
    Node *prev;

	//assert makes sure that the target value to be removed is present in the list
    assert ( present(target) );

    prev = first;
    if ( prev->data == target )//if the target is the first element of the list
    {
      first = first->next;
      delete prev;
    }
    else
    {
      while ( prev->next != NULL && prev->next->data < target )
        prev = prev->next;
      temp = prev->next;
      prev->next = temp->next;
      delete temp;
    }
  }

// Constant member functions
size_t List::length( ) const
  {
    Node *cursor;
    size_t count;

    count = 0;
    for ( cursor=first; cursor != NULL; cursor=cursor->next )
      ++count;
    return count;
  }

bool List::present ( const Item& target ) const//search if the value entered is present in the list
  {
    Node *cursor;

    for ( cursor=first;
          cursor!=NULL && cursor->data!=target;
          cursor=cursor->next )
      ;   
    return ( cursor != NULL );
  }

  List::Item List::kth ( size_t k ) const
  {
    Node *cursor;
    size_t count;
	assert ( 1 <= k && k <= length() );

    cursor = first;
    for (count=1; count<k; ++count)
      cursor = cursor->next;
    return cursor->data;	
  }

// Friend Function
ostream& operator << ( ostream& out_s, const List& l )
  {
    List::Node *cursor;

    out_s << '<';
    for ( cursor=l.first;
          cursor != NULL && cursor->next != NULL;
          cursor=cursor->next )
      out_s << cursor->data << ", ";
    if ( cursor != NULL )
      out_s << cursor->data;
    out_s << '>';

    return out_s;
  }

// Private function
List::Node* List::get_node ( const Item& entry, Node* link )
  {
    Node *temp;

    temp = new Node;
    temp->data = entry;
    temp->next = link;
    return temp;
  }
