#include<bits/stdc++.h>
int solveRec(int curr_day, int last_performed_task, vector<vector<int>> &points){
    // Baase case: Stop when you'll reach day 0
    if(curr_day == 0){
        int maxi = 0;
        // Return the max points of the taskl on day zero provided that task has not been previously performed
        for(int task = 0 ; task < 3; task++){
            if(task != last_performed_task){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    // Do stuff on index
    int maxi = 0;
    for(int task = 0 ; task < 3; task++){
        int curr_points = 0;
        if(task != last_performed_task){
            curr_points = points[curr_day][task] + solveRec(curr_day-1, task, points);
            maxi = max(maxi, curr_points);
        }
    }
    // Return the max
    return maxi;
}

int solveMem(int curr_day, int last_performed_task, vector<vector<int>> &points, vector<vector<int>>& dp){
    // Baase case: Stop when you'll reach day 0
    if(curr_day == 0){
        int maxi = 0;
        // Return the max points of the taskl on day zero provided that task has not been previously performed
        for(int task = 0 ; task < 3; task++){
            if(task != last_performed_task){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[curr_day][last_performed_task] != -1) return dp[curr_day][last_performed_task];

    // Do stuff on index
    int maxi = 0;
    for(int task = 0 ; task < 3; task++){
        int curr_points = 0;
        if(task != last_performed_task){
            curr_points = points[curr_day][task] + solveMem(curr_day-1, task, points, dp);
            maxi = max(maxi, curr_points);
        }
    }
    // Return the max
    return dp[curr_day][last_performed_task] = maxi;
}

int solveTab(vector<vector<int>> &points, int n){
    // Create DP array
    vector<vector<int>>dp(n+1, vector<int>(4, 0));
    // Analyze base cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // For each day from 1 to n
    // For each task 1 to 3
    for(int day = 1; day < n; day++){
        for(int last = 0; last <= 3; last++){
            dp[day][last] = 0;
            // Do stuff on index
            for(int task = 0 ; task < 3; task++){
                if(task != last){
                    int curr_points = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], curr_points);
                }
            }
        }
    }
    return dp[n-1][3];
}

int SO(vector<vector<int>> &points, int n){
    // Create DP array
    vector<int>prev_row(4, 0);
    // Analyze base cases
    prev_row[0] = max(points[0][1], points[0][2]);
    prev_row[1] = max(points[0][0], points[0][2]);
    prev_row[2] = max(points[0][0], points[0][1]);
    prev_row[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // For each day from 1 to n
    // For each task 1 to 3
    for(int day = 1; day < n; day++){
        vector<int>curr_row(4, 0);
        for(int last = 0; last <= 3; last++){
            curr_row[last] = 0;
            // Do stuff on index
            for(int task = 0 ; task < 3; task++){
                if(task != last){
                    int curr_points = points[day][task] + prev_row[task];
                    curr_row[last] = max(curr_row[last], curr_points);
                }
            }
        }
        prev_row = curr_row;
    }
    return prev_row[3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int curr_day = n-1;
    int last_performed_task = 3;
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return SO(points, n);
    return solveTab(points, n);
    return solveMem(curr_day, last_performed_task, points, dp);
    return solveRec(curr_day, last_performed_task, points);
}
