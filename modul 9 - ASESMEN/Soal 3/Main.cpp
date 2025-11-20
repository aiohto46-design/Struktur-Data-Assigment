#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

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

int main() {
    StackMahasiswa S;
    createStack(S);

    S.Top++; S.dataMahasiswa[S.Top] = {"Venti", "11111", 75.7, 82.1, 65.5};
    S.Top++; S.dataMahasiswa[S.Top] = {"Xiao", "22222", 87.4, 88.9, 81.9};
    S.Top++; S.dataMahasiswa[S.Top] = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    S.Top++; S.dataMahasiswa[S.Top] = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    S.Top++; S.dataMahasiswa[S.Top] = {"Lynette", "55555", 77.7, 65.4, 79.9};
    S.Top++; S.dataMahasiswa[S.Top] = {"Chasca", "66666", 99.9, 93.6, 87.3};

    cout << "\nSTACK AWAL\n";
    View(S);

    Pop(S);

    cout << "\nSETELAH POP\n";
    View(S);

    S.dataMahasiswa[2] = {"Heizou", "77777", 99.9, 88.8, 77.7};

    cout << "\nSETELAH UPDATE POSISI 3\n";
    View(S);

    cout << "\nHASIL SEARCH NILAI 85.5 - 95.5\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    MaxNilaiAkhir(S);

    return 0;
}
