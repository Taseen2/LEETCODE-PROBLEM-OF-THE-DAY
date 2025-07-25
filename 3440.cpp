/*
3440. Reschedule Meetings for Maximum Free Time II
Medium
Topics:

You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.

These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.

Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting */

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freearray;
        freearray.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); i++) {
            freearray.push_back(startTime[i] - endTime[i - 1]);
        }
        freearray.push_back(eventTime - endTime[endTime.size() - 1]);


        int n = freearray.size(); // n = number of free slots = m + 1
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);

        // Fill maxRightFree[i] = max free gap from i+1 to end
        for (int i = n - 2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i + 1], freearray[i + 1]);
        }
        for (int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i - 1], freearray[i - 1]);
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            int currEventTime = endTime[i - 1] - startTime[i - 1];

            // CASE 1
            if (currEventTime <= max(maxLeftFree[i-1] ,maxRightFree[i])) {
                result = max(result, freearray[i - 1] + freearray[i] + currEventTime);
            }

            // CASE 2
            result = max(result, freearray[i - 1]+ freearray[i]);
        }

        return result;
    }
};
