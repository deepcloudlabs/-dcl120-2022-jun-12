#include <iostream>
#include <cstring>

using namespace std;

/* Abstract base class declared by framework */
class Document {
  public:
    Document(const char *fn) {
        strcpy(name, fn);
    }
    virtual void open() = 0;
    virtual void close() = 0;
    const char *getName() {
        return name;
    }
  private:
    char name[20];
};

/* Concrete derived class defined by client */
class MyDocument: public Document {
  public:
    MyDocument(const char *fn): Document(fn){}
    void open() {
        cout << "   MyDocument: Open()" << endl;
    }
    void close() {
        cout << "   MyDocument: Close()" << endl;
    }
};

/* Framework declaration */
class Application {
  public:
    Application(): _index(0) {
        cout << "Application: ctor" << endl;
    }
    /* The client will call this "entry point" of the framework */
    void newDocument(const char *name) {
        cout << "Application: NewDocument()" << endl;
        /* Framework calls the "hole" reserved for client customization */
        _docs[_index] = createDocument(name);
        _docs[_index++]->open();
    }
    void openDocument(){}
    void reportDocs();
    /* Framework declares a "hole" for the client to customize */
    virtual Document *createDocument(const char*) = 0;
  private:
    int _index;
    /* Framework uses Document's base class */
    Document *_docs[10];
};

void Application::reportDocs() {
  cout << "Application: ReportDocs()" << endl;
  for (int i = 0; i < _index; i++)
    cout << "   " << _docs[i]->getName() << endl;
}

/* Customization of framework defined by client */
class MyApplication: public Application {
  public:
    MyApplication() {
        cout << "MyApplication: ctor" << endl;
    }
    /* Client defines Framework's "hole" */
    Document *createDocument(const char *fn) {
        cout << "   MyApplication: CreateDocument()" << endl;
        return new MyDocument(fn);
    }
};

int main() {
  /* Client's customization of the Framework */
  MyApplication myApp;

  myApp.newDocument("foo");
  myApp.newDocument("bar");
  myApp.reportDocs();
  return 0;
}
