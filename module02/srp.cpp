#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
// Domain Class
// Solution Class -> Technology
using namespace std;

template<class E>
struct Repository { // interface
    virtual void save() = 0;
};

struct Journal { // domain class
    string title;
    vector<string> entries;

    explicit Journal(const string &title) : title{title} {
    }

    void add(const string &entry);

    void save() {
        repository->save();
    }

    void setter(shared_ptr<Repository<Journal>> repository) {
        this->repository = repository;
    }

private:
    shared_ptr<Repository<Journal>> repository;
};

void Journal::add(const string &entry) {
    static int count = 1;
    entries.push_back(to_string(count++) + ": " + entry);
}

struct JournalFileRepository : public Repository<Journal> {

    void save() override {
        ofstream ofs(filename);
        for (auto &s: journal.entries)
            ofs << s << endl;
    }

    JournalFileRepository(Journal &journal, const string &filename) : journal(journal), filename(filename) {}

private:
    Journal &journal;
    const string &filename;
};

struct JournalMongoRepository : public Repository<Journal> {

    void save() override {
        cout << "saving the journal in mongodb" << endl;
    }

    JournalMongoRepository(Journal &journal, const string &filename) : journal(journal), url(url) {}

private:
    Journal &journal;
    const string &url;
};

struct JournalS3Repository : public Repository<Journal> {

    void save() override {
        cout << "saving the journal in s3" << endl;
    }

    JournalS3Repository(Journal &journal, const string &filename) : journal(journal), url(url) {}

private:
    Journal &journal;
    const string &url;
};

int main() {
    Journal journal{"Dear Diary"};
    journal.add("I ate a bug");
    journal.add("I cried today");
    journal.add("I have learned single responsibility principle.");

    JournalS3Repository repository{journal, string("s3 http url")};
    journal.setter(make_shared<JournalS3Repository>(repository));
    journal.save();

    return 0;
}