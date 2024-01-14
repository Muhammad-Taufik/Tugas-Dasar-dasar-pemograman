#include<iostream>
using namespace std;

char baris, kolom;
char kotak[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};	
string user1;
string user2;
bool imbang;
int digit;
char user = 'x';

//prosedur pertaman untuk mencetak papan game dengan array 2D
void papan(){

	cout<< " _______________\n";
	cout<< "|    |     |    |\n";
	cout<< "| "<<kotak[0][0]<<"  |  "<<kotak[0][1]<<"  | "<<kotak[0][2]<<"  |\n";
	cout<< "|____|_____|____|\n";
	cout<< "|    |     |    |\n";
	cout<< "| "<<kotak[1][0]<<"  |  "<<kotak[1][1]<<"  | "<<kotak[1][2]<<"  |\n";
	cout<< "|____|_____|____|\n";
	cout<< "|    |     |    |\n";
	cout<< "| "<<kotak[2][0]<<"  |  "<<kotak[2][1]<<"  | "<<kotak[2][2]<<"  |\n";
	cout<< "|____|_____|____|\n";

}

//prosedur ke dua untuk pemilihan kotak setiap langkah pemain 
void kondisi_input_angka(){

    
    if(user=='x')
    {
    	cout<<user1<<" pilih nomor : ";
    	cin>>digit;
	}

if(user=='0')
    {
    	cout<<user2<<" pilih nomor : ";
    	cin>>digit;
	}if(digit==1)
    {
    	baris=0;
    	kolom=0;
	}else if(digit==2)
    {
    	baris=0;
    	kolom=1;
	}else if(digit==3)
    {
    	baris=0;
    	kolom=2;
	}else if(digit==4)
    {
    	baris=1;
    	kolom=0;
	}else if(digit==5)
    {
    	baris=1;
    	kolom=1;
	}else if(digit==6)
    {
    	baris=1;
    	kolom=2;
	}else if(digit==7)
    {
    	baris=2;
    	kolom=0;
	}else if(digit==8)
    {
    	baris=2;
    	kolom=1;
	}else if(digit==9)
    {
    	baris=2;
    	kolom=2;
	}else{
		cout<<"Masukan angka yang ada dikolom"<<endl;
		kondisi_input_angka();
	}
	
	// untuk bergantian memilih
	if(user=='x' && kotak[baris][kolom] !='x' && kotak[baris][kolom] !='0'){
		kotak[baris][kolom]='x';
		user='0';
	}else if(user=='0' && kotak[baris][kolom] !='x' && kotak[baris][kolom] != '0'){
		kotak[baris][kolom] = '0';
		user = 'x';
	}
	else{
		cout << "Kotak telah dipilih. Pilih kotak lain!"<< endl;
		kondisi_input_angka();
	}
}

//prosedur ke tiga menjelaskan kondisi menang atau seri
bool cek_Hasil(){
	
	//kondisi suatu pemain mendapatkan satu baris yang sama
	if(kotak[0][0] == kotak[0][1] && kotak[0][1] == kotak[0][2] || kotak[1][0] == kotak[1][1] && kotak[1][1] == kotak[1][2] || kotak[2][0] == kotak[2][1] && kotak[2][1] == kotak[2][2]){
		imbang = true;
		return true;
	//kondisi suatu pemain mendapatkan satu kolom yang sama
	}else if(kotak[0][0] == kotak[1][0] && kotak[1][0] == kotak[2][0] || kotak[0][1] == kotak[1][1] && kotak[1][1] == kotak[1][2] || kotak[2][0] == kotak[2][1] && kotak[2][1] == kotak[2][2]){
	    imbang = true;
	    return true;
	//kondisi suatu pemain mendapatkan satu baris secara diagonal
    }else if(kotak[0][0] == kotak[1][1] && kotak[1][1] == kotak[2][2] || kotak[0][2] == kotak[1][1] && kotak[1][1] == kotak[1][2]){
	    imbang = true;
	    return true;
	}else{
	//cek kondisi apabila masih terdapat kotak yang masih kosong untuk lanjut bermain
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(kotak[i][j] != 'X' && kotak[i][j] != 'O'){
					return false;				
				}
			}
		}
		imbang = false;
		return true;
	}
}

// untuk menampilkan output dari semua proses masing-masing fungsi
int main(){
	
	cout << "Input User 1 : ";
	getline(cin, user1);
	cout << "Input User 2 : ";
	getline(cin, user2);
	
	cout << user1 << " bermain sebagai 'x' \n" << user2 << " bermain sebagai '0'\n " << endl;
	
	while(!cek_Hasil()){
		papan();
		kondisi_input_angka();
		cek_Hasil();
	}
	
	papan();
	if(user == 'x' && imbang == true){
		cout << "selamat " << user2 << " menang" << endl;
	}else if(user == '0' && imbang == true){
		cout << "selamat " << user1 << " menang" << endl;
	}else{
		cout << " HASIL SERI" << endl;
	}
}
