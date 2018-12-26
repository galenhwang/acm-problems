#include <bits/stdc++.h>

#define Max 100000

using namespace std;

bool check[Max];
int Prime[Max];

void get_prime(){
    int k = 0;
    check[0] = true;
    check[1] = true;
    for(int i = 2; i < Max; i++){
        if(!check[i]){
            Prime[k++] = i;
        }
        for(int j = i+i; j < Max; j += i){
            check[j] = true;
        }
    }
}

int DividInPrime(int num){
    int k = 0;
    for(int i = 0; pow(Prime[i], 2) <= num; i++) {
        while (num % Prime[i] == 0){
            num /= Prime[i];
            k++;
        }
    }
    if (num != 1) {
      k++;
    }
    return k;
}

int main() {
    get_prime();
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; i++){
      if(!check[DividInPrime(i)]) {
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
}
