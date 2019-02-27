/*

Arbori binari "insestrati"  ( informatii atasate nodurilor )
[I] Metode de reprezentare

    I.a) Prin "legatura la tata"
    I.b) Prin " fii stangi - fii drepti"
    I.c) Prin  alocare dinamica

I.c) Ideea : se urmareste mai indeaproape , cu mai putine codificari ( conventii )
                   ceea ce  vrem de fapt sa reprezentam

Arborele  este un pointer ( adresa de memorie catre nodul radacina )
fiecare nod este un obiect continand informatiile :

- nume nod
- "zestrea" informatia depusa in acel nod
- adresa subarborelui stang
- adresa subarborelui drept


OBS : in cazul ca nod curent nu are unul sau ambii descendenti
          adresa catre acestia va fi pointer constant  NULL

modalitati de introducere a unui arbore binar "inzestrat" alocat dinamic

- prin enumerarea nodurilor ca o parcurgere ( RSD  de exemplu )
   cu explicitarea suplimentara a momentelor de intoarcere
   ( nu sunt descendenti )

exemplu :
                               100(1)
                            /          \
                           /             \
                          50(2)         170(5)
                          /      \                \
                        20(3)   60(4)     190(6)

RSD(1) : 1,2,3,4,5,6



input.dat

1
2
3
0
0
4
0
0
5
0
6
0
0

OBS : Insa pentru o anumita parcurgere arborele binar al acesteia nu este unic !


[II] Metode de parcurgere

     II.a) RSD radacina stanga dreapta = preordine
     II.b) SRD stanga radacina  dreapta = inordine
     II.c)  SDR stanga dreapta radacina  = postordine


exemplu :
                               100(1)
                            /          \
                           /             \
                          50(2)         170(5)
                          /      \                \
                        20(3)   60(4)     190(6)

INFO ={100,50,20,60,170,190}
STANGI={2,3,0,0,0,0}
DREPTI={5,4,0,0,6,0}

Input.dat
6
100 50 20 60 170 190
2 3 0 0 0 0
5 4 0 0 6 0

aplicatii :
( parcurgere in preordine )
RSD(1): 100,50,20,60,170,190
( parcurgere in inordine )
SRD(1): 20,50,60,100,170,190
( parcurgere in postordine )
SDR(1): ... ,100


Aplic :

- conversie din fii stangi fii drepti in alocare dinamica
  si apoi RSD,SRD,SDR, pe reprezentarea dinamica

*/
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.dat");

int n;
int info[100], st[100], dr[100];

struct Nod
{
    int nr;
    int info;
    int* st;
    int* dr;
};
Nod dat[100];

int read_data()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>info[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>st[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>dr[i];
    }
}

int conversie()
{
    for(int i=1;i<=n;i++)
    {
        dat[i].nr=i;
        dat[i].info=info[i];
        dat[i].st=&st[i];
        dat[i].dr=&dr[i];
    }

}

int arboreRSD(int k)
{
    cout<<dat[k].info<<" ";
    if(*dat[k].st!=0)
    {
        arboreRSD(*dat[k].st);
    }
    if(*dat[k].dr!=0)
    {
        arboreRSD(*dat[k].dr);
    }
}

int arboreSRD(int k)
{
    if(*dat[k].st!=0)
    {
        arboreSRD(*dat[k].st);
    }
    cout<<dat[k].info<<" ";
    if(*dat[k].dr!=0)
    {
        arboreSRD(*dat[k].dr);
    }
}

int arboreSDR(int k)
{
    if(*dat[k].st!=0)
    {
        arboreSDR(*dat[k].st);
    }
    if(*dat[k].dr!=0)
    {
        arboreSDR(*dat[k].dr);
    }
    cout<<dat[k].info<<" ";
}

int main()
{
    read_data();
    conversie();
    arboreRSD(1);
    cout<<endl;
    arboreSRD(1);
    cout<<endl;
    arboreSDR(1);
}
