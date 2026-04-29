class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] reqcoin = new int[amount + 1];
        Arrays.fill(reqcoin, amount + 1);
        reqcoin[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (i - coins[j] >= 0) {
                    reqcoin[i] = Math.min(reqcoin[i], 1 + reqcoin[i - coins[j]]);
                }
            }
        }
        return reqcoin[amount] != amount + 1 ? reqcoin[amount] : -1;
    }
}