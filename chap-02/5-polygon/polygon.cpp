

#include "polygon.h"

void Polygon::add_vertex(int x, int y) {
    _vertices.emplace_back(x, y);
}

Vertex Polygon::get_vertice(int index) const {
    return _vertices.at(index);
}