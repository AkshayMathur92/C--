//
//  Movie.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//
#include <string>
#include <vector>
#include "Genere.cpp"
#include "../User/UserType.cpp"

using namespace std;

class Movie{
    int _id;
    string _name;
    Genere _genere;
    int _year;
    vector<pair<int, UserType>> _ratings;
public:
    Movie(int i, string s, Genere g, int y): _id(i), _name(s), _genere(g), _year(y){}
    int getId(){
        return _id;
    }
    string getName(){
        return _name;
    }
    Genere getGenere(){
        return _genere;
    }
    int getYear(){
        return _year;
    }
    void add_raiting(int rating, UserType t){
        _ratings.push_back(make_pair(rating, t));
    }
    vector<pair<int, UserType>> getRatings(){
        return _ratings;
    }
    void remove_last_raiting(){
        _ratings.pop_back();
    }
    
};
