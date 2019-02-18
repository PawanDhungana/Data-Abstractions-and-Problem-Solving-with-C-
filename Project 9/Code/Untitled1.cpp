#include<iostream>
#include<cstdlib>
using namespace std;

class bigO
{
	public:
		int mergeCount;
		int insertionCount;
		int quicksortCount;
		
	//Constructor
	bigO(){
	mergeCount = 0;
	insertionCount=0;
	quicksortCount=0;
	}
	
	//Modification Member Functions
		//Insertion Sort Function
		void insertionSort(int Array[],int size);
		
		//Merge Sort Functions
		void mergeSort(int Array[], int low, int high);
		void Merge(int a[], int low, int mid, int high);
		
		//Quick Sort functions
		void quickSortinsert(int a[], int size);
		void quickSort(int a[], int low, int high);
		void partition(int a[],int low, int high, int pivot, int &i, int &j);
		
		//Prints the content to main
		void writeCount(int size);
		
	private:
		static const int MAX = 5000;
		int sortedArray[MAX];
	
};

int main()
{
	bigO Sort;
	int seed;
	char ch;
	int size;
	
	cout<<"Press any key to continue...|Q to quit|"<<endl;
	cin>>ch;
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
		Sort.insertionSort(list, size);
		Sort.quickSortinsert(list,size);
		Sort.mergeSort(list, 0, size);
		
		Sort.writeCount(size);
	}while (ch != 'q');
	return 0;
}

void bigO::insertionSort(int Array[],int size)
{
	int index2;
	for(int i=0;i<size;++i)
	{
		sortedArray[i]=Array[i];
	}
	for(int index=1;index<size;++index)
	{
		index2=index;
		while(index2>0 && sortedArray[index2]<sortedArray[index2-1])
		{
			swap(sortedArray[index2],sortedArray[index2-1]);
			++insertionCount;
			--index2;
		}
	}
}

void bigO::mergeSort(int Array[], int low, int high)
{
	int mid;
	++mergeCount;
	if(low<high)
	{
		mid = (low+high)/2;
		mergeSort(Array, low, mid);
		Merge(Array,low,mid,high);
	}
}

void bigO::Merge(int a[], int low, int mid, int high)
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

void bigO::quickSortinsert(int a[], int size)
{
	for(int i=0;i<size;++i)
		sortedArray[i]=a[i];
		quickSort(sortedArray, 0, size);
}

void bigO::quickSort(int a[], int low, int high)
{
	int i,j;
	int pivot;
	++quicksortCount;
	if(low<high)
	{
		pivot = a[low];
		partition(a,low,high,pivot,i,j);
		quickSort(a,low,i);
		quickSort(a,j,high);
	}
}

void bigO::partition(int a[], int low, int high, int pivot, int&i, int&j)
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
			swap(a[firstU], a[firstS3]);
		}
		++quicksortCount;
	}
	i=lastS1;
	j=firstS3;
}

void bigO::writeCount(int size)
{
	cout<<endl;
	char ch;
	cout<<"Print the values? "<<endl;
	cin>>ch;
	if(ch=='y')
	{
		for(int index = 0; index<size; ++index)
		{
			cout<<sortedArray[index]<<" \t ";
		}
	}
	cout<<"Merge Sort Count is "<<mergeCount<<endl;
	cout<<"Insertion Sort Count is "<<insertionCount<<endl;
	cout<<"Quick Sort Count is "<<quicksortCount<<endl;
}

