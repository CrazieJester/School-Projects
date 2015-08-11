//finds index of biggest row in 2d array
  
public static int findMaxRow(int[][] newArray) {
    int ans = 0;
    int maxRowNum = 0;
    for (int i = 0; i < newArray.length; i++) {
    int rowTotal = 0;
        for (int j = 0; j < newArray[i].length; j++) {
            rowTotal += newArray[i][j];
            }
if (rowTotal > maxRowNum) {
maxRowNum = rowTotal;
ans = i;
        }
    }
return ans;
}