#include<iostream>
#include<fstream>
#include<cstdlib>

//function prototypes
using namespace std;
void read_file(ifstream &in_f,int matrix[9][9]);
void print_matrix(int matrix[9] [9], ifstream &in_f);
bool isValid(int matrix[9][9]);

int main()
{
	int matrix[9][9];
	cout<<"Enter the filename you want to open including the extension: "<<endl;
	ifstream in_f;	
	char file[50];//takes input what file user want to open
	cin.getline(file,50);
	in_f.open(file);//opens file
	
	read_file(in_f,matrix);//calls read_file function to read the file
	print_matrix(matrix, in_f);//prints the file
	in_f.close();
	
	
	if (isValid(matrix)==true)
    	cout << "Is a sudoku solution. " << endl;
	else
		cout << "Is not a sudoku solution. " << endl;
	

	in_f.close();

	return 0;
}



void read_file(ifstream &in_f,int matrix[9][9])//reads file
{
	do{
		
	
    for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
		in_f >> matrix[i] [j];
	}while(in_f.good());
}

//Prints out the matrix read from file 
void print_matrix(int matrix[9] [9], ifstream &in_f)
{
	for (int i = 0; i < 9; i++)//for rows
	{
		for (int j = 0; j < 9; j++)//for columns
			cout << matrix[i] [j] << " ";
			
		cout << endl;
	}
	in_f.close();
}

bool isValid(int matrix[9][9])//checks if the matrix is valid sudoku solution
{
	int i, j;
	bool status;
	status = true;
	for(i=0;i<9;i++){
		
	for (int column = 0; column < 9; column++)//checking if there is a duplication in the column
		{
			if (column != j && matrix[i] [column] == matrix[i] [j])
				status = false;
		}
	}
			
	for(j=0;j<9;j++)
		{
	for (int row = 0; row < 9; row++)//checking if there is a duplication in the row
		{
			if (row != i && matrix[row] [j] == matrix[i] [j])
			status = false;
		}
	}
	
			
	for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] = 0)
				status = false;
			}
		}
	
	for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if ((matrix[i][j] < 0) || (matrix[i][j] > 9))
				status = false;
			}
		}
	return status;
}

