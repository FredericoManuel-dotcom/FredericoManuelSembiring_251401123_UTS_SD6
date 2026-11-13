#include <iostream>
#include <string>
using namespace std;

char antrian[100];
int depan = 0;
int belakang = 0;

void enqueue(char c) {
    antrian[belakang++] = c;
}

char dequeue() {
    return antrian[depan++];
}

int main() {
    string kata;
    cout << "Masukan: ";
    cin >> kata;

    int n = kata.length();
    if (n > 100) n = 100;

    for (int i = 0; i < n; i++) {
        enqueue(kata[i]);
    }

    string vokal = "aiueoAIUEO";

    cout << "Luaran: ";
    while (depan < belakang) {
        char c = dequeue();
        if (vokal.find(c) == string::npos) {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}