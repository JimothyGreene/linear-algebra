#include "vector.h"

int main(void) {
    int vals[] = {1,2,3,4,5};
    int len = 5;
    Vector vector(vals, len);
    vector.display();
    return 0;
}