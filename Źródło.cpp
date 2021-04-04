#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generation(int A[], int n, int p)
{
	A[0] = rand() % 5 + 1;
	for (int i = p; i < n; i++)
	{
		A[i] = A[i - 1] + (rand() % 5 + 1);
	}
}

void print(int B[], int n, int p)
{
	cout << "Elementy w tablicy:" << endl;
	for (int i = p; i < n; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
}

//p=-1 lub p=indeks k, ip=pierwsza komorka tablicy, ik=ostatnia komorka tablicy
//isr=indeks elementu srodkowego, c=liczba porownan

void binarySearch(int C[], int n, int k, int p, int ip, int ik, int c)
{
	while (ip <= ik)
	{
		c++; //zwiekszamy liczbe porownan
		int isr = (ip + ik) / 2; //obliczamy indeks elementu srodkowego dla danego przedzialu, zbioru, w ktorym sie akurat znajdujemy
		if (C[isr] == k)
		{
			p = isr;
			break;
		}
		else if (k < C[isr])
		{
			ik = isr - 1;
		}
		else
		{
			ip = isr + 1;
		}
	}

	//wynik, mozemy tego w sumie nie rozbijac na if i else
   /**if (p >= 0) //k zostalo znalezione
   {
	   cout << "Wynik: " << p;
   }
   else //k nie zostalo znalezione
   {
	   cout << "Wynik: " << p;
   }**/

	cout << "Wynik: " << p;
	cout << endl;

	cout << "Liczba porownan: " << c << endl;
}

int main()
{
	int n, k; //n-liczba elementow w tablicy, k-klucz
	cout << "Podaj liczbe elementow n = ";
	cin >> n;
	int* Z = new int[n]; //tablica przechowujaca elementy do przeszukania
	//wypelniamy tablice - elementy musza byc uporzadkowane, np. rosnaco!!!
	srand(time(NULL));
	generation(Z, n, 1);
	//wyswietlamy tablice
	print(Z, n, 0); 
	//pytamy o klucz
	cout << "Podaj klucz k = ";
	cin >> k;
	//binary search i number of comparisons
	binarySearch(Z, n, k, -1, 0, n - 1, 0);
	//zwalniamy pamiec
	delete[] Z;

	return 0;
}