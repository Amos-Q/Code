#define _CRT_SECURE_NO_WARNINGS 1
void bubble_sort() {
?      int a[] = {1, 34, 23, 55, 22, 11};
        int i,j,k;   
	 
	for(i=0;i<5;i++)      
	{
		for(j=0;j<5-i;j++)
			if(a[j]>a[j+1])      
			{
				
				k=a[j];           
				a[j]=a[j+1];           
				a[j+1]=k;  
				printf("%d\n", a[j]);
			
			
			//	a[j] ^= a[j+1] ^= a[j];
			}    
	}

void insert_sort() {
        int i, j, m, tmp;
	int a[10] = {1, 34, 23, 55, 22, 11, 45, 67, 35, 26};
#if 1
	for(i=0;i<10;i++) {
		m=a[i];         
		for(j=i-1;j >= 0;j--) {
		    if(a[j] < m)
				break;
			else 
				a[j+1] = a[j];
		}
		a[j+1] = m;
	}
#else 
	for(i = 1; i < 10; i++) {
		m = 5;
		if(i != m){
			j = i;
			tmp = a[i];
			while(j > m){
				a[j] = a[j-1];
				j--;
			}
			a[j] = tmp;
		}
	}

quick_sort(int L[],int first,int end) {  
	int pos;      
	if(end>first) {  
		pos=quick(first,end,L);         
		quick_sort(L,first,pos-1);         
		quick_sort(L,pos+1,end);      
	}   
}
quick(int first,int end,int L[]) { 
	int left=first,
		right=end,key;   
	key=L[first];   
 
	while(left<right) {  
		while((left<right)&&(L[right]>=key)) {
		        right--;       
			printf("left:%d  right:\n",left);
		}
		if(left<right) {
			L[left++]=L[right];       
		//	printf("left2:%d  right: \n",left);
		}
		while((left<right)&&(L[left]<=key))      
			left++;       
		if(left<right)
			L[right--]=L[left];
	}      
	L[left]=key;      
//	printf("left3:%d  right: \n",left);
	return left;   
}    