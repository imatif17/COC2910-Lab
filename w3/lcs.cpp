#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;

int main(){
	int n,m,i,j,x,y,lar;
	string a,b,seq;
	int lcs_table[15][15] = {};
	cout<<"Enter first string"<<endl;
	cin>>a;
	cout<<"Enter second string"<<endl;
	cin>>b;
	n = a.size();
	m = b.size();

	//LCS Table construction

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(a[i] == b[j]){
				lcs_table[i+1][j+1] = 1 + lcs_table[i][j];
			}
			else
				lcs_table[i+1][j+1] = (lcs_table[i][j+1] > lcs_table[i+1][j]) ? lcs_table[i][j+1] : lcs_table[i+1][j];
		}	
	}
	//Printing LCS table
	cout<<"LCS table is :"<<endl;
	for(i = 0; i <= n; i++){
		for(j = 0; j <= m; j++){
			cout<<lcs_table[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	//Printing LCS sequence
	i = n;
	j = m;
	while(i > 0 && j > 0){
		x = lcs_table[i-1][j];
		y = lcs_table[i][j-1];
		lar = (x>y)?x:y;
		if(lcs_table[i][j] == lar){
			if(x > y)
				i--;
			else
				j--;
		}
		else{
			seq += b[j-1];
			j--;
			i--;
		}
	}
	reverse(seq.begin(),seq.end()); 
	cout<<"\nLongest sequence is : "<<lcs_table[n][m]<<endl;
	cout<<"Sequence is : "<<seq<<endl;
}
