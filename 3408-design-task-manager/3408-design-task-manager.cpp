class TaskManager {
public:
    unordered_map<int, pair<int, int>> tasksInfo; // taskid -> (userid, priority)
    set<pair<int, int>> tasks; // (priority, taskid)

    TaskManager(vector<vector<int>>& tasks) {
        for(const auto &task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasksInfo[taskId] = {userId, priority};
        tasks.insert({-priority, -taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, _] = tasksInfo[taskId];
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = tasksInfo[taskId];
        tasks.erase({-priority, -taskId});
        tasksInfo.erase(taskId);
    }
    
    int execTop() {
        if(tasks.empty()) {
            return -1;
        }
        int taskId = -begin(tasks)->second;
        auto [userId, priority] = tasksInfo[taskId];
        rmv(taskId);
        return userId;
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

 /*
    map: taskid -> (userid, priority)
    set: (priority, taskid)
 */