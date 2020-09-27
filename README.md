# OOP-Uzduotis-1 v0.1

### Naudojimosi instrukcija

Pateiktos dvi programos versijos:
- main.cpp naudoja masyvus,
- main_vector.cpp naudoja std::vector konteinerį,

Norint įvesti studentų namų darbų pažymius rankiniu būdu, po studento vardo ir pavardės įvedimo naudoti **ivedamiND()** funkciją. Pvz:
```c++
  cout << "Iveskite studento varda ir pavarde: \n";
  cin >> Stud[i].vardas;
  cout << "Iveskite studento pavarde: \n";
  in >> Stud[i].pav;
  if (m != 0) ivedamiND(Stud, i, m);
```

Norint sugeneruoti studentų namų darbų pažymius, šią funkciją pakeisti į **atsitiktiniaiND()**. Pvz:
```c++
  cout << "Iveskite studento varda ir pavarde: \n";
  cin >> Stud[i].vardas;
  cout << "Iveskite studento pavarde: \n";
  in >> Stud[i].pav;
  if (m != 0) atsitiktiniaiiND(Stud, i, m);
```

Apskaičiuojamas galutinis pažymis priklauso nuo to kokia funkcija jam apskaičiuoti naudojama (**naudojantMediana()** ar **naudojantVidurki()**).
Vėliau funkcijai **isvedimas()** kaip argumentą perduodame kokį būdą apskaičiuoti rezultatą naudojome. Pvz:

```c+++
isvedimas(Stud, n, "(Med.)");
```
