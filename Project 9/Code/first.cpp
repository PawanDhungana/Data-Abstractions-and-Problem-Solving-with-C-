#include<iostream>
#include<cstdlib>
using namespace std;

class bigO
{
	public:
		int insertionCount;
		int mergeCount;
		int quicksortCount;
		
		//Constructor
		bigO()
		{
		mergeCount = 0;
		insertionCount=0;
		quicksortCount=0;
		}
	
		//Modification Member Functions
		//Insertion Sort Function
		void insertionSort(int a[],int size);
		
		//Merge Sort Functions
		void merge_sort(int a[], int low, int high);
		void Merge(int a[], int low, int mid, int high);
		
		//Quick Sort functions
		void quick_sort(int a[], int size);
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
	
	cout<<"Enter number of values to generate and sort, between 1 and 5000: ";
	cin>>size;
	cout<<"\nEnter an integer seed value: ";
	cin>>seed;
	srand(seed);
	
	int a[size];
		
	//initializing random numbers into the array
	for(int index = 0; index<size; ++index)
	{
		a[index]=rand()%(size-0)+size;
	}
	
	Sort.insertionSort(a, size);
	Sort.quick_sort(a,size);
	Sort.merge_sort(a, 0, size);
	
	Sort.writeCount(size);

	return 0;
}

void bigO::insertionSort(int a[],int size)
{
	int j;
	for(int i=0;i<size;++i)
	{
		sortedArray[i]=a[i];
	}
	for(int index=1;index<size;++index)
	{
		j=index;
		while(j>0 && sortedArray[j]<sortedArray[j-1])
		{
			swap(sortedArray[j],sortedArray[j-1]);
			++insertionCount;
			--j;
		}
	}
}

void bigO::merge_sort(int a[], int low, int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		Merge(a,low,mid,high);
	}
	++mergeCount;
}

void bigO::Merge(int a[], int low, int mid, int high)
{
	int b[MAX];
	int i, i1, i2;
	
	for(i=low;i<high;++i)
	{
		++mergeCount;
		//copying the elements of the array
		b[i]=a[i];
	}
	i1=low;
	i2=mid+1;
	i=low;
	while(i1<=mid && i2<=high)
	{
	++mergeCount;
	if(a[i1]<a[i2])
		a[i++]=b[i1++];
	else
		a[i++]=b[i2++];
	}
	while(i1<=mid)
	{
		a[i++] = b[i1++];
	}
	while(i2<=high)
	{
		a[i++] = b[i2++];
	}
}

void bigO::quick_sort(int a[], int size)
{
	for(int i=0;i<size;++i)
		sortedArray[i]=a[i];
	quickSort(sortedArray, 0, size);
}

void bigO::quickSort(int a[], int low, int high)	//recursive function
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

void bigO::partition(int a[], int low, int high, int pivot, int&i, int&j) //patition step in quick sort
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

void bigO::writeCount(int size) //write out the contents in the array
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
	cout<<"\nInsertion Sort Count = "<<insertionCount<<endl;
	cout<<"Merge Sort Count = "<<mergeCount<<endl;
	cout<<"Quick Sort Count = "<<quicksortCount<<endl;
}
