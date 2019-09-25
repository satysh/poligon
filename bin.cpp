#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using std::vector;
int main(int argc, char const *argv[])
{
	int32_t N_run;
	int32_t i_scattering;
	int32_t i_tel;
	int32_t N_b_f;

	double E;
	double theta;
	double phi;
	double X_core[3] = {};
	double h1int;
	double Particle_type;
	double xmax;
	double hmax;
	double X_telescope[3] = {};
	double X_offset[3] = {};

	double theta_tel;
	double phi_tel;
	double da1;
	double da0;
	double T0;

	vector<int32_t> history;
	vector<double> time;
	vector<double> wl;
	vector<int32_t> Nr;
	vector<int32_t> Nc;
	vector<double> x;
	vector<double> y;

	ifstream fin("taiga291_seb", ios::binary);
	if (!fin.is_open()) {
		cerr << "Input file read error!" << endl;
		return -1;
	}
	else {
		cout << "\n### Input file was read successful! ###\n" << endl;
	}
	for (int j = 0; j < 1; j++) {
		fin.read((char*)&N_run, sizeof(int32_t));
		fin.read((char*)&i_scattering, sizeof(int32_t));
		fin.read((char*)&i_tel, sizeof(int32_t));
		fin.read((char*)&N_b_f, sizeof(int32_t));

		cout << "N_run: " << N_run << endl;
		cout << "i_scattering: " << i_scattering << endl;
		cout << "i_tel: " << i_tel << endl;
		cout << "N_b_f: " << N_b_f << endl;

		fin.read((char*)&E, sizeof(double));
		fin.read((char*)&theta, sizeof(double));
		fin.read((char*)&phi, sizeof(double));
		fin.read((char*)X_core, sizeof(X_core));
		fin.read((char*)&h1int, sizeof(double));
		fin.read((char*)&Particle_type, sizeof(double));
		fin.read((char*)&xmax, sizeof(double));
		fin.read((char*)&hmax, sizeof(double));
		fin.read((char*)X_telescope, sizeof(X_telescope));
		fin.read((char*)X_offset, sizeof(X_offset));

		cout << "E: " << E << endl;
		cout << "theta: " << theta << endl;
		cout << "phi: " << phi << endl;
		for (int i = 0; i < 3; i++)
			cout << "X_core[" << i << "]: " << X_core[i] << " ";
		cout << endl << "h1int: " << h1int << endl;
		cout << "Particle_type: " << Particle_type << endl;
		cout << "xmax: " << xmax << endl;
		cout << "hmax: " << hmax << endl;
		for (int i = 0; i < 3; i++)
			cout << "X_telescope[" << i << "]: " << X_telescope[i] << " ";
		cout << endl;
		for (int i = 0; i < 3; i++)
			cout << "X_offset[" << i << "]: " << X_offset[i] << " ";
		cout << endl;

		fin.read((char*)&theta_tel, sizeof(double));
		fin.read((char*)&phi_tel, sizeof(double));
		fin.read((char*)&da1, sizeof(double));
		fin.read((char*)&da0, sizeof(double));
		fin.read((char*)&T0, sizeof(double));

		cout << "theta_tel: " << theta_tel << endl;
		cout << "phi_tel: " << phi_tel << endl;
		cout << "da1: " << da1 << endl;
		cout << "da0: " << da0 << endl;
		cout << "T0: " << T0 << endl;


	}
	return 0;
}
