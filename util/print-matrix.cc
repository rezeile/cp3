#include <iostream>
#include <cstdlib>
#include "cust-types.h"

void populateMatrix(mtx &m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[0].size(); j++) {
			m[i][j] = std::rand() % 10;	
		}
	}

}

void printMatrix(mtx m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[0].size(); j++) {
			if(j == m[0].size() - 1)
				std::cout << m[i][j] << std::endl;
			else 
				std::cout << m[i][j] << " ";
		}
	}
}
