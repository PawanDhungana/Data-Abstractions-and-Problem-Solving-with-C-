#include<iostream>
#include<cstdlib>

using namespace std;
void menu();

class BST
{       
    public:
      	//constructors
        BST() { root = NULL; }
        //BST( const BST& t );
    	//destructor
        ~BST()
        {
          destroy(root);
        }
        //typedef
        typedef int Item ;
		
		//member functions
        bool empty() const { return root == NULL; }
        void make_empty();
		void insert ( const Item entry );
        void remove ( Item target );
		int length();
		bool present ( Item entry );
        void write();
        friend std::ostream& operator <<( std::ostream& out_s, const BST &t );
           
        private:
    	//Data members
    	struct Node
        {
          Item data;
          Node *left;
          Node *right;
        };
        Node *root;

        //recursive functions
        void destroy(Node* &t);
        void r_insert(Node* &t, Item entry);
        void r_remove ( Node* &t, Item target );
        void remove_node ( Node* &t );
        int length(Node* &t);
        void help_print ( std::ostream& out_s, Node *t ) const;
};

int main()
{
    char select;                 
    int entry;
    int x;
    BST b;
    
	//displays the menu.
	 menu();
	                       
	 do
	  {
    	cout <<endl<< "--> ";
    	cin >> select;
    	switch ( select )
    	{
            case 'e':
                b.make_empty();
                break;

            case 'i': cin >> entry ;  
                b.insert(entry);
                break;

            case 'w':    
                cout<<"The list: "<<b;
                break;

            case 'r':
    			cin>>entry;
                b.remove(entry);
                break;

            case 'p':cin>>entry;
                if(b.present(entry)==1)
                    cout<<"The value "<<entry<<" is present in the list.";
                else
                    cout<<"The value "<<entry<<" is NOT present in the list.";
                    break;

            case 'l':
                     x=b.length();
                     cout<<"The list contains "<<x<<" values.";
                    break;

            case 'h': menu();
                break;
    		
			default:  
				;           
    	}
  	  } while ( select != 'q' );
    return 0;
}

void menu()
{
  cout <<endl;
  cout <<"This program responds to commands the user enters to manipulate"<<endl;
  cout<<"an ordered list of integers, which is initially empty."<<endl;
  cout<<"In the following commands, v is any integer."<<endl;

  cout << "e -- Re-initialize the list to be empty."<<endl;
  cout << "i v -- Insert the value v into the list." << endl;
  cout << "r v -- Remove the value v from the list." << endl;
  cout << "l -- Report the length of the list."<<endl;
  cout << "p v -- Is the value v present in the list?"<<endl;
  cout << "w -- Write out the list." << endl;
  cout << "h -- See this menu." << endl;
  cout << "q -- Quit." << endl;
}

void BST::insert(Item entry)
  {
      r_insert(root,entry);
  }

void BST::r_insert(Node* &t, Item entry)
  {
      if(t==NULL)
      {
          t=new Node;
          t->data=entry;
          t->left=NULL;
          t->right=NULL;
      }
      else if(entry<t->data)
        r_insert(t->left,entry);
      else //entry > t->data
        r_insert(t->right,entry);
  }

void BST::remove ( Item target )
  {

    r_remove ( root, target );
  }


void BST::r_remove ( Node* &t, Item target )
  {
    if ( t->data == target )
      remove_node ( t );
    else if ( target < t->data )
      r_remove ( t->left, target );
    else   // target > t->data
      r_remove ( t->right, target );
  }

void BST::remove_node ( Node* &t )
  {
    Node* ptr;
    Node* back;

    if ( t->left == NULL && t->right == NULL )  // removing a leaf
    {
      delete t;
      t = NULL;
    }
    else if ( t->left == NULL )  // removing a node with right child only
    {
      ptr = t;
      t = t->right;
      delete ptr;
    }
    else if ( t->right == NULL )  // removing a node with left child only
    {
      ptr = t;
      t = t->left;
      delete ptr;
    }
    else  //removing a value whose node has two children
    {
      back = t;
      ptr = t->right;
      while ( ptr->left != NULL )
      {
        back = ptr;
        ptr = ptr->left;
      }
      t->data = ptr->data;
      if ( back == t )
        remove_node ( back->right );
      else
        remove_node ( back->left );
    }
  }
  
  bool BST::present(Item target)//to search if the value is in the list
  {
      Node *p;
      p=root;
      while(true)
      {
          if(p==NULL)
                return false;
          if(target<p->data)
            p=p->left;
          else if(target==p->data)
          return true;
          else
            p=p->right;
      }
  }

void BST::make_empty()	//to make the list empty
{
    destroy(root);
    root=NULL;
}
void BST::destroy(Node* &p)
{
    if(p!=NULL)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

int BST::length()//te return the length of the list
 {
     return length(root);
 }
int BST::length(Node* &p)
 {
     if(p==NULL)
            return 0;
     else
        return length(p->left)+1+length(p->right);
 }
 
std::ostream& operator << ( std::ostream& out_s, const BST &t )
  {
    t.help_print ( out_s, t.root );
    return out_s;
  }

void BST::help_print ( std::ostream& out_s, Node *t ) const
  {
    if ( t != NULL )
    {
      help_print ( out_s, t->left );
      out_s << t->data << ' ';
      help_print ( out_s, t->right );
    }
  }

