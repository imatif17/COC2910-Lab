import java.util.Scanner;


public class Matrix_Chain_Multiplication{

	static int ch;
	
	public static void Parenthesis(int i, int j, int[][] s){
		if (i==j){
			System.out.print(ch++);
			return;
		}

		System.out.print("(");
		Parenthesis(i, s[i][j], s);
		Parenthesis(s[i][j] + 1, j, s);
		System.out.print(")");
	} 
	
	
	public static void main(String[] args){
		int n,i,j,least,q;

		int[] shape= new int[10];
		int[][] cost = new int[10][10];
		int[][] s = new int[10][10];

		System.out.println("Enter the number of matrix to multiply");
		Scanner take = new Scanner(System.in);
		n = take.nextInt();

		System.out.println("If number of matrix is 3 with size (2,3), (3,4) and (4,5) than enter as (2,3,4,5)");
		System.out.println("Enter the size of matrices");
		for(i = 0; i <= n; i ++){
			shape[i] = take.nextInt();
			System.out.println("");
			if(i != n){
				System.out.print("Enter "+(n-i)+" more numbers");
				System.out.println("");
			}
		}

	
		for(int d = 1; d < n; d++){
			for(i = 1; i < n + 1 - d; i++){
				j = i + d;
				least = 1000000;
				for(int k = i; k <= j - 1; k++){
					q = cost[i][k] + cost[k+1][j] + shape[i-1] * shape[k] * shape[j];
					if (q < least){
						least = q;
						s[i][j] = k;
					}
				}
				cost[i][j] = least;
			}
		}
		
		System.out.println("Minimum number of multiplications : "+cost[1][n]);

		ch = 1;
		System.out.print("Multiply as : ");
		Parenthesis(1,n, s);
		System.out.println("");
	}

}


