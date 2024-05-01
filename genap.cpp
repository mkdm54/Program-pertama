// Ini adalah program mencari nilai ganjil atau genap sesuai diinputkan user
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const string merah = "\x1b[31m";
const string hijau = "\x1b[32m";
const string reset = "\x1b[0m";

void warna(const string &warna)
{
    cout << warna;
}
void KondisiInput(int &num, int &percobaan, int &maks_percobaan)
{
    while (percobaan < maks_percobaan)
    {
        try
        {
            cout << "Masukkan angka : ";
            if (!(cin >> num))
            {
                throw invalid_argument("Input harus berupa angka");
            }
            break;
        }
        catch (const invalid_argument &e)
        {
            warna(merah);
            cout << "ERROR : " << e.what() << endl;
            warna(reset);
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            percobaan++;
        }
    }
}
void GenapGanjil(int &num , int &percobaan, int &maks_percobaan)
{
    if (percobaan == maks_percobaan)
    {
        cout << "\nLIMIT PERCOBAAN : Anda telah mencapai batas percobaan" << endl;
        exit(1);
    }

    if (num == 0)
    {
        warna(merah);
        cout << num << " bukan bilangan ganjil dan bilangan genap" << endl;
        warna(reset);
    }
    else if (num % 2 == 0)
    {
        warna(hijau);
        cout << num << " adalah bilangan genap" << endl;
        warna(reset);
    }
    else
    {
        warna(hijau);
        cout << num << " adalah bilangan ganjil" << endl;
        warna(reset);
    }
}
int main(int argc, char const *argv[])
{
    int num;
    int maks_percobaan = 3;
    int percobaan = 0;
    cout << "Batas percobaan = " << maks_percobaan << endl;

    KondisiInput(num, percobaan, maks_percobaan);

    GenapGanjil(num, percobaan, maks_percobaan);

    return 0;
}
