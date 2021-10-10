#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <stdexcept> 
#include <algorithm>

using namespace std;
using hrClock = chrono::high_resolution_clock;
const int db = 200; //kiek studentu saugoti

class GalutinisBalas {
private:
	string vardas = "", pavarde = "";
	double nd = 0, egz = 0, galutinis = 0;

	vector<string>v2, p2, rez;
	vector<double>n, ndd2, e2, g2;
	string v[db], p[db];
	double ndd[db], e[db], g[db];
	int kiekStud = 0, vARm=0, ndx = 5;
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
	void ivesk() {
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
			cout << "--Namu darbu atsitiktiniai balai--" << endl;
			for (int i = 0; i < ndx; i++) {
				n.push_back(i);
				double x = randomas(1, 10);
				cout << i + 1 << "-ojo namu darbo ivertinimas: " << setprecision(2) << fixed << x << endl;
				n.insert(n.begin()+i, x);
			}
			for (int i = 0; i < ndx; i++) {
				nd = nd + n[i];
			}
			egz = randomas(1, 10);
			cout << "Egzamino ivertinimas: " << setprecision(2) << fixed << egz <<endl;
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
			cout << left << setw(19) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Vid.)" << endl;
			cout << "--------------------------------------------------" << endl;
			vidurkis();
			int a = 0;
			for (int q = 0; q < kiekStud; q++)
			{
				cout << left << setw(19) << rez[a] << left << setw(12) << rez[a+1] << right << setprecision(2) << fixed << stod(rez[a+2]) << endl;
				a += 3;
			}
		}
		else if (vARm == 2) {
			cout << left << setw(19) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Med.)" << endl;
			cout << "--------------------------------------------------" << endl;
			mediana();
			int a = 0;
			for (int q = 0; q < kiekStud; q++)
			{
				
				cout << left << setw(19) << rez[a] << left << setw(12) << rez[a+1] << right << setprecision(2) << fixed << stod(rez[a + 2]) << endl;
				a += 3;
			}
		}
	}
	
	void vidurkis() {
		//0.4 * vidurkis + 0.6 * egzaminas
		int a = 0;
		for (int q = 0; q < kiekStud; q++) {
			ndd2.at(q) = (ndd2.at(q) / ndx) * 0.4;
			e2.at(q) = e2.at(q) * 0.6;
			g2.push_back(ndd2.at(q) + e2.at(q));
			rez.push_back(p2[q]);
			rez.push_back(v2[q]);
			rez.push_back(to_string(g2[q]));
			a+3;
		}
	}
	double sort2(double x, double y) {
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
		int a = 0;
		for (int q = 0; q < kiekStud; q++) {
			sort2(n[0], n[ndx-1]);
			if (ndx % 2 == 0) {
				ndd2.at(q) = (n[ndx / 2 - 1] + n[ndx / 2]) / 2;
			}
			else {
				ndd2.at(q) = n[ndx / 2];
			}
			ndd2.at(q) = (ndd2.at(q) / ndx) * 0.4;
			e2.at(q) = e2.at(q) * 0.6;
			g2.push_back(ndd2.at(q) + e2.at(q));
			rez.push_back(p2[q]);
			rez.push_back(v2[q]);
			rez.push_back(to_string(g2[q]));
			a + 3;
		}
	}
	double randomas(double a, double b) {
		mt19937 mt(static_cast<double>(hrClock::now().time_since_epoch().count()));
		uniform_real_distribution<double> dist(a, b);
		return dist(mt);
	}
	int randomasInt(int a, int b) {
		mt19937 mt(static_cast<int>(hrClock::now().time_since_epoch().count()));
		uniform_int_distribution<int> dist(a, b);
		return dist(mt);
	}
	string randomSurame() {
		string surnames[10] = { "Kazlauskas", "Jankauskas", "Petrauskas", "Vasiliauskas", "Butkus", "Urbonas", "Kavaliauskas", "Pranevicius", "Navickas", "Ramanauskas" };
		return surnames[randomasInt(0, 9)];
	}
	void generateFile(int x, string pav) {

		ofstream NewFile(pav);
		NewFile << left << setw(19) << randomSurame() << left << setw(13) << "Vardas" << left << setw(4) << "ND1" << left << setw(4) << "ND2" << left << setw(4) << "ND3" << left << setw(4) << "ND4" << left << setw(4) << "ND5" << left << setw(4) << "Egzaminas" << endl;
		NewFile << "-------------------------------------------------------" << endl;
		for (int i = 0; i < x; i++)
		{
			NewFile<<left << setw(18) << randomSurame() << left << setw(14) << "Vardenis" << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << endl;
		
		}
		NewFile.close();
	}
	void openFile(string x) {
		vector<string> students;
		string student;
		int vSize = 0;
		ifstream file(x);
		getline(file, student);//Skipping line
		getline(file, student);//Skipping line
		while (file >> student) {
			students.push_back(student);
			vSize++;//eiluciu duomenu
		}
		vSize/=8; //eiluteje 8 stulpeliai
		//
		//for (const auto& i : students) { // atspausdina faila
		//	cout << i << "; ";
		//}
		cout << endl;
		cout <<"Students in txt file: " << vSize << endl;
		kiekStud = vSize;
		n.reserve(ndx*vSize+5);
		file.close();

		ndx = 5; // txt faile 5 ND
		vSize *= 8;
		int a = 0;
		for (int q = 0; q < vSize; q++)
		{
			for (int i = 0; i < ndx; i++) {
				double x = stod(students[q+2+i]);
				n.push_back(i);
				ndd[a] = ndd[a] + x;
			}
			p[a] = students[q];
			p2.push_back(students[q]);
			v[a] = students[q + 1];
			v2.push_back(students[q+1]);
			e[a] = stod(students[q + 7]); //egz to double
			e2.push_back(stod(students[q+7]));
			ndd2.push_back(ndd[a]);
			q += 7;
			a++;
		}
		//sort(p2.begin(), p2.end());		
		//sort(v2.begin(), v2.end());
		//sort(p2.begin(), p2.end());
		//sort(ndd2.begin(), ndd2.end());
		//sort(e2.begin(), e2.end());
	}
};
int main() {
	//Generuojamas txt failas, perskaitomas ir pateikiami rezultatai

	GalutinisBalas stud;
	stud.generateFile(100, "kursiokai.txt");
	stud.openFile("kursiokai.txt");
	try {
		stud.print(); 
	}
	catch (const std::out_of_range& oor) {
		cerr << "Out of Range error: " << oor.what() << '\n';
	}
	return 0;
}