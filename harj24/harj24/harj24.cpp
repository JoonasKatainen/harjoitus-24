#include <iostream>
#include <fstream>
using namespace std;
struct TIEDOT
{
	char nimi[20];
	float matka;
	int koko;
};
void TulostaKaikkiHenkilot(TIEDOT tiedot[10], int j);
void LisaaHenkilo(TIEDOT tiedot[10], int *j);
void TulostaHenkilo(TIEDOT tiedot[10]);
int kierros=0;
void PoistaHenkilo(TIEDOT tiedot[10], int j);
void TallennaTiedostot(TIEDOT tiedot[10], int j);
TIEDOT* LueTiedostot(void);
int Valikko(void);
int main()
{
	TIEDOT tiedot[10];
	int valinta;
	int i, j=0;
	for(i=0;i == 0;)
	{
		valinta=Valikko();
		if(valinta == 0)
		{
			cout<<"Lopetetaan"<<endl;
			i++;
		}
		if(valinta == 1)
		{
			LisaaHenkilo(&tiedot[0], &j);
			j++;
		}
		if(valinta == 2)
		{
			TulostaKaikkiHenkilot(&tiedot[0], j);
		}
		if(valinta == 3)
		{
			TulostaHenkilo(&tiedot[0]);
		}
		if(valinta == 4)
		{
			PoistaHenkilo(&tiedot[0], j);
			j--;
		}
		if(valinta == 5)
		{
			TallennaTiedostot(&tiedot[0], j);

		}

		if(valinta == 6)
		{
			for(int k = 0; k<10;k++)
			{
				tiedot[k]=LueTiedostot()[k];
			}
			j=kierros;
		}

		if(valinta>6||valinta<0)
			cout<<"YOU FAIL TO TYPE 0-6"<<endl;
	}
return 0;
}
int Valikko(void)
{
	int valinta;
		cout<<"----------------"<<endl<<"VALIKKO"<<endl<<"0 Lopeta"<<endl<<"1 Lisaa henkilo"<<endl<<"2 Nayta kaikki henkilot"<<endl<<"3 Nayta yksi henkilo"<<endl<<"4 Poista henkilon tiedot"<<endl<<"5 Tallenna tiedot tiedostoon"<<endl<<"6 Hae tiedot tiedostosta"<<endl;
		cin>>valinta;
		return valinta;
}
void TulostaHenkilo(TIEDOT tiedot[10])
{
	int k;
	cout<<"Monesko henkilo? 0-9"<<endl;
	cin>>k;
	cout<<"------------------"<<endl<<tiedot[k].nimi<<endl<<tiedot[k].matka<<endl<<tiedot[k].koko<<endl;
			
	return;
}
void TulostaKaikkiHenkilot(TIEDOT tiedot[10], int j)
{
			for(int k=0; k<j; k++)
			{
				cout<<"------------------"<<endl<<tiedot[k].nimi<<endl<<tiedot[k].matka<<endl<<tiedot[k].koko<<endl;
			}
}
void LisaaHenkilo(TIEDOT tiedot[10], int *j)
{
	TIEDOT t;
			cout<<"Anna nimi, koulumatka ja hatun koko"<<endl;
			cin>>t.nimi>>ws>>t.matka>>ws>>t.koko;
			tiedot[*j] = t;
}
void PoistaHenkilo(TIEDOT tiedot[10], int j)
{
	int k;
	cout<<"Monesko henkilo? 0-9"<<endl;
	cin>>k;
	for( ; k < j ; k++ )
	{
		tiedot[k] = tiedot[k+1];
	}
}
void TallennaTiedostot(TIEDOT tiedot[10], int j)
{
	ofstream kirj;
	kirj.open("tiedot.txt");
	kirj << j <<endl;
	for(int k=0 ; k < j ; k++ )
	{
	kirj<<tiedot[k].nimi<<" ";
	kirj<<tiedot[k].koko<<" ";
	kirj<<tiedot[k].matka<<endl;
	}
	kirj.close();
}
TIEDOT* LueTiedostot()
{
	TIEDOT* pointer = new TIEDOT[10];
	int k=0;
	ifstream kirj;
	kirj.open("tiedot.txt");
	kirj >> kierros>>ws;
	for( ; k<kierros ; k++)
	{
		kirj >> pointer[k].nimi>>ws>>pointer[k].koko>>ws>>pointer[k].matka>>ws;
	}
	kirj.close();
	return pointer;
}
