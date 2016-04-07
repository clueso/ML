#include <iostream>
#include <time.h>

#define RANDOM 1
#define ZEROES 0

class TwoDArray
{
	private:
		double *Array;
		int Rows;
		int Columns;
	public:
		TwoDArray();
		TwoDArray(int rows, int cols);
		double& operator()(int rows, int col);
		double ReturnElement(int row, int col);
		void SetElement(int row, int col, double element);
		void BuildArray(int rows, int cols);
		void PopulateArray(int Values);
		~TwoDArray();
};

TwoDArray::TwoDArray()
{
	Rows = 0;
	Columns = 0;
	Array = NULL;	
}

TwoDArray::TwoDArray(int rows, int cols)
{
	Array = NULL;
	Rows=rows;
	Columns=cols;
	Array = new double[Rows*Columns];	//Error check the memory allocation
}

void TwoDArray::BuildArray(int rows, int cols)
{
	#ifdef ENTER_EXIT_LOGS
	std::cout << "Entering TwoDArray::BuildArray()" << std::endl;
	#endif
	
	Rows = rows;
	Columns = cols;
	Array = new double[Rows*Columns];
	#ifdef ENTER_EXIT_LOGS
	std::cout << "Leaving TwoDArray::BuildArray()" << std::endl;
	#endif
}

double TwoDArray::ReturnElement(int row, int col)
{
	if(Array != NULL)
		return(Array[row*Columns+col]);
	else
		return -1.0;
}

void TwoDArray::SetElement(int row, int col, double element)
{
	if(Array != NULL)
		Array[row*Columns+col] = element;
}

double& TwoDArray::operator()(int row, int col)
{
	return Array[row*Columns+col];
}

void TwoDArray::PopulateArray(int Values)
{
	int i;
	
	srand(time(NULL));
	
	for(i = 0;i < (Rows*Columns); i++)
	{
		if(Values == RANDOM)
		{
			Array[i] = (double)(rand())/RAND_MAX;
		}
		
		if(Values == ZEROES)
			Array[i] = 0;
	}	
}


TwoDArray::~TwoDArray()
{	
	if (Array != NULL)
		delete [] Array;
}