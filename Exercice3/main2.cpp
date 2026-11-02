#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    double prix;

public:
    Livre() {
        titre = "";
        prix = 0.0;
    }

    void saisir() {
        cout << "Donner le titre du livre : ";
        getline(cin, titre);

        cout << "Donner le prix du livre : ";
        cin >> prix;
        cin.ignore();
    }

    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }
};

int main() {

    int n;

    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;
    cin.ignore();

    Livre* tab = new Livre[n];

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << " " << endl;
        tab[i].saisir();
    }

    cout << "\n Liste des livres " << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << " :" << endl;
        tab[i].afficher();
    }

    delete[] tab;

    return 0;
}




