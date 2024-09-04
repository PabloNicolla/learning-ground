from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        courses = dict()
        all_visited = set()

        for course in range(numCourses):
            courses[course] = []

        for course, prerequisite in prerequisites:
            courses[course].append(prerequisite)

        for course, c_prerequisites in courses.items():
            if not c_prerequisites:
                all_visited.add(course)
            elif course in all_visited:
                continue
            elif not self.dfs(course, all_visited, courses):
                return False
        return True

    def dfs(self, course: int, all_visited: set, courses: dict) -> bool:
        visited_memory = set()
        local_visited = set()

        def helper(cur_course: int):
            if cur_course in all_visited:
                return True
            if cur_course in local_visited:
                return False
            local_visited.add(cur_course)

            for prerequisite in courses[cur_course]:
                if not helper(prerequisite):
                    return False
            local_visited.remove(cur_course)
            visited_memory.add(cur_course)
            return True

        ans = helper(course)
        all_visited.update(visited_memory)
        return ans
