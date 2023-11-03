#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction nb_lignes qui compte le nombre lignes
// d'un fichier dont le nom est passé en paramètre. Il doit retourner
// une valeur négative en cas d'impossibilité d'ouvrir le fichier

int nb_lignes(string filename);

int main() {
    cout << "Entrez le nom du fichier : " << flush;
    string filename; cin >> filename;
    auto n = nb_lignes(filename);
    if(n >= 0)
        cout << "Le fichier contient " << n << " lignes" << endl;
    else
        cout << "Le fichier est illisible";
}

int nb_lignes(string filename){
    //ouvrir le fichier en lecture
    ifstream file_in(filename);
    if (!file_in){
        return -1;
    }

    int nb_ligness = 0;
    string une_ligne;

    // Tant qu'il reste encore des choses à lire
    while (getline(file_in, une_ligne)) {
        nb_ligness++;
    }
    // fermer le fichier
    file_in.close();

    return nb_ligness;
}