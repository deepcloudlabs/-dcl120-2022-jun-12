#include <iostream>
#include <map>

using namespace std;

class Integer {
private:
    int value;

    Integer(int value) {
        this->value = value;
    }

protected:
    static map<int, Integer *> bytes;
public:
    int intValue() {
        return value;
    }

    static Integer *of(int value) {
        if (value >= -128 && value <= 127) {
            map<int, Integer *>::iterator it = bytes.find(value);
            Integer *mapped;
            if (it == bytes.end()) {
                mapped = new Integer(value);
                bytes.insert(pair<int, Integer *>(value, mapped));
            } else {
                mapped = it->second;
            }
            return mapped;
        } else {
            return new Integer(value);
        }
    }
};

map<int, Integer *> Integer::bytes;

int main() {
    Integer *p = Integer::of(108);
    Integer *q = Integer::of(108);
    if (p == q) {
        cout << "p is equal to q!" << endl;
    } else {
        cout << "p is NOT equal to q!" << endl;

    }
    Integer *r = Integer::of(549);
    Integer *s = Integer::of(549);
    if (r == s) {
        cout << "r is equal to s!" << endl;
    } else {
        cout << "r is NOT equal to s!" << endl;
    }
    for (int j = 0; j < 1'000; ++j) {
        for (int i = 0; i < 1'000'000; ++i) {
            Integer::of(108);
            //new int(108);
        }
    }
    cout << "done." << endl;
    return 0;
}
