

#include <iostream>
#include <vector>

using namespace std;

const static int NUMBER_LETTERS = 26;

void count_lower(const string& chaine, vector<int>& occurences) {
    for (char c : chaine) {
        int pos = c - 'a';
        occurences[pos] += 1;
    }
}

void display_lower_occ(const vector<int>& occurences) {
    for (size_t i = 0; i < occurences.size(); i++) {
        char letter = 'a' + i;
        cout << letter << " : " << occurences[i] << endl;
    }
}

void add_chaine(const string& chaine, vector<string>& chaines) {
    chaines.emplace_back(chaine);
}

void display_chaines(const vector<string>& chaines) {
    for (string chaine : chaines) {
        cout << chaine << endl;
    }
}

int main(void) {

    vector<int>    occurences(NUMBER_LETTERS, 0);
    string         chaine;
    vector<string> chaines;

    for (;;) {
        cin >> chaine;
        if (chaine == "QUIT") {
            break;
        }
        count_lower(chaine, occurences);
        add_chaine(chaine, chaines);
    }

    display_lower_occ(occurences);
    display_chaines(chaines);

    return 0;
}