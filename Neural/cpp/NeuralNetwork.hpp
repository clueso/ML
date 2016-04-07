#include "TwoDArray.hpp"
#include <iostream>

class NeuralNetwork
{
	private:
		int NoOfLayers;
		int *NoOfNodes;
		TwoDArray *WeightArrays;
		double **LayerOutputs;
	public:
		NeuralNetwork(int Layers);
		NeuralNetwork();
		void SetNoOfLayers(int layers);
		void SetNoOfNodes(int layer, int nodes);
		int GetNoOfLayers();
		int GetNoOfNodes(int layer);
		void BuildNetwork();
		void SaveNetwork();
		void LoadNetwork();
		void PrintNetwork();
		~NeuralNetwork();
};

NeuralNetwork::NeuralNetwork(int Layers)
{
	#ifdef ENTER_EXIT_LOGS
	std::cout << "Entering NeuralNetwork::NeuralNetwork(int NoOfLayers)" << std::endl;
	#endif
	
	NoOfLayers = Layers;
	NoOfNodes = new int[NoOfLayers];
	WeightArrays = new TwoDArray[NoOfLayers-1];
	LayerOutputs = new double*[NoOfLayers];
	
	#ifdef ENTER_EXIT_LOGS
	std::cout << "Leaving NeuralNetwork::NeuralNetwork(int NoOfLayers)" << std::endl;
	#endif
}

NeuralNetwork::NeuralNetwork()
{
	NoOfLayers = 0;
	NoOfNodes = NULL;
	WeightArrays = NULL;
	LayerOutputs = NULL;
}

void NeuralNetwork::SetNoOfLayers(int layers)
{
	NoOfLayers = layers;
	
	if(NoOfNodes == NULL)
		NoOfNodes = new int[NoOfLayers];
	
	if(WeightArrays == NULL)
		WeightArrays = new TwoDArray[NoOfLayers-1];
	
	if(LayerOutputs == NULL)
		LayerOutputs = new double*[NoOfLayers];
}

void NeuralNetwork::SetNoOfNodes(int layer, int nodes)
{
	NoOfNodes[layer] = nodes;
	LayerOutputs[layer] = new double[nodes];	//the () initialises the array to 0?
}

int NeuralNetwork::GetNoOfLayers()
{
	return NoOfLayers;
}

int NeuralNetwork::GetNoOfNodes(int layer)
{
	int i;
	int sum = 0;
	
	if(NoOfNodes != NULL)
	{
		//for(i = 0;i < NoOfLayers;i++)
		//	sum += NoOfNodes[i];
		return NoOfNodes[layer];
	}
	else
		return -1;
}

void NeuralNetwork::BuildNetwork()
{
	int i;
	
	#ifdef ENTER_EXIT_LOGS
	std::cout << "Entering NeuralNetwork::BuildNetwork()" << std::endl;
	#endif
	
	for(i = 0; i < NoOfLayers-1; i++)
	{
		WeightArrays[i].BuildArray(NoOfNodes[i+1],NoOfNodes[i] + 1); //array for weights between layer j and (j+1) has dimensions S(J+1) x (S(J) + 1) 
		WeightArrays[i].PopulateArray(RANDOM);
	}
	
	#ifdef ENTER_EXIT_LOGS
	std::cout << "leaving NeuralNetwork::BuildNetwork()" << std::endl;
	#endif
}

void NeuralNetwork::PrintNetwork()
{
	int i,j,k;
	
	for(i = 0;i < NoOfLayers-1; i++)
	{
		std::cout << "Printing Matrix between Layer " << i << " and Layer " << i+1 << std::endl;
		for(j = 0; j < NoOfNodes[i+1]; j++)
		{
			for(k = 0; k < NoOfNodes[i] + 1; k++)
				std::cout << WeightArrays[i](j,k) << " " ;
			std::cout << std::endl;
		}		
	}
}
void NeuralNetwork::SaveNetwork()
{
	
}

void NeuralNetwork::LoadNetwork()
{
	
}

NeuralNetwork::~NeuralNetwork()
{
	if(NoOfNodes != NULL)
		delete [] NoOfNodes;
	if(WeightArrays != NULL)
		delete [] WeightArrays;
	if(LayerOutputs != NULL)
		delete [] LayerOutputs;	
}

