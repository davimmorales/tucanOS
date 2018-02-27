int mean(int arr[], int sz)
{
    int result;
    int ct;
    result = 0;
    while(ct<sz){
        result = result + arr[ct];
	ct = ct + 1; 
   }
    result = result/sz;
    return result;
}

void main(void)
{
    int array[3];
    int size;
    int count;

    size = 3;
    count = 0;
    while(count<size){
	array[count] = input();
	count = count + 1;
    }
    	
    output(mean(array,size));
}
