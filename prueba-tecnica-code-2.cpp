#include <thread>
#include <iostream>

#include <cstdlib>
#include <ctime>

using namespace std;

class SharedData {
private:

public:

    string next_date;
    int rand_number;
    string name = "Marc Guzman Albiol";
    bool is_ready;

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

    void dateThread() {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        rawtime += 60 * 60 * 24 * 123;
        timeinfo = localtime(&rawtime);

        strftime(buffer, 80, "%Y-%m-%d", timeinfo);
        string str(buffer);
        next_date = buffer;
    }

    void nameThread() {
        reverse(name.begin(), name.end());
    }

    void randomThread() {
        srand(time(nullptr));
        rand_number = rand() % 100 + 1;
    }

    void isReadyThread() {
        is_ready = true;
    }
};

void printData(SharedData shared_data) {
    cout << "******************************" << endl;
    cout << shared_data.next_date << endl;
    cout << shared_data.name << endl;
    cout << shared_data.rand_number << endl;
    cout << shared_data.is_ready << endl;
    cout << "******************************" << endl;
}

int main() {

    SharedData shared_data;
    shared_data.fillData();
    printData(shared_data);

    return 0;
}

