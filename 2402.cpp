/* You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b, including a and not including b. */

// Approach-1: simple but has larger time and space complexity..


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings));

        vector<long long> lastEmpty(n, 0); // room kab available hoga

        vector<int> count(n, 0); // Number of time room used

        for (vector<int>& meet : meetings) { // meet is current meeting
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;

            //Find the first available room
            for (int room = 0; room < n; room++) {

                if (lastEmpty[room] <= start) {
                    lastEmpty[room] = end;
                    count[room]++;
                    found = true;
                    break;
                }
            }

            // No room is found--> delay the meeting
            if (!found) {

                // we need to find that room that get free early
                long long minTime = lastEmpty[0];

                int minRoom = 0;
                for (int room = 1; room < n; room++) {
                    if (lastEmpty[room] < minTime) {
                        minTime = lastEmpty[room];
                        minRoom = room;
                    }
                }

                // Delay meeting to start at minTime
                lastEmpty[minRoom] = lastEmpty[minRoom] + duration;
                count[minRoom]++;
            }
        }
        // Find the room with the most meetings
        int maxCount = count[0];
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                result = i;
            }
        }

        return result;
    }
};


//Approach -2 



  
