/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
import java.io.*;

public class Main{
	
	public static long s[] = new long[200010];
	public static long dp[][] = new long[200010][2];;
	public static void main( String args[] ) throws IOException {
		BufferedReader bf = new BufferedReader( new InputStreamReader( System.in ) );
		String l;
		while((l = bf.readLine()) != null){
			String line[] = l.trim().split("\\s+");
			int n = Integer.parseInt(line[0]);
			int c = Integer.parseInt(line[1]);
			line  = bf.readLine().trim().split("\\s+");
			for(int i=0;i<n;i++){
				s[i] = Long.parseLong(line[i]);
			}
			for(int i=0;i<=n;i++){
				dp[i][0] = -1;
				dp[i][1] = -1;
			}
			System.out.println(solve(0, n, c, 0));
		}

		bf.close();
	}

	public static long max(long a, long b){
		if(a > b){
			return a; 
		}
		return b;
	}

	public static long solve(int i, int n, int c, int status){
		if(i >= n){
			return 0;
		}
		if(dp[i][status] != -1){
			return dp[i][status];
		}
		if(status == 1){
			dp[i][status] = max(solve(i+1, n, c, 1), solve(i+1, n, c, 0)+s[i]);
		}else{
			dp[i][status] = max(solve(i+1, n, c, 0), solve(i+1, n, c, 1)-(s[i]+c));
		}
		return dp[i][status];
	}

}