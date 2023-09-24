#include <iostream>
#include <cmath>
using namespace std;

long int dfactorial (int n){
	if (n == 0 or n == 1){
		return 1;
	}
	return n * dfactorial(n-2);
}

double calculateT(float x){
	long double numerator = 0;
	long double denominator = 0;
	for (int k = 0; k <= 10; k++){
		numerator += (pow(x, 2*k + 1)) / (dfactorial(2*k+1));
		denominator += (pow(x,2*k)) / (dfactorial(2*k));
	}
	return numerator/denominator;
}

int main(){
	double y;
	cout << "Введите y:"; cin >> y;
	double total = (7 * calculateT(0.25) + 2 * calculateT(1 + y)) / (6 - calculateT(pow(y,2) - 1));
	cout << total;
	return 0;
}
