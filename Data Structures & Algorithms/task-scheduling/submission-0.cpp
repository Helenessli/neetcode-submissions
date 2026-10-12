
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        // 1. Count the frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // 2. Max-Heap: stores remaining task frequencies
        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0) {
                maxHeap.push(f);
            }
        }
        // Queue stores {remaining frequency, available time}
        queue<pair<int, int>> cooldown;
        int time = 0;
        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;
            // 3. Process the task with the highest frequency
            if (!maxHeap.empty()) {
                int remaining = maxHeap.top();
                maxHeap.pop();
                remaining--;
                // 4. Put the task in cooldown if it has remaining executions
                if (remaining > 0) {
                    cooldown.push({remaining, time + n});
                }
            }
            // 5. Reinsert tasks whose cooldown has finished
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};
