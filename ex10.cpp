#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction caractere_le_plus_frequent(string const& filename)
// qui retourne une structure ou une paire (voir chapitre 7) qui
// contient le caractère (hors espace ' ') le plus fréquent dans ce fichier,
// ainsi que le nombre de fois qu'il apparait. Ce nombre est négatif
// si le fichier est illisible.

struct char_nombre {
    char c;
    int n;
};

char_nombre caractere_le_plus_frequent(string filename);

int main() {
   cout << "Entrez le nom du fichier : " << flush;
   string filename;
   cin >> filename;

   auto [c, n] = caractere_le_plus_frequent(filename);
   if (n >= 0)
      cout << "Le caractère " << c
           << " est le plus fréquent et apparait " << n
           << " fois dans le fichier " << filename << endl;
   else
      cout << "Le fichier est illisible";
}

char_nombre caractere_le_plus_frequent(string filename){
    //ouvrir le fichier en lecture
    ifstream file_in(filename);
    if (!file_in){
        return {0, -1};
    }

    char_nombre plusGrand;
    string une_ligne;

    // Tant qu'il reste encore des choses à lire
    while (getline(file_in, une_ligne)) {
        for(char d:une_ligne){

        }
    }
    // fermer le fichier
    file_in.close();

    return plusGrand;
}