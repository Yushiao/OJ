// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
// https://uva.onlinejudge.org/external/1/100.pdf
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m, n;
    int start, end;
    int num;
    int cycle = 0;
    int max_cycle = 0;
    while(cin >> m >> n){
        max_cycle = 0;
        if(m>n){
            start=n;
            end=m;
        }
        else{
            start=m;
            end=n;
        }
        for(int i=start; i<=end; i++){
            num = i;
            // printf("%d ", num);
            cycle = 1;
            while(num!=1){
                if(num%2 == 1){
                    num = 3*num + 1;
                }
                else{
                    num = num / 2;
                }
                // printf("%d ", num);
                cycle++;
            }
            if(cycle > max_cycle){
                max_cycle = cycle;
            }
            // printf("%d\n", cycle);
            // printf("\n");
        }
        printf("%d %d %d\n", m, n, max_cycle);
    }
    return 0;
}
