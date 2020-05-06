#include <iostream>
#include <fstream>

using namespace std;

class pliki {
	public:
	ifstream plik1;
	ofstream plik2;
};

class film : public pliki{
	public:

	string tytul, rezyser;
	int rok;
	
		void wczytaj();
		void zapisz();
};

void film::zapisz(){
	plik2<<"{\"tytul\":\""<<tytul<<"\", \"rezyser\":\""<<rezyser<<"\", \"rok\":\""<<rok<<"\"}\n";
}

void film::wczytaj(){
	plik1.open("c:\\a.txt");
	plik2.open("c:\\wy.json");
	plik2<<"["<<endl;
	while(!plik1.eof()){
		plik1>>tytul>>rezyser>>rok;
		zapisz();	
	}
	plik2<<"]";
	plik1.close();
	plik2.close();
}


class film_dokumentalny : public film {
	string opis_wydarzenia;
	public:
		void wczytaj();
		void zapisz();
};

void film_dokumentalny::zapisz(){
	plik2<<"{\"tytul\":\""<<tytul<<"\", \"rezyser\":\""<<rezyser<<"\", \"rok\":\""<<rok<<"\", \"opis_wydarzenia\":\""<<opis_wydarzenia<<"\"},\n";
}

void film_dokumentalny::wczytaj(){
	plik1.open("c:\\a.txt");
	plik2.open("c:\\wy.json");
	plik2<<"["<<endl;
	while(!plik1.eof()){
		plik1>>tytul>>rezyser>>rok>>opis_wydarzenia;
		zapisz();	
	}
	plik2<<"]";
	plik1.close();
	plik2.close();
}




int main(int argc, char** argv) {
	film_dokumentalny f1;
	f1.wczytaj();
	return 0;
}
