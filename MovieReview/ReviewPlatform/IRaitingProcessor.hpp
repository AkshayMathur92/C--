//
//  RaitingProcessor.hpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#ifndef RaitingProcessor_hpp
#define RaitingProcessor_hpp
#include <vector>
#include "User/UserType.cpp"
using namespace std;

class IRatingProcessor{
public: 
    virtual int getRaitingByCritic(vector<pair<int,UserType>>) = 0;
    virtual int getRaitingByViewer(vector<pair<int,UserType>>) = 0;
    virtual int getTotalRating(vector<pair<int,UserType>>) = 0;
    virtual float getAverageRaitingByViewer(vector<pair<int,UserType>>) = 0;
    virtual float getAverageRaitingByCritic(vector<pair<int,UserType>>) = 0;
};

#endif /* RaitingProcessor_hpp */
