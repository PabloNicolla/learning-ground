import java.util.List;

class Result {
    public static List<Integer> gradingStudents(List<Integer> grades) {
        for (int i = 0; i < grades.size(); i++) {
            Integer grade = grades.get(i);
            if (grade >= 38 && ((grade % 5) >= 3)) {
                grades.set(i, grade + (5 - (grade % 5)));
            }
        }

        return grades;
    }
}