//
//  ReviewController.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//
#include "User/UserRepo.cpp"
#include "Movie/MovieRepo.cpp"
#include "IUserUpgradePolicy.hpp"
#include "IRaitingProcessor.hpp"
#include <iostream>

class ReviewController{
    
    MovieRepo _movieRepo;
    UserRepo _userRepo;
    shared_ptr<IUserUpgradePolicy> _upgradePolicy;
    shared_ptr<IRatingProcessor> _raitingProcessor;
    
public:
    ReviewController() = delete;
    ReviewController(shared_ptr<IUserUpgradePolicy> up, shared_ptr<IRatingProcessor> rp):_upgradePolicy(up), _raitingProcessor(rp){}
    
    void AddMovie(string name, int year, Genere g){
        try{
            _movieRepo.addMovie(name, year, g);
        }
        catch(exception &e){
            cout << e.what() << endl;
        }
    }
    
    void AddUser(string name){
        try{
            _userRepo.addUser(name);
        }
        catch(exception &e){
            cout << e.what() << endl;
        }
    }
    
    void add_review(string user_name, string movie_name, int rating ){
        //TODO: validate raitings
        try{
            auto user = _userRepo.getRefrenceUser(user_name).lock();
//            auto user = _userRepo.getUser(user_name);
            //assuming here the user is unique else there is some more handling required here.

            //_movieRepo.add_rating(movie_name, rating, user.gettype());
            _movieRepo.add_rating(movie_name, rating, user -> gettype());
            try{
//                _userRepo.incrementRaiting(user.getName(), movie_name);
                _userRepo.incrementRaiting(user -> getName(), movie_name);

            }catch(exception &e){
                _movieRepo.remove_last_raiting(movie_name);
                throw;
            }
//            user = _userRepo.getUser(user_name); // if use get reference then this would not be required.
            //TODO: the above two functions should happen as a transaction, Commit Rollback handler should be written here or create IsSafe functions for above two functions
            if(_upgradePolicy->shouldUpgradeUser(*user)){
                _userRepo.upgradeUser((*user).getName(), _upgradePolicy->getUpgradeType(*user));
            }
        }
        catch (exception &e){
            cout << e.what() << endl;
        }
    }
    
    pair<Movie,int> topByTotalScoreViewer(vector<Movie> movies){
        //vector<Movie> movies = _movieRepo.getAllMovies();
        vector<int> ratings;
        for(Movie &m : movies){
            ratings.push_back(_raitingProcessor -> getRaitingByViewer(m.getRatings()));
        }
        auto max_itr = max_element(ratings.begin(), ratings.end());
        auto movie_index = max_itr - ratings.begin();
        return make_pair(movies[movie_index], *max_itr);
    }
    
    pair<Movie,int> topByTotalScoreCritic(vector<Movie> movies){
        //vector<Movie> movies = _movieRepo.getAllMovies();
        vector<int> ratings;
        for(Movie &m : movies){
            ratings.push_back(_raitingProcessor -> getRaitingByCritic(m.getRatings()));
        }
        auto max_itr = max_element(ratings.begin(), ratings.end());
        auto movie_index = max_itr - ratings.begin();
        return make_pair(movies[movie_index], *max_itr);
    }
    
    pair<Movie,float> topByAverageScoreViewer(vector<Movie> movies){
        //vector<Movie> movies = _movieRepo.getAllMovies();
        vector<float> ratings;
        for(Movie &m : movies){
            ratings.push_back(_raitingProcessor -> getAverageRaitingByViewer(m.getRatings()));
        }
        auto max_itr = max_element(ratings.begin(), ratings.end());
        auto movie_index = max_itr - ratings.begin();
        return make_pair(movies[movie_index], *max_itr);
    }
    
    pair<Movie,int> topinYearByViewer(int year){
        vector<Movie> movies;
        vector<int> ratings;
        try{
            movies = _movieRepo.getAllMoviesForYear(year);
        }catch(exception &ex){
            cout << ex.what() << endl;
        }
        return topByTotalScoreViewer(movies);
    }
    
    pair<Movie, int> topinYearByCritic(int year){
        vector<Movie> movies;
        vector<int> ratings;
        try{
            movies = _movieRepo.getAllMoviesForYear(year);
        }catch(exception &ex){
            cout << ex.what() << endl;
        }
        return topByTotalScoreCritic(movies);
    }
    
    pair<Movie,int> topinGenreByViewer(Genere genre){
        vector<Movie> movies;
        vector<int> ratings;
        try{
            movies = _movieRepo.getAllMoviesForGenre(genre);
        }catch(exception &ex){
            cout << ex.what() << endl;
        }
        return topByTotalScoreViewer(movies);
    }
    
    pair<Movie,int> topinGenreByCritic(Genere genre){
        vector<Movie> movies;
        vector<int> ratings;
        try{
            movies = _movieRepo.getAllMoviesForGenre(genre);
        }catch(exception &ex){
            cout << ex.what() << endl;
        }
        return topByTotalScoreCritic(movies);
    }
    
    pair<Movie,float> topinYearByAverageViewer(int year){
        vector<Movie> movies;
        vector<int> ratings;
        try{
            movies = _movieRepo.getAllMoviesForYear(year);
        }catch(exception &ex){
            cout << ex.what() << endl;
        }
        return topByAverageScoreViewer(movies);
    }
    
//    vector<pair<Movie,float>> topNinYearByAverageViewer(int year, int n){
//        vector<Movie> movies;
//        vector<float> ratings;
//        try{
//            movies = _movieRepo.getAllMoviesForYear(year);
//        }catch(exception &ex){
//            cout << ex.what() << endl;
//        }
//        for(Movie &m : movies){
//            ratings.push_back(_raitingProcessor -> getAverageRaitingByViewer(m.getRatings()));
//        }
//        vector<pair<Movie,float>> result;
//        for(int i = 0; i < movies.size(); i++){
//            result.push_back(make_pair(movies[i], ratings[i]));
//        }
//        sort(result.begin(),result.end(), [](pair<const Movie,float>&a, const pair<Movie,float> &b){
//            return a.second < b.second;
//        });
//        return vector<Movie,float> (result.begin(), result.begin() + n);
//    }
};
