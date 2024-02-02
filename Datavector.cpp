#include "Datavector.h"
#include <bits/stdc++.h>

DataVector::DataVector(int dimension) {
    setDimension(dimension);
}

void DataVector::setDimension(int dimension) {
    v.clear();
    v.resize(dimension, 0.0);
}

DataVector::~DataVector(){

}

DataVector::DataVector(const DataVector& other){
    v=other.v;
}

DataVector& DataVector::operator=(const DataVector &other){
    if(this!=&other){
        v=other.v;
    }
    return *this;
}

DataVector DataVector::operator+(const DataVector &other){
    DataVector sum(v.size());
    for(int i=0;i<v.size();i++){
        sum.v[i]=v[i]+other.v[i];
    }
    return sum;
}

DataVector DataVector::operator-(const DataVector &other){
    DataVector diff(v.size());
    for(int i=0;i<v.size();i++){
        diff.v[i]=v[i]-other.v[i];
    }
    return diff;
}

double DataVector::operator*(const DataVector& other){
    double dotProduct=0.0;
    for(int i=0;i<v.size();i++){
        dotProduct+=v[i]*other.v[i];
    }
    return dotProduct;
}

DataVector& DataVector::operator=(const vector<double>& vec){
    v=vec;
    return *this;
}

double DataVector::norm(){
    return sqrt((*this)*(*this));
}

double DataVector::dist(const DataVector& other){
    DataVector diff= *this-other;
    return diff.norm();
}
void DataVector::print(){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



// int main(){
//     DataVector a(5);
//     DataVector b(5);
//     a={1.9,2.3,1.3,3.2,1.1};
//     double moda=a.norm();
//     cout<<moda<<endl;
//     b={2.0,1.2,1.4,5.7,2.1};
//     double distance=a.dist(b);
//     cout<<distance<<endl;
//     a=b;
//     a.print();
//     DataVector sum=a+b;
//     double product=a*b;
//     sum.print();
//     cout<<product<<endl;
//     return 0;
// }

