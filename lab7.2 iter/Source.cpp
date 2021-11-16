#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int k , const int n);
int countEvenNumbers(int** a, const int k, const int n);
int main()
{
    srand((unsigned)time(NULL));

    int Low = -10;
    int High = 25;

    int n,k;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, n,k, Low, High);
    Print(a,k, n);
    cout << "sum min = " << countEvenNumbers(a, k, n) << endl;

   

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int k, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}


void Print(int** a, const int  k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}


int countEvenNumbers(int** a, const int k, const int n) 
{
    int s = 0;
    for (int j = 0; j < k; j++) {	

        int min = a[j][0];

        for (int i = 0; i < n; i++) 
        {		
            if (a[j][i] < min)
                min = a[j][i];
        }
        s += min;
    }

    return s;
    
   

}
