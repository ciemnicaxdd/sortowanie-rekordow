#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;


struct players

{

string imie, nazwisko;
int pozycja;

};

class miejsce

{
    vector <struct players> spis;


    ifstream plik1;
    ofstream plik2;

    public:


miejsce();
~miejsce();

void wprowadz();
void sortuj();

};
int compare(const void *a, const void *b)

{

		return ( (*(players*)a).pozycja - (*(players*)b).pozycja );

}

miejsce::miejsce()
{

plik1.open("plik1.txt");
plik2.open("plik2.txt");

}



void miejsce::wprowadz()
{
	struct players in;

	while(!plik1.eof())
    {
    plik1>>in.imie>>in.nazwisko>>in.pozycja;

    spis.push_back(in);
	}

}

void miejsce::sortuj()
{
	qsort(&spis[0], spis.size(), sizeof(players),compare);

    plik2<<"["<<endl;

        for(vector<struct players>::iterator it = spis.begin(); it != spis.end(); ++it)

    {

        plik2<<"{\"pozycja\":\""<<it->pozycja<<"\", \"imie\":\""<<it->imie<<"\", \"nazwisko\":\""<<it->nazwisko<<"\"},"<<endl;

    }
    plik2<<"]";

}

miejsce::~miejsce()
{
plik1.close();
plik2.close();
}


int main(int argc, char** argv)
{
miejsce t1;
t1.wprowadz();
t1.sortuj();


    return 0;
}
