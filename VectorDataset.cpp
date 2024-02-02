#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

#include "VectorDataset.h"


VectorDataset:: VectorDataset() {}
VectorDataset:: VectorDataset(const vector<DataVector>& inputdata): dataset(inputdata) {}
VectorDataset:: ~VectorDataset() {}

DataVector VectorDataset:: getDataVector(int index)const {
        return dataset[index];
}

int VectorDataset::getSize() const{
    return dataset.size();
}

VectorDataset VectorDataset::readDataset(const string& filepath){
    VectorDataset final;
    ifstream file(filepath);

    if(!file.is_open()){
        cerr<<"Error: File not found\n";
        return final; 
    }
    string line;
    getline(file,line);
    while(getline(file,line)){
        istringstream iss(line);
        vector<double>values;
        double val;
        char comma;
        while(iss>>val){
            values.push_back(val);
            if(iss>>comma && comma!=','){
                std::cerr << "Error: Unexpected character after value in line: " << line << std::endl;
                return final;
            }
        }
        DataVector temp;
        temp=values;
        DataVector dataVector(temp);
        final.dataset.push_back(dataVector);
    }
    file.close();
    return final;
}


