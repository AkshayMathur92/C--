//
//  RaitingProcessor.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include "IRaitingProcessor.hpp"

class DefaultRaitingProcessor : public IRatingProcessor {
    
//    const UserRepo &repo;
public:
    virtual int getRaitingByCritic(vector<pair<int,UserType>> raitings) override {
        int sum = 0;
        for(const pair<int,UserType> &p : raitings){
            if(p.second == Critic){
                sum += p.first;
            }
        }
        return sum;
    }
    virtual int getRaitingByViewer(vector<pair<int,UserType>> raitings) override {
        int sum = 0;
        for(const pair<int,UserType> &p : raitings){
            sum += p.first;
            if(p.second == Critic){
                sum += p.first;
            }
        }
        return sum;
    }
    virtual int getTotalRating(vector<pair<int,UserType>> ratings) override {
        int sum = 0;
        for(const pair<int,UserType> &p : ratings){
            sum += p.first;
        }
        return sum;
    }
    
    virtual float getAverageRaitingByViewer(vector<pair<int,UserType>> raitings) override {
        int sum = 0;
        int viewer = 0;
        for(const pair<int,UserType> &p : raitings){
            sum += p.first;
            viewer++;
            if(p.second == Critic){
                sum += p.first;
                viewer++;
            }
        }
        return sum / float(viewer);
    }
    virtual float getAverageRaitingByCritic(vector<pair<int,UserType>> raitings) override {
        return getRaitingByCritic(raitings) / float(raitings.size());
    }
    
};
