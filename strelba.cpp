#include <iostream>
#include <vector>
#include <math.h>
#include <string>

double shoot(double ksi, std::vector<double> &x, std::vector<double> &y);
double f(double x);

int main(int argc, char* argv[]){
	int i, n = 11, default_value = 0;
	double ksi1, ksi2, h;
	
	try{
		ksi1 = std::stod(argv[1]);
		ksi2 = std::stod(argv[2]);
		h = std::stod(argv[3]);
	}
	catch(...){
		std::cout << "Not able to parse arguments" << std::endl;
	}
	std::vector <double> x(n, default_value);
	std::vector <double> y(n, default_value);
	
	
	double ksi, min_ksi, min_shoot;
	
	min_ksi = ksi1;	
	min_shoot = shoot(min_ksi, x, y);
	
	for(ksi = ksi1; ksi < ksi2; ksi +=h){
		if(fabs(min_shoot) > fabs(shoot(ksi, x, y))){
			min_shoot = shoot(ksi, x, y);
			min_ksi = ksi;
		}
		//std::cout << "ksi = " << ksi << " shoot = " << shoot(ksi) << std::endl;
	}
	std::cout << std::endl;
	
	if(min_shoot > 1){
		std::cout << "plohiye nachalniye usloviya" << std::endl;
		return 0;
	}
	
	shoot(min_ksi, x, y);
	
	std::cout << "ksi = " << min_ksi << " pogreshnost = " << fabs(min_shoot) << std::endl << std::endl;
	
	for(i = 0; i < n; i++){
		std::cout << "x[" << i << "] = " << x[i] << " y[" << i << "] = " << y[i] <<std::endl;
	}
	
	return 0;
}

double shoot(double ksi, std::vector<double> &x_n, std::vector<double> &y_n){
	int n, i, default_value = 0;	
	double h, z_1, y_1;
	
	n = 11;
	h = 1.0/(n - 1);
	std::vector <double> x(n, default_value);
	std::vector <double> y(n, default_value);
	std::vector <double> z(n, default_value);
	
	y[0] = 2;
	z[0] = ksi;
		
	for(i = 0; i < n; i++){
		x[i] = i*h;
	}	
		
	for(i = 0; i < n - 1; i++){
		y_1 = y[i] + 0.5*h*z[i];
		z_1 = z[i] + 0.5*h*(-z[i]*sin(x[i]) - x[i]*x[i]*y[i] - x[i]*x[i]);
		y[i+1] = y[i] + h*z_1;
		z[i+1] = z[i] + h*(-z_1*sin(x[i] + 0.5*h) - (x[i] + 0.5*h)*(x[i] + 0.5*h)*y_1 - (x[i] + 0.5*h)*(x[i] + 0.5*h));
	}
	//printf("%.8lf\n",y[n-1]);
	//std::cout << std::setprecision(5) << y[n - 1] << std::endl; 
	
	for(i = 0; i < n; i++){
		x_n[i] = x[i];
		y_n[i] = y[i];
	}
	
	return y[n-1] - 2.0;
}

double f(double x){
	return exp(-x) + exp(3*x) + 0.2*exp(4*x);
}
