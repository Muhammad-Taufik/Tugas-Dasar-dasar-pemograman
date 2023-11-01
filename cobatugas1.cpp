#include <iostream>
using namespace std;
int main ( )
{

 cout << "## Program C++ Papan Tiktaktoe ##" << endl;
  cout << "===================================" << endl;
  cout << endl;
  
int lebar_persegi; 
int tinggi_persegi; 

cout << "lebar persegi: ";
cin >> lebar_persegi;
cout << "tinggi persegi: ";
cin >> tinggi_persegi;

for (int j = 1; j <= tinggi_persegi; j++)
{
	cout<<" _";
}
    cout<<endl;
for (int i = 1; i <= tinggi_persegi; i++)
{ 
    cout << "|";
for (int j = 1; j <= lebar_persegi ; j++)
{

	//cout << "_|";
}
cout << endl;
}
return 0;
}
