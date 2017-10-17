/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
