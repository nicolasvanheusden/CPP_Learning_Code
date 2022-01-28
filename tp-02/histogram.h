#pragma once

#include <iostream>
#include <vector>

class Histogram {
public:
    Histogram()
        : _count(26) {
        std::cout << "constructeur" << std::endl;
    };                                                                  // constructeur
    Histogram(const Histogram&) { std::cout << "copie" << std::endl; }; // constructeur de copie
    ~Histogram() { std::cout << "destructeur" << std::endl; };          // destructeur

    Histogram& operator=(const Histogram&); // opérateur d'assignation par copie

    void analyze(const std::string&); // analyse la string passée en paramètre
    void print() const;               // affiche l'histogramme

private:
    std::vector<unsigned int>
        _count; // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
};