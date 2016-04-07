//#define ENTER_EXIT_LOGS

#include "NeuralNetwork.hpp"
#include <iostream>

void main()
{
	NeuralNetwork NN(3);
	
	NN.SetNoOfNodes(0,2);
	NN.SetNoOfNodes(1,3);
	NN.SetNoOfNodes(2,1);
	
	std::cout << "Nodes in Layer 1 = " << NN.GetNoOfNodes(0) << std::endl;
	std::cout << "Nodes in Layer 2 = " << NN.GetNoOfNodes(1) << std::endl;
	std::cout << "Nodes in Layer 3 = " << NN.GetNoOfNodes(2) << std::endl;
	
	NN.BuildNetwork();
	NN.PrintNetwork();
}