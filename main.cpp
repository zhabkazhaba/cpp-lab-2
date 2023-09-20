#include <iostream>
#include <cmath>
using namespace std;

long int dfactorial (int n){
	if (n == 0 or n == 1){
		return 1;
	}
	return n * dfactorial(n-2);
}

double calculate_t(float x){
	long double temp1 = 0;
	long double temp2 = 0;
	int k;
	double result;
	for (k = 0; k <= 10; k++){
		temp1 += (pow(x, 2*k + 1)) / (dfactorial(2*k+1));
		temp2 += (pow(x,2*k)) / (dfactorial(2*k));
	}
	result = temp1/temp2;
	return result;
}

int main(){
	double y;
	cout << "Введите y:"; cin >> y;
	double total = (7 * calculate_t(0.25) + 2 * calculate_t(1 + y)) / (6 - calculate_t(pow(y,2) - 1));
	cout << total;
	return 0;
}
