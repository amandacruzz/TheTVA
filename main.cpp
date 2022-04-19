#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

class unOrderedMaps
{
public:
    ifstream dataset;

    // Map with key = title, value = number of occurrences
    unordered_map<string, int> Saudi;
    unordered_map<string, int> China;
    unordered_map<string, int> UnitedStates;
    // keep counter for number of articles in each country
    int SaudiCount = 0;
    int ChinaCount = 0;
    int UnitedStatesCount = 0;

    // Methods
    void insertTitle(string line);
    vector<int> indexCalculator();
};

class orderedMapCalc
{
public:
    ifstream dataset;

    // Map with key = title, value = number of occurrences
    map<string, int> Saudi;
    map<string, int> China;
    map<string, int> UnitedStates;
    // keep counter for number of articles in each country
    int SaudiCount = 0;
    int ChinaCount = 0;
    int UnitedStatesCount = 0;

    // Methods
    void getTitleInsert(string line);
    vector<int> calculateIndex();
};

// method to parse title and insert into map
void unOrderedMaps::insertTitle(string countryData)
{
    if (countryData == "news-week-17aug24.csv") {
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        // cout << "test " << i << ": " << line << endl;
        while (getline(dataset, line)) {
            i++;
            // cout << "test " << i << ": " << line << endl;
            //FIXME: if(first char == Arab char)
            // insert into Saudi map
            SaudiCount++;
            //FIXME: if(first char == Chinese char)
            // insert into China map
            ChinaCount++;
            //FIXME: if(first char == US char)
            // insert US map
            UnitedStatesCount++;
        }
    }
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
    prosperityIndex[0] = totalWords1 / SaudiCount;

    // TODO: count the number of words in vector of China
    int totalWords2 = 0;
//    for (int i = 0; i < titles2.size(); i++){
//
//    }
    prosperityIndex[1] = totalWords2 / ChinaCount;

    // TODO: count the number of words in vector of US
    int totalWords3 = 0;
//    for (int i = 0; i < titles3.size(); i++){
//
//    }
    prosperityIndex[2] = totalWords3 / UnitedStatesCount;

    return prosperityIndex;
}

// method to parse title and insert into map
void orderedMapCalc::getTitleInsert(string countryData) {

    if (countryData == "news-week-17aug24.csv") {
        dataset.open(countryData);
        string input, line;int i = 0;
        getline(dataset, line);
        // cout << "test " << i << ": " << line << endl;
        while (getline(dataset, line)) {
            i++;
            // cout << "test " << i << ": " << line << endl;

            //FIXME: if(first char == Arab char)
            // insert into Saudi map
            SaudiCount++;

            //FIXME: if(first char == Chinese char)
            // insert into China map
            ChinaCount++;

            //FIXME: if(first char == US char)
            // insert US map
            UnitedStatesCount++;
        }
    }
}

// method to calculate prosperity index: add up words of first 100,000 articles and divide it by 100,000
vector<int> orderedMapCalc::calculateIndex() {
    vector<int>prosperityIndex;

    // TODO: count the number of words in vector of Saudi
    int totalWords1 = 0;
//   for (int i = 0; i < titles1.size(); i++){
//
//   }
    prosperityIndex[0] = totalWords1 / SaudiCount;

    // TODO: count the number of words in vector of China
    int totalWords2 = 0;
//   for (int i = 0; i < titles2.size(); i++){
//
//   }
    prosperityIndex[1] = totalWords2 / ChinaCount;

    // TODO: count the number of words in vector of US
    int totalWords3 = 0;
//   for (int i = 0; i < titles3.size(); i++){
//
//   }
    prosperityIndex[2] = totalWords3 / UnitedStatesCount;

    return prosperityIndex;
}


int main()
{

    ifstream dataset;
    string file = "news-week-18aug24.csv";
    dataset.open(file);
    string input, line;
    int i = 0;
    getline(dataset, line);
    cout << "test " << i << ": " << line <<  endl;
    while(getline(dataset, line)){
        i++;
        cout << "test " << i << ": " << line << endl;
    }


    unOrderedMaps prosperityCalculator;
    orderedMapCalc prosperityCalc;

    // UNORDERED MAPS: Parse data and insert into map for each key
    string file1 = "news-week-17aug24.csv";
    prosperityCalculator.insertTitle(file1);

    // Reset stream for another pass
    prosperityCalculator.dataset.clear();
    prosperityCalculator.dataset.seekg(0);
    prosperityCalc.dataset.clear();
    prosperityCalc.dataset.seekg(0);

    // ORDERED MAPS: Parse data and insert into map for each key
    prosperityCalc.getTitleInsert(file1);

    // UNORDERED MAP: Calculate the prosperity index of three countries
    vector<int> unorderedIdx;
    unorderedIdx = prosperityCalculator.indexCalculator();
    int idx1, idx2, idx3;
    idx1 = unorderedIdx[0];
    idx2 = unorderedIdx[1];
    idx3 = unorderedIdx[2];
    // Display data
    cout << "The prosperity index of Saudi using unordered map is: " << idx1 << endl;
    cout << "The prosperity index of the CHANGE country using unordered map is: " << idx2 << endl;
    cout << "The prosperity index of the CHANGE country using unordered map is: " << idx3 << endl;

    // ORDERED MAP: Calculate the prosperity index of three countries
    vector<int> index;
    index = prosperityCalc.calculateIndex();
    int index1, index2, index3;
    index1 = index[0];
    index2 = index[1];
    index3 = index[2];
    // Display data
    cout << "The prosperity index of the United States using ordered map is: " << index1 << endl;
    cout << "The prosperity index of the TBD using ordered map is: " << index2 << endl;
    cout << "The prosperity index of the TBD using ordered map is: " << index3 << endl;

    return 0;
}
