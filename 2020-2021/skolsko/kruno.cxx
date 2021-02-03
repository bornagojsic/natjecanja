#include <bits/stdc++.h>

using namespace std;

const int MAX = 12;

char dvorana[MAX][MAX];
int R, S;
pair<int,int> mjesta_sjedala[MAX*MAX];
int bio[MAX][MAX];

// 3 6 .......##.###....#
// 7 5 #.... #.##. #.... #.### ..... .##.# ....#

pair<int,int> dx[4] = {pair<int,int> (0, 1),
                       pair<int,int> (0, -1),
                       pair<int,int> (1, 0),
                       pair<int,int> (-1, 0)};

pair<int,int> dd[4] = {pair<int,int> (1, 1),
                       pair<int,int> (1, -1),
                       pair<int,int> (-1, 1),
                       pair<int,int> (-1, -1)};


int sjedala(int r, int s, int ima) {
    int ima_sjedala = ima;
    cout << r << s << ima << endl;
    if (dvorana[r][s] == '#') {
        bio[r][s] = ima_sjedala;
        for (pair<int,int> xy: dx) {
            if (ima_sjedala > 20) {
                break;
            }
            if (dvorana[r + xy.first][s + xy.second] == '#' && bio[r + xy.first][s + xy.second] == 0) {
                cout << r << " " << s << " " << xy.first << xy.second << endl;
                sjedala(r+xy.first, s+xy.second, ima+1);
                for(pair<int,int> dxy: dd) {
                    if (dvorana[r + dxy.first][s + dxy.second] == '#' || dvorana[r + dxy.first + xy.first][s + dxy.second + xy.second] == '#') {
                        //cout << r << " " << xy.first << " " << s << " " << " " << xy.second << endl;
                        ima_sjedala = 100;
                        break;
                    }
                }
                ima_sjedala++;
            }
        }
    }
    return ima_sjedala + 1;
}


int main() {
    int brojac = 0;
    cin >> R >> S;
    for (int i = 1; i < R + 1; ++i) {
        for (int j = 1; j < S + 1; ++j) {
            cin >> dvorana[i][j];
            if (dvorana[i][j] == '#') {
                mjesta_sjedala[brojac] = pair<int, int>(i, j);
                brojac++;
            }
            // cout << dvorana[i][j];
        }
        // cout << endl;
    }

    for(pair<int,int> sjedalo: mjesta_sjedala) {
        if(sjedalo.first && sjedalo.second) {
            cout << sjedalo.first << " " << sjedalo.second << endl;
            cout << sjedala(sjedalo.first, sjedalo.second, 0) << endl;
        }
    }

    return 0;
}
