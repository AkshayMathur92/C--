//
//  User.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//
#ifndef USER_hpp
#define USER_hpp
#include "UserType.cpp"
#include <string>
#include <set>
using namespace std;

class User{
    public :
    string name;
    int _id;
    int ratings_submitted;
    set<string> movies_reviewed;
    UserType _type;
    User(int i, string s, UserType t):_id(i), name(s), _type(t), ratings_submitted(0){}
    User():_id(-1), name(""), ratings_submitted(0), _type(Viewer){}
//    User( User &u) : name(u.getName()), _id(u.getId()), ratings_submitted(u.get_raitings_submitted()), _type(gettype()){}
    
    string getName() const {
        return name;
    }
    const int getId() const {
        return _id;
    }
    void setUserType(UserType t) {
        _type = t;
    }
    int get_raitings_submitted() const {
        return ratings_submitted;
    }
    void increment_raiting(string movie){
        if(movies_reviewed.find(movie) == movies_reviewed.end()){
            movies_reviewed.insert(movie);
            ratings_submitted++;
        }
        else{
            throw invalid_argument("Movie "+ movie+" has already been reviewed by user " + name);
        }
    }
    UserType gettype() const {
        return _type;
    }
};
#endif
