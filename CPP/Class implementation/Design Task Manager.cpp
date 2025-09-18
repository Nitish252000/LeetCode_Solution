class TaskManager {
public:
  // I used a tuple because we need to store 3 values together in the heap:
    // priority → so we can order by max priority
    // taskId → so if priorities are equal, the larger taskId wins
    // userId → so when we execute, we know which user gets credit
    unordered_map<int, pair<int, int>> store; // taskId -> {userId, priority}
    priority_queue<tuple<int,int,int>> pq;                      // {priority,taskId,userId}
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            store[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        store[taskId] = {userId, priority};

        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto it = store[taskId]; // guaranteed that taskId exists in the system,
        int userId = it.first;
        store[taskId] = {userId, newPriority};

        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        store.erase(taskId); // deleting by key
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top(); // candidate
            auto it = store.find(taskId);
            if (it == store.end() || it->second.second != priority) {
                pq.pop(); // discard because it's invalid
                continue;
            }
            // valid top task
            pq.pop();
            store.erase(taskId); // remove from store so it’s executed
            return userId;
        }
        return -1; // no tasks
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
