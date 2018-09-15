//
//  UserUpgradePolicy.hpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#ifndef UserUpgradePolicy_hpp
#define UserUpgradePolicy_hpp

#include <stdio.h>
#include "User/User.cpp"

class IUserUpgradePolicy{
public: 
    virtual bool shouldUpgradeUser(User u) = 0;
    virtual UserType getUpgradeType(User u) = 0;
};
#endif /* UserUpgradePolicy_hpp */
