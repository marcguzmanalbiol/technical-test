#include <iostream>
#include <string>
#include <bits/stdc++.h>

void print_permutations(std::string str, std::string aux_str);

using namespace std;

int main(void)
{

    string str;

    cout << "***************************************************" << endl;
    cout << "Program to get all permutations of a given string " << endl;
    cout << "Please, introduce a string:                       " << endl;
    cin >> str;
    cout << "**************************************************" << endl;

    print_permutations(str, "");
    return 0;
}

/**
 * @brief This function prints in the console all posible permutations of a given string using recursion. 
 * 
 * @param str String from which we will obtain all possible permutations.
 * @param aux_str Auxiliary string used in the recursion step. 
 */
void print_permutations(string str, string aux_str)
{

    /**
     * @brief Base case of the recursion. 
     * 
     */
    if (str.length() == 0)
    {
        cout << aux_str << endl;
    }

    for (int i = 0; i < str.length(); i++)
    {
        print_permutations(str.substr(1), aux_str + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}