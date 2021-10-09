#include <iostream>
#include <iomanip>
#include <string>
//#include <algorithm>

using namespace std;
const int db = 20;

class GalutinisBalas {
private:
	string vardas = "", pavarde = "";
	double nd = 0, egz = 0, galutinis = 0;

	double* n = new double[ndx];
	string v[db], p[db];
	double ndd[db], e[db], g[db];
	int kiekStud = 0, vARm=0, ndx = 1;

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
			cout << "Kiek namu darbu norite ivesti? ";
			cin >> ndx;
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
		cout << "Ka norite taikyti: vidurki ar mediana?" << endl << "Vidurkis = 1; Mediana = 2: ";
		cin >> vARm;
		while (vARm != 1 && vARm != 2) {
				cout << "Tokio pasirinkimo nera! Bandyk dar karta." << endl;
				cin >> vARm;
		}
		
		if (vARm == 1) {
			cout << left << setw(12) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Vid.)" << endl;
			cout << "--------------------------------------------------" << endl;
			for (int q = 0; q < kiekStud; q++)
			{
				vidurkis();
				cout << left << setw(12) << p[q] << left << setw(12) << v[q] << right << setprecision(2) << fixed << g[q] << endl;
			}
		}
		else if (vARm == 2) {
			cout << left << setw(12) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Med.)" << endl;
			cout << "--------------------------------------------------" << endl;
			for (int q = 0; q < kiekStud; q++)
			{
				mediana();
				cout << left << setw(12) << p[q] << left << setw(12) << v[q] << right << setprecision(2) << fixed << g[q] << endl;
			}
		}
	}
	void vidurkis() {
		//0.4 * vidurkis + 0.6 * egzaminas
		for (int q = 0; q < kiekStud; q++) {
			ndd[q] = (ndd[q] / ndx) * 0.4;
			e[q] = e[q] * 0.6;
			g[q] = ndd[q] + e[q];
		}
	}
	double sort(double x, double y) {
		double temp;
		for (int i = 0; i < ndx; i++) {
			for (int j = i + 1; j < ndx; j++) {
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
		//0.4 * mediana + 0.6 * egzaminas
		for (int q = 0; q < kiekStud; q++) {
			sort(n[0], n[ndx-1]);
			if (ndx % 2 == 0) {
				ndd[q] = (n[ndx / 2 - 1] + n[ndx / 2]) / 2;
			}
			else {
				ndd[q] = n[ndx / 2];
			}
			
			ndd[q] = ndd[q] * 0.4;
			e[q] = e[q] * 0.6;
			g[q] = ndd[q] + e[q];
		}
	}

};
int main() {
	//Namu darbai saugomi masyve
	//Rezultatas
	
	//--------------------------------------------------
	//Ka norite taikyti : vidurki ar mediana ?
	//Vidurkis = 1; Mediana = 2: 2
	//Pavarde     Vardas      Galutinis(Med.)
	//--------------------------------------------------
	//Pavardenis  Vardenis    8.40

	GalutinisBalas stud;
	stud.ivesk();
	stud.print();

	//GalutinisBalas y;
	//y = x;
	//GalutinisBalas z = x;

	return 0;
}