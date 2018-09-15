//
//  UserRepo.cpp
//  MovieReview
//
//  Created by Akshay on 23/06/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include <unordered_map>
#include <vector>
#include "UserFactory.cpp"
using namespace std;

class UserRepo{
    unordered_map<string, vector<int>> user_to_id;
    unordered_map<int, User> id_to_user;
    UserFactory _userFactory;
public:
    void addUser(string name){
        //create unique user
        User _user = _userFactory.createUser(name);
        
        // Add to user repo
        if(user_to_id.find(name) == user_to_id.end()){
            user_to_id[name] = vector<int> (1, _user.getId());
        }
        else{
            user_to_id[name].push_back(_user.getId());
        }
        id_to_user[_user.getId()] = _user;
    }
    
    vector<User> getUser(string name){
        vector<User> _user_list;
        if(user_to_id.find(name) == user_to_id.end()){
            throw "User Not Found!! ";
        }
        else{
            for(const int i : user_to_id[name]){
                _user_list.push_back(id_to_user[i]);
            }
        }
        return _user_list;
    }
    
    void updateUser(int _id, UserType t){
        if(id_to_user.find(_id) == id_to_user.end()){
            throw "user Not found !!";
        }
        else{
            id_to_user[_id].setUserType(t);
        }
    }
};
