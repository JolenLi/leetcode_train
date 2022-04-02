//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;

//vector<vector<int>> mustLearn;
//vector<int> visited;
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
//    for (const int &needLearn:mustLearn[course])
//        if (!learn(needLearn))
//            return false;
//    visited[course] = 2;
//    return true;
//}
//
//bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
//    mustLearn = vector<vector<int>>(numCourses);
//    visited = vector<int>(numCourses, 0);
//    for (vector<int> &require:prerequisites)
//        mustLearn[require[0]].push_back(require[1]);
//    for (int i = 0; i < numCourses; i++)
//        if (!learn(i))
//            return false;
//    return true;
//}

vector<vector<int>> mustLearn;
vector<int> indeg;

bool bfs(int numCourses){
    queue<int> courses;
    for (int i = 0; i < numCourses; i++)
        if (indeg[i] == 0)
            courses.push(i);
    int learned = 0;
    while (!courses.empty()) {
        int course = courses.front();
        courses.pop();
        learned++;
        for (const int &next:mustLearn[course]) {
            indeg[next]--;
            if (indeg[next] == 0)
                courses.push(next);
        }
    }
    return learned == numCourses;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    mustLearn.resize(numCourses);
    indeg.resize(numCourses, 0);
    for (vector<int> &require:prerequisites) {
        mustLearn[require[0]].push_back(require[1]);
        indeg[require[1]]++;
    }
   return bfs(numCourses);
}


int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << canFinish(numCourses, prerequisites) << endl;

}