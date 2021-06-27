#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <conio.h>
#include <iostream>
using namespace std;
#define MAX 100

void buat_simpul(int x);
void awal();
void cetak();
void insertkanan();
struct node
{
    int N1, N2;
    int info;
    struct node *LINK1;
};

struct nodeSDL {
    int data;
    nodeSDL *LINK2;
};

class FAJAR {
private:
    nodeSDL *First, *Last, *fa;
public:
    FAJAR();
    int insertkiri(int data);
    void cetak1();
};

node *P, *Q;
typedef struct node simpul;
simpul *p, * first, *last, *q; 
int x;

//Graph DFS
class DFSGraph { 
    int V; 
    list<int> *adjList;
    void DFS_util(int v, bool visited[]); 
public: 
    DFSGraph(int V){
        this->V = V; 
        adjList = new list<int>[V]; 
    }
     
void addEdge(int v, int w) {
    adjList[v].push_back(w);
}
    
void DFS();
}; 

void DFSGraph::DFS_util(int v, bool visited[]) {  
    visited[v] = true; 
    cout << v << " ";  
    list<int>::iterator i; 
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
    if(!visited[*i]) 
    DFS_util(*i, visited); 
} 

void DFSGraph::DFS() { 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
    visited[i] = false; 
    for (int i = 0; i < V; i++) 
    if (visited[i] == false) 
    DFS_util(i, visited); 
}
//HASH TABLE
typedef struct nodeHASH {
    char *fanama;
    char *fanama2;
    struct nodeHASH *NEXT;
}nodeHASH;

#define HASHSIZE 5
static nodeHASH* hashtable[HASHSIZE];

void inithashtable() {
    int r;
    for (r = 0; r < HASHSIZE; r++)
        hashtable[r];
}

unsigned int hashfajar(const char *s) {
    unsigned int h = 0;
    for (;*s; s++)
        h = *s+h*31;
    return h%HASHSIZE;
}

nodeHASH* lookup(const char *n) {
    unsigned int h = hashfajar(n);
    nodeHASH* np = hashtable[h];
    for (;np != NULL; np = np -> NEXT) {
        if (!strcmp(np -> fanama, n))
            return np; }
    return NULL;
}

char* m_strdup(const char *o) {
    int l = strlen(o) + 1;
    char *ns = (char*) malloc(l*sizeof(char));
    strcpy(ns, o);
    if (ns == NULL)
        return NULL;
    else
        return ns;
}

char* get(char* fanama) {
    nodeHASH* n = lookup(fanama);
    if (n == NULL)
        return NULL;
    else
        return n -> fanama2;
}

int install(const char* fanama, const char* fanama2) {
    unsigned int h;
    nodeHASH* np;
    if ((np = lookup(fanama)) == NULL) {
        h = hashfajar(fanama);
        np = (nodeHASH*)malloc(sizeof(nodeHASH));
        if (np == NULL)
            return 0;
        np -> fanama = m_strdup(fanama);
        if (np -> fanama == NULL) return 0;
        np -> NEXT = hashtable[h];
        hashtable[h] = np; }
    else
        free(np -> fanama2);
    np -> fanama2 = m_strdup(fanama2);
    if (np -> fanama2 == NULL) return 0;
    return 1;
}

void displaytable() {
    int r;
    nodeHASH*t;
    for (r = 0; r < HASHSIZE; r++) {
        if (hashtable[r] == NULL)
            cout << "";
        else
            t = hashtable[r];
            cout << "";
            for (;t != NULL; t = t -> NEXT)
            cout << t -> fanama << t -> fanama2;
            cout << "";
            cout << "";
    }
}

void cleanup() {
    nodeHASH *np, *t;
    int r;
    for (r = 0; r < HASHSIZE; r++) {
        if (hashtable[r] != NULL) {
            np = hashtable[r];
            while (np != NULL) {
                t = np -> NEXT;
                free(np -> fanama);
                free(np -> fanama2);
                free(np);
                np = t; 
            }
        }
    }
}

void data() {
    int r;
    const char* fanamas[] = {"NAMA :","TUJUAN :", "PEMBERANGKATAN : "};
    const char* fanama2s[] = {"FAJAR |","BALI |", "JAKARTA |"};
    inithashtable();
    for (r = 0; r < 3; r++)
        install(fanamas[r], fanama2s[r]);
    cout << endl;
}

int main () {
    system ("cls");
    int harga, total, jumlah, i;
    int a[2] = {28, 9};
    first = NULL;
    i = 0;
    x = a[i];
    jumlah = 0;
    harga = 1000000;
    string nama1 = " FAJAR MUKHOLLIS ";
    string nama2 = " SINTA RAHMADANI ";
    string kelas = " Ekonomi ";
    string asal = " Jakarta ";
    string tujuan = " Bali ";
    string pesawat = "Pesawat 2";
    cout << endl;
    P = new node;
    P -> N1 = 1;
    cout << " PENJUALAN TIKET PESAWAT " << endl;
    cout << "-------------------------" << endl;
    cout << " Masukkan Jumlah Penumpang  : " << P -> N1 << endl;
    total = P -> N1 * harga;
    if (jumlah < P -> N1) {
       cout << " Masukkan Nama Penumpang    : " << nama1 << endl;
       cout << " Masukkan Nama Penumpang    : " << nama2 << endl;
    }
    else {
       cout << " Masukkan Nama Penumpang    : " << nama1 << endl;
    }
    cout << "________________________________________________" << endl;
    cout << endl;
    cout << " Jenis Kelas : " << endl;
    cout << "---------------" << endl;
    cout << " 1. First Class " << endl;
    cout << " 2. Ekonomi " << endl;
    cout << " 3. Business " << endl;
    cout << " Masukkan Kelas yang akan anda tempati : " << kelas << endl;
    cout << "________________________________________________" << endl;
    cout << " Pilih Asal Perjalan Anda   : " << asal << endl;
    cout << " Pilih Tujuan Perjalan Anda : " << tujuan << endl;
    buat_simpul(x);
    awal();
    for (i = 1; i <= 1; i++) {
        x = a[i];
        buat_simpul(x);
        insertkanan();
    }
    x = 2020;
    buat_simpul(x);
    insertkanan();
    cout << endl;
    cout << " Masukkan Tanggal Pemberangkatan  : ";
    cetak();
    cout << endl;
    cout << "________________________________________________" << endl;
    cin.get();
    FAJAR Xx;
    cout << " Jenis Pesawat Yang tersedia " << endl; 
    Xx.insertkiri(4);
    Xx.insertkiri(3);
    Xx.insertkiri(2);
    Xx.insertkiri(1);
    Xx.cetak1();
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << " PILIH JENIS PESAWAT YANG AKAN ANDA GUNAKAN : " << pesawat << endl;
    cout << " Anda Memilih : " << pesawat << endl;
    cout << "________________________________________________" << endl;
    cin.get();
    cout << " Jumlah yang harus Dibayar  : Rp " << total << endl;
    cout << endl;
    cout << "________________________________________________" << endl;
    DFSGraph gdfs(5); 
    gdfs.addEdge(0, 1); 
    gdfs.addEdge(0, 2);
    gdfs.addEdge(0, 3);
    gdfs.addEdge(1, 2); 
    gdfs.addEdge(2, 4);
    gdfs.addEdge(3, 3); 
    gdfs.addEdge(4, 4);
    cout << " Mohon Tunggu, Sedang Melakukan Proses Konfirmasi ulang...." << endl; 
    gdfs.DFS();
    cout << endl;
    cout << " Selesai... " << endl;
    int pilihan = 1;
    do {
        cout << " KONFIRMASI ULANG PEMESANAN TIKET " << endl;
        cout << "----------------------------------" << endl;
        cout << " 1. MELANJUTKAN PEMESANAN TIKET PESAWAT " << endl;
        cout << " 2. MEMBATALKAN PEMESANAN TIKET PESAWAT " << endl;
        cout << "|PILIHAN ANDA ? : " << pilihan;
        cout << endl;
        switch(pilihan) {
            case 1:
                cout << endl;
                cout << " TERIMAKASIH ANDA TELAH MELAKUKAN PEMESANAN TIKET PESAWAT " << endl;
                cout << " KAMI AKAN MEMBERIKAN KABAR JIKA KAMI TELAH MENYELESAIKAN PROSES PEMESANAN ANDA " << endl;
                cout << " DAN KAMI AKAN MENGIRIMKAN TIKET MELALUI EMAIL DAN NO.HP YANG TELAH ANDA MASUKAN " << endl;
                cout << " TERIMAKASIH " << endl;
                data();
                cout << endl;
            case 3:
                displaytable(); 
                cout << endl; break;
            case 4:
                cleanup(); 
                cout << endl; break;
            case 2:
                cout << " PEMESANAN TIKET TELAH DIBATALKAN " << endl;
                cout << " TERIMAKASIH " ;
                cout << ""; break;  }
        return 0;
    } while (pilihan != 4);
    return 0;
}

//ADT
void buat_simpul(int x) {
    p = ( simpul *) malloc (sizeof (simpul));
    if (p != NULL) {
        p -> info = x;
    }
    else
    {
        cout << " " << endl;
        cin.get();
        exit(1);
    }
}

void awal() {
    first = p;
    last = p;
    p -> LINK1 = NULL;
}

void insertkanan() {
    last -> LINK1 = p;
    last = p;
    p -> LINK1 = NULL;
}

void cetak() {
    int x;
    q = first;
    while (q != NULL) {
        x = q -> info;
        cout << " " << x;
        q = q -> LINK1;
    }
}
//SDL
FAJAR :: FAJAR() {
    First = NULL;
}

int FAJAR :: insertkiri(int dt) {
    nodeSDL *f;
    f = new nodeSDL;
    f -> LINK2 = First;
    f -> data = dt;
    First = f;
    return(1);
}

void FAJAR :: cetak1() {
    nodeSDL *fa;
    fa = First;
    while(fa != NULL) {
        cout << " Pesawat " << fa -> data << "  " <<endl;
        fa = fa -> LINK2;
    }
}