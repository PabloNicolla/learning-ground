class Result {
    public static String timeConversion(String s) {
        String[] timeParts = s.split(":");
        int hour = Integer.parseInt(timeParts[0]);

        if (s.endsWith("PM") && hour != 12) {
            hour += 12;
        } else if (s.endsWith("AM") && hour == 12) {
            hour = 0;
        }

        return String.format("%02d:%s:%s", hour, timeParts[1], timeParts[2].substring(0, 2));
    }

}