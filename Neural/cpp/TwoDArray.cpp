#include <iostream>
#include "TwoDArray.hpp"

void main()
{
	TwoDArray t(2,2);
	
	t(0,0) = 1.0;
	t(0,1) = 2.5;
	t(1,0) = 3.0;
	t(1,1) = 4.3;
	
	std::cout << "Element at row=0, col=0 is " << t(0,0) << std::endl;
	std::cout << "Element at row=0, col=1 is " << t(0,1) << std::endl;
	std::cout << "Element at row=1, col=0 is " << t(1,0) << std::endl;
	std::cout << "Element at row=1, col=1 is " << t(1,1) << std::endl;
}