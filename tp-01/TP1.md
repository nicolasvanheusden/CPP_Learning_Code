# TP1 - Introduction au C++


## Exercice 1 - Compilation et exécution

1. Quels sont les avantages et désavantages d'un langage dit "*compilé*" (C, C++, Pascal) ou "*semi-compilé*" (Java) comparé à un langage dit "*interpreté*" (Python, PHP, Javascript, etc) ?
Programme compilé  ou semi-compilé: 
  Avantages : plus rapide à éxécuter.
  Inconvénients : doit le re-compiler pour chaque système. non portable.

Éxecution:
  Avantages : portable
  Inconvénients : Plus lent à éxécuter qu'un langage compilé

2. Quelle est la différence entre une erreur de compilation et une erreur d'exécution ? (à quel moment se produisent-elles?, dans quelles circonstances, comment les identifier?, comment les corriger?, ...)
Une erreur de compilation, se produit à la compilation, c'est souvent des erreurs de syntaxe ou de typage.
Pour les corriger, il faut se relire.

Une erreur d'éxécution est une erreur qui arrive à l'éxécution, cela peut être par exemple un null pointer exception. On les identifies par des Exceptions qui sont levées. Pour les corriger, il faut se relire et comprendre l'erreur et la fix.

3. Que signifie en pratique l'expression "*undefined behavior*" (UB) ? Peut-on compiler un programme contenant du code classifié UB par le standard ? Si oui, que peut-il se produire au moment de son exécution ?
  L'expression undefined behavior est tout ce qui n'est pas supporté par le langage. Oui on peut compiler un code classifié UB. Cela peut planter au niveau de l'éxécution en ne donnant pas le bon resultat.

## Exercice 2 - Primitives et initialisation

En C++, il existe plein de syntaxes différentes pour initialiser une variable de type primitif (int, char, bool, ...) :

```cpp
int v;       // pas d'initialisation            -> valeur indéfinie
int v = 2;   // initialisation avec '= value'   -> value
int v {};    // initialisation avec '{}'        -> tous les bits à 0
int v { 2 }; // initialisation avec '{ value }' -> value
int v(2);    // initialisation avec '(value)'   -> value
```

1. Parmi les lignes suivantes, lesquelles déclenchent des erreurs de compilation ? Quelles sont ces erreurs et comment les corriger ?\
Mêmes questions en ajoutant l'option `-Werror` à la compilation.\
Vous pouvez utiliser [CompilerExplorer](https://www.godbolt.org/z/rPPoro) pour tester la compilation de petits snippets de code.

```cpp
short s0; // ok
int   i1 = 2; // ok
bool  b2{false}; // ok
bool  b3{i1}; // warning de conversion int et bool | avec -Werror : remplacer bool b3 -> int i3; ou changer i1 par un bool
bool* b4; 
unsigned       u5{0x10}; // ok
unsigned short us6 = -10; // ok
unsigned long  ul7{b3 + u5 + us6}; //ok
char c8{"a"}; // erreur de conversion char et char* : remplacer " -> '
char c9 = -10; // ok
double  d10{i1}; // warning conversion int et double | avec -Werror : remplacer double b3 -> int i3; ou changer i1 par un double
double* d11{d10}; // erreur de conversion double et double* : remplacer d10 -> &d10
double& d12; // erreur d12 déclarer comme une référencer mais non initialisé : remplacer:  double& -> double*
const double d13{.0f}; //ok
const int    i14 = i1; //ok 
int* i15 = &i1; // ok
int* i16 = &b2; // erreur de conversion int* et bool* : remplacer int* -> bool*
int  i17 = *i15; // ok
int& i18{i14}; // erreur de conversion int& et int : remplacer cont int i14 -> int i14 ou rajouter const int& i18
const int* i19{nullptr}; // ok
const bool b20; // error variable const non initialisée : initialiser b20 = false
```

2. Pouvez-vous donner la valeur de `s0` ? De `*i15` ? De `ul7` ?
so = 0; *i15 = 2; ul7 = {0 + 16 + 65526} = 65542


## Exercice 3 - Les fonctions et leurs paramètres

1. Remplacez les `XX` par les bons types, de manière à ce que le programme compile et affiche `42`.

```cpp
#include <iostream>

int add(int a, int b) {
  return a + b;
}

void add_to(int& a, int b) {
  a += b;
}

void another_add_to(int* a, int b) {
  *a += b;
}

int main() {
  const int x{10};
  int y = add(x, x);
  add_to(y, 22);
  std::cout << y << std::endl;
  return 0;
}
```

2. En C++, vous pouvez passer vos paramètres par valeur, par référence et par référence constante.
Quelles sont les différences entre ces différentes méthodes de passage ?
Dans quels contextes est-il préférable de passer par valeur ? Par référence ? Et par référence constante ?

Une référence, c’est simplement une variable qui agit comme un alias d’une autre variable. En d’autres termes, les deux variables font référence au même emplacement dans la mémoire.

Une const référence est une variable coûteuse style std::string ou std::vector dont on ne veut pas passer une copie qui va ré-allouer de la mémoire. A l'inverse une passe une référence auquel on rajoute const pour indiquer qu'on ne veut pas pouvoir la modifié dans la fonction.

On passe par valeur quand on a des variables simple dont on ne veut pas modifier sa valeur dans une fonction.
Par référence quand on veut modifier une variable dans une fonction.
Par const référence quand on a une variable coûteuse dont on ne veut pas modifier sa valeur dans une fonction.


3. Modifiez les signatures des fonctions suivantes de manière à ce que le passage de paramètres soit le plus efficace et sécurisé possible.
Vous pouvez vous aidez des commentaires pour comprendre comment les fonctions utilisent leurs paramètres.
```cpp
// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(const std::string& s);

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(const float& dt, std::string& errors_out);

// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(std::vector<int> values, int negative_indices_out[], size_t& negative_count_out);

// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
std::string concatenate(const char& str1,const char& str2);
```


## Exercice 4 - `std::string` et `std::vector`

1. Ecrivez un programme qui utilise `std::cin` pour lire une variable de type `std::string`, puis calcule et affiche pour chaque lettre miniscule ('a', 'b', ..., 'z') le nombre des fois où elle apparaît.\
Le comptage des lettres se fera dans une fonction `count_lower` prenant une chaîne de caractères en paramètre et renvoyant un `std::vector<unsigned int>`. La première case du tableau contiendra le nombre d'occurences de 'a', la seconde de 'b', etc.\
Vous afficherez ce tableau dans une seconde fonction `display_lower_occ`.\
Essayez d'utiliser les signatures qui rendront votre programme le plus efficace possible.

2. Modifiez le programme pour que l'utilisateur puisse entrer plusieurs chaînes de caractères, jusqu'à ce qu'il entre la chaîne "QUIT".\
Vous afficherez en plus des occurrences la concaténation de toutes les chaînes de caractères renseignées par l'utilisateur.


## Exercice 5 - Traducteur malade

Dans la vie, on se retrouve souvent face à du code tout pourri qu'il faut débugguer. Afin de vous préparer psychologiquement aux tourments de votre futur métier de programmeur, vous allez devoir corriger le code du programme que vous trouverez dans le dossier `tp-01` du dépôt https://github.com/Laefy/CPP_Learning_Code/.

---

Ce programme consiste en un traducteur, censé s'utiliser comme suit :
```b
# Ajoute une nouvelle traduction au dictionnaire dict.txt (il est créé s'il n'existe pas).
./translator -d path/to/dict.txt -a chat cat

# Utilise le dictionnaire dict.txt pour traduire la phrase "le chat est beau"
./translator -d path/to/dict.txt le chat est beau
```

Voici le format attendu pour le fichier dict.txt :
```b
bonjour hello
cheval horse
tu you
```
---

1. Pour commencer, essayez de faire en sorte que le programme compile.\
Un indice : si seulement on pouvait bannir les chaînes de caractères de type char*.

2. Une fois que le programme compile, essayez de le lancer, afin de constater que le programme est bourré de bug.\
Placez un breakpoint sur la première ligne du `main`, lancez le programme en mode debug et itérez d'instruction en instruction, tout en inspectant le contenu des variables.\
Cela vous permettra d'identifier d'où viennent les problèmes pour réussir à les corriger.

> Dans VSCode, vous pouvez placer des breakpoints avec F9, lancer un programme en mode debug via F5 (il faut modifier le fichier launch.json pour passer des arguments au programme), exécuter l'instruction courante avec F10, entrer dans un appel de fonction avec F11 et en sortir avec Shift+F11. Afin de voir le contenu des variables, ouvrez le panneau d'exécution (`View > Run`) et regardez dans la section `Variables`.

> Voici la liste des types de problèmes que trouverez dans le programme :
>- passage par valeur au lieu de référence,
>- mauvais usage de `std::vector`,
>- condition inversée ou au mauvais endroit.

3. Si vous parvenez à corriger tous les bugs, vous pouvez faire une dernière passe sur le programme afin de remplacer les passages par valeur coûteux par des passages par const-ref, et ajouter les `const` sur toutes les variables qui ne sont pas modifiées après leur initialisation.   

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
