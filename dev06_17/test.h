template <typename T>
void sort(T arr[],int len){
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-1-i;j++)
		{
			if(arr[j]>arr[j+1]){
				T tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}
