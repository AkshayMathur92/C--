//
//  UserRepo.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include <unordered_map>
#include <vector>
#include <iostream>
#include "UserFactory.cpp"
using namespace std;

class UserRepo{
    vector<shared_ptr<User>> _user_list;
    unordered_map<string, weak_ptr<User>> name_to_user;
    UserFactory _userFactory;
public:
    void addUser(string name){
        //create unique user
        auto _user = shared_ptr<User>(_userFactory.createUser(name));
        _user_list.push_back(_user);
        // Add to user repo
        if(name_to_user.find(name) == name_to_user.end()){
            name_to_user[name] = weak_ptr<User>(_user);
        }
        else{
            throw std::invalid_argument("User already present");
        }
    }
    
     User getUser(string name){
        if(name_to_user.find(name) == name_to_user.end())
            throw invalid_argument("User is not present");
        else{
            return User(*(name_to_user[name].lock()));
        }
    }
    
    weak_ptr<const User> getRefrenceUser(string name){
        if(name_to_user.find(name) == name_to_user.end())
            throw invalid_argument("User is not present");
        else{
            return name_to_user[name];
        }
    }
    
    void upgradeUser(string name, UserType t){
        if(name_to_user.find(name) == name_to_user.end())
            throw invalid_argument("User is not present");
        else{
            name_to_user[name].lock() -> _type = t;
            std::cout << "User " + name + "upgraded " << endl;
        }
    }
    
    void incrementRaiting(string name, string movie_name){
        if(name_to_user.find(name) == name_to_user.end())
            throw invalid_argument("User is not present");
        else{
            name_to_user[name].lock() -> increment_raiting(movie_name);
        }
    }
};
