#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job{
    int id;
    int arrived_time;
    int processing_time;
    int started_time;
    int finished_time;
    Job(int I, int A, int P, int S, int F) : id(I), arrived_time(A), processing_time(P), started_time(S), finished_time(F) {}
    bool operator<(const Job& other) const {
        if (processing_time != other.processing_time) {
            return processing_time > other.processing_time;
        }
        if (arrived_time != other.arrived_time) {
            return arrived_time > other.arrived_time;
        }
        return id > other.id;
    }
};

bool compareByArrivedTime(const Job& a, const Job& b) {
    return a.arrived_time < b.arrived_time;
}

int solution(vector<vector<int>> _jobs) {
    vector<Job> jobs;
    for(int i = 0; i < _jobs.size(); i++){
        Job new_job = Job(i, _jobs[i][0], _jobs[i][1], 0, 0);
        jobs.push_back(new_job);
    }
    sort(jobs.begin(), jobs.end(), compareByArrivedTime);
    
    priority_queue<Job> pq;
    Job current_job = Job(-1, 0, 0, 0, 0);
    bool current_job_flag = true;
    int time = 0, idx = 0;
    
    do{
        if(time == 500000) break;
        // 1. 큐에 넣기
        while(jobs[idx].arrived_time == time){
            pq.push(jobs[idx]);
            idx++;
        }
        // 2. 작업이 끝나있으면, 끝난 시간 기입해주기
        if(current_job.processing_time == (time - current_job.started_time) && !current_job_flag){
            jobs[current_job.id].finished_time = time;
            current_job_flag = true;
            // cout << time << endl;
        }
        // 3. 이전 작업 끝나있고, 우선순위 큐에 작업이 있으면 작업 넣어주기
        if(!pq.empty() && current_job_flag){
            current_job = pq.top(); pq.pop();
            current_job.started_time = time;
            current_job_flag = false;
            // cout << current_job.arrived_time << " " << current_job.processing_time << " " << current_job.started_time << endl;
        }
    } while(++time);
    
    int answer = 0;
    for(auto job : jobs){
        // cout << job.arrived_time << " " << job.processing_time << " " << job.finished_time << endl;
        answer += (job.finished_time - job.arrived_time);
    }
    answer /= jobs.size();
    
    return answer;
}