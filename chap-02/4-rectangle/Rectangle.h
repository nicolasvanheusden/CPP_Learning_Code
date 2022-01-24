#pragma once

class Rectangle {
public:
    static float _default_size;

    Rectangle(float length, float width);
    Rectangle(float size);
    Rectangle();

    // : _length { length }
    // , _width { width } {}

    float get_length() const;
    float get_width() const;

    void        scale(float ratio);
    static void set_default_size(float size);

private:
    float _length;
    float _width;
};

std::ostream& operator<<(std::ostream& stream, const Rectangle& person);
