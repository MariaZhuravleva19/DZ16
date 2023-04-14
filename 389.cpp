#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

bool isGrayCode(const vector<int>& seq)
{
    int n = seq.size();
    for (int i = 0; i < n; i++)
    {
        int diff = seq[i] ^ seq[(i + 1) % n];
        if (diff == 0 || (diff & (diff - 1)) != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream input;
    input.open("389(input).txt");
    ofstream output;
    output.open("389(output).txt");


    int n, m;
    input >> n;
    vector<int> seq(1 << n);
    for (int i = 0; i < (1 << n); i++)
    {
        input >> seq[i];
    }
    input >> m;
    for (int k = 0; k < m; k++)
    {
        int i, j;
        input >> i >> j;
        swap(seq[i], seq[j]);
        if (isGrayCode(seq))
        {
            output << "Yes" << endl;
        }
        else
        {
            output << "No" << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}