//
//  OnThreeUpgradePolicy.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include <stdio.h>
#include "IUserUpgradePolicy.hpp"
class OnThreeUpgradePolicy : public IUserUpgradePolicy {
    
public:
    virtual bool shouldUpgradeUser(User u) override{
        if(u.get_raitings_submitted() >= 3 && u.gettype() != Critic){
            return true;
        }
        else{
            return false;
        }
    }
    
    virtual UserType getUpgradeType(User u) override{
        if(shouldUpgradeUser(u)){
            //complex logic for user here
            if(u.gettype() == Viewer){
                return Critic;
            }
            else{
                throw std::invalid_argument("cannot upgrade critic");  // more thought required here to throw or to add userType.None to enum
            }
        }
        else{
            throw std::invalid_argument("not eligible for upgrade");
        }
    }
    
};
