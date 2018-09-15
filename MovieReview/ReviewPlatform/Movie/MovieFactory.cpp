//
//  MovieFactory.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include "Movie.cpp"

class MovieFactory{
    int getId(){
        static int _id = 0;
        return _id++;
    }
public:
    Movie* createMovie(string name, int year, Genere g){
        return new Movie(getId(), name, g, year);
    }
};
