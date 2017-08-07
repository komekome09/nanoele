#include <iostream>
#include <iomanip>
#include <cmath>

const double hbar = 1.05459e-34;
const double m = 9.109534e-31;
const double e_0 = 1.602189e-19;

int main(){
	double dE = 1e-3 * e_0;
	double dx = 1e-10;
	double E;
	double psi0, psi1, psi2;
	double x;

	std::cout << "#E, psi(infty)" << std::endl;
	for(E = 0; E < e_0; E += dE){
		psi0 = 0;
		psi1 = 1;
		for(x = dx; x < 100e-10; x += dx){
			psi2 = (2*m*(dx/hbar)*(dx/hbar)*(e_0*(x/100e-10)*(x/100e-10)-E)+2)*psi1-psi0;
			psi0 = psi1;
			psi1 = psi2;
		}
		std::cout << E/(1e-3*e_0) << " " << psi2 << std::endl;
	}
	return 0;
}
