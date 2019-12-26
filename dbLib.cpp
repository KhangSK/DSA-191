/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */

void LoadData(void* &pData) {
    TDataset* data = new TDataset();

    ifstream f("cities.csv");
	string str;
    getline(f, str);
    while(getline(f, str)) {
        City cities;
        stringstream ss;
        ss << (char *)str.data();
		char a[1000];
		ss.getline(a , 1000, ',');
		string s(a);
        cities.id = s;
        string x;
		stringstream ss1;
		ss1 << (char *)str.data();
		ss1.getline(a , 1000, ',');
        ss1 >> x;
        if (x[0] == '"') {
            ss.getline(a , 1000, '"');
			ss.getline(a , 1000, '"');
		}
        else 
            ss.getline(a , 1000, ',');
		s = a;
        while (s[0] == ' ') s.erase(0, 1);
        while (s[s.length() - 1] == ' ') s.pop_back();
        cities.name = s;
        data->city.push_back(cities);
    }
    f.close();
    
    ifstream f1("lines.csv");
    getline(f1, str);
    while(getline(f1, str)) {
        Line _line;
        stringstream ss;
        ss << (char *)str.data();
		char a[1000];
		ss.getline(a , 1000, ',');
		string s(a);
        _line.id = s;
        ss.getline(a , 1000, ',');
		s = a;
        _line.city_id = s;
        string x;
		stringstream ss1;
		ss1 << (char *)str.data();
		ss1.getline(a , 1000, ',');
		ss1.getline(a , 1000, ',');
        ss1 >> x;
        if (x[0] == '"') {
            ss.getline(a , 1000, '"');
			ss.getline(a , 1000, '"');
		 	s = a;
			ss.getline(a , 1000, ',');
		}
        else {
            ss.getline(a , 1000, ',');
            s = a;
        }
        while (s[0] == ' ') s.erase(0, 1);
        while (s[s.length() - 1] == ' ') s.pop_back();
        _line.name = s;
        data->line.push_back(_line);
    }
    f1.close();

    ifstream f2("station_lines.csv");
    getline(f2, str);
    while(getline(f2, str)) {
        Station_line _sline;
        stringstream ss;
        ss << (char *)str.data();
		char a[1000];
		ss.getline(a , 1000, ',');
		string s(a);
        _sline.id = s;
        ss.getline(a , 1000, ',');
		s = a;
        _sline.station_id = s;
        ss.getline(a , 1000, ',');
		s = a;
        _sline.line_id = s;
        ss.getline(a , 1000, ',');
		s = a;
        _sline.city_id = s;
        data->sline.push_back(_sline);
    }
    f2.close();

    ifstream f3("stations.csv");
    getline(f3, str);
    while(getline(f3, str)) {
        Station _station;
        stringstream ss;
        ss << (char *)str.data();
		char a[1000];
		ss.getline(a , 1000, ',');
		string s(a);
        _station.id = s;
        string x;
		stringstream ss1;
		ss1 << (char *)str.data();
		ss1.getline(a , 1000, ',');
        ss1 >> x;
        if (x[0] == '"') {
            ss.getline(a , 1000, '"');
            ss.getline(a , 1000, '"');
		 	s = a;
			ss.getline(a , 1000, ',');
		}
        else {
            ss.getline(a , 1000, ',');
            s = a;
        }
        while (s[0] == ' ') s.erase(0, 1);
        while (s[s.length() - 1] == ' ') s.pop_back();
        _station.name = s;
        ss.getline(a , 1000, ',');
		s = a;
        _station.geometry = s;
        ss.getline(a , 1000, ',');
        ss.getline(a , 1000, ',');
        ss.getline(a , 1000, ',');
        ss.getline(a , 1000, ',');
		s = a;
        _station.city_id = s;
        data->station.push_back(_station);
    }
    f3.close();

    ifstream f4("tracks.csv");
    getline(f4, str);
    while(getline(f4, str)) {
        Track _track;
        stringstream ss;
        ss << (char *)str.data();
		char a[10000];
		ss.getline(a , 1000, ',');
		string s(a);
        _track.id = s;
        ss.getline(a, 1000, '"');
        ss.getline(a, 10000, '"');
        s = a;
        _track.geometry = s;
        ss.getline(a, 1000, ',');
        ss.getline(a, 1000, ',');
        ss.getline(a, 1000, ',');
        ss.getline(a, 1000, ',');
        ss.getline(a, 1000, ',');
        ss.getline(a, 1000, ',');
        s = a;
        _track.city_id = s;
        data->track.push_back(_track);
    }
    f4.close();

    ifstream f5("track_lines.csv");
    getline(f5, str);
    while(getline(f5, str)) {
        Track_line _trackl;
        stringstream ss;
        ss << (char *)str.data();
		char a[1000];
		ss.getline(a , 1000, ',');
		string s(a);
        _trackl.id = s;
        ss.getline(a , 1000, ',');
        ss.getline(a , 1000, ',');
		s = a;
        _trackl.line_id = s;
        ss.getline(a , 1000, ',');
        ss.getline(a , 1000, ',');
        ss.getline(a, 1000, ',');
        s = a;
        _trackl.city_id = s;
        data->trackl.push_back(_trackl);
    }
    f5.close();

    pData = data;

}; 
void ReleaseData(void* &pData) {
    TDataset * pdata1 = (TDataset *)pData;
    delete pdata1;
    pdata1 = nullptr;
};
