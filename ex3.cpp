#include <iostream>

using namespace std;

// écrire la fonction plus_petite_lettre(str) qui retourne
// le plus petite caractère (au sens du code ASCII) de la chaine
// str. Si cette lettre apparait plusieurs fois c'est la
// dernière instance qui doit être retournée.

char& plus_petite_lettre(string& s);

int main() {

   string s{"wisigoth"};
   plus_petite_lettre(s) = '*';
   cout << s << endl;
   // affiche wisi*oth

   s = "abraracourcix";
   plus_petite_lettre(s) = '*';
   cout << s << endl;
   // affiche abrar*courcix
}

char& plus_petite_lettre(string& s){
    int counter = 0;
    int idSmall = 0;
    char cSmall = s[idSmall];
    for(char c:s){
        if(c <= cSmall){
            cSmall = c;
            idSmall = counter;

        }
        counter++;
    }
    return s[idSmall];
}
