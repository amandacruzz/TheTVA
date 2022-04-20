#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

class unorderedMapCalc
{
public:
    // Map with key = title, value = number of occurrences
    unordered_map<string, int> MidEast;
    unordered_map<string, int> Asia;
    unordered_map<string, int> EUNA;
    // keep counter for number of articles in each country
    int MidEWordCnt = 0;
    int AsiaWordCnt = 0;
    int EUNAWordCnt = 0;
    int MidECnt = 0;
    int AsiaCount = 0;
    int EUNACount = 0;

    // Methods
    void insertTitle(string articleTitle, string region, unordered_map<string, int> &asia, unordered_map<string, int> &ME, unordered_map<string, int> &EUNA);
    vector<double> indexCalculator();
};

class orderedMapCalc
{
public:
    // Map with key = title, value = number of occurrences
    map<string, int> MidEast;
    map<string, int> Asia;
    map<string, int> EUNA;
    // keep counter for number of articles in each country
    int MidEWordCnt = 0;
    int AsiaWordCount = 0;
    int EUNAWordCount = 0;
    int MidECnt = 0;
    int AsiaCount = 0;
    int EUNACount = 0;

    // Methods
    void getTitleInsert(string line);
    void insertTitle(string articleTitle, string region, map<string, int> &asia, map<string, int> &ME, map<string, int> &EUNA);
    vector<double> calculateIndex();
};

// method to parse title and insert into map
void unorderedMapCalc::insertTitle(string articleTitle, string region, unordered_map<string, int> &asia, unordered_map<string, int> &ME, unordered_map<string, int> &EUNA) {
    int mapCount;
    if(region == "Mid East"){
        mapCount = MidEast.size();
        MidEast.insert(pair<string, int> (articleTitle, 1));
        if(MidEast.size() == mapCount)
            MidEast[articleTitle]++;
        MidEWordCnt += articleTitle.length();
        MidECnt++;
    }
    else if(region == "Asia"){
        mapCount = Asia.size();
        Asia.insert(pair<string, int> (articleTitle, 1));
        if(Asia.size() == mapCount)
            Asia[articleTitle]++;
        AsiaWordCnt += articleTitle.length();
        AsiaCount++;
    }
    else{
        mapCount = EUNA.size();
        EUNA.insert(pair<string, int> (articleTitle, 1));
        if(EUNA.size() == mapCount)
            EUNA[articleTitle]++;
        EUNAWordCnt += articleTitle.length();
        EUNACount++;
    }
}

// method to calculate prosperity index: add up num of words in articles of each country / num of articles in each country
vector<double> unorderedMapCalc::indexCalculator()
{
    vector<double>prosperityIndex;

    prosperityIndex.push_back((double) MidEWordCnt / (double) MidECnt);

    prosperityIndex.push_back((double) AsiaWordCnt / (double) AsiaCount);

    prosperityIndex.push_back((double) EUNAWordCnt / (double) EUNACount);

    return prosperityIndex;
}

// method to parse title and insert into map
void orderedMapCalc::getTitleInsert(string countryData) {

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
//            MidEWordCnt++;
//
//            //FIXME: if(first char == Chinese char)
//            // insert into Asia map
//            AsiaWordCount++;
//
//            //FIXME: if(first char == US char)
//            // insert US map
//            EUNAWordCount++;
//        }
//    }
}

// method to calculate prosperity index: add up words of first 100,000 articles and divide it by 100,000
vector<double> orderedMapCalc::calculateIndex() {
    vector<double>prosperityIndex;

    prosperityIndex.push_back((double) MidEWordCnt / (double) MidECnt);

    prosperityIndex.push_back((double) AsiaWordCount / (double) AsiaCount);

    prosperityIndex.push_back((double) EUNAWordCount / (double) EUNACount);

    return prosperityIndex;
}

void orderedMapCalc::insertTitle(string articleTitle, string region, map<string, int> &asia, map<string, int> &ME, map<string, int> &EUNA) {

    int mapCount;
    if(region == "Mid East"){
        mapCount = MidEast.size();
        MidEast.insert(pair<string, int> (articleTitle, 1));
        if(MidEast.size() == mapCount)
            MidEast[articleTitle]++;
        MidEWordCnt += articleTitle.length();
        MidECnt++;
    }
    else if(region == "Asia"){
        mapCount = Asia.size();
        Asia.insert(pair<string, int> (articleTitle, 1));
        if(Asia.size() == mapCount)
            Asia[articleTitle]++;
        AsiaWordCount += articleTitle.length();
        AsiaCount++;
    }
    else{
        mapCount = EUNA.size();
        EUNA.insert(pair<string, int> (articleTitle, 1));
        if(EUNA.size() == mapCount)
            EUNA[articleTitle]++;
        EUNAWordCount += articleTitle.length();
        EUNACount++;
    }
}

string findRegion(string url){
    if(url.find(".uk/") != string::npos)
        return "NA";
    else if(url.find(".ca/") != string::npos)
        return "NA";
    else if(url.find(".br/") != string::npos)
        return "NA";
    else if(url.find(".de/") != string::npos)
        return "NA";
    else if(url.find(".ir/") != string::npos)
        return "Mid East";
    else if(url.find(".sa/") != string::npos)
        return "Mid East";
    else if(url.find(".tr/") != string::npos)
        return "Mid East";
    else if(url.find(".ae/") != string::npos)
        return "Mid East";
    else if(url.find(".il/") != string::npos)
        return "Mid East";
    else if(url.find(".cn/") != string::npos)
        return "Asia";
    else if(url.find(".jp/") != string::npos)
        return "Asia";
    else if(url.find(".in/") != string::npos)
        return "Asia";
    else if(url.find(".kr/") != string::npos)
        return "Asia";
    return "not found";
}

int main() {

    // UNORDERED MAPS: Parse data and insert into map for each key
    unorderedMapCalc prospCalcUnord;
    // ORDERED MAPS: Parse data and insert into map for each key
    orderedMapCalc prospCalcOrd;
    ifstream dataset;
    string file = "news-week-17aug24.csv";
    dataset.open(file);
    string line;
//    int testCount = 0;

    getline(dataset, line);
    while(getline(dataset, line)){
        string url;
        string region;
//        testCount++;
        stringstream myStream(line);
        getline(myStream, line, ',');
        getline(myStream, line, ',');
        getline(myStream, line, ',');
        url = line;
        getline(myStream, line);
        region = findRegion(url);
        if(region != "not found"){
//            cout << region << endl;
            prospCalcOrd.insertTitle(line, region, prospCalcOrd.Asia, prospCalcOrd.MidEast, prospCalcOrd.EUNA);
            prospCalcUnord.insertTitle(line, region, prospCalcUnord.Asia, prospCalcUnord.MidEast, prospCalcUnord.EUNA);
        }

    }

    // UNORDERED MAP: Calculate the prosperity index of three countries
    vector<double> unorderedIdx;
    unorderedIdx = prospCalcUnord.indexCalculator();
    double idx1, idx2, idx3;
    idx1 = unorderedIdx[0];
    idx2 = unorderedIdx[1];
    idx3 = unorderedIdx[2];
    cout << "1: " << idx1 << endl << "2: " << idx2 << endl << "3: " << idx3 << endl;
//     Display data
    cout << "The prosperity index of the Middle East using an unordered map is: " << idx1 << endl;
    cout << "The prosperity index of the Asia country using an unordered map is: " << idx2 << endl;
    cout << "The prosperity index of Western countries using an unordered map is: " << idx3 << endl;

    // ORDERED MAP: Calculate the prosperity index of three countries
    vector<double> index;
    index = prospCalcOrd.calculateIndex();
    double index1, index2, index3;
    index1 = index[0];
    index2 = index[1];
    index3 = index[2];
    // Display data
    cout << "--------------------------------------------------" << endl;
    cout << "The prosperity index of the Middle East using an ordered map is: " << index1 << endl;
    cout << "The prosperity index of the Asia using an ordered map is: " << index2 << endl;
    cout << "The prosperity index of Western countries using an ordered map is: " << index3 << endl;

    return 0;
}
/*

.uk/ = 27,192 - united kingdom (actually 27,192)
.cn/ = 5871 - china (actually 5871)
.ca/ = 7161 - canada
.ir/ = 4145 - iran
.sa/ = 1687 - saudi arabia
.tr/ = 4739 - turkey
.jp/ = 6756 - japan
.in/ = 2763 - india
.br/ = 16452 - brazil
.de/ = 55842 - germany
.ae/ = 1162 - united arab emirates
.il/ - 2671 - israel
.kr/ - 9683 - south korea


western
{uk, canada, brazil, germany}
middle east
{iran, saudi arabia, turkey, united arab emirates, israel}
Asia
{china, japan, india, south korea}


DONT USE NOT WORTH - .hk/ = 430 - hong kong (actually 430)
DONT USE NOT WORTH - .th/ = 143 - thailand (actually 143)
DONT USE NOT WORTH - .us/ = 170 - united states
*/
