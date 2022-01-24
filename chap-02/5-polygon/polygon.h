
#pragma once

#include <utility>
#include <vector>

using Vertex = std::pair<int, int>;

class Polygon {

public:
    void   add_vertex(int x, int y);
    Vertex get_vertice(int index) const;

private:
    std::vector<Vertex> _vertices;
};