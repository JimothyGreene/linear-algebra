class Vector {
    private:
        int length;
        int* values;
    public:
        Vector(int length);
        Vector(int vals[], int length);
        void display(void);
};
