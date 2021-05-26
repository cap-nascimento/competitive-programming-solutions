/*
	Anderson Vieira's solution
	Don't copy this, try for yourself
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{	
	public static void main( String args[] ) throws IOException {
		BufferedReader bf = new BufferedReader( new InputStreamReader( System.in ) );

		int n = Integer.parseInt(bf.readLine());

		for(int i=0;i<n;i++)
		{
			String v[] = bf.readLine().trim().split("\\s+");
			int a = Integer.parseInt(v[0]), b = Integer.parseInt(v[1]);
			int c = Integer.parseInt(v[2]), d = Integer.parseInt(v[3]);
			if((a < c && b < d) || (a < d && b < c))
				System.out.println("S");
			else
				System.out.println("N");
		}

		bf.close();
	}
}
