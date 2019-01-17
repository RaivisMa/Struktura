#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void makelist();
void addtolist();
void checkitem();
void displaylist();

struct list
{

    int quant;
    string items;
    string place;
    string date;
};
int main()
{
    int a;
    cout << "                        *Sveiki atvykę į pirkinių sąrašą*" << endl;
    cout << "Prašome įvesti: " << endl;
    do
    {
        cout << "     (1) Jeigu tu nori padaryti sąraša." << endl;
        cout << "     (2) Jeigu tu nori pridėti pirkini į saraša." << endl;
        cout << "     (3) Jeigu tu nori patikrinti , tam tikra produktą" << endl;
        cout << "     (4) Jeigu norite tam tikrą dieną nuskaityti prekybos sąrašą" << endl;
        cout << "     (5) Jeigu norite išeiti" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            makelist();
            break;
        case 2:
            addtolist();
            break;
           case 5:
                cout << "...Uždaroma...";
                return 0;
            default:
                cout << "..ERROR..paspauskite skaičių 1 to 5"<<endl;
                break;
        }
    } while (a != 5);
    return 0;
}
void makelist()
{
    string FileName;
    cout << "Iveskite saraso pavadinimą: ";
    cin >> FileName;
    ofstream WriteToFile;
    WriteToFile.open(FileName);
    list L;
    int n;
    cout << "Įveskite prekės numerį:" << endl;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cout << "Įveskite elementus ir kiekį:" << endl;
        cin >> L.items >> L.quant;
        WriteToFile << L.items << L.quant;
    }
    cout << "Įveskite parduotuvės pavadinimą:" << endl;
    cin >> L.place;
    WriteToFile << L.place;
    cout << "Įveskite datą:" << endl;
    cin >> L.date;
    WriteToFile << L.date;
}
void addtolist()
{
    cout << "ur lists:" << endl;
    ifstream readfromfile;
    if (readfromfile.is_open())
    {
        makelist();
    }
    else
        cout << "ERROR atidarant faila" << endl;
}
