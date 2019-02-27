#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int info[100], st[100], dr[100];

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

int arboreRSD(int k)
{
    cout<<info[k]<<" ";
    if(st[k]!=0)
    {
        arboreRSD(st[k]);
    }
    if(dr[k]!=0)
    {
        arboreRSD(dr[k]);
    }
}

int arboreSRD(int k)
{
    if(st[k]!=0)
    {
        arboreSRD(st[k]);
    }
    cout<<info[k]<<" ";
    if(dr[k]!=0)
    {
        arboreSRD(dr[k]);
    }
}

int arboreSDR(int k)
{
    if(st[k]!=0)
    {
        arboreSDR(st[k]);
    }
    if(dr[k]!=0)
    {
        arboreSDR(dr[k]);
    }
    cout<<info[k]<<" ";
}

int main()
{
    read_data();
    arboreRSD(1);
    cout<<endl;
    arboreSRD(1);
    cout<<endl;
    arboreSDR(1);
}
