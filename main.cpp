#include "vector.h"

int main(void) {
    int vals[] = {1,2,3,4,5};
    int len = 5;
    Vector vector1(vals, len);
    vector1.display();
    Vector vector2(100);
    vector2.display();
    Vector sumVector = vector1.add(vector2);
    sumVector.display();
    return 0;
}