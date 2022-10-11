/**
 * @author Benjamin Peronne
 * @email contact@benjaminperonne.fr
 * @create date 2022-10-11 10:15:22
 * @modify date 2022-10-11 10:15:22
 * @desc [TP2 - PGCD]
 */

// Calcul du PGCD de deux nombres entiers
/*
Le PGCD de deux nombres entiers est le Plus Grand Commun Diviseur. La desciption de l’algorithme qui permet de le calculer est la suivante :
• On compare les deux nombres entiers.
• On échange le plus grand par le résultat de la soustraction du plus petit au plus grand.
• Tant que les deux nombres ne sont pas égaux on reprend les deux points précédents.
Une fois que les deux nombres sont égaux, le résultat obtenu est le PGCD.
*/

#include <iostream>

using namespace std;

void echange(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int pgcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main(int argc, char const *argv[]) {

    int a, b;

    cout << "Entrez le premier nombre : ";
    cin >> a;
    cout << "Entrez le deuxième nombre : ";
    cin >> b;

    if (a < b) {
        echange(a, b);
    }

    cout << "Le PGCD de " << a << " et " << b << " est " << pgcd(a, b) << endl;

    return 0;
}
