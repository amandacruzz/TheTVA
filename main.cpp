#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <ctime>
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
    else if(region == "NA"){
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
    clock_t timer;

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
    string lastTitleNA;
    string lastTitleAsia;
    string lastTitleME;
    for(auto iter = prospCalcOrd.EUNA.begin(); iter != prospCalcOrd.EUNA.end(); iter++){
        lastTitleNA = iter->first;
    }
    for(auto iter = prospCalcOrd.Asia.begin(); iter != prospCalcOrd.Asia.end(); iter++){
        lastTitleAsia = iter->first;
    }
    for(auto iter = prospCalcOrd.MidEast.begin(); iter != prospCalcOrd.MidEast.end(); iter++){
        lastTitleME = iter->first;
    }
    string input;
    cout << "Welcome to the Prosperity Indexer!" << endl << endl;
    cout << "Prosperity Index Rule of Thumb:" << endl;
    cout << "PI < 70: This region is experiencing an era of prosperity." << endl;
    cout << "70 < PI < 80: This region is fairly prosperous." << endl;
    cout << "PI > 80: This region is facing an era of development." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "To find the prosperity index of a region, enter:" << endl;
    cout << "1: Europe, North America, & South America" << endl;
    cout << "2: Middle East" << endl;
    cout << "3: Asia" << endl;
    cout << "4: exit" << endl;

    bool findProsperity = true;
    int test;
    while(findProsperity) {
        cin >> input;
        if (input == "1") {
            cout << "The prosperity index of Western civilizations is: " << idx3 << endl;
            timer = clock();
            test = prospCalcUnord.EUNA[lastTitleNA];
            timer = clock() - timer;
            cout << "It took an unordered map " << (float)timer/CLOCKS_PER_SEC << " seconds to access its last inputted key!" << endl;
            timer = clock();
            test = prospCalcOrd.EUNA[lastTitleNA];
            timer = clock() - timer;
            cout << "It took an ordered map " << (float)timer/CLOCKS_PER_SEC << " seconds to access its last inputted key!";
            //print how much time it takes to print the last item in the americas map
        } else if (input == "2") {
            cout << "The prosperity index of the Middle East is: " << idx1 << endl;
            timer = clock();
            test = prospCalcUnord.MidEast[lastTitleME];
            timer = clock() - timer;
            cout << "It took an unordered map " << (float)timer/CLOCKS_PER_SEC << " seconds to access its last inputted key!" << endl;
            timer = clock();
            test = prospCalcOrd.MidEast[lastTitleME];
            timer = clock() - timer;
            cout << "It took an ordered map " << (float)timer/CLOCKS_PER_SEC << " seconds to access its last inputted key!";

        } else if (input == "3") {
            cout << "The prosperity index of Asia is: " << idx2 << endl;
            timer = clock();
            test = prospCalcUnord.Asia[lastTitleAsia];
            timer = clock() - timer;
            cout << "It took an unordered map " << (float)timer/CLOCKS_PER_SEC << " seconds to access its last inputted key!" << endl;
            timer = clock();
            test = prospCalcOrd.Asia[lastTitleAsia];
            timer = clock() - timer;
            cout << "It took an ordered map " << (float)timer/CLOCKS_PER_SEC << " seconds to access its last inputted key!";
        }
        else if (input == "4")
            findProsperity = false;
        else{
            cout << "Please enter valid input (1, 2, or 3)" << endl;
        }
        cout << endl;
    }
    cout << "END";

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
