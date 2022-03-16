//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
vector<vector<int>> mustLearn;
vector<bool> visited;
vector<bool> learned;
vector<int> inDegree;
vector<int> res;

bool dfs( int course) {
    if (learned[course])
        return true;
    else if (visited[course])
        return false;
    visited[course]=true;
    for (auto &nextCourse:mustLearn[course])
        if(!dfs(nextCourse))
            return false;
    learned[course] = true;
    res.push_back(course);
    visited[course] = false;
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    mustLearn = vector<vector<int>>(numCourses);
    learned = vector<bool>(numCourses, 0);
    visited = vector<bool>(numCourses, 0);
    for (auto &it :prerequisites)
        mustLearn[it[0]].push_back(it[1]);
    for (int i = 0; i < numCourses; i++)
        if (!learned[i] && !dfs(i))
            return {};
    return res;
}
//
//bool bfs(int course) {
//    queue<int> learnLast;
//    for (int i = 0; i < course; i++)
//        if (inDegree[i] == 0) {
//            learnLast.push(i);
//            visited[i] = true;
//        }
//    while (!learnLast.empty()) {
//        int cur = learnLast.front();
//        learnLast.pop();
//        visited[cur] = true;
//        res.push_back(cur);
//        for (auto &nextCourse:mustLearn[cur]) {
//            inDegree[nextCourse]--;
//            if (inDegree[nextCourse] == 0)
//                learnLast.push(nextCourse);
//        }
//    }
//    for (int i = 0; i < course; i++)
//        if (!visited[i])
//            return false;
//    return true;
//}
//
//
//vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//    mustLearn = vector<vector<int>>(numCourses);
//    inDegree = vector<int>(numCourses, 0);
//    visited = vector<bool>(numCourses, false);
//    for (auto &it :prerequisites) {
//        mustLearn[it[0]].push_back(it[1]);
//        inDegree[it[1]]++;
//    }
//    if(!bfs(numCourses))
//        return {};
//    reverse(res.begin(),res.end());
//    return res;
//}
int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    for(auto i:findOrder(numCourses, prerequisites))
    cout <<i  << endl;
}