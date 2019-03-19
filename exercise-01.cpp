/*
	Nama= Dzikri algiffari
	NPM= 140810180053
	Kelas =A
	Deskripsi= program linked list mahasiswa
*/
#include<iostream>
using namespace std;
struct Elemtlist{
	char nama[20],bidang[30];
	int gaji;
	Elemtlist* next;
};
typedef Elemtlist* pointer;
typedef pointer List;

void createList(List& First){
	First=NULL;
}
void createElmt(pointer& pBaru) {

	pBaru= new Elemtlist; 
	cout<< "Masukkan nama pegawai  : ";
	cin.ignore();
	cin.getline(pBaru->nama, 30); 
	cout<<"Masukan Bidang = ";
	cin.getline(pBaru->bidang, 30);
	cout<<"Masukan Gaji= ";cin>>pBaru->gaji;
	pBaru->next = NULL; 
	
}
void insertFirst(List& First, pointer pBaru){
	
	if (First==NULL){ 
	First=pBaru;
}
	else {
	pBaru->next=First; 
	First=pBaru; 
	}
	
}
void traversal(List First){
	
	pointer pBantu;
	pBantu=First; 
	cout<<"Nama\tBidang\tGaji\n";
	do {
	cout << pBantu->nama<<"\t"; 
	cout<<pBantu->bidang<<"\t";
	cout <<pBantu->gaji<<"\t\n";

	pBantu = pBantu->next; // berpindah ke berikutnya
	cout<<endl;

	}while(pBantu != NULL);
	}
void deleteFirst(List& First,pointer pHapus){
	// I.S List First mungkin kosong
	// F.S. List berkurang satu di depan, yang dihapus
	// dikembalikan
	cout<<"Delete First"<<endl;
	if (First==NULL){ // kosong
	pHapus= NULL;
	cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){ //isi 1 elemen
	pHapus=First;
	First=NULL;
	}
	else { // isi > 1 elemen
	pHapus=First; // 1
	First=First->next; // 2
	pHapus->next=NULL; // 3
	}
  
}
void insertLast(List& First,pointer pBaru){
// I.S List First mungkin kosong dan pBaru sudah terdefinisi
// F.S List bertambah satu elemen di belakang (sesudah last)
	pointer last; //last utk mencatat elemen terakhir
	cout<<"Insert Last"<<endl;
	if (First==NULL){ //kosong
	First=pBaru;
	}
	else { // ada isi
	last=First; // menemukan elemen terakhir
	while (last->next!=NULL){
	last=last->next;
	}last->next=pBaru; // sambungkan
	}
	}

void deleteLast(List& First,pointer pHapus){
// I.S List First mungkin kosong
// F.S. List berkurang satu di belakang, yang dihapus
// dikembalikan
	pointer last,precLast;
	cout<<"Delete Last"<<endl;
	if (First==NULL){ // kosong
	pHapus=NULL;
	cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){ //isi 1 elemen
	pHapus=First;
	First=NULL; // list jadi kosong
	}
	else { // isi > 1 elemen
	last=First; // menemukan elemen terakhir
	precLast=NULL;
	while (last->next!=NULL){
	precLast=last; // preclast mencatat yg akan ditinggalkan Last
	last=last->next; // last berpindah
	}
	pHapus=last;
	precLast->next=NULL;
	}
}


int main()
{
	pointer Baru,hapus;
	int x,n;
	List list;
	createList(list);
	while(x!=4){
	cout<<"Menu "<<endl;
	cout<<"1.insert First"<<endl;
	cout<<"2.Insert Last"<<endl;
	cout<<"3.Delete First"<<endl;
	cout<<"4.Delete Last"<<endl;
	cout<<"5.output data"<<endl;
	cout<<"6.Exit"<<endl;
	cout<<"silahkan pilih = "; cin>>x;
	switch(x){
	case 1:
	cout<<"Masukan banyak pegawai:";
	cin>>n;
	for(int i=0;i<n;i++){
	createElmt(Baru); 
	insertFirst(list,Baru);
}

	traversal(list);	
	break;	
	
	case 2:
	cout<<"Masukan banyak pegawai:";
	cin>>n;
	for(int i=0;i<n;i++){
	createElmt(Baru); 
	insertLast(list,Baru);
	cout<<endl;
}
	traversal(list);			
	break;	
	case 3:
	deleteFirst(list,hapus);	
	break;	
	case 4:
	deleteLast(list,hapus);	
	break;
	case 5:
	traversal(list);	
	default:
		cout<<"Exit\n";
		exit(0);
		break;
	
	}
}

}
