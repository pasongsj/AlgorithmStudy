// 2024.10.23
// PGS_43165_타겟넘버
#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int>& numbers, int& answer, int& target, int cnt = 0, int sum = 0){
    if(cnt == numbers.size() - 1){ 
        if(target == sum + numbers[cnt]) answer++;
        if(target == sum - numbers[cnt]) answer++;
        return;
    }
    bfs(numbers, answer, target, cnt + 1, sum + numbers[cnt]);
    bfs(numbers, answer, target, cnt + 1, sum - numbers[cnt]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    bfs(numbers, answer, target);
    return answer;
}
