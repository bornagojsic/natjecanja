#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> niz;

// 9 110010011
// 12 000111000111

void flip(int poz) {
    int p = niz[poz - 1];
    p = (p) ? 0 : 1;
    niz[poz - 1] = p;
}


void lijevi_flip(int poz) {
    for (int i = 0; i <= poz; ++i) {
        flip(i);
    }
}

int main() {
    cin >> N;
    int n;
    char broj = '0';
    for (int i = 0; i < N; ++i) {
        cin >> broj;
        broj = (broj == '1') ? 1 : 0;
        niz.push_back(broj);
    }
    int ohne = -1;
    int n0 = 1;
    for (int broj_u_nizu: niz) {
        if(broj_u_nizu == 0) {
            n0++;
        }
    }
    if (n0 == 2) {
       cout << 1 << endl;
       return 0;
    }
    for (int i = 0; i < N-1; ++i){
        if (ohne != -1) {
            ohne = -1;
            continue;
        } else {
            int b = niz[i];
            //cout << b << i << endl;
            if (b) {
                n++;
                if (b == niz[i+1]) {
                    ohne = i+1;
                }
            }
        }
    }
    cout << n;

    return 0;
}
