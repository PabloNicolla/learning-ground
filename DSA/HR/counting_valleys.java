class Result {
    public static int countingValleys(int steps, String path) {
        int currLevel = 0;
        int valleysCount = 0;
        boolean isInAValley = false;
        for (char c : path.toCharArray()) {
            currLevel += c == 'D' ? -1 : 1;
            if (!isInAValley && currLevel == -1) {
                valleysCount++;
                isInAValley = true;
            } else if (isInAValley && currLevel == 0) {
                isInAValley = false;
            }
        }
        return valleysCount;
    }

}