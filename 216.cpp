#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

int main()
{

    ifstream input;
    input.open("216(input).txt");
    ofstream output;
    output.open("216(output).txt");

    int n;
    input >> n;

    vector<int> albums(n);
    int capacity = 0;

    for (int i = 0; i < n; i++)
    {
        input >> albums[i];
        capacity += albums[i];
    }



    int labels = 0;
    int current_capacity = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (current_capacity + albums[i] <= capacity / 2)
        {
            current_capacity += albums[i];
            labels += albums[i];
        }
        else
        {
            labels += (capacity / 2 - current_capacity);
            break;
        }
    }

    output << labels << endl;


    input.close();
    output.close();

    return 0;
}