#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Buku;

class Pengarang{
public:
	string nama_pengarang;
	vector <Buku*> buku;

	Pengarang(string nama) : nama_pengarang(nama) {}

	void tambah_buku(Buku* b);

	void daftar_buku();
};

class Penerbit {
private:
	string nama_penerbit;
	vector <Pengarang*> pengarang;

public:
    Penerbit(string nama) : nama_penerbit(nama) {}

    void tambah_pengarang(Pengarang* p) {
        pengarang.push_back(p);
    }

    void daftar_pengarang() {
        cout << "Daftar pengarang pada penerbit \"" << nama_penerbit << "\":\n";
        for (auto p : pengarang) {
            cout << p->nama_pengarang << endl;
        }
    }
};

class Buku {
public:
    string judul_buku;

    Buku(string judul) : judul_buku(judul){}
};

void Pengarang::tambah_buku(Buku* b) {
    buku.push_back(b);
}

void Pengarang::daftar_buku() {
    cout << "Daftar buku yang dikarang \"" << nama_pengarang << "\":\n";
    for (auto b : buku) {
        cout << b->judul_buku << endl;
    }
}


int main() {
    //MEMBUAT OBJEK PENERBIT
    Penerbit gama_press("Gama Press");
    Penerbit intan_pariwara("Intan Pariwara");

    //MEMBUAT OBJEK PENGARANG
    Pengarang giga("Giga");
    Pengarang joko("Joko");
    Pengarang lia("Lia");
    Pengarang asroni("Asroni");

    //MEMBUAT OBJEK BUKU
    Buku fisika("Fisika");
    Buku algoritma("Algoritma");
    Buku basisdata("Basisdata");
    Buku pemprograman("Dasar Pemprograman");
    Buku mtk("Matematika");
    Buku multimedia("Multimedia 1");

    //MENGHUBUNGKAN PENERBIT DENGAN PENGARANG
    gama_press.tambah_pengarang(&joko);
    gama_press.tambah_pengarang(&lia);
    gama_press.tambah_pengarang(&giga);
    intan_pariwara.tambah_pengarang(&asroni);
    intan_pariwara.tambah_pengarang(&giga);

    //MENGHUBUNGKAN PENGARANG DENGAN BUKU
    joko.tambah_buku(&fisika);
    joko.tambah_buku(&algoritma);
    lia.tambah_buku(&basisdata);
    asroni.tambah_buku(&pemprograman);
    giga.tambah_buku(&mtk);
    giga.tambah_buku(&multimedia);

    // Menampilkan daftar pengarang pada penerbit "Gama Press"
    gama_press.daftar_pengarang();
    cout << endl;

    // Menampilkan daftar pengarang pada penerbit "Intan Pariwara"
    intan_pariwara.daftar_pengarang();
    cout << endl;

    // Menampilkan daftar buku yang dikarang joko
    joko.daftar_buku();
    cout << endl;

    //Menampilkan daftar buku yang dikarang Lia
    lia.daftar_buku();
    cout << endl;

    //Menampilkan daftar buku yang dikarang Asroni
    asroni.daftar_buku();
    cout << endl;

    //Menampilkan daftar buku yang dikarang oleh giga
    giga.daftar_buku();
    cout << endl;


    return 0;
}
