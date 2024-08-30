class Result {
    public static int marsExploration(String s) {
        int changes = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (i % 3) {
                case 0:
                case 2: {
                    changes += s.charAt(i) == 'S' ? 0 : 1;
                    break;
                }
                case 1: {
                    changes += s.charAt(i) == 'O' ? 0 : 1;
                    break;
                }
            }
        }
        return changes;
    }

}