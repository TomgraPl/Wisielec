//TODO
//Sprawdzanie, czy dana litera była już wcześniej podawana
//Wczytywanie tylko pierwszej litery, a wyrazu tylko w przypadku, gdy ma on długość hasła

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
//#include <locale.h> - biblioteka niezbędna do wprowadzenia języka polskiego
//szubienice
void szubienica(int bledy)
{
	switch(bledy)
	{
	case 0:
		std::cout<<"";
		break;
	case 1:
		std::cout<<"\n\n\n\n========="<<std::endl;
		break;
	case 2:
		std::cout<<"|\n|\n|\n|\n|\n========="<<std::endl;
		break;
	case 3:
		std::cout<<"======\n|\n|\n|\n|\n|\n========="<<std::endl;
		break;
	case 4:
		std::cout<<"=====\n|    |\n|\n|\n|\n|\n========="<<std::endl;
		break;
	case 5:
		std::cout<<"=====\n|   |\n|   O\n|\n|\n|\n========="<<std::endl;
		break;
	case 6:
		std::cout<<"=====\n|   |\n|   O\n|   |\n|   |\n|\n========="<<std::endl;
		break;
	case 7:
		std::cout<<"=====\n|   |\n|   O\n|  \\|\n|   |\n|\n========="<<std::endl;
		break;
	case 8:
		std::cout<<"=====\n|   |\n|   O\n|  \\|/\n|   |\n|\n========="<<std::endl;
		break;
	case 9:
		std::cout<<"=====\n|   |\n|   O\n|  \\|/\n|   |\n|  /\n========="<<std::endl;
		break;
	case 10:
		std::cout<<"=====\n|   |\n|   O\n|  \\|/\n|   |\n|  / \\\n========="<<std::endl;
		break;
	}
}

int main()
{
	//SET(LC_ALL, "Polish") - na wpół gotowa klasa do ustawienia języka polskiego (nie pamiętam dokładnej klasy)
	//zmienne
	std::string litery[28]; //alfabet
	size_t test; //długość hasła
	int bledy=0; //ilość błedów
	int proby=0; //ilość prób
	std::string litera; //wpisywana litera
	std::string wynik; //stan odgadywanego hasła
	size_t gruby; //długość podawanej litery - można wprowadzić od razu cały wyraz
	
	//hasła
	std::string hasla[20];
	hasla[0]="ryba";
	hasla[1]="papier";
	hasla[2]="kleszcz";
	hasla[3]="internet";
	hasla[4]="pomocnik";
	hasla[5]="zeszyt";
	hasla[6]="czytnik";
	hasla[7]="pojemnik";
	hasla[8]="kot";
	hasla[9]="nauczyciel";
	hasla[10]="dzbanek";
	hasla[11]="woda";
	hasla[12]="kaloryfer";
	hasla[13]="piernik";
	hasla[14]="kurtka";
	hasla[15]="donica";
	hasla[16]="biurko";
	hasla[17]="deszcz";
	hasla[18]="dywan";
	hasla[19]="karabin";
	
	//losowanie hasła
	srand(time(NULL));
	int i=rand()%20;
	std::string haslo=hasla[i];
	
	//drukowanie długości hasła
	size_t dlugosc=haslo.size();
	std::cout<<"Haslo do odgadniecia: ";
	for(int a=0; a<dlugosc; a++)
	{
		wynik+="_";
		std::cout<<"_ ";
	}
	std::cout<<std::endl;
	std::cout<<std::endl;
	
	//podawanie litery
	do
	{
		std::cout<<"Podane litery: ";
		for(int j=0; j<proby; j++)
			std::cout<<litery[j]<<", ";
		std::cout<<std::endl;
		std::cout<<"Podaj kolejna litere: ";
		std::cin>>litera;
		litery[proby]=litera;
		gruby=litery[proby].size();
	
	//właściwa część
		test=haslo.find(litery[proby]);
		if(test==std::string::npos)
			bledy++;
		else
		{
			do
			{
				wynik.erase(test, gruby);
				wynik.insert(test, litery[proby]);
				test=haslo.find(litery[proby], test+1);
			}while(test!=std::string::npos);
		}
		proby++;
		std::cout<<"Wynik: "<<wynik<<std::endl;
		std::cout<<"Stan szubienicy: "<<std::endl;
		szubienica(bledy);
		std::cout<<std::endl;
		std::cout<<std::endl;
	}while((bledy<10)&&(wynik!=haslo));
	
	//Ekran końcowy
	if(bledy!=10)
	{
		std::cout<<std::endl;
		std::cout<<std::endl;
		std::cout<<"Gratulacje! Udalo ci sie odgadnac haslo!"<<std::endl;
		std::cout<<"Haslo brzmialo: "<<haslo<<". Udalo ci sie je odgadnac po "<<proby<<" probach."<<std::endl;
		std::cout<<"Stan szubienicy: "<<std::endl;
		szubienica(bledy);
		std::cout<<std::endl;
		std::cout<<std::endl;
		std::cout<<"Dziekujemy za gre."<<std::endl;
	}
	else
	{
		std::cout<<"Przegrales! Dziesieciokrotnie sie pomyliles i zawisnales na szubienicy."<<std::endl;
		szubienica(bledy);
		std::cout<<std::endl;
		std::cout<<"Twoj wynik: "<<wynik<<std::endl;
		std::cout<<"Haslo brzmialo: "<<haslo<<std::endl;
		std::cout<<std::endl;
		std::cout<<std::endl;
		std::cout<<"Dziekujemy za gre."<<std::endl;
	}
	return 1;
}
