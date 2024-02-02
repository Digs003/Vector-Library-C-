#include <iostream>
#include <vector>
using namespace std;
class DataVector {
    vector<double> v;
    public:
    DataVector(int dimension=0);
    ~DataVector();
    DataVector(const DataVector& other);
    DataVector & operator=(const DataVector &other);
    DataVector& operator=(const vector<double>& vec);
    void setDimension(int dimension=0);
    DataVector operator+(const DataVector &other);
    DataVector operator-(const DataVector &other);
    double operator*(const DataVector &other);
    double norm();
    double dist(const DataVector& other);
    void print();
};
