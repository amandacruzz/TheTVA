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

    // Map with key = country and values = news article title
    unordered_map<string, string> countryNews;
    // Vector to hold titles for data of each country
    vector<string> titles1;  // U.S. news data
    vector<string> titles2;
    vector<string> titles3;

    // Methods
    string getTitle(string line);
    vector<int> indexCalculator();
};

class orderedMapCalc
{
public:
    ifstream dataset;

    // Map with key = country and values = news article title
    map<string, string> countryNews;
    // Vector to hold titles for data of each country
    vector<string> titles1;  // U.S. news data
    vector<string> titles2;  // TODO: get country data
    vector<string> titles3;  // TODO: get country data

    // Methods
    string getTitleInsert(string line);
    vector<int> calculateIndex();
};

// method to parse title and insert into map
string unOrderedMaps::getTitle(string countryData)
{
    if (countryData == "articles1.csv"){
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        cout << "test " << i << ": " << line <<  endl;
        while(getline(dataset, line)){
            i++;
            cout << "test " << i << ": " << line << endl;
        }
        //TODO: parse string
        // add to vector

        // insert into map using vector
        for (int i = 0; i < titles1.size(); i++){
            countryNews.insert(pair<string, string>(countryData,titles1[i]));
        }
    }
    else if (countryData == "tbd1"){    //FIXME:
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        cout << "test " << i << ": " << line <<  endl;
        while(getline(dataset, line)){
            i++;
            cout << "test " << i << ": " << line << endl;
        }
        //TODO: parse string
        // add to vector

        // insert into map using vector
        for (int i = 0; i < titles2.size(); i++){
            countryNews.insert(pair<string, string>(countryData,titles2[i]));
        }
    }
    else if (countryData == "tbd2"){    //FIXME:
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        cout << "test " << i << ": " << line <<  endl;
        while(getline(dataset, line)){
            i++;
            cout << "test " << i << ": " << line << endl;
        }
        //TODO: parse string
        // add to vector

        // insert into map using vector
        for (int i = 0; i < titles3.size(); i++){
            countryNews.insert(pair<string, string>(countryData,titles3[i]));
        }
    }
}
// method to calculate prosperity index: add up words of first 100,000 articles and divide it by 100,000
vector<int> unOrderedMaps::indexCalculator()
{
    vector<int>prosperityIndex;

    // TODO: count the number of words in vector of country 1
    int totalWords1 = 0;
    for (int i = 0; i < titles1.size(); i++){

    }
    prosperityIndex[0] = totalWords1 / 30,000;  //FIXME: adjust 30,000

    // TODO: count the number of words in vector of country 1
    int totalWords2 = 0;
    for (int i = 0; i < titles2.size(); i++){

    }
    prosperityIndex[1] = totalWords2 / 30,000;  //FIXME: adjust 30,000

    // TODO: count the number of words in vector of country 1
    int totalWords3 = 0;
    for (int i = 0; i < titles3.size(); i++){

    }
    prosperityIndex[2] = totalWords3 / 30,000;  //FIXME: adjust 30,000

    return prosperityIndex;
}
// method to parse title and insert into map
string orderedMapCalc::getTitleInsert(string countryData) {
    if (countryData == "articles1.csv"){
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        cout << "test " << i << ": " << line <<  endl;
        while(getline(dataset, line)){
            i++;
            cout << "test " << i << ": " << line << endl;
        }
        //TODO: parse string
        // add to vector

        // insert into map using vector
        for (int i = 0; i < titles1.size(); i++){
            countryNews.insert(pair<string, string>(countryData,titles1[i]));
        }
    }
    else if (countryData == "tbd1"){    //FIXME:
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        cout << "test " << i << ": " << line <<  endl;
        while(getline(dataset, line)){
            i++;
            cout << "test " << i << ": " << line << endl;
        }
        //TODO: parse string
        // add to vector

        // insert into map using vector
        for (int i = 0; i < titles2.size(); i++){
            countryNews.insert(pair<string, string>(countryData,titles2[i]));
        }
    }
    else if (countryData == "tbd2"){    //FIXME:
        dataset.open(countryData);
        string input, line;
        int i = 0;
        getline(dataset, line);
        cout << "test " << i << ": " << line <<  endl;
        while(getline(dataset, line)){
            i++;
            cout << "test " << i << ": " << line << endl;
        }
        //TODO: parse string
        // add to vector

        // insert into map using vector
        for (int i = 0; i < titles3.size(); i++){
            countryNews.insert(pair<string, string>(countryData,titles3[i]));
        }
    }
}
// method to calculate prosperity index: add up words of first 100,000 articles and divide it by 100,000
vector<int> orderedMapCalc::calculateIndex() {
    vector<int>prosperityIndex;

    // TODO: count the number of words in vector of country 1
    int totalWords1 = 0;
    for (int i = 0; i < titles1.size(); i++){

    }
    prosperityIndex[0] = totalWords1 / 30,000;  //FIXME: adjust 30,000

    // TODO: count the number of words in vector of country 1
    int totalWords2 = 0;
    for (int i = 0; i < titles2.size(); i++){

    }
    prosperityIndex[1] = totalWords2 / 30,000;  //FIXME: adjust 30,000

    // TODO: count the number of words in vector of country 1
    int totalWords3 = 0;
    for (int i = 0; i < titles3.size(); i++){

    }
    prosperityIndex[2] = totalWords3 / 30,000;  //FIXME: adjust 30,000

    return prosperityIndex;
}



int main() {
    unOrderedMaps prosperityCalculator;
    orderedMapCalc prosperityCalc;

    // Parse first country data and insert into map
    string file1 = "articles1.csv";
    prosperityCalculator.getTitle(file1);
    prosperityCalc.getTitleInsert(file1);

    // Reset stream for another pass
    prosperityCalculator.dataset.clear();
    prosperityCalculator.dataset.seekg(0);

    prosperityCalc.dataset.clear();
    prosperityCalc.dataset.seekg(0);

    // Parse second country data and insert into map
    string file2 = "CHANGE";   //FIXME
    prosperityCalculator.getTitle(file2);
    prosperityCalc.getTitleInsert(file2);

    // Reset stream for another pass
    prosperityCalculator.dataset.clear();
    prosperityCalculator.dataset.seekg(0);
    prosperityCalc.dataset.clear();
    prosperityCalc.dataset.seekg(0);

    // Parse third country data and insert into map
    string file3 = "CHANGE";   //FIXME
    prosperityCalculator.getTitle(file3);
    prosperityCalc.getTitleInsert(file3);

    // Calculate the prosperity index of three countries
    vector<int> unorderedIdx;
    unorderedIdx = prosperityCalculator.indexCalculator();
    int idx1, idx2, idx3;
    idx1 = unorderedIdx[0];
    idx2 = unorderedIdx[1];
    idx3 = unorderedIdx[2];

    // Display data
    cout << "The prosperity index of the United States is: " << idx1 << endl;
    cout << "The prosperity index of the CHANGE country is: " << idx2 << endl;
    cout << "The prosperity index of the CHANGE country is: " << idx3 << endl;




    // Calculate the prosperity index of three countries
    vector<int> index;
    index = prosperityCalc.calculateIndex();
    int index1, index2, index3;
    index1 = index[0];
    index2 = index[1];
    index3 = index[2];

    // Display data
    cout << "The prosperity index of the United States is: " << index1 << endl;
    cout << "The prosperity index of the TBD is: " << index2 << endl;
    cout << "The prosperity index of the TBD is: " << index3 << endl;

    return 0;
}
