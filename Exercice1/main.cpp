
#include <iostream>
using namespace std;

int main() {
    int n;


    cout << "Donner la taille du tableau : ";
    cin >> n;


    int* tab = new int[n];


    for (int i = 0; i < n; i++) {
        cout << "Donner la valeur " << i + 1 << " : ";
        cin >> tab[i];
    }


    cout << "\nLes valeurs du tableau sont :" << endl;

    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;


    delete[] tab;

    return 0;
}




