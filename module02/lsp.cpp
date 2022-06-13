// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program

#include <iostream>
#include <memory>

using namespace std;

struct Shape2D {
    virtual int area() const = 0;
    virtual int circumference() const = 0;
};

struct Shape3D {
    virtual int surface_area() const = 0;

    virtual int volume() const = 0;
};

class Cube : public Shape3D {
    int edge;
public:
    Cube(int edge) : edge(edge) {}

    int surface_area() const override {
        return 6 * edge * edge;
    }

    int volume() const override {
        return edge*edge*edge;
    }
};
class Rectangle : public Shape2D {
protected:
    int width, height;
public:
    Rectangle(const int width, const int height) : width{width}, height{height} {}

    int get_width() const { return width; }

    virtual void set_width(const int width) { this->width = width; }

    int get_height() const { return height; }

    virtual void set_height(const int height) { this->height = height; }

    int area() const override { return width * height; }

    int circumference() const override { return 2 * (width + height); }
};

class Square : public Shape2D {
    int edge;
public:
    Square(int edge) : edge(edge) {}

    void set_edge(const int edge) {
        this->edge = edge;
    }

    int get_edge() {
        return edge;
    }

    int circumference() const override { return 4 * edge; }

    int area() const override { return edge * edge; }

};

struct Shape2DFactory {
    static shared_ptr<Shape2D> create_rectangle(int w, int h) {
        return make_shared<Rectangle>(Rectangle{w, h});
    };

    static shared_ptr<Shape2D> create_square(int size) {
        return make_shared<Square>(Square{size});
    }
};

void process(shared_ptr<Shape2D> &r) {
    std::cout << "Area         : " << r->area() << std::endl;
    std::cout << "Circumference: " << r->circumference() << std::endl;
}

int main() {
    shared_ptr<Shape2D> shape1 = Shape2DFactory::create_rectangle(3, 4);
    process(shape1);

    shared_ptr<Shape2D> shape2 = Shape2DFactory::create_square(5);
    process(shape2);

    return 0;
}