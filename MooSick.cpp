//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;
int n, c, note[20020], cnote[15];
int in[20020], s=0;
int dif[15];

int check(int s)
{
    int i;
    int x[15];
    for(i=0;i<c;i++){
        x[i]=note[s++];
    }
    sort(x, x+c);
    for(i=0;i<c-1;i++){
        if(dif[i]!=x[i+1]-x[i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> note[i];
    }
    cin >> c;
    for(i=0;i<c;i++){
        cin >> cnote[i];
    }
    sort(cnote, cnote+c);
    for(i=0;i<c-1;i++){
        dif[i]=cnote[i+1]-cnote[i];
    }
    
    for(i=0;i<n-c+1;i++){
        if(check(i)){
            in[s++]=i+1;
        }
    }
    
    cout << s << endl;
    for(i=0;i<s;i++){
        cout << in[i] << endl;
    }
    
    return 0;
}
