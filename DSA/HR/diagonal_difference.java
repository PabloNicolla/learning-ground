import java.util.List;

class Result {

    public static int diagonalDifference(List<List<Integer>> arr) {
        int leftDiagonal = 0, rightDiagonal = 0;
        for (int i = 0; i < arr.size(); i++) {
            leftDiagonal += arr.get(i).get(i);
            rightDiagonal += arr.get(i).get(arr.size() - 1 - i);
        }

        return Math.abs(leftDiagonal - rightDiagonal);
    }

}