#include <iostream>
#include <iomanip>

long int dfactorial (int n){
	if (n == 0 or n == 1){
		return 1;
	}
	return n * dfactorial(n-2);
}

double calculateT(float x){
	double numerator = x;
	double denominator = 1; // k = 0 values. made this so I don`t have to deal with power of 0
	double incr = x*x;
	for (int k = 1; k <= 10; k++){
		denominator += (incr) / (dfactorial(k<<1));
		incr = incr*x;
		numerator += (incr) / (dfactorial((k<<1)+1));
		incr = incr*x;
	}
	return numerator/denominator;
}

int main(){
	double y;
	std::cout << "Введите y:"; std::cin >> y;
	double total = (7 * calculateT(0.25) + 2 * calculateT(1 + y)) / (6 - calculateT(y*y - 1));
	std::cout << std::setprecision(15) << total;
	return 0;
}
