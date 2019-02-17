int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n= nums.size();
        int mx_reach = nums[0];
        int n_mx_reach = -1;
        int step = 1;
        int i = 1;
        while(i < n) {
            if(mx_reach >= n-1) return step;
            
            if(i > mx_reach) {
                if(n_mx_reach == -1) return -1;
                mx_reach = n_mx_reach;
                n_mx_reach = -1;
                step++;
            }
            
            else {
                n_mx_reach = max(n_mx_reach, i+nums[i]);
                i++;
            }
        }
        
        return step;
    }