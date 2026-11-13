#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    float persen;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertTail(const string& nama, float persen) {
    Node* baru = new Node{nama, persen, nullptr};
    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void deleteHead() {
    if (head == nullptr) return;
    Node* hapus = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete hapus;
}

void deleteTail() {
    if (head == nullptr) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* bantu = head;
    while (bantu->next != tail) bantu = bantu->next;
    delete tail;
    tail = bantu;
    tail->next = nullptr;
}

void tampilkanTidakLayak() {
    cout << "List Mahasiswa tidak layak ujian:" << endl;
    int no = 1;
    for (Node* p = head; p != nullptr; p = p->next) {
        if (p->persen < 80) {
            cout << no++ << " | " << p->nama << " (" << p->persen << "%)"
                 << " - Tidak layak ujian" << endl;
        }
    }
}

int main() {
    cout << "Pilih menu (1 - 4)" << endl;
    cout << "1. Insert tail" << endl;
    cout << "2. Delete head" << endl;
    cout << "3. Delete tail" << endl;
    cout << "4. Tampilkan Mahasiswa Tidak Layak Ujian" << endl;

    int pilihan;
    bool selesai = false;
    while (!selesai && cin >> pilihan) {
        switch (pilihan) {
            case 1: {
                string nama;
                float persen;
                cout << "Nama : ";
                cin >> ws;
                getline(cin, nama);
                cout << "Persentase (%) : ";
                cin >> persen;
                insertTail(nama, persen);
                break;
            }
            case 2:
                deleteHead();
                break;
            case 3:
                deleteTail();
                break;
            case 4:
                tampilkanTidakLayak();
                selesai = true;
                break;
            default:
                break;
        }
    }

    while (head != nullptr) deleteHead();

    return 0;
}