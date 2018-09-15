//
//  MovieRepo.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include <unordered_map>
#include <vector>
#include "MovieFactory.cpp"

#define CURRENT_YEAR 2018

using namespace std;

class MovieRepo{
    vector<shared_ptr<Movie>> _movie_list;
    unordered_map<string, weak_ptr<Movie>> name_to_movie;
    unordered_map<int, weak_ptr<Movie>> id_to_movie;
    unordered_map<int, vector<weak_ptr<Movie>>> year_to_movie;
    unordered_map<int, vector<weak_ptr<Movie>>> genere_to_movie;
    MovieFactory _movieFactory;
public:
    void addMovie(string name, int year, Genere g){
    
        // find duplicate to movie repo
        if(name_to_movie.find(name) != name_to_movie.end()){
            throw std::invalid_argument("Movie already present");
        }
        //create unique movie
        auto _movie = shared_ptr<Movie>(_movieFactory.createMovie(name, year, g));
        
        //add to movie list
        _movie_list.push_back(_movie);
        name_to_movie[name] = weak_ptr<Movie>(_movie);
        id_to_movie[_movie -> getId()] = weak_ptr<Movie>(_movie);
        
        //add to year indexing
        if(year_to_movie.find(year) == year_to_movie.end()){
            year_to_movie[year] = vector<weak_ptr<Movie>>(1,weak_ptr<Movie>(_movie));
        }
        else{
            year_to_movie[year].push_back(weak_ptr<Movie>(_movie));
        }
        
        //add to genere indexing
        if(genere_to_movie.find(g) == genere_to_movie.end()){
            genere_to_movie[g] = vector<weak_ptr<Movie>>(1,weak_ptr<Movie>(_movie));
        }
        else{
            genere_to_movie[g].push_back(weak_ptr<Movie>(_movie));
        }
    }
    
    Movie getMovieByName(string name){
        if(name_to_movie.find(name) == name_to_movie.end()){
            throw std::invalid_argument("No movie by this name found");
        }
        else{
            //TODO be safe check index first
            return Movie(*name_to_movie[name].lock());
        }
    }
    
    void add_rating(string movie_name, int rating, UserType user_type){
        if(name_to_movie.find(movie_name) == name_to_movie.end()){
            throw std::invalid_argument("No movie by this name found");
        }
        else{
            //TODO be safe check index first
            if(name_to_movie[movie_name].lock() -> getYear() > CURRENT_YEAR){
                throw std::invalid_argument("Movie " + movie_name + "not release yet wait till " + to_string(name_to_movie[movie_name].lock() -> getYear()));
            }
            name_to_movie[movie_name].lock() -> add_raiting(rating, user_type);
        }
    }
    //TODO : update / remove / delete movies
    
    vector<pair<int,UserType>> getRaitingforMovie(string movie){
        return name_to_movie[movie].lock() -> getRatings();
    }
    
    vector<Movie> getAllMovies(){
        vector<Movie> result;
        for(auto ptr : _movie_list){
            result.push_back(Movie(*ptr));
        }
        return result;
    }
    
    vector<Movie> getAllMoviesForYear(int year){
        if(year_to_movie.find(year) == year_to_movie.end()){
            throw std::invalid_argument("No movies in year " + to_string(year));
        }
        vector<Movie> result;
        for(auto ptr : year_to_movie[year]){
            result.push_back(Movie(*(ptr.lock())));
        }
        return result;
    }
    
    vector<Movie> getAllMoviesForGenre(Genere genre){
        if(genere_to_movie.find(genre) == genere_to_movie.end()){
            throw std::invalid_argument("No movies for genre ");
        }
        vector<Movie> result;
        for(auto ptr : genere_to_movie[genre]){
            result.push_back(Movie(*(ptr.lock())));
        }
        return result;
    }
    
    void remove_last_raiting(string movie_name){
        (*name_to_movie[movie_name].lock()).remove_last_raiting();
    }
            
};

