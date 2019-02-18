#include<iostream>
#include<cstdlib>

using namespace std;

class Queue
{
	public:
		typedef int Item;
		static const int CAPACITY = 30;
		
		//constructor
		Queue()
		{
			front = 0;
			rear = CAPACITY-1;
			count = 0;
		};
		
		//constant member function
		bool empty() {return count == 0;}
		int size() {return count;}
		
		//Modification member functions
		void enqueue(Item entry);
		Item dequeue();
		
		//friend function
		friend ostream& operator <<(ostream & out_s, Queue q);
		
	private:
		//Data members
		Item data[CAPACITY];
		int front;
		int rear;
		int count;
		
		//private member function
		int next_index(int i)
		{
			return (i+1) % CAPACITY;
		}
};

int main()
{
	int number;
	int ARV_PROB;
	int MAX_TRANS_TIME;
	int DURATION;
	
	//Asking for details from the user
	cout<<"\nEnter these parameters of the simulation: "<<endl;
	cout<<"The number of queue/server pairs: "<<endl;
	cin>>number;
	cout<<"The probability that a customer arrives in one tick (%) : "<<endl;
	cin>>ARV_PROB;
	cout<<"The maximum duration of a transaction in ticks: "<<endl;
	cin>>MAX_TRANS_TIME;
	cout<<"The duration of the simulation in ticks: "<<endl;
	cin>>DURATION;
	
	//An array of Queue
	Queue line[number];
	//An array of transaction
	int trans_time[number];
	//Initialization
	for(int l=0; l<number; ++l)
	{
		trans_time[l] = 0;
	}
	
	int count = 0;
	int entrytime;
	int wait_sum = 0;
	int wait = 0;
	int seed;
	
	int rCustomer = 0;
	int longWait = 0;
	
	cout<<"Enter a random number seed : "<<endl;
	cin>>seed;
	cout<<"\n \n \n";
	srand(seed);
	
	for(int time=0; time<DURATION; ++time)
	{
		int least =0;
		if(rand()%100 < ARV_PROB)
		{
			int start = 1;
			while (start < number)
			{
				//getting the line with the smallest size
				if(line[least].size() > line[start].size())
				{
					least = start;
				}
				++start;
			}
			line[least].enqueue(time);
		}
		for (int i = 0;i<number; ++i)
		{
			if(trans_time[i] == 0)
			//tailor is free
			{
				if(!line[least].empty())
				{
					entrytime = line[least].dequeue();
					wait_sum += time - entrytime;
					wait = time - entrytime;
					if(wait>longWait)
						longWait = wait;
					++count;
					trans_time[i] = rand() % MAX_TRANS_TIME + 1;
				}
			}
			else
			--trans_time[i];
			cout<<endl;
	 	}
			cout<<time<<" ";
			for(int j = 0; j<number; ++j)
			{
				cout<<"\t"<<trans_time[j]<<"\t"<<line[j]<<endl;
			}
		}
	for(int i = 0; i<number; ++i)
	{
		rCustomer = rCustomer + line[i].size();
	}
	cout<<count<<"customers waited an average of "<<wait_sum/count<<"ticks."<<endl;
	cout<<"The longest time a customer waited was "<<longWait<<"ticks."<<endl;
	cout<<rCustomer<<"customers remain in the lines. "<<endl;
	return 0;
}

void Queue::enqueue(Item entry)
{
	rear = next_index(rear);
	data[rear] = entry;
	++count;
}

Queue::Item Queue::dequeue()
{
	Item dequed;
	dequed=data[front];
	front=next_index(front);
	--count;
	return dequed;
}

ostream& operator<<(ostream& out_s, Queue q)
{
	int j = q.front;
	for(int i = 0; i<q.count; ++i)
	{
		out_s<<q.data[j]<<' ';
		j = q.next_index(j); 
	}
	return out_s;
}

