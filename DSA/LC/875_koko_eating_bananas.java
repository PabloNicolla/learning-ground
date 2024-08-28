class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxPile = 0;

        for (int num : piles) {
            if (maxPile < num) {
                maxPile = num;
            }
        }

        int left = 1;
        int right = maxPile - 1;
        int bananaPerHour;
        int minBananaPerHour = maxPile;

        while (left <= right) {
            bananaPerHour = (right - left) / 2 + left;
            int hoursUsed = 0;
            for (int bananas : piles) {
                hoursUsed += (int) Math.ceil((double) bananas / bananaPerHour);
                if (hoursUsed > h) {
                    break;
                }
            }

            if (hoursUsed > h) {
                left = bananaPerHour + 1;
            } else {
                right = bananaPerHour - 1;
                minBananaPerHour = bananaPerHour;
            }
        }

        return minBananaPerHour;
    }
}