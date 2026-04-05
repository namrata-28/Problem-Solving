class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            int destroyed = 0;
            while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }

                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }

                destroyed = 1;
                break;
            }
            
            if (!destroyed) {
                st.push(asteroid);
            }
        }
        

        vector<int> remainAsteroids (st.size());
        for (int i = remainAsteroids.size() - 1; i >= 0; i--){
            remainAsteroids[i] = st.top();
            st.pop();
        }
        
        return remainAsteroids;
    }
};