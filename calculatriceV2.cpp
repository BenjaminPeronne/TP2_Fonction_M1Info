/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-11 09:05:53
 * @modify date 2022-10-11 09:05:53
 * @desc [TP2 - CalculatriceV2]
 */

// Il s 'agit d' ecrire un programme simulant une calculatrice rudimentaire sur des nombres entiers.

// Le programme suivant est une améliration du programme calculatrice du TP1.

/*
    Ajouter les fonctions suivantes :
    • PGCD : calcul du PGCD de deux nombres entiers
    • Factorielle : calcul de la factorielle d'un nombre entier
*/

/*
    Objectif : Le programme doit permettre de saisir deux nombres entiers et de choisir l'operation a effectuer.

    CR : Le programme est fonctionnel et répond aux exigences de l'objectif.
*/

#include <iomanip>
#include <iostream> // librairie de base pour les entrees/sorties (cin, cout)

using namespace std; // permet d'utiliser cout et cin sans le préfixe std;

// ==================== FONCTIONS OPERATIONS ====================
int addition(int a, int b) { // fonction addition
    return a + b;
}

int soustraction(int a, int b) { // fonction soustraction
    return a - b;
}

int multiplication(int a, int b) { // fonction multiplication
    return a * b;
}

int division(int a, int b) { // fonction division
    return a / b;
}

int reste(int a, int b) { // fonction reste
    return a % b;
}

int xexposant(int a, int b) { // fonction x exposant
    int resultat = 1;
    for (int i = 0; i < b; i++) {
        resultat *= a;
    }
    return resultat;
}

void echange(int &a, int &b) { // fonction echange de deux variables
    int temp = a;
    a = b;
    b = temp;
}

// Exercice TP2
int pgcd(int *a, int *b) { // fonction pgcd
    if (*a < *b) {         // on echange les deux variables si a est plus petit que b
        echange(*a, *b);
    }

    while (*a != *b) {
        if (*a > *b) {
            *a = *a - *b;
        } else {
            *b = *b - *a;
        }
    }
    return *a;
}

// Exercice TP2
float factorielle(float a) { // fonction factorielle
    float resultat = 1;
    for (float i = 1; i <= a; i++) {
        resultat *= i;
    }
    return resultat;
}

// ==================== FONCTIONS AFFICHAGE ====================
// Exercice TP2
void menu() {
    cout << "\n"; // saut de ligne
    cout << "Que voulez-vous faire ?" << endl;
    cout << "+ | Addition" << endl;
    cout << "- | Soustraction" << endl;
    cout << "* | Multiplication" << endl;
    cout << "/ | Division (avec reste)" << endl;
    cout << "^ | Calcul du x^n" << endl;
    cout << "% | Reste de la division" << endl;
    cout << "p | PGCD" << endl;
    cout << "! | Factorielle" << endl;
    cout << "q | Quitter" << endl;
    cout << "Votre choix : ";
}

// Exercice TP2
void input(int *a, int *b) { // fonction d'entree des deux variables
    cout << "\n";            // saut de ligne
    cout << "Entrez le premier nombre : ";
    cin >> *a;
    cout << "Entrez le deuxieme nombre : ";
    cin >> *b;
    cout << "\n"; // saut de ligne
}

// Exercice TP2
void output(int a, int b, int resultat, char operateur) { // fonction d'affichage du resultat
    cout << "\n";                                         // saut de ligne
    cout << ">>>>>> Le resultat : " << a << " " << operateur << " " << b << " = " << resultat << endl;
}

// ==================== FONCTION PRINCIPALE ====================
int main(int argc, char const *argv[]) {
    int nombre1, nombre2, resultat;
    char operateur = ' ';

    do {
        menu();

        cin >> operateur;
        switch (operateur) {
        case '+':
            input(&nombre1, &nombre2);
            output(nombre1, nombre2, addition(nombre1, nombre2), '+');
            break;

        case '-':
            input(&nombre1, &nombre2);
            output(nombre1, nombre2, soustraction(nombre1, nombre2), '-');
            break;

        case '*':
            input(&nombre1, &nombre2);
            output(nombre1, nombre2, multiplication(nombre1, nombre2), '*');
            break;

        case '/':
            input(&nombre1, &nombre2);
            output(nombre1, nombre2, division(nombre1, nombre2), '/');
            cout << "Le reste est : " << reste(nombre1, nombre2) << endl;
            break;

        case '^':
            input(&nombre1, &nombre2);
            cout << "Le resultat est : " << xexposant(nombre1, nombre2) << endl;
            break;

        case '%':
            input(&nombre1, &nombre2);
            output(nombre1, nombre2, reste(nombre1, nombre2), '%');
            break;

        case 'p':
            input(&nombre1, &nombre2);
            cout << ">>>>>> Le PGCD de " << nombre1 << " et " << nombre2 << " est " << pgcd(&nombre1, &nombre2) << endl;
            break;

        case '!':
            float nbFact;
            cout << "\n"; // saut de ligne
            cout << "Entrez le premier nombre : ";
            cin >> nbFact;
            cout << "\n"; // saut de ligne

            cout << ">>>>>> La factorielle de " << nbFact << " est " << fixed << setprecision(2) << factorielle(nbFact)
                 << endl;
            break;

        case 'q':
            cout << "Au revoir !" << endl;
            break;

        default:
            cout << "Choix invalide ! \n"
                 << endl;
            break;
        }
    } while (operateur != 'q');

    return 0;
}
