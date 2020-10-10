#include "Timer.h"


void pradeti(time_point& start) {
    start = hrClock::now();
}

double praejoLaiko(time_point start) {
    return durationDouble(hrClock::now() - start).count();
}

void visasLaikas(vector<duomuo> A, vector<duomuo> A2, string failoPav) {
    time_point start;
    time_point task_start;
    pradeti(start);
    nuskaitytiFaila(A, failoPav);
    cout << "Nuskaityti faila uztruko: " << praejoLaiko(start) << "s" << endl;
    pradeti(task_start);
    for (int i = 0; i < A.size(); i++) {
        naudojantVidurki(A, i);
        naudojantMediana(A, i);
    }
    cout << "Apskaiciuoti pazymius uztruko: " << praejoLaiko(task_start) << "s" << endl;
    pradeti(task_start);
    A2 = padalinti(A);
    cout << "Padalinti i dvi grupes uztruko: " << praejoLaiko(task_start) << "s" << endl;
    pradeti(task_start);
    isvestiFaila(A, "islaike.txt");
    isvestiFaila(A2, "neislaike.txt");
    cout << "Isvesti i failus uztruko: " << praejoLaiko(task_start) << "s" << endl;
    cout << "Viso uztruko: " << praejoLaiko(start) << "s" << endl << endl;
}