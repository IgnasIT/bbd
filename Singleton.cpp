#include "Singleton.h"
#include "iostream"
#include <fstream>
#include <iomanip>

using namespace std;

// Global static pointer used to ensure a single instance of the class.
Singleton* Singleton::m_pInstance = NULL;

/** This function is called to create an instance of the class.
Calling the constructor publicly is not allowed. The constructor
is private and is only called by this Instance function.
*/

Singleton* Singleton::Instance()
{
	if (!Singleton::m_pInstance)   // Only allow one instance of class to be generated.
		Singleton::m_pInstance = new Singleton;

	return Singleton::m_pInstance;
}

void Singleton::writeToLogFile()
{
	cout << "Hello Singleton world" << endl;
}


void Singleton::Ivedimas  (int A[][10], int & n, int & m)
{
	ifstream fd("Duomenys.txt");
	fd >> n >> m;
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			fd >> A[i][j];
	fd.close();
}


void Singleton::Spausdinti ( int A[][10], int n, int m)
{
	ofstream fr("Rezultatai.txt");
	fr << "Mokinio nr.      Ivertinimas " << endl;
	fr << "---------------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < n; i++)
	{
		fr << setw(5) << i + 1 << " . " ;
		for(int j = 0; j < m; j++)
		fr <<  setw(12) << A[i][j] << " " ;
		fr << endl;
	}
	fr << "---------------------------------------------------------------------------------------" << endl;
	fr << endl;
	fr.close();
}

int Singleton::geriauisais( int A[][10], int n, int m)
{
	double mvid = 0;
	double v;
	int idm = 0;
	for(int i = 0; i< n; i++)
	{
		int suma = 0;
		for(int j = 0; j < m; j++)
		{
			suma += A[i][j];
		}
		if(m == 0) v = 0;
		else v = (double) suma / m;
		if(mvid < v)
			{
				mvid = v;
				idm = i;
			}
	}
	return idm;
}


int Singleton::Neigiami (int A[][10], int n, int m)
{
	int kiekis = 0;
	for(int i = 0; i < n; i++)
	{
		int k = 0;
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] < 4)
			k++;
		}
		if(k > 0)
		kiekis++;
	}
	return kiekis;
}