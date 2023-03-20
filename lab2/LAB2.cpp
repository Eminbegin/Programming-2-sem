#define CURL_STATICLIB
#include <curl/curl.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <conio.h>
#include <vector>
#include <math.h>
#include <map>
#include<windows.h>
#include <iomanip>
#include <algorithm>
#include <nlohmann/json.hpp>

int green = 2;
int red = 4;
int white = 15;
using json = nlohmann::json;
const std::string url = "http://www.cbr-xml-daily.ru/daily_json.js";

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

class Currency {
private:
    std::vector<double> avalues;
    std::vector<double> svalues;
    double average_value = 0;
    double middle_value = -1;
    int colora = 15;
    int colorm = 15;
public:
    Currency(){}
    void add (const double& i) {
        double saveav = average_value;
        double savemv = middle_value;
        avalues.push_back(i);
        svalues.push_back(i);
        average_value = (average_value * (avalues.size() - 1) + avalues.back()) / avalues.size();
        for (int i = svalues.size() - 1; i > 0; --i) {
            if (svalues[i] < svalues[i - 1])
                std::swap(svalues[i], svalues[i - 1]);
            else
                break;
        }
        middle_value = svalues[svalues.size() / 2];

        middle_value = ceil(middle_value * 10000) / 10000;
        average_value = ceil(average_value * 10000) / 10000;

        if (fabs(saveav - average_value) <= 0.01)
            colora = white;
        else
            if (saveav + 0.01 < average_value)
                colora = green;
            else
                colora = red;
        if (fabs(savemv - middle_value) <= 0.01)
            colora = white;
        else
            if (savemv + 0.01 < middle_value)
                colora = green;
            else
                colora = red;
    }

    double getM() const{
        return middle_value;
    }

    double getA() const{
        return average_value;
    }

    int get_colorA() const {
        return colora;
    }

    int get_colorM() const {
        return colorm;
    }
};


std::map<std::string, Currency> values_currencies;

size_t write_callback(char* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string get_request()
{
    //curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    std::string response_string;
    struct curl_slist* headers = NULL;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    
    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    curl_global_cleanup();
    
    return response_string;
    
}

void parse() {
    std::string temp_s = get_request();
    json j = json::parse(temp_s.begin(), temp_s.end());
    for (auto &i : j["Valute"].items()) {
        values_currencies[i.key()].add(i.value()["Value"]);
    }
}

std::ostream& operator<<(std::ostream& out, std::map<std::string, Currency> const& obj) {
    SetColor(15, 0);
    out << " |-------|-----------------|----------------|\n";
    out << " |  UID  |  average_value  |  middle_value  |\n";
    out << " |-------|-----------------|----------------|\n";
    for (auto it : values_currencies) {
        out << " |  " << std::fixed << std::setprecision(4) << it.first << "  |     ";
        if (it.second.getA() >= 100) {
            SetColor(it.second.get_colorA(), 0);
            out << it.second.getA();
        }
        else {
            SetColor(it.second.get_colorA(), 0);
            out <<"0" << it.second.getA();
        }
        SetColor(15, 0);
        if (it.second.getM() >= 100) {
            out << "    |    ";
            SetColor(it.second.get_colorM(), 0);
            out << it.second.getM();
            SetColor(15, 0);
            out << "    |\n";
        }
        else {
            out << "    |    ";
            SetColor(it.second.get_colorM(), 0);
            out << "0" << it.second.getM();
            SetColor(15, 0);
            out <<"    |\n";
        }
    }
    return out;
}

int main()
{
    while (!_kbhit()) {
        parse();
        std::cout << values_currencies;
        Sleep(3000);
    }
    
    return 0;
    
}

