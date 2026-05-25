class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s[n - 1] != '0') return false;

        vector<int> vis(n, 0);
        vis[n - 1] = 1; 

        int i = n - 2;
        int ptr1 = n - 1; 
        int ptr2 = n - 1; 

        while (i >= 0) {
            if (s[i] == '0') {
                int l = i + minJump;
                int r = min(i + maxJump, n - 1); 

                while (ptr2 > r && ptr2 > ptr1) {
                    ptr2--;
                }

                if (r < ptr1 || l > ptr2) {
                    i--;
                    continue;
                }

                bool found = false;
                while (ptr2 >= ptr1 && ptr2 >= l) {
                    if (s[ptr2] == '0' && vis[ptr2]) { 
                        vis[i] = 1;    
                        found = true;
                        ptr1 = i;
                        break;
                    }
                    ptr2--;
                }
            }
            i--;
        }

        bool result = (vis[0] == 1);
        
        return result;
    }
}; 