//
//  UserFactory.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include "User.cpp"

class UserFactory{
    int getId(){
        static int _id = 0;
        return _id++;
    }
public:
    User* createUser(string name){
        return new User(getId(), name, Viewer);
    }
};
