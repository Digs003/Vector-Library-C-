#include <vector>
#include "Datavector.h"
using namespace std;

class VectorDataset{
    public:
        vector<DataVector> dataset;
        VectorDataset();
        VectorDataset(const vector<DataVector>& inputdata);
        ~VectorDataset();
        DataVector getDataVector(int index) const;
        int getSize() const;
        static VectorDataset readDataset(const string& path);
};