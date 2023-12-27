#include <iostream> 
#include <cmath>
#include <vector> 

std::vector <std::vector <double>> inv_matr(int n, std::vector <std::vector<double>> matr){
	int i, j, m, max_i;
	double max_a, b, del,default_value;
	default_value = 0.0;
	std::vector <std::vector<double>> ematr(n, std::vector<double>(n, default_value));
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j)ematr[i][j] = 1;
			else ematr[i][j] = 0;
		}	
	}

	for(m = 0; m < n - 1; m++){		
		max_a = matr[m][m];
		
		for(i = m + 1; i < n; i++){
			if(fabs(max_a) < fabs(matr[i][m])){max_i = i; max_a = matr[i][m];}
		}
		
		if(max_i != m){
			for(j = 0; j < n; j++){
				b = matr[m][j]; matr[m][j] = matr[max_i][j]; matr[max_i][j] = b;
				b = ematr[m][j]; ematr[m][j] = ematr[max_i][j]; ematr[max_i][j] = b;
			}
		}
		
		for(i = m + 1; i < n; i++){
			del = matr[i][m]/matr[m][m];
			for(j = 0; j < n; j++){
				matr[i][j] -= del*matr[m][j];
				ematr[i][j] -= del*ematr[m][j];
			}
		}
	}
	
	for(i = 0; i < n; i++){
		del = matr[i][i];
		for(j = 0; j < n; j++){
			matr[i][j] /= del;
			ematr[i][j] /= del;
		}
	}
		
	for(m = n - 1; m > 0; m--){
		for(i = 0; i < m; i++){
			del = matr[i][m]/matr[m][m];
			for(j = 0; j < n; j++){
				matr[i][j] -= del*matr[m][j];
				ematr[i][j] -= del*ematr[m][j];
			}
		}
	}
	
	for(i = 0; i < n; i++){
		del = matr[i][i];
		for(j = 0; j < n; j++){
			matr[i][j] /= del;
			ematr[i][j] /= del;
		}
	}

	return ematr;
}
