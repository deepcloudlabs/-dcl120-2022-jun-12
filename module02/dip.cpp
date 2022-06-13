// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions/interface.
// B. Abstractions should not depend on details.
//    Details should depend on abstractions.
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship {
    parent,
    child,
    sibling
};

struct Person {
    string name;
};

struct RelationshipBrowser { // abstract class -> interface
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

struct StandardRelationshipBrowser : public RelationshipBrowser // low-level
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child) {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override {
        vector<Person> result;
        for (auto&&[first, rel, second] : relations) {
            if (first.name == name && rel == Relationship::parent) {
                result.push_back(second);
            }
        }
        return result;
    }
};
struct Research // high-level
{
    RelationshipBrowser &relationshipBrowser; // DIP

    Research(RelationshipBrowser &relationshipBrowser) : relationshipBrowser(relationshipBrowser) {}

    void find_all_children_of(const string &name){
        for (auto &child : relationshipBrowser.find_all_children_of(name)) {
            cout << name << " has a child called " << child.name << endl;
        }
    }
};

int main() {
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    StandardRelationshipBrowser standardRelationshipBrowser;
    standardRelationshipBrowser.add_parent_and_child(parent, child1);
    standardRelationshipBrowser.add_parent_and_child(parent, child2);

    Research research(standardRelationshipBrowser); // DI by constructor
    research.find_all_children_of("John");

    return 0;
}