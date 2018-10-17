#include <iostream>
using namespace std;

string letters = "abcdefghijklmnopqrstuvwxyz ";
void break_otp(string ciphertext[])
{
    int n = sizeof(ciphertext);
    int l = ciphertext[0].size();
    cout << n << "," << l << endl;
    string keys = "";
    for (int j = 0; j < l; j++)
    {
        
        for (int key = 0; key < 256; key++)
        {
            int c = 0; //counter
            for (int i = 0; i < n; i++)
            {
                char m = ciphertext[i][j];
                char r = m ^ (char)key;
                if (letters.find(r) == string::npos)
                {
                    c++;
                } else {
                    cout << m << "," << r << endl;
                }
            }
            if (c == 0)
                keys += key;
        }
    }
    cout << "keys: " << keys.size() << endl;
    keys = "cscmhbpgflzqaiayfeda";
    for (int i = 0; i < n; i++)
    {
        string plaintext = "";

        for (int j = 0; j < l; j++)
        {
            char m = (char)ciphertext[i][j];
            cout << m;
            plaintext = plaintext + (char)(m ^ keys[j]);
        }
        cout << plaintext << endl;
    }
}
