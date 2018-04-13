//
//  main.cpp
//  SBPNN
//
//  Created by Jerry Zhang on 29/03/2018.
//  Copyright © 2018 Jerry Zhang. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include "SBPNN.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    const int input_n = 748;
    const int hidden_n =64;
    const int out_n = 10;
    
    double err = 0;
    double temp;
    int i;
    double input[input_n];
    double out[out_n];
    SBPNN *net = createBPNN(input_n, hidden_n, out_n);
    char filename[100] = "sample_data";
    //cin>>filename;
    ifstream file(filename);
    while(!file.is_open()) {
        cerr<<"Opening file failure! Enter new file name";
        cin>>filename;
        file.open(filename);
    }
    initSeed((int)time(NULL));
    while (!file.eof()) {
        for(i = 0;i < input_n;i++)
            cin>>input[i];
        for(i = 0;i < out_n;i++)
            cin>>out[i];
        train(net, input, input_n, out, out_n, &err, &temp);
        std::cout<<"traning success."<<endl;
        
    }
    char save_filename[100] ="resultdata";
    saveBPNN(net, save_filename);
    cout<<"Train completed."<<endl;
    
    
    return 0;
}
