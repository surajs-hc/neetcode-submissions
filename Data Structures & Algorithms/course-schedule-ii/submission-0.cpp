class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependants(numCourses);
        vector<int> unsatisfiedPrereqs(numCourses, 0);
        vector<int> courseOrder;

        for (const vector<int> prereq : prerequisites) {
            ++unsatisfiedPrereqs[prereq[0]];
            dependants[prereq[1]].push_back(prereq[0]);
        }

        queue<int> takeableCourses;
        for (int course = 0; course < numCourses; ++course) {
            if (unsatisfiedPrereqs[course] == 0) {
                takeableCourses.push(course);
            }
        }
        
        for (int courseCount = 0; courseCount < numCourses; ++courseCount) {
            if (takeableCourses.empty()) {
                return vector<int>{};
            }
            int course = takeableCourses.front();
            takeableCourses.pop();
            courseOrder.push_back(course);
            for (int subsequentCourse : dependants[course]) {
                if (--unsatisfiedPrereqs[subsequentCourse] == 0) {
                    takeableCourses.push(subsequentCourse);
                }
            }
        }

        return courseOrder;
    }
};
