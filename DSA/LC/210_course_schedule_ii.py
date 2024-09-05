
from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        courses = dict()
        all_visited = set()
        ans = []

        for course in range(numCourses):
            courses[course] = []

        for course, prerequisite in prerequisites:
            courses[course].append(prerequisite)

        for course, c_prerequisites in courses.items():
            if course in all_visited:
                continue
            if not c_prerequisites:
                ans.append(course)
                all_visited.add(course)
            elif not self.dfs(course, all_visited, courses, ans):
                return []
        return ans

    def dfs(self, course: int, all_visited: set, courses: dict, ans: list) -> bool:
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

            if cur_course not in visited_memory:
                ans.append(cur_course)
            visited_memory.add(cur_course)
            return True

        ans = helper(course)
        all_visited.update(visited_memory)
        return ans
