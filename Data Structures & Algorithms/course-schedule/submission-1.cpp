class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereqGraph(numCourses);
        vector<int> incomingEdges(numCourses, 0);

        for (const vector<int>& prereq : prerequisites) {
            ++incomingEdges[prereq[1]];
            prereqGraph[prereq[0]].push_back(prereq[1]);
        }

        queue<int> availableCourses;
        for (int course = 0; course < numCourses; ++course) {
            if (incomingEdges[course] == 0) {
                availableCourses.push(course);
            }
        }

        for (int courseCounter = 0; courseCounter < numCourses; ++courseCounter) {
            if (availableCourses.empty()) {
                return false;
            }
            int courseToFinish = availableCourses.front();
            availableCourses.pop();
            for (int course : prereqGraph[courseToFinish]) {
                if (--incomingEdges[course] == 0) {
                    availableCourses.push(course);
                }
            }
        }
        return true;
    }
};
