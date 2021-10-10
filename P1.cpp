#include <iostream>
#include <iomanip>
#include <string>
//#include <algorithm>

using namespace std;
const int ndx = 5;
const int db = 20;


class GalutinisBalas {
private:
	string vardas = "", pavarde = "";
	double nd = 0, egz = 0, galutinis = 0;

	double* n = new double[ndx];
	string v[db], p[db];
	double ndd[db], e[db], g[db];
	int kiekStud = 0;
public:
	GalutinisBalas() {}
	GalutinisBalas(string v, string p, double n, double e) {
		vardas = v;
		pavarde = p;
		nd = n;
		egz = e;
	}
	GalutinisBalas& operator= (GalutinisBalas& obj) {
		vardas = obj.vardas;
		pavarde = obj.pavarde;
		nd = obj.nd;
		egz = obj.egz;
		cout << "---Assignment operator---" << endl;
		return *this;
	}
	GalutinisBalas(GalutinisBalas& copy) {
		vardas = copy.vardas;
		pavarde = copy.pavarde;
		nd = copy.nd;
		egz = copy.egz;
		cout << "---Copy constructor---" << endl;
	}
	~GalutinisBalas() {}
	//void setVardas(string v) { vardas=v; }
	//void setPavarde(string p) { pavarde=p; }
	//void setNd(double n) { nd=n; }
	//void setEgz(double e) { egz=e; }
	//string getVardas() { return vardas; }
	//string getPavarde() { return pavarde; }
	//double getNd() { return nd; }
	//double getEgz() { return egz; }

	void ivesk() {

		//GalutinisBalas* stud = new GalutinisBalas[db];

		cout << "Keliu studentu duomenis norite ivesti? ";
		cin >> kiekStud;

		for (int q = 0; q < kiekStud; q++)
		{
			cout << "---Ivesk duomenis---" << endl;
			cout << "Vardas: " << endl;
			cin >> vardas;
			cout << "Pavarde: " << endl;
			cin >> pavarde;
			for (int i = 0; i < ndx; i++) {
				cout << i + 1 << "-jo namu darbo ivertinimas: " << endl;
				cin >> n[i];
			}
			for (int i = 0; i < ndx; i++) {
				nd = nd + n[i];
			}
			cout << "Egzamino ivertinimas: " << endl;
			cin >> egz;
			cout << "--------------------------------------------------" << endl;
			v[q] = vardas;
			p[q] = pavarde;
			ndd[q] = nd;
			e[q] = egz;
		}
	}
	void print() {
		cout << left << setw(12) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Vid.)" << endl;
		cout << "--------------------------------------------------" << endl;
		for (int q = 0; q < kiekStud; q++)
		{
			vidurkis();
			cout << left << setw(12) << p[q] << left << setw(12) << v[q] << right << setprecision(2) << fixed << g[q] << endl;
		}
	}
	void vidurkis() {
		//0.4 * vidurkis + 0.6 * egzaminas
		for (int q = 0; q < kiekStud; q++) {
			ndd[q] = (ndd[q] / ndx) * 0.4;
			e[q] = e[q] * 0.6;
			galutinis = ndd[q] + e[q];
			g[q] = galutinis;
		}
	}
	/*double sort(double x, double y) {
		int size = sizeof n;
		double temp;
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (n[j] < n[i]) {
					temp = n[i];
					n[i] = n[j];
					n[j] = temp;
				}
			}
		}
		return 0;
	}
	void mediana() {
		int size = sizeof n;
		if (size == 0) {
			nd = 0;
		}
		else {
			sort(n[0], n[size]);
			if (size % 2 == 0) {
				nd = (n[size / 2 - 1] + n[size / 2]) / 2;
			}
			else {
				nd = n[size / 2];
			}
		}
		nd = nd * 0.4;
		egz = egz * 0.6;
		galutinis = nd + egz;
	}*/

};
int main() {
	//nepavyko padaryti, kaip norejau
	//Rezultatas:
	
	//--------------------------------------------------
	//Pavarde     Vardas      Galutinis(Vid.)
	//--------------------------------------------------
	//Pavardenis1 Vardenis1   7.52
	//Pavardenis2 Vardenis2   3.35

	GalutinisBalas stud;
	stud.ivesk();
	stud.print();


	//GalutinisBalas y;
	//y = x;
	//GalutinisBalas z = x;

	return 0;
}