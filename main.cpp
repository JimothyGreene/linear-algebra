#include "vector.h"

int main(void) {
    float vals[] = {1,2.5,3,4,5};
    int len = 5;
    Vector vector1(vals, len);
    vector1.display();
    Vector vector2(10);
    vector2.display();
    Vector sumVector = vector1.addVector(vector2);
    sumVector.display();
    vector1.concatenate(vector2);
    vector1.display();
    vector2.addScalar(1.3);
    vector2.display();
    return 0;
}