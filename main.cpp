#include <bits/stdc++.h>

using namespace std;

int main()
{
    char perehodS[4][4] ={
        {'0', 'a', '0', '1' },
        {'0', 'b', '1', '0' },
        {'1', 'a', '0', '1' },
        {'1', 'b', '0', '0' }
    };
    char perehodQ[6][4] = {
        {'0', 'a', '0', '1' },
        {'0', 'b', '1', '0' },
        {'1', 'a', '0', '1' },
        {'1', 'b', '0', '2' },
        {'2', 'a', '0', '1' },
        {'2', 'b', '1', '0' }
    };

    cout<< "vvedite avtomat Q:" << endl;
    for (int i = 0; i < 6; ++i){
        cout<< "Vvedite sostoyanie perehoda q" << perehodQ[i][0] << " " << perehodQ[i][1];
        cin >> perehodQ[i][2];
        cout<< endl << "Vvedite kuda idet perehod q" << perehodQ[i][0] << " " << perehodQ[i][1] << "/" << perehodQ[i][2];
        cin >> perehodQ[i][3];
    }
    vector<vector<char>> v;

    for(int i = 0; i < 4; ++i)
    {
        if(i%2==0){
            for(int j = 0; j < 6; j = j + 2)
            {
                v.push_back({perehodS[i][0], perehodQ[j][0], perehodS[i][1], perehodS[i][2], perehodQ[j][1], perehodQ[j][2], perehodS[i][3], perehodQ[i][3]});
            }
        }
        else{
            for(int j = 1; j < 6; j = j + 2)
            {
                v.push_back({perehodS[i][0], perehodQ[j][0], perehodS[i][1], perehodS[i][2], perehodQ[j][1], perehodQ[j][2], perehodS[i][3], perehodQ[i][3]});
            }
        }
    }
    int sost[6] = {1,0,0,0,0,0};
    for(int i = 0; i < 12; ++i)
    {
        sost[(v[i][6]-'0')*3 + (v[i][7]-'0')] += 1;
    }

    bool otvet = true;
    for(int i = 0; i < 6; ++i)
    {
        if(sost[i] > 0)
        {
            for(int j = 0; j < 12; ++j)
            {
                if(((v[j][0]-'0')*3 + (v[j][1]-'0')) == i) {
                    if (v[j][3] != v[j][5]) otvet = false;
                }
            }
        }
    }
    if (otvet) cout << "da";
    else cout << "net";

}
