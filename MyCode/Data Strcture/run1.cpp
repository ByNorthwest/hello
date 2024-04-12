#include<stdio.h>
int a[20],b[20],c[40];
int main(){
	int n,m;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",b+i);
	}
	int l=0,k=0;
	i=0;
	while(i<n+m&&l<n&&k<m){
		if (a[l]<b[k]){
			c[i]=a[l];
			i++;l++;
		}else{
			c[i]=b[k];
			i++;k++;
		}
	}
	if (a[l]!=0){
		while(l<n){
			c[i++] = a[l++];
		}
	}else{
		while(k<m){
			c[i++]=b[k++];
		}
	}
	for(i=0;i<n+m;i++){
		printf("%d\n",c[i]);
	}
	return 0;
}