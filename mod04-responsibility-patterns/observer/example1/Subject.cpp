#include "Subject.h"
#include <algorithm>

using namespace std;

void Subject::attach(Shop *shop) {
    list.push_back(shop);
}

void Subject::detach(Shop *shop) {    
    list.erase(std::remove(list.begin(), list.end(), shop), list.end());    
}

void Subject::notify(float price) {
    for(vector<Shop*>::const_iterator iter = list.begin(); iter != list.end(); ++iter) {
        if(*iter != 0) {
            (*iter)->update(price);
        }
    }
}
