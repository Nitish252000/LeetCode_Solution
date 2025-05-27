class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans=new ArrayList<Integer>();
        int top=0,left=0,bottom=matrix.length-1,right=matrix[0].length-1;
        while(left<=right && top<=bottom){
            // Traverse top row
            for(int i=left;i<=right;i++){
                ans.add(matrix[top][i]);
            }
            top++;
            // Traverse right column
            for(int i=top;i<=bottom;i++){
                ans.add(matrix[i][right]);
            }
            right--;
            // Traverse bottom row
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.add(matrix[bottom][i]);
                }
                bottom--;
            }
            // Traverse left column
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.add(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
}
