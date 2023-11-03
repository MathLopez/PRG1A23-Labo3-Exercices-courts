#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction nb_char_in_file(filename, c) qui compte le nombre
// de fois que la caractère c apparait dans le fichier. Il doit retourner
// une valeur négative en cas d'impossibilité d'ouvrir le fichier

int nb_char_in_file(string filename, char c);

int main() {
   cout << "Entrez le nom du fichier : " << flush;
   string filename; cin >> filename;
   cout << "Entrez le caractère : " << flush;
   char c; cin >> c;

   auto n = nb_char_in_file(filename,c);
   if(n >= 0)
      cout << "Le fichier contient " << n << " fois le caractère " << c << endl;
   else
      cout << "Le fichier est illisible";
}

int nb_char_in_file(string filename, char c){
    //ouvrir le fichier en lecture
    ifstream file_in(filename);
    if (!file_in){
        return -1;
    }

    int nb_caracteresC = 0;
    string une_ligne;

    // Tant qu'il reste encore des choses à lire
    while (getline(file_in, une_ligne)) {
        for(char d:une_ligne){
            if(d == c){
                nb_caracteresC++;
            }
        }
    }
    // fermer le fichier
    file_in.close();

    return nb_caracteresC;
}