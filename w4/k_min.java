import java.util.*;


public class k_min{

	public static int minimum(int a, int b){
		if (a > b)
			return b;
		return a;
	}

	public static int k_smallest(int[] arr1, int[] arr2, int m, int n, int k){
		if(m > n)
			return k_smallest(arr2,arr1,n,m,k);
		if(m == 0 && n > 0)
			return arr2[k-1];
		if(k == 1)
			return minimum(arr1[0],arr2[0]);
		int i = minimum(k/2, m);
		int j = minimum(k/2, n);

		int[] temp = new int[15];

		if(arr1[i-1] < arr2[j-1])
		{
			temp = Arrays.copyOfRange(arr1, i, m);
			return k_smallest(temp, arr2, (m - i), j, (k-i));
		}
		else
		{
			temp = Arrays.copyOfRange(arr2, j, n);
			return k_smallest(arr1,temp,i,(n - j),(k-j));
		}

	}
	
	public static void main(String[] args){
		int n,m,i,k;
		int[] array1 = new int[15];
		int[] array2 = new int[15];

		System.out.println("Enter the size of first array");
		Scanner take = new Scanner(System.in);
		m = take.nextInt();
		System.out.println("Enter the size of second array");
		n = take.nextInt();

		System.out.println("Enter the elements of first array");
		for(i = 0; i < m; i++)
			array1[i] = take.nextInt();

		System.out.println("Enter the elements of second array");
		for(i = 0; i < n; i++)
			array2[i] = take.nextInt();
		
		System.out.println("Enter the number k");
		k = take.nextInt();

		System.out.println(k_smallest(array1,array2,m,n,k));
	}
}
