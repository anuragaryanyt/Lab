public class ques4 {
    public static void main(String[] args) {
        int[][] arr = new int[3][3];
        int index = 0;

        for(int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = Integer.parseInt(args[index++]);
            }
        }

        int left = 0, right = 0;
        for(int i = 0; i < 3; i++) 
        {
            left += arr[i][i];
            right += arr[i][2 - i];
        }
        System.out.println("Sum of Left Diagonal : " +left+ "\nSum of Right Diagonal : "+right);
    }
}
