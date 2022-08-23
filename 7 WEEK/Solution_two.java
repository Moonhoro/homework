import java.util.Collections;
import java.util.PriorityQueue;

public class Solution_two {
    public int[] getLeastNumbers(int[] arr, int k) {
        PriorityQueue<Integer>pq= new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<k;i++)pq.add(arr[i]);
        for(int i=k;i<arr.length;i++)if(!pq.isEmpty()&&arr[i]<pq.peek()){
            pq.remove();
            pq.add(arr[i]);
        }
        int[] res=new int[k];
        for (int i=0;i<k;i++){
            res[i]=pq.remove();
        }
        return  res;
    }
}
