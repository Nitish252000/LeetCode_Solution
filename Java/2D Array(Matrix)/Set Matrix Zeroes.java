class Solution {
    public void setZeroes(int[][] matrix) {
        HashSet<Integer>zrow = new HashSet();
        HashSet<Integer>zcol=new HashSet();
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    zrow.add(i);
                    zcol.add(j);
                }
            }
        }
        for(int r:zrow){
            for(int i=0;i<matrix[0].length;i++){
                matrix[r][i]=0;
            }
        }
        for(int c:zcol){
            for(int j=0;j<matrix.length;j++){
                matrix[j][c]=0;
            }
        }
    }
}
