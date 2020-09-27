
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setfill;
using std::left;
using std::setw;
using std::sort;

struct duomuo {
    string vardas;
    string pav;
    int nd[10];
    int egz;
    float paz = 0;
};


void teisingasIvedimas() {
    // Skirta naudoti kai tikrinima ar ivestas sveikas skaicius
    cin.clear();
    cin.ignore(80, '\n');
    cout << "Iveskite sveikaji skaiciu: ";
}


void ivedamiND(duomuo A[], int i, int m) {
    // Leidzia ivesti namu darbu pazymius rankiniu budu 
    cout << "Iveskite studento namu darbu pazymius: \n";
    for (int j = 0; j < m; j++) {
        while (!(cin >> A[i].nd[j])) {
            teisingasIvedimas();
        }
    }
}


void atsitiktiniaiND(duomuo A[], int i, int m) {
    // Sugeneruoja atsitiktinius namu darbu pazymius 
    for (int j = 0; j < m; j++) {
        A[i].nd[j] = (rand() % 10) + 1;
    }
}


void naudojantMediana(duomuo A[], int i, int m) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu mediana
    if (m == 1) A[i].paz = A[i].nd[0];
    else {
        sort(A[i].nd, A[i].nd + m);
        if (m % 2 != 0) {
            A[i].paz = A[i].nd[m / 2];
        }
        else {
            A[i].paz = (A[i].nd[m / 2] + A[i].nd[m / 2 - 1]) / 2;
        }
    }
    A[i].paz = A[i].paz * 0.4 + A[i].egz * 0.6;
}



void naudojantVidurki(duomuo A[], int i, int m) {
    // Apskaiciuoja galutini pazymi naudojant namu darbu vidurki
    for (int j = 0; j < m; j++) {
        A[i].paz = A[i].paz + A[i].nd[j];
    }
    A[i].paz = A[i].paz * 0.4 / m + A[i].egz * 0.6;
}


void isvedimas(duomuo A[], int n, string tipas = "(Vid.)") {
    // Isveda galutinius pazymius
    cout << setw(15) << left << "Pavarde";
    cout << setw(15) << left << "Vardas";
    cout << "Galutinis " << tipas << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << left << A[i].pav << setw(15) << left << A[i].vardas << std::setprecision(3) << A[i].paz << endl;
    }
}


int main()
{
    duomuo* Stud;
    int n, m;
    cout << "Kiek studentu norite ivesti? ";
    while (!(cin >> n)) {
        teisingasIvedimas();
    }
    cout << "Kiek namu darbu buvo uzduota? ";
    while (!(cin >> m)) {
        teisingasIvedimas();
    }
    Stud = new duomuo[n];
    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento varda ir pavarde: \n";
        cin >> Stud[i].vardas;
        cout << "Iveskite studento pavarde: \n";
        cin >> Stud[i].pav;
        /* Galima arba ivesti pazymius rankiniu budu naudojant ivedamiND()
        arba juos sugeneruoti atsitiktinai naudojant atsitiktiniaiND() */
        if (m != 0) ivedamiND(Stud, i, m);
        cout << "Iveskite studento egzamino pazymi: \n";
        while (!(cin >> Stud[i].egz)) {
            teisingasIvedimas();
        }
        /* Galima apskaiciuoti galutini pazymi naudojant namu darbu vidurki su naudojantVidurki()
        arba naudojant mediana su naudojantMediana() */
        if (m > 0) naudojantMediana(Stud, i, m);
        else Stud[i].paz = Stud[i].egz;
    }
    // Paskutiniam funkcijos argumentui naudoti pasirinkto pazymio skaiciavimo tipo pavadinima
    isvedimas(Stud, n, "(Med.)");
    delete [] Stud;
}
