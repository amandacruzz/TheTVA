#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <map>
#include <string.h>
#include <sstream>
using namespace std;

bool findCountry(string url, string urlExtension)
{
    if(url.find(urlExtension) != string::npos)
        return true;
    return false;
}

class unOrderedMaps
{
public:
    ifstream dataset;

    // Map with key = title, value = number of occurrences
    unordered_map<string, int> middleEast;
    unordered_map<string, int> EastAsia;
    unordered_map<string, int> Western;
    // keep counter for number of articles in each country
    int midEastCount = 0;
    int eAsiaCount = 0;
    int westernCount = 0;

    // Methods
    void insertTitle(string articleTitle, unordered_map<string,int>& currRegion);
    vector<int> indexCalculator();
};

class orderedMaps
{
public:
    ifstream dataset;

    // Map with key = title, value = number of occurrences
    map<string, int> middleEast;
    map<string, int> EastAsia;
    map<string, int> Western;
    // keep counter for number of articles in each country
    int midEastCount = 0;
    int eAsiaCount = 0;
    int westernCount = 0;

    // Methods
    void insertTitle(string articleTitle, map<string,int>& currRegion);
    vector<int> indexCalculator();

};
void findCountry(string region, string url, string urlExt, string artTitle, unOrderedMaps &obj)
{
    if(url.find(urlExt) != string::npos){
        if(region == "Western")
            obj.insertTitle(artTitle, obj.Western);
        if(region == "Asia")
            obj.insertTitle(artTitle, obj.EastAsia);
        if(region == "MidEast")
            obj.insertTitle(artTitle, obj.middleEast);
    }
}
// method to parse title and insert into map
void unOrderedMaps::insertTitle(string articleTitle, unordered_map<string,int>& currRegion)
{
    int cnt= currRegion.size();
    currRegion.insert(pair<string, int> (articleTitle,1));
    if(currRegion.size()==cnt)
        currRegion[articleTitle]++;

}

// method to calculate prosperity index: add up num of words in articles of each country / num of articles in each country
vector<int> unOrderedMaps::indexCalculator()
{
    vector<int>prosperityIndex;

    // TODO: count the number of words in vector of Saudi
    int totalWords1 = 0;
//    for (int i = 0; i < titles1.size(); i++){
//
//    }
    prosperityIndex[0] = totalWords1 / midEastCount;

    // TODO: count the number of words in vector of China
    int totalWords2 = 0;
//    for (int i = 0; i < titles2.size(); i++){
//
//    }
    prosperityIndex[1] = totalWords2 / eAsiaCount;

    // TODO: count the number of words in vector of US
    int totalWords3 = 0;
//    for (int i = 0; i < titles3.size(); i++){
//
//    }
    prosperityIndex[2] = totalWords3 / westernCount;

    return prosperityIndex;
}

// method to parse title and insert into map
//void orderedMapCalc::getTitleInsert(string countryData)
//{
//
//    if (countryData == "news-week-17aug24.csv") {
//        dataset.open(countryData);
//        string input, line;int i = 0;
//        getline(dataset, line);
//        // cout << "test " << i << ": " << line << endl;
//        while (getline(dataset, line)) {
//            i++;
//            // cout << "test " << i << ": " << line << endl;
//
//            //FIXME: if(first char == Arab char)
//            // insert into Saudi map
//            SaudiCount++;
//
//            //FIXME: if(first char == Chinese char)
//            // insert into China map
//            ChinaCount++;
//
//            //FIXME: if(first char == US char)
//            // insert US map
//            UnitedStatesCount++;
//        }
//    }
//}
void findCountry(string region, string url, string urlExt, string artTitle, orderedMaps &obj)
{
    if(url.find(urlExt) != string::npos){
        if(region == "Western")
            obj.insertTitle(artTitle, obj.Western);
        if(region == "Asia")
            obj.insertTitle(artTitle, obj.EastAsia);
        if(region == "MidEast")
            obj.insertTitle(artTitle, obj.middleEast);
    }
}
// method to calculate prosperity index: add up words of first 100,000 articles and divide it by 100,000
vector<int> orderedMaps::calculateIndex()
{
    vector<int>prosperityIndex;

    // TODO: count the number of words in vector of Saudi
    int totalWords1 = 0;
//   for (int i = 0; i < titles1.size(); i++){
//
//   }
    prosperityIndex[0] = totalWords1 / midEastCount;

    // TODO: count the number of words in vector of China
    int totalWords2 = 0;
//   for (int i = 0; i < titles2.size(); i++){
//
//   }
    prosperityIndex[1] = totalWords2 / eAsiaCount;

    // TODO: count the number of words in vector of US
    int totalWords3 = 0;
//   for (int i = 0; i < titles3.size(); i++){
//
//   }
    prosperityIndex[2] = totalWords3 / westernCount;

    return prosperityIndex;
}

void orderedMaps::insertTitle(string articleTitle, map<string, int> &currRegion) {
    int cnt= currRegion.size();
    currRegion.insert(pair<string, int> (articleTitle,1));
    if(currRegion.size()==cnt)
        currRegion[articleTitle]++;
}



int main()
{
    unOrderedMaps unorderedProsperity;
    orderedMaps orderedProsperity;

    ifstream dataset;
    string file = "news-week-17aug24.csv";
    dataset.open(file);
    string line;
    int i = 0;
    getline(dataset, line);
    //cout << line << endl;

    while(getline(dataset, line))
    {
        //mymap[line];
        stringstream myStream(line);
        getline(myStream, line, ',');
        getline(myStream, line, ',');
        getline(myStream, line, ',');
        string url = line;
        getline(myStream, line);

        findCountry("Western", url, ".uk/", line, unorderedProsperity);
        findCountry("Western", url, ".ca/", line, unorderedProsperity);
        findCountry("Western", url, ".us/", line, unorderedProsperity);
        findCountry("MidEast", url, ".ir/", line, unorderedProsperity);
        findCountry("MidEast", url, ".sa/", line, unorderedProsperity);
        findCountry("Asia", url, ".cn/", line, unorderedProsperity);
        findCountry("Asia", url, ".jp/", line, unorderedProsperity);
        findCountry("Asia", url, ".th/", line, unorderedProsperity);

        findCountry("Western", url, ".uk/", line, orderedProsperity);
        findCountry("Western", url, ".ca/", line, orderedProsperity);
        findCountry("Western", url, ".us/", line, orderedProsperity);
        findCountry("MidEast", url, ".ir/", line, orderedProsperity);
        findCountry("MidEast", url, ".sa/", line, orderedProsperity);
        findCountry("Asia", url, ".cn/", line, orderedProsperity);
        findCountry("Asia", url, ".jp/", line, orderedProsperity);
        findCountry("Asia", url, ".th/", line, orderedProsperity);

    }

    return 0;
}
//.uk = 27,338 - united kingdom
//.cn = 9,194 - china
//.us = 2,782 - united states
//.ca = 15,544 - canada
//.ir = 5,767 - iran
//.sa = 19,996 - saudi arabia
//.th = 21,388 - thailand
//.hk = 1,149 - hong kong
//.jp = 7,180 - japan



