#include <iostream>
#include <vector>
#include <math.h>
#include <gtest/gtest.h>

#include "progonka.cpp"

int n = 11;
std::vector <double> u(n, 0);


TEST(matrixTests,values)
{
	std::vector<double> testVec = {{2.0}, {2.02657}, {2.05253}, {2.07671}, {2.09741}, {2.11241}, {2.11906}, {2.11437}, {2.09516}, {2.05811}, {2.0}};
	
	for(int i = 0; i < 11; i++){
		ASSERT_LT(abs(u[i] - testVec[i]), 2e-3);
	}
}

int main(int argc, char* argv[]){
	int n;
	try{
		n = std::stod(argv[1]);;
	}
	catch(...){
		std::cout << "Not able to parse arguments" << std::endl;
	}
	
	int i;
	double default_value = 0, h = 1.0/(n - 1);	
	std::vector <double> u_nk(n, default_value);
	
	u_nk = progonka(n, h);
	
	for(i = 0; i < n; i++)std::cout << "u[" << i << "] = " << u_nk[i] << std::endl;
	std::cout << std::endl; 
	
	u = u_nk;
	
	::testing::InitGoogleTest();
	
	return RUN_ALL_TESTS();
}
