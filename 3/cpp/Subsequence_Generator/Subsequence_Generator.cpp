
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void GenerateSubsequences(string str)
{
    // Return value is stored
    // on vecString

    // Retrieve str length
    int strLen = str.size();

    // bitCounter is used to check
    // character position
    int bitCounter = pow(2, strLen);

    // Check from 000..001 to 111..111
    // Empty subset is ignored
    for (int i = 1; i < bitCounter; ++i)
    {
        // Temporary variable
        // to store current subsequence
        string subsequence = "";

        // Construct the new subsequence string
        for (int j = 0; j < strLen; j++)
        {
            if (i & (1 << j))
                subsequence += str[j];
        }
        cout<<subsequence<<" "<<i<<endl;
    }

}

int main()
{
    cout << "Subsequence Generator" << endl;

    // Input string
    string str;
    cout << "Input string -> ";
    getline(cin, str);

    // Generate subsequences
GenerateSubsequences(str);
    return 0;
}
