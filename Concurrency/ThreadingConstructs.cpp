//
//  Threading.cpp
//  Learning
//
//  Created by Akshay on 05/05/18.
//  Copyright © 2018 Akshay. All rights reserved.
//

#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <chrono>
#define NOW std::chrono::high_resolution_clock::now()
#define SLEEPTIME 10
using namespace std;

int square(int i){
//    cout << " Running on " << this_thread::get_id() << "this thread ." << endl;
//    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(SLEEPTIME));
//    cout << i << endl;
    return i*i;
}
void square_with_atomic(int i, atomic<int> &accum){
//    cout << " Running on " << this_thread::get_id() << "this thread ." << endl;
//    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(SLEEPTIME));
//    cout << i << endl;
    accum += i * i;
}
void square_with_mutex(int i, int& accum){
    mutex accm_mutex;
    this_thread::sleep_for(chrono::milliseconds(SLEEPTIME));
    accm_mutex.lock();
//    cout << " Running on " << this_thread::get_id() << "this thread ." << endl;
//    cout.flush();
//    cout << i << endl;
    accum += i * i;
    accm_mutex.unlock();
}

int calculate_with_mutex(){
    vector<thread> thread_pool ;
    int accum = 0;
    for (int i = 1; i <= 20; i++) {
        thread_pool.push_back(thread(&square_with_mutex, i, ref(accum)));
    }
    for (auto& th : thread_pool) {
        th.join();
    }
    return accum;
}
int calculate_with_atomic(){
    vector<thread> thread_pool ;
    atomic_int accum;
    for (int i = 1; i <= 20; i++) {
        thread_pool.push_back(thread(&square_with_atomic, i, ref(accum)));
    }
    for (auto& th : thread_pool) {
        th.join();
    }
    return accum.load();
}
int calculate_with_async(){
    vector<future<int>> futures;
    for (int i = 1; i <= 20; i++) {
        futures.push_back(async(launch::async,&square, i));
    }
    int accum = 0;
    for(auto &f : futures){
        accum+= f.get();
    }
    return accum;
}
int calculate_with_singlethread(){
    int acc = 0 ;
    for(int i = 1; i <= 20; i ++){
        acc += square(i);
    }
    return acc;
}
int main()
{
    auto start = NOW;
    for(int i = 0; i < 100; i ++){
        calculate_with_mutex();
    }
    auto end = NOW;
    
    cout << "Time taken with mutexes : " << (end - start).count() << endl;
    start = NOW;
    for(int i = 0; i < 100; i ++){
        calculate_with_atomic();
    }
    end = NOW;
    cout << "Time taken with atomics : " << (end - start).count() << endl;
    
    start = NOW;
    for(int i = 0; i < 100; i ++){
        calculate_with_async();
    }
    end = NOW;
    cout << "Time taken with   Tasks : " << (end - start).count() << endl;
    
    start = NOW;
    for(int i = 0; i < 100; i ++){
        calculate_with_singlethread();
    }
    end = NOW;
    cout << "Time taken with 1thread : " << (end - start).count() << endl;
    
    return 0;
}
