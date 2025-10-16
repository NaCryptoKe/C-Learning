#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> x (new int(34));
    unique_ptr<int> y = make_unique<int>(45);


    shared_ptr<int> z = make_shared<int>(56);

    weak_ptr<int> a = z;

    return 0;
}