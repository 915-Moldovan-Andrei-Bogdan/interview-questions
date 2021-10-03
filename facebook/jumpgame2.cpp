
///jumpgame2 on leetcode
///bfs based solution(12ms)
///Andrei-Bogdan Moldovan

class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int> >q;
        int end=nums.size()-1;
        if(nums[0]>=1 && end==0){
            return 0;
        }
        bitset<10004>visited;
        ///q.first is the node and q.second is the number of jumps to each node in queue
        pair<int,int>var,front_value;
        int result=0;bool found=false;var.first=0;var.second=0;
        q.push(var);visited[var.first]=true;int i;
        while(!q.empty() && found==false){
            front_value=q.front();
            q.pop();
            for(i=nums[front_value.first];i>=1 && found== false;i--){
                if(visited[front_value.first+i]== false) {
                    if (front_value.first + i >= end && found == false) {
                        result = front_value.second + 1;
                        found = true;
                    } else {
                        var.first = front_value.first + i;
                        var.second = front_value.second + 1;
                        visited[var.first]=true;
                        q.push(var);
                    }
                }else{
                    break;
                }
            }
        }
        return result;
    }
};
