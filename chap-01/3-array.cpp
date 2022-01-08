#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    if (argc <= 1)
    {
        cerr << "Merci d'indiquer un nombre en paramètre" << endl;
        return -1;
    }
    int length = stoi(argv[1]);
    if (length <= 0)
    {
        cerr << "Merci d'indiquer un PUTAIN DE NOMBRE" << endl;
        return -1;
    }

    vector<int> array;

    for (int i = 0; i < length; i++)
    { array.emplace_back(i + 1); }

    for (int i = 0; i < length; i++)
    { cout << array[i] << endl; }

    return 0;
}
