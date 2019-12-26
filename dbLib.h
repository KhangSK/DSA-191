/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct City {
    string id;
    string name;
};

struct Line {
    string id;
    string city_id;
    string name;
};

struct Station_line {
    string id;
    string station_id;
    string line_id;
    string city_id;
};

struct Station {
    string id;
    string name;
    string geometry;
    string city_id;
};

struct Track {
    string id;
    string geometry;
    string city_id;
};

struct Track_line {
    string id;
    string line_id;
    string city_id;

};

class TDataset {
    public:
    L1List<City> city;
    L1List<Line> line;
    L1List<Station_line> sline;
    L1List<Station> station;
    L1List<Track> track;
    L1List<Track_line> trackl;
    public:
    ~TDataset(){
        city.clean();
        line.clean();
        sline.clean();
        station.clean();
        track.clean();
        trackl.clean();
    }
};

// Please add more or modify as needed

void LoadData(void* &);
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
