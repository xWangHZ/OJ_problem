//https://www.acwing.com/problem/content/795/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main() {
	string s1,s2;
	int a[N+5],b[N+5],c[N+10];//c存放结果
	int i,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>s1>>s2;
	a[0]=s1.length();
	b[0]=s2.length();
	for(int i=1; i<=a[0]; i++) {
		a[i] = s1[a[0]-i]-'0';
	}
	for(int i=1; i<=b[0]; i++) {
		b[i] = s2[b[0]-i]-'0';
	}
	//按位处理
	for(int i = 1; i<=a[0]; i++) {
		for(int j=1; j<=b[0]; j++) {
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	int len = a[0]+b[0]+1;
	while((c[len]==0&&(len>1)))len--;//去掉最高位的零
	for(int i=len; i>=1; i--) {
		cout<<c[i];
	}
	return 0;
}
