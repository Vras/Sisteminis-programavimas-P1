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
const int db = 102; //kiek studentu saugoti
struct GalutinisBalas
{
    vector<string> rez;
    int kiekStud = 0, ndx = 5;
    double sum = 0;//for time
    double add = 1;//for time

public:
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
    void laikas() {
        auto begin = hrClock::now();
        int iterations = 1000 * 1000 * 1000;
        for (int i = 0; i < iterations; i++) {
            sum += add;
            add /= 2.0;
        }
        auto end = hrClock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        //printf("Result: %.20f\n", sum);
        printf("Generate files - Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    }
    void generateFiles(int kiek, int x, string pav) {
        laikas();
        for (int i = 0; i < kiek; i++)
        {
            ofstream NewFile(pav + to_string(i+1) + ".txt");
            NewFile << left << setw(19) << "Pavarde" << left << setw(13) << "Vardas" << left << setw(4) << "ND1" << left << setw(4) << "ND2" << left << setw(4) << "ND3" << left << setw(4) << "ND4" << left << setw(4) << "ND5" << left << setw(4) << "Egzaminas" << endl;
            NewFile << "-------------------------------------------------------" << endl;
            for (int i = 0; i < x; i++)
            {
                NewFile << left << setw(18) << randomSurame() << i + 1 << left << setw(14) << "Vardenis" << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << left << setw(4) << randomasInt(1, 10) << endl;
            }
            NewFile.close();
            x *= 10;
        }
        
    }
    void openFile(string x) {
        string v[db], p[db];
        double ndd[db], e[db], g[db];
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
        //eiluteje 8 stulpeliai
        cout << endl;
        cout << "Students in file: " << vSize/8 << endl;
        kiekStud = vSize / 8;
        
        double nd = 0;
        int a = 0;
        for (int q = 0; q < vSize; q++) {
 
            rez.push_back(students[q]);
            rez.push_back(students[q+1]);
            //galutinis
            for (int w = 2; w < ndx+2; w++) {
                nd= nd + stod(students[q + w]);
            }
            nd /= ndx;//nd vidurkis
            //0.4 * vidurkis + 0.6 * egzaminas
            nd = (nd * 0.4) + 0.6 * stod(students[q + 7]);
            rez.push_back(to_string(nd));
            nd = 0;
            q += 7;
        }
        
    }
    void print() {

            cout << left << setw(19) << "Pavarde" << left << setw(12) << "Vardas" << right << setw(10) << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------" << endl;
            int a = 0;
            for (int q = 0; q < kiekStud; q++)
            {
                cout << left << setw(19) << rez[a] << left << setw(12) << rez[a + 1] << right << setprecision(2) << fixed << stod(rez[a + 2]) << endl;
                a += 3;
            }
    }

};

//bool sortByvardas(const GalutinisBalas& lhs, const GalutinisBalas& rhs) { return lhs.vardas < rhs.vardas; }




int main()
{
    GalutinisBalas stud;

    stud.generateFiles(1, 14, "kursiokai");//kiekvienas sarasas dideja 10x

    stud.openFile("kursiokai1.txt");

    stud.print();



    return 0;
}