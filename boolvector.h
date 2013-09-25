#ifndef BOOLVECTOR_H
#define BOOLVECTOR_H
typedef bool Data;

class BoolVector
{
    public:
        BoolVector();
        BoolVector(int x);
        //BoolVector(int x, Data *ar);
        ~BoolVector();
        BoolVector(const BoolVector& other);
        BoolVector &operator=(const BoolVector &other);
        int get_n(){return n;}
        Data *getVector(){return array;}
        void displayVector();
        void inputVector();
        BoolVector conunction(BoolVector A);
        BoolVector disunction(BoolVector A);
        BoolVector notVector();
        int numberOf(Data x);
        BoolVector(BoolVector& other);
        BoolVector& operator=(BoolVector& other);
    private:
        int n;
        Data *array;
};

#endif // BOOLVECTOR_H
