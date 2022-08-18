class Solution {
public:
    
//    int partition(vector<int> &arr, int s, int e){
//         int cnt =0;
//         int pivot = arr[s];
//         for(int i =s+1; i<=e; i++){
//             if(arr[i]<=pivot) cnt++;
//         }
//         int pivInd = s + cnt;
//         swap(arr[pivInd], arr[s]);
    
    
//         int i = s;
//         int j = e;
//         while(i<pivInd && j>pivInd){
//             while(arr[i]<=pivot){
//                  i++;
//             }
//             while(arr[j]>pivot){
//                 j--;
//             }
//             if(i<pivInd && j>pivInd)
//                 swap(arr[i++], arr[j--]);
//         }
//             return pivInd;
//     }
    
//     void quickSort(vector<int> &arr, int s, int e){
//         if (s>=e) return;
    
//         int p = partition(arr, s, e);
    
//         quickSort(arr, s, p-1);
//         quickSort(arr, p+1, e);
//     }
    void heapify(vector<int> &nums, int n, int i){
        
        if(n==1) return;
        int curr = i;
        
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left<n && nums[left]>nums[curr])
            curr = left;
        
        if(right<n && nums[right]>nums[curr])
            curr = right;
        
        if(curr!=i){
            swap(nums[curr], nums[i]);
            heapify(nums, n, curr);
        }
    }
    
    
    
    void buildHeap(vector<int> &nums, int n){
        for(int i = (n-1)/2; i>=0; i--)
            heapify(nums, n, i);
    }
    
    
    
    void heapSort(vector<int> &nums, int n){
        
        buildHeap(nums, n);
        int index = n-1;
        
        for(int i=n-1;i>=1;i--){
           swap(nums[0],nums[i]);
           heapify(nums,i,0);
        }
    }

    
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // quickSort(nums, 0 , n);
        heapSort(nums, n);
        return nums;
        
    }
};