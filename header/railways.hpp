#ifndef __RAILWAYS
#define __RAILWAYS

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <assert.h>
#include <exception>
#include "station.hpp"

using namespace std;

// Singleton Railways class
class Railways
{
private:
    Railways(){};
    ~Railways(){};

public:
    static vector<Station> sStations;                           // list of stations
    static map<pair<string, string>, double> sDistanceStations; // distance between stations
    static const string path;                                   // path of file where master data is stored

    static const Railways &IndianRailways();
    // get distance between stations
    static double getDistacne(const Station &s1, const Station &s2);
    // print entire matrix of station distance
    friend ostream &operator<<(ostream &os, const Railways &f);
    // unit test for railways class
    static void UnitTest(const string n1, const string n2, const double dis);
    
};
const Railways &Railways::IndianRailways() // Indian Railways
{
    try
    {
        static Railways indianRailways;
        int numOfStations, edges; // number of stations and number of edges in the graph of cities
        if (sStations.size() == 0)
        {
            ifstream file(path);
            file >> numOfStations >> edges;
            for (int i = 0; i < numOfStations; i++) // read list of stations then store in sStation vector
            {
                string name;
                file >> name;
                sStations.push_back(Station::createStation(name));
            }
            for (int i = 0; i < edges; i++) // create a undirected graph with dis as weight
            {
                string name1, name2;
                double dis;
                file >> name1 >> name2 >> dis;

                sDistanceStations[pair<string, string>(name1, name2)] = dis;
                sDistanceStations[pair<string, string>(name2, name1)] = dis;
            }
            file.close();
        }
        return indianRailways;
    }
    catch (const Bad_Railways &e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
}
double Railways::getDistacne(const Station &s1, const Station &s2) // distance between two stations
{
    return sDistanceStations[pair<string, string>(s1.getName(), s2.getName())];
}
// print entire matrix of station distance
ostream &operator<<(ostream &os, const Railways &f)
{
    for (auto &x : f.sStations)
        os << x << " ";
    cout << endl;
    for (auto &x : f.sDistanceStations)
        os << x.first.first << " " << x.first.second << " " << x.second << "\n";
    return os;
}
// get distance between stations
double Station::getDistance(const Station &from)
{
    return Railways::IndianRailways().getDistacne(*this, from);
}
// ###################################################################################
// implementation of unit tests
void Railways::UnitTest(const string n1, const string n2, const double dis)
{
    Railways::IndianRailways();
    Station s1 = Station::createStation(n1);
    Station s2 = Station::createStation(n2);
    assert(Railways::IndianRailways().getDistacne(s1, s2) == dis);
    cout << "Success in Railways Unit Testing" << endl;
}
// ###################################################################################
// initializing static variables
vector<Station> Railways::sStations;
map<pair<string, string>, double> Railways::sDistanceStations;
#endif