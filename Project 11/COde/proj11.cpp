#include<iostream>
#include<cstdlib>
using namespace std;
class sorting
{
	public:
		int mergeCount;
		int insertionCount;
		int quicksortCount;
		int heapsortCount;
		
	//Constructor
	sorting(){
	mergeCount = 0;
	insertionCount=0;
	quicksortCount=0;
	heapsortCount=0;
	}
	//Modification Member Functions
		//Insertion sort Function
		void insertionsort(int Array[],int size);
		
		//Merge sort Functions
		void mergesort(int Array[], int low, int high);
		void Merge(int a[], int low, int mid, int high);
		
		//Quick sort functions
void quicksortinsert(int a[], int size);
		void quicksort(int a[], int low, int high);
		void partition(int a[],int low, int high, int pivot, int &i, int &j);
		//Prints
		void print(int size);	
		
		void Heapify(int a[], int i, int n);
		void heapSort(int a[], int n);
		void maxHeap(int a[], int n);
	private:
		static const int MAX = 5000;
		int sortedArray[MAX];	
};
int main()
{
	sorting sort;
	int seed;
	char ch;
	int size;
	
	do
	{
		cout<<"Enter number of values to generate and sort, between 1 and 5000: "<<endl;
		cin>>size;
		cout<<"Enter an integer seed value: ";
		cin>>seed;
		srand(seed);
		int list[size];	
		//initializing random numbers into the array
		for(int index = 0; index<size; ++index)
		{
			list[index]=rand()%(size-0)+size;
		}
		sort.insertionsort(list, size);
		sort.quicksortinsert(list,size);
		sort.mergesort(list, 0, size);
		sort.heapSort(list,size);
		sort.maxHeap(list,size);
		
		sort.print(size);
	}while (ch != 'q');
	return 0;
}
void sorting::insertionsort(int Array[],int size)
{
	int i2;
	for(int i=0;i<size;++i)
	{
		sortedArray[i]=Array[i];
	}
	for(int index=1;index<size;++index)
	{
		i2=index;
		while(i2>0 && sortedArray[i2]<sortedArray[i2-1])
		{
			swap(sortedArray[i2],sortedArray[i2-1]);
			++insertionCount;
			--i2;
		}
}
}
void sorting::mergesort(int Array[], int low, int high)
{
	int mid;
	++mergeCount;
	if(low<high)
	{
		mid = (low+high)/2;
		mergesort(Array, low, mid);
		Merge(Array,low,mid,high);
	}
}
void sorting::Merge(int a[], int low, int mid, int high)
{
	int b[MAX];
	int i1, i2, index;
	
	for(index=low;index<high;++index)
	{
		++mergeCount;
		//copying the elements
		b[index]=a[index];
	}
	i1=low;
	i2=mid+1;
	index=low;
	while(i1<=mid && i2<=high)
	{
	++mergeCount;
	if(a[i1]<a[i2])
		a[index++]=b[i1++];
	else
		a[index++]=b[i2++];
	}
	while(i1<=mid)
	{
		a[index++] = b[i1++];
	}
	while(i2<=high)
	{
		a[index++] = b[i2++];
	}
}

void sorting::quicksortinsert(int a[], int size)
{
	for(int i=0;i<size;++i)
		sortedArray[i]=a[i];
		quicksort(sortedArray, 0, size);
}
void sorting::quicksort(int a[], int low, int high)
{
	int i,j;
	int pivot;
	++quicksortCount;
	if(low<high)
	{
		pivot = a[low];
		partition(a,low,high,pivot,i,j);
		quicksort(a,low,i);
		quicksort(a,j,high);
	}
}
void sorting::partition(int a[], int low, int high, int pivot, int&i, int&j)
{
	int lastS1 = low-1;
	int firstU = low;
	int firstS3 = high+1;
	
	while(firstU<firstS3)
	{
		if(a[firstU]<pivot)
		{
			++lastS1;
			swap(a[firstU],a[lastS1]);
			++firstU;
		}
		else if(a[firstU]==pivot)
		++firstU;
		else
		{
			--firstS3;
			(a[firstU], a[firstS3]);
		}
		++quicksortCount;
	}
	i=lastS1;
	j=firstS3;
}

void sorting::Heapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
		
		++heapsortCount;
	}
	a[j/2] = temp;
	return;
}

void sorting::heapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		Heapify(a, 1, i - 1);
	}
}
void sorting::maxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
	{
		Heapify(a, i, n);
	}
		
}

void sorting::print(int size)
{
	cout<<endl;
	char ch;
	cout<<"Print the values? "<<endl;
	cin>>ch;
	if(ch=='k')
	{
		for(int index = 0; index<size; ++index)
		{
			cout<<sortedArray[index]<<" \t ";
		}
	}
	cout<<"Insertion sort Count is "<<insertionCount<<endl;
	cout<<"Merge sort Count is "<<mergeCount<<endl;
	cout<<"Quick sort Count is "<<quicksortCount<<endl;
	cout<<"Heap sort Count is "<<heapsortCount<<endl;
}
