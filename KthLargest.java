import java.util.concurrent.PriorityBlockingQueue;
import java.util.*;
public class KthLargest{
  public static int  kthLargestMinHeap(int[] arr,int k){
      if(arr.length<k){
          System.out.println("Invalid");
          return -1;
      }
      PriorityQueue<Integer> minHeap=new PriorityQueue<>();
      for(int i=0;i<k;i++){
         minHeap.add(arr[i]); 
      }
      for(int i=k;i<arr.length;i++){
          if(arr[i]>minHeap.peek()){
              minHeap.poll();
              minHeap.add(arr[i]);

          }

      }
      return minHeap.peek();
  }
     public static void main(String[] args) {
         
        int[] arr={10,7,11,30,2,38,2,45};
        int k=3;
        System.out.println(kthLargestMinHeap(arr,k));

        // System.out.println(kthLargestMaxHeap(arr,k));
    }
}