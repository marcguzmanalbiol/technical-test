#include <thread>
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <sstream>

/**
 * IMPORTANT NOTE: when compiling, we need to introduce the following flag: -pthread.
 */

using namespace std;

class SharedData {
private:
    struct shared_data {
        string next_date;
        int rand_number;
        string name = "Marc Guzman Albiol";
        bool is_ready;
    };

public:

    shared_data data;

    /**
     * Function that fills the data of the class using the 4 threads.
     */
    void fillData() {
        thread dateT(&SharedData::dateThread, this);
        thread nameT(&SharedData::nameThread, this);
        thread randT(&SharedData::randomThread, this);

        dateT.join();
        nameT.join();
        randT.join();

        thread readyT(&SharedData::isReadyThread, this);
        readyT.join();
    }

    /**
     * Function that retrieves the date of today and adds 123 days to it. The strategy is to use UNIX timestamp and
     * add 60*60*24*123.
     */
    void dateThread() {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        rawtime += 60 * 60 * 24 * 123;
        timeinfo = localtime(&rawtime);

        strftime(buffer, 80, "%Y-%m-%d", timeinfo);
        string str(buffer);
        data.next_date = buffer;
    }

    /**
     * Function that reverse the order of the name attribute. Uses the reverse function.
     */
    void nameThread() {
        reverse(data.name.begin(), data.name.end());
    }

    /**
     * Function that gets a random integer number from 1 to 100. Firt, we 'randomly' initialize a seed in order to
     * invoke the random behaviour of the rand function. Then, take the modulo 100 and sum one to obtain a random in
     * the desired integer interval.
     */
    void randomThread() {
        srand(time(nullptr));
        data.rand_number = rand() % 100 + 1;
    }

    void isReadyThread() {
        data.is_ready = true;
    }
};

/**
 * Function to correctly print a bool.
 * @param b bool.
 * @return true if 1, false if 0
 */
string boolstring(bool b) {
    return b ? "true" : "false";
}

/**
 * Transforms the shared_data into a JSON.
 * @param shared_data
 * @return JSON string.
 */
string getJSONData(const SharedData& shared_data) {
    stringstream ss;
    string data;

    ss << "{" << endl;
    ss << R"( "next_date": )" + shared_data.data.next_date << endl;
    ss << R"( "rand_number": )" + std::to_string(shared_data.data.rand_number) << endl;
    ss << R"( "name": )" + shared_data.data.name << endl;
    ss << R"( "is_ready": )" + boolstring(shared_data.data.is_ready) << endl;
    ss << "}" << endl;

    return ss.str();
}

int main() {
    SharedData shared_data;
    shared_data.fillData();
    cout << getJSONData(shared_data) << endl;

    return 0;
}

