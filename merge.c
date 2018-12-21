#include<stdio.h>
int m[100],i,low,high,c=0,p=1,q[100],left,right,pivot,qsortp,t,ce=0,cq=0,leftpointer,rightpointer,cqp=0,pass=1,cmp=0,passm=1,n,i,it;
void divide(int low,int high);
void merge(int low,int mid,int high);
void quick(int q[],int n);
void qdivide(int left,int right);
int qsort(int left,int right,int pivot);
void main()
{
   
    printf("\nEnter no. of elements\n");
    scanf("%d",&n);
    printf("\nEnter elements\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&m[i]);
         q[i]=m[i];
    }
    divide(0,n-1);
    printf("\nSorted array of Merge sort\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",m[i]);
    }
    printf("\nTotal no. of Comparison of merge sort=%d",c);
    quick(q,n);
    printf("\n\nSorted array of Quick sort\n");
    for(i=0;i<n;i++)
    {
         printf("%d\t",q[i]);
    }
    printf("\nTotal no. of Comparison of Quick sort=%d",cq);
    
}
void divide(int low,int high)
{
      int mid;
      if(low<high)
      {   
          mid=(low+high)/2;
          divide(low,mid);
          divide(mid+1,high);
          merge(low,mid,high);
      }
      else
      {
         return;
      }
}
void merge(int low,int mid,int high)
{
     int l,h,b[100],a1,a2;
     a1=mid-low+1;
     a2=high-mid;
     printf("\npass%d\n",passm);
     printf("Left Array=");
     for(i=0;i<a1;i++)
         printf("%d  ",m[low+i]);
     printf("\nRight Array=");
     for(i=0;i<a2;i++)
         printf("%d  ",m[mid+1+i]);
     for(l=low,i=low,h=mid+1;l<=mid&&h<=high;i++)
     {
         if(m[l]<=m[h])
         {
            c++;
            cmp++;
            b[i]=m[l];
            l++;
         }
         else
         {
            b[i]=m[h];
            h++;
         }  
    }
    while(l<=mid)
    {
        b[i]=m[l];
        i++;
        l++;
    }
    while(h<=high)
    {
        b[i]=m[h];
        i++;
        h++;
    }
    passm++;
    printf("\nNo. of Comparison=%d\n",cmp);
    cmp=0;
    for(i=low;i<=high;i++)
    {
        m[i]=b[i];
    }
    
}                                         
void quick(int q[],int n)    
{
      printf("\n\nInput array of quick sort\n");
      for(i=0;i<n;i++)
           printf("%d\t",q[i]);
      qdivide(0,n-1); 
}
void qdivide(int left,int right)
{
      if(right-left <= 0)
      {
         return;   
      }
      else 
      {
         pivot = q[right];
         qsortp = qsort(left, right, pivot);
         qdivide(left,qsortp-1);
         qdivide(qsortp+1,right);
      }     
}
int qsort(int left,int right,int pivot)
{
     int lp,rp;
     lp = left-1;
     rp = right;
     while(lp<rp)
     {
         while(q[++lp] < pivot) 
         {
             cq++;
             cqp++;
         }
         while(rp > 0 && q[--rp] > pivot) 
         {
             cq++;
             cqp++;
         }
         if(lp >= rp) 
         {
            
            break;
              
         } 
         else 
         {
            printf("\npass%d",pass);
            printf("\nItem swapped :%d,%d\n", q[lp],q[rp]);
            t=q[lp];
            q[lp]=q[rp];
            q[rp]=t;
            for(i=0;i<n;i++)
                 printf("%d\t",q[i]);
            printf("\nNo. of Comparison:%d\n",cqp);
            pass++;
            cqp=0;
          }
         
      }
      printf("\npass%d",pass);
      printf("\nPivot swapped :%d,%d\n", q[lp],q[right]);
      t=q[lp];
      q[lp]=q[right];
      q[right]=t;
      for(i=0;i<n;i++)
                 printf("%d\t",q[i]);
      printf("\nNo. of Comparison:%d\n",cqp);
      pass++;
      cqp=0;
      return lp;
}
    
/*tejal@ubuntu:~/Desktop/daa$ gcc merge.c
tejal@ubuntu:~/Desktop/daa$ ./a.out

Enter no. of elements
5

Enter elements
8 6 1 9 3

pass1
Left Array=8  
Right Array=6  
No. of Comparison=0

pass2
Left Array=6  8  
Right Array=1  
No. of Comparison=0

pass3
Left Array=9  
Right Array=3  
No. of Comparison=0

pass4
Left Array=1  6  8  
Right Array=3  9  
No. of Comparison=3

Sorted array of Merge sort
1	3	6	8	9	
Total no. of Comparison of merge sort=3

Input array of quick sort
8	6	1	9	3	
pass1
Item swapped :8,1
1	6	8	9	3	
No. of Comparison:1

pass2
Pivot swapped :6,3
1	3	8	9	6	
No. of Comparison:1

pass3
Pivot swapped :8,6
1	3	6	9	8	
No. of Comparison:2

pass4
Pivot swapped :9,8
1	3	6	8	9	
No. of Comparison:1


Sorted array of Quick sort
1	3	6	8	9	
Total no. of Comparison of Quick sort=5tejal@ubuntu:~/Desktop/daa$ */

