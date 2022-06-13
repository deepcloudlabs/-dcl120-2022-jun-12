#include <vector>
#include <iostream>

using namespace std;

struct Document {
};

struct PrinterMachine { // interface
    virtual void print(Document &doc) = 0;
};

struct ScannerMachine { // interface
    virtual void scan(Document &doc) = 0;
};

struct FaxMachine { // interface
    virtual void fax(Document &doc) = 0;
};

struct MultiFunctionalMachine : public PrinterMachine, public ScannerMachine, public FaxMachine { // interface

};


struct Scanner : public ScannerMachine {
    void scan(Document &doc) override {
        cout << "scanning the document" << endl;
    };
};


struct Printer : public PrinterMachine {
    void print(Document &doc) override {
        cout << "printing the document" << endl;
    };

};

struct HP8710 : public PrinterMachine, public ScannerMachine {
    void print(Document &doc) override {
        cout << "printing the document" << endl;
    };

    void scan(Document &doc) override {
        cout << "scanning the document" << endl;
    };
};

struct Canon123 : public MultiFunctionalMachine {
    void print(Document &doc) override {
        cout << "printing the document" << endl;
    };

    void scan(Document &doc) override {
        cout << "scanning the document" << endl;
    };

    void fax(Document &doc) override {
        cout << "sending the document to the fax machine" << endl;
    };
};

int main() {
    Document document;
    Printer printer;
    HP8710 hp8710;
    Canon123 canon123;

    hp8710.print(document);
    hp8710.scan(document);
    canon123.print(document);
    canon123.scan(document);
    canon123.fax(document);
    return 0;
}