#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Animal : private T {
public:
    void talk() {
        T::talkImplement();
    }
};

class SayMiao {
public:
    void talkImplement() {
        cout << "Miao.\n";
    }
};

class SayHW {
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
    Animal<SayMiao> am;
    Animal<SayHW> ah;

    LetAnimalTalk(am);
    LetAnimalTalk(ah);

    vector<Animal<SayMiao>> va;
    va.push_back(am);
    // va.push_back(ah);

    return 0;
}
