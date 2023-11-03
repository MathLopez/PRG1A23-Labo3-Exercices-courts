#include <iostream>
#include <limits>

using namespace std;

// Ecrivez la fonction lire_multiple_de(n) qui demande
// à l'utilisateur d'entrer un multiple de n, et lui
// dit d'essayer encore jusqu'à ce qu'il le fasse.
//
// Exemple d'exécution :
//
//Entrez un entier multiple de 3: 23
//Essayez encore : douze ?
//Essayez encore : pardon, 12
//Essayez encore : 13
//Essayez encore : 12
//Merci, vous avez entre 12

int lire_multiple_de(int nb);
bool is_number(const string& s);

int main() {

   int n = lire_multiple_de(3);
   cout << "Merci, vous avez entre " << n << endl;
}

int lire_multiple_de(int nb){
    string in;
    cout << "Entrez un entier multiple de " << nb << ": ";
    startFunc:
    while ((cin >> in) and !is_number(in)){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Essayez encore : ";
    }
    if(stoi(in) % nb != 0){
        cout << "Essayez encore : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto startFunc;
    }
    return stoi(in);
}

// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
