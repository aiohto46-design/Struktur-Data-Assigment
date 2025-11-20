#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}

float HitungNilaiAkhir(Mahasiswa M) {
    return 0.2f * M.NilaiTugas + 0.4f * M.NilaiUTS + 0.4f * M.NilaiUAS;
}

void Push(StackMahasiswa &StackMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh\n";
        return;
    }

    Mahasiswa M;
    cin.ignore();
    cout << "Nama: "; getline(cin, M.Nama);
    cout << "NIM: "; getline(cin, M.NIM);
    cout << "Nilai Tugas: "; cin >> M.NilaiTugas;
    cout << "Nilai UTS: "; cin >> M.NilaiUTS;
    cout << "Nilai UAS: "; cin >> M.NilaiUAS;

    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = M;
}

void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong\n";
        return;
    }
    StackMHS.Top--;
}

void Update(StackMahasiswa &StackMHS, int posisi) {
    int index = posisi - 1;
    if (index < 0 || index > StackMHS.Top) {
        cout << "Posisi tidak valid\n";
        return;
    }

    cin.ignore();
    cout << "Nama baru: "; getline(cin, StackMHS.dataMahasiswa[index].Nama);
    cout << "NIM baru: "; getline(cin, StackMHS.dataMahasiswa[index].NIM);
    cout << "Nilai Tugas baru: "; cin >> StackMHS.dataMahasiswa[index].NilaiTugas;
    cout << "Nilai UTS baru: "; cin >> StackMHS.dataMahasiswa[index].NilaiUTS;
    cout << "Nilai UAS baru: "; cin >> StackMHS.dataMahasiswa[index].NilaiUAS;
}

void View(StackMahasiswa StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong\n";
        return;
    }

    cout << "\nDATA STACK:\n";
    for (int i = StackMHS.Top; i >= 0; i--) {
        Mahasiswa M = StackMHS.dataMahasiswa[i];
        float NA = HitungNilaiAkhir(M);

        cout << "Posisi " << (i + 1)
             << " | " << M.Nama
             << " | NIM: " << M.NIM
             << " | Nilai Akhir: " << NA << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    bool found = false;

    for (int i = 0; i <= StackMHS.Top; i++) {
        float NA = HitungNilaiAkhir(StackMHS.dataMahasiswa[i]);
        if (NA >= NilaiAkhirMin && NA <= NilaiAkhirMax) {
            found = true;
            cout << "Posisi " << (i + 1)
                 << " | " << StackMHS.dataMahasiswa[i].Nama
                 << " | Nilai Akhir: " << NA << endl;
        }
    }

    if (!found)
        cout << "Tidak ada data dalam rentang nilai\n";
}

void MaxNilaiAkhir(StackMahasiswa StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong\n";
        return;
    }

    float maxNA = -999;
    int posMax = -1;

    for (int i = 0; i <= StackMHS.Top; i++) {
        float NA = HitungNilaiAkhir(StackMHS.dataMahasiswa[i]);
        if (NA > maxNA) {
            maxNA = NA;
            posMax = i + 1;
        }
    }

    cout << "\nNilai Akhir Tertinggi:\n";
    cout << "Posisi: " << posMax
         << " | Nama: " << StackMHS.dataMahasiswa[posMax - 1].Nama
         << " | Nilai Akhir: " << maxNA << endl;
}
