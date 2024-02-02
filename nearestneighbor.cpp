#include <iostream>
#include "VectorDataset.h"

bool cmp(const pair<int,double>& a,const pair<int,double>& b){
    return a.second < b.second;
}
VectorDataset knearestneighbor(const VectorDataset& traindata,  DataVector& testvector,int k){
    vector<pair<int,double> >distances;
    for(int i=0;i<traindata.getSize();i++){
        double distance=testvector.dist(traindata.getDataVector(i));
        distances.push_back(make_pair(i,distance));
    }
    sort(distances.begin(),distances.end(),cmp);
    VectorDataset neighbors;
    for(int i=0;i<min(k,traindata.getSize());i++){
        cout<<"Index:"<<distances[i].first<<endl;
        neighbors.dataset.push_back(traindata.getDataVector(distances[i].first));
    }
    return neighbors;
}

int main(){
    string testfile="fmnist-test.csv";
    VectorDataset testdata=VectorDataset::readDataset(testfile);
    cout << "Test Dataset Size: " << testdata.getSize() << "\n";
    DataVector testvector = testdata.getDataVector(0);
    testvector.print();
    cout<<endl;
    string trainfile="fmnist-train.csv";
    VectorDataset traindata=VectorDataset::readDataset(trainfile);
    auto start_time = std::chrono::high_resolution_clock::now();
    VectorDataset result=knearestneighbor(traindata,testvector,5);
    auto end_time = std::chrono::high_resolution_clock::now();
    int n=result.getSize();
    for(int i=0;i<n;i++){
        DataVector t=result.getDataVector(i);
        t.print();
        cout<<endl;
    }
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double> >(end_time - start_time);
    cout<<"TIME TAKEN="<<duration.count()<<" seconds"<<endl;
    
    return 0;

}