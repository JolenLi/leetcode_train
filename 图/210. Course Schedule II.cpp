//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;


//
//vector<vector<int>> edge;
//vector<int> visited;
//vector<int> ans;
/////// visted=0 未检查过
/////// visted=1 正在检查
/////// visted=2 备忘可以学习
//
//bool learn(int course) {
//    if (visited[course] == 1)
//        return false;
//    if (visited[course] == 2)
//        return true;
//    visited[course] = 1;
//    for (const int &needLearn:edge[course])
//        if (!learn(needLearn))
//            return false;
//    ans.push_back(course);
//    visited[course] = 2;
//    return true;
//}
//
//vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
//    edge = vector<vector<int>>(numCourses);
//    visited = vector<int>(numCourses, 0);
//    for (vector<int> &require:prerequisites)
//        edge[require[0]].push_back(require[1]);
//    for (int i = 0; i < numCourses; i++)
//        if (!learn(i))
//            return {};
//    return ans;
//}




vector<vector<int>> edge;
vector<int> indeg;
vector<int> ans;

bool bfs(int numCourses) {
    queue<int> courses;
    for (int i = 0; i < numCourses; i++)
        if (indeg[i] == 0)
            courses.push(i);
    while (!courses.empty()) {
        int course = courses.front();
        courses.pop();
        ans.push_back(course);
        for (const int &next:edge[course]) {
            indeg[next]--;
            if (indeg[next] == 0)
                courses.push(next);
        }
    }
    return ans.size() == numCourses;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    edge.resize(numCourses);
    indeg.resize(numCourses, 0);
    for (vector<int> &require:prerequisites) {
        edge[require[1]].push_back(require[0]);
        indeg[require[0]]++;
    }
    if (bfs(numCourses))
        return ans;
    else
        return {};
}


int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto ans = findOrder(numCourses, prerequisites);
    for (auto i :ans)
        cout << i;
    cout << endl;
}