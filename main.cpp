#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

string file = "List.txt";
string fileRdn = "List.txt"; // "List-rnd.txt";
string fileBak = "List.txt_bak";

vector<string> Liste1(0, "");

void readListe1() { // Ok.
    for(int a = 0; a < Liste1.size(); a++) {
        cout << Liste1[a] << endl;
        }
    }

void mixList1() { // Mix Liste1, via une liste temporaire. // Ok.
    vector<string> tempVector(Liste1.size(), " ");
    tempVector.swap(Liste1);
    for(int a = 0; a < Liste1.size(); a++) {
        int b = rand() % tempVector.size();
        Liste1[a] = tempVector[b];
        tempVector.erase(tempVector.begin() + b);
        }
    }

void initListe(string fileName1 = file) {   // With BAK. // Ok.
    ifstream file(fileName1.c_str(), ios::in);
    ofstream outfile(fileBak.c_str());     // Pas d'append pour le BAK : on remplace !
    if(!file) {
        cerr << "Impossible to read the file: " << fileName1 << endl;
        }
    else if(!outfile) {
        cerr << "Impossible to write the BAK file: " << fileBak << endl;
        }
    else {
        string line;
        while(getline(file, line)) {
            Liste1.push_back(line);
            outfile << line << endl;
            }
        file.close();
        }
    }

void writeListe1(string fileOut = "out.txt") {
    ofstream outfile(fileOut.c_str());     // Pas d'append : on remplace ! On a déjà sauvé avant.
    if(!outfile) {
        cerr << "Impossible to write the file: " << fileOut << endl;
        }
    else {
        string line;
        for(int a = 0; a < Liste1.size(); a++) {
            outfile << Liste1[a] << endl;
            }
        outfile.close();
        }
    }

int main() {
    srand(time(NULL));       // No need for better init.
    initListe();
    // readListe1(); // Tests ok.
    mixList1();
    // cout << " " << endl;
    // readListe1(); // Tests ok.
    writeListe1(fileRdn);
   cout << "Ok." << endl;
    return 0;
    }
