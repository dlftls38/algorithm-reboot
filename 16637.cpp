#include <bits/stdc++.h>

using namespace std;

long long ans;

void solve(int cur_n, string cur_str){
    // printf("%d %d %s\n", cur_str.size(), cur_n, cur_str.c_str());
    if((int)cur_str.size()-cur_n<=1){
        queue<int>q1;
        queue<char>q2;
        for(int i=0; i< cur_str.size();i++){
            if(cur_str[i]=='('){
                if(cur_str[i+2]=='+'){
                    q1.push((cur_str[i+1]-'0') + (cur_str[i+3]-'0'));
                }
                else if(cur_str[i+2]=='-'){
                    q1.push((cur_str[i+1]-'0') - (cur_str[i+3]-'0'));
                }
                else if(cur_str[i+2]=='*'){
                    q1.push((cur_str[i+1]-'0') * (cur_str[i+3]-'0'));
                }
                i+=4;
            }
            else if(cur_str[i]>='0' && cur_str[i]<='9'){
                q1.push(cur_str[i]-'0');
            }
            else{
                q2.push(cur_str[i]);
            }
        }
        long long val = q1.front();
        q1.pop();
        while(!q1.empty()){
            if(q2.front()=='+'){
                val+=q1.front();
            }
            else if(q2.front()=='-'){
                val-=q1.front();
            }
            else if(q2.front()=='*'){
                val*=q1.front();
            }
            q1.pop();
            q2.pop();
        }
        ans = max(ans, val);
        return;
    }
    solve(cur_n+2, cur_str);
    string temp1 = cur_str.substr(0, cur_n);
    temp1 += '(';
    temp1 += cur_str.substr(cur_n, 3);
    temp1 += ')';
    temp1 += cur_str.substr(cur_n + 3, cur_str.size()-(cur_n+3));
    solve(cur_n+6, temp1);
}

int main(){
    int n;
    string str;
    cin >> n >> str;
    ans=INT_MIN;
    solve(0, str);
    printf("%d", ans);
    return 0;
}