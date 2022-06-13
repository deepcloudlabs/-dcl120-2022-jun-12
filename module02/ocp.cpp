// open closed principle

// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

enum class Color {
    red, green, blue
};
enum class Size {
    small, medium, large
};

struct Product {
    string name;
    Color color;
    Size size;
    double price;
};

template<typename T>
struct Predicate { // interface
    virtual bool filter(const T &item) const = 0;
};

struct ColorPredicate : Predicate<Product> {
    bool filter(const Product &item) const override {
        return item.color == color;
    }

    ColorPredicate(Color color) : color(color) {}

private:
    Color color;
};

template<double VALUE>
struct CheapPredicate : Predicate<Product> {
    bool filter(const Product &item) const override {
        return item.price < VALUE;
    }
};

struct SizePredicate : Predicate<Product> {
    bool filter(const Product &item) const override {
        return item.size == size;
    }

    SizePredicate(Size size) : size(size) {}

private:
    Size size;
};

template<typename T>
struct AndPredicate : Predicate<T> {
    bool filter(const T &item) const override {
        return first.filter(item) && second.filter(item);
    }

    AndPredicate(Predicate<T> &first, Predicate<T> &second) : first(first), second(second) {}

private:
    Predicate<T> &first;
    Predicate<T> &second;
};

template<typename T>
struct OrPredicate : Predicate<T> {
    bool filter(const T &item) const override {
        return first.filter(item) || second.filter(item);
    }

    OrPredicate(Predicate<T> &first, Predicate<T> &second) : first(first), second(second) {}

private:
    Predicate<T> &first;
    Predicate<T> &second;
};

template<typename T>
struct NotPredicate : Predicate<T> {
    bool filter(const T &item) const override {
        return !predicate.filter(item);
    }

    NotPredicate(Predicate<T> &predicate) : predicate(predicate) {}

private:
    Predicate<T> &predicate;
};

template<typename T>
struct Catalog { // interface
    virtual vector<T> search(Predicate<T> &predicate) const = 0;
};

struct ProductCatalog : public Catalog<Product> {

    ProductCatalog(const vector<Product> &items) : items(items) {}

    vector<Product> search(Predicate<Product> &predicate) const override {
        vector<Product> result;
        for (auto &item: items) {
            if (predicate.filter(item))
                result.push_back(item);
        }
        return result;
    }

private:
    vector<Product> items;
};

int main() {
    Product apple{"Apple", Color::green, Size::small, 10'000};
    Product tree{"Tree", Color::green, Size::large, 20'000};
    Product house{"House", Color::blue, Size::large, 30'000};

    ProductCatalog catalog(vector<Product>{apple, tree, house});
    SizePredicate large{Size::large};
    ColorPredicate green{Color::green};
    AndPredicate<Product> large_green{large, green};
    CheapPredicate<25000.0> cheaper;
    NotPredicate<Product> notCheaper{cheaper};
    OrPredicate<Product> complex{large_green, notCheaper};
    for (auto &item: catalog.search(complex)) {
        cout << item.name << endl;
    }
    return 0;
}