#include <iostream>
#include <iomanip>
#include <cmath>

const double R = 30.0;

int main(){
	double psi_at_inf(double E, int flag);
	double dE = 5.0e-6;
	double dummy;
	double E;
	double E_eV;
	double E_soln;
	double Y1, Y2;

	Y1 = psi_at_inf(-0.7, 0);

	for(E = -0.7+dE; E < 0.0; E += dE){
		Y2 = psi_at_inf(E, 0);
		if(Y1 * Y2 < 0.0){
			E_soln = fabs(Y1) * dE / (fabs(Y1) + fabs(Y2)) + E - dE;
			E_eV = E_soln * 27.2116;
			std::cout << "#E=" << E_eV << "eV" << std::endl;
			dummy = psi_at_inf(E, 1);
		}
	Y1 = Y2;
	}
}

double psi_at_inf(double E, int flag){
	double V(double r);
	double dr = 0.0050;
	double psi0, psi1, psi2;
	double r;
	double m_eff = 1.0;

	psi0 = psi1 = 1.0;
	if(flag){
		std::cout << "0.000000 " << psi0 << std::endl;
	}
	for(r = dr; r < R; r += dr){
		if(flag){
			std::cout << std::scientific << r << std::resetiosflags(std::ios_base::floatfield) << " " << psi1 << std::endl;
		}
		psi2 = (r * (2.0 * m_eff * dr * dr * (V(r) - E) + 2.0) * psi1 + (-r + dr) * psi0) / (r + dr);
		psi0 = psi1;
		psi1 = psi2;
	}
	return psi2;
}

double V(double r){
	return (-1.0 / r);
}
