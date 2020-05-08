#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Animal {
public:
    void talk() {
        static_cast<T *>(this)->talkImplement();
    }
};

class Cat : public Animal<Cat> {
public:
    void talkImplement() {
        cout << "Miao.\n";
    }
};

class Developer : public Animal<Developer> {
public:
    void talkImplement() {
        cout << "Hello, world.\n";
    }
};

template<typename T>
void LetAnimalTalk(Animal<T> & pa) {
    pa.talk();
}

int main()
{
    Developer pd;
    Cat pc;

    LetAnimalTalk(pd);
    LetAnimalTalk(pc);

    vector<Animal<Cat>> va;
    va.push_back(pc);
    // va.push_back(pd);

    return 0;
}
