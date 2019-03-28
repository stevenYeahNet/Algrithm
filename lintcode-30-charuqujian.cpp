/*
 * charuqujian.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: xdh
 */


class Interval {
	 int start, end;
	 Interval(int start, int end){
		 this->start = start;
		 this->end = end;
	 }
 };


class Solution {
public:
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
     static bool cmp(Interval a,Interval b)
     {
        if (a.start != b.start)
        {
            return a.start < b.start;
        }
        return a.end > b.end;
     }
     //贪心算法
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> ans;
        ans.push_back(intervals[0]);
        for( int i = 1;i < intervals.size();++i )
        {
            int len = ans.size() - 1;
            if( intervals[i].end <= ans[len].end)
            {
                continue;
            }else{
                if( intervals[i].start <= ans[len].end)
                {
                    ans[len].end = intervals[i].end;
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
    /*
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = intervals.begin();
        int cur = 0;
        while (it != intervals.end()) {
            if (it->end < newInterval.start) {
                res.push_back(*it);
                ++cur;
            } else if (it->start > newInterval.end) {
                res.push_back(*it);
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
            }
            ++it;
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
    */
};


