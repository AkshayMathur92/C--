//
//  main.cpp
//  MovieReview
//
//  Created by Akshay on 11/08/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include <iostream>
#include "ReviewController.cpp"
#include "OnThreeUpgradePolicy.cpp"
#include "defaultRaitingProcessor.cpp"

int main(int argc, const char * argv[]) {
    IUserUpgradePolicy* _policy = new OnThreeUpgradePolicy();
    IRatingProcessor * _raitingProcessor = new DefaultRaitingProcessor();
    ReviewController _review_app((shared_ptr<IUserUpgradePolicy>(_policy)), shared_ptr<IRatingProcessor>(_raitingProcessor));
    
    _review_app.AddUser("SRK");
    _review_app.AddUser("Salman");
    _review_app.AddUser("Deepika");
    
    _review_app.AddMovie("Don", 2006, Comedy);
    _review_app.AddMovie("Tiger", 2008, Drama);
    _review_app.AddMovie("Padmavati", 2006, Comedy);
    _review_app.AddMovie("LunchBox", 2019, Drama);
    _review_app.AddMovie("Guru", 2006, Drama);
    _review_app.AddMovie("Metro", 2006, Romance);
    
    _review_app.add_review("SRK", "Don" , 2);
    _review_app.add_review("SRK", "Padmavati", 8);
    _review_app.add_review("Salman", "Don" , 5);
    _review_app.add_review("Deepika", "Don" , 9);
    _review_app.add_review("Deepika", "Guru" , 6);
    _review_app.add_review("SRK", "Don" , 10);
    _review_app.add_review("Deepika", "LunchBox" , 5);
    _review_app.add_review("SRK", "Tiger" , 5);
    _review_app.add_review("SRK", "Metro" , 7);
    
    auto top_movie_by_viewer_2006 = _review_app.topinYearByViewer(2006);
    cout << "Top in year by Viewer " << top_movie_by_viewer_2006.first.getName() << " " << top_movie_by_viewer_2006.first.getYear() << " " << top_movie_by_viewer_2006.second <<endl;
    
    auto top_movie_by_critic_2006 = _review_app.topinYearByCritic(2006);
    cout << "Top in year by Critic " << top_movie_by_critic_2006.first.getName() << " " << top_movie_by_critic_2006.first.getYear() << " " << top_movie_by_critic_2006.second <<endl;
    
    auto top_movie_by_viewer_drama = _review_app.topinGenreByViewer(Drama);
    cout << "Top in genre by Viewer" << top_movie_by_viewer_drama.first.getName() << " " << top_movie_by_viewer_drama.first.getYear() << " " << top_movie_by_viewer_drama.second <<endl;
    
    auto top_movie_by_avg_2006 = _review_app.topinYearByAverageViewer(2006);
    cout << "Top in year by Viewer " << top_movie_by_avg_2006.first.getName() << " " << top_movie_by_avg_2006.first.getYear() << " " << top_movie_by_avg_2006.second <<endl;
    
//    auto top2in2006ByAvgViewer = _review_app.topNinYearByAverageViewer(2006, 2);
//    for(pair<Movie,float> &a : top2in2006ByAvgViewer){
//        cout << "Movie name" + a.first.getName() << endl;
//    }
}
