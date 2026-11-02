#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    string getNom() {
        return nom;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

void ajouterContact(Contact** carnet, int& n) {
    string nom, telephone, email;

    cout << "Donner le nom : ";
    getline(cin, nom);

    cout << "Donner le telephone : ";
    getline(cin, telephone);

    cout << "Donner l'email : ";
    getline(cin, email);

    carnet[n] = new Contact(nom, telephone, email);
    n++;

    cout << "Contact ajoute avec succes !" << endl;
}

void afficherContacts(Contact** carnet, int n) {
    if (n == 0) {
        cout << "Le carnet est vide." << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\n Contact " << i + 1 << " " << endl;
        carnet[i]->afficher();
    }
}

void supprimerContact(Contact** carnet, int& n, string nom) {
    int position = -1;

    for (int i = 0; i < n; i++) {
        if (carnet[i]->getNom() == nom) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "Contact introuvable !" << endl;
        return;
    }

    delete carnet[position];

    for (int i = position; i < n - 1; i++) {
        carnet[i] = carnet[i + 1];
    }

    n--;

    cout << "Contact supprime avec succes !" << endl;
}

int main() {
    const int MAX = 100;
    int n = 0;

    Contact** carnet = new Contact*[MAX];

    int choix;

    do {
        cout << "\n CARNET D'ADRESSES " << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
            case 1:
                if (n < MAX) {
                    ajouterContact(carnet, n);
                } else {
                    cout << "Le carnet est plein !" << endl;
                }
                break;

            case 2:
                afficherContacts(carnet, n);
                break;

            case 3: {
                string nom;
                cout << "Donner le nom du contact a supprimer : ";
                getline(cin, nom);

                supprimerContact(carnet, n, nom);
                break;
            }

            case 4:
                cout << "Fermeture du programme..." << endl;
                break;

            default:
                cout << "Choix invalide !" << endl;
        }

    } while (choix != 4);

    for (int i = 0; i < n; i++) {
        delete carnet[i];
    }

    delete[] carnet;

    return 0;
}




