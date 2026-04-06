class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = obstacles.size();
        int maxDist=0;
        set<pair<int, int>> obs;
        for (auto& o : obstacles) {
            obs.insert({o[0], o[1]});
        }

        // define direction vector: North, East, South, West
        vector<vector<int>> dir_v = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // start facing north
        int x = 0, y = 0;

        //         North(0)
        //            ↑
        // West(3) ←     → East(1)
        //            ↓
        //         South(2)
        // Turning Right (clockwise): North → East → South → West → North; +1
        // step in circle; dir = (dir + 1) % 4; Turning Left (anti-clockwise):
        // North → West → South → East → North; -1 step in circle; But in c++ ,
        // -1 % 4 = -1 ❌ (not 3); so we convert: dir = (dir + 3) % 4;
        for (auto& cmd : commands) {
            if (cmd == -2) { // left
                dir = (dir + 3) % 4;
            } else if (cmd == -1) { // right
                dir = (dir + 1) % 4;
            } else {
                // move step by step
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dir_v[dir][0];
                    int ny = y + dir_v[dir][1];
                    if (obs.count({nx, ny})) {
                        break; // obstacle found
                    }
                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};
