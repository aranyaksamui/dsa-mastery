// Job Sequencing With Deadline

#include <iostream>
#include <vector>

using namespace std;

struct Job
{
    char jobId;
    int profit;
    int deadline;
};

int main()
{
    // Input no. of jobs
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    // Insert Job ID, profit and deadline
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
    {

        int p, d;
        cout << "Enter the info for job: " << i << endl;
        jobs[i].jobId = 'A' + i;
        cout << "P: ";
        cin >> p;
        jobs[i].profit = p;
        cout << "D: ";
        cin >> d;
        jobs[i].deadline = d;
    }

    // Sort the jobs by profit and find the max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (jobs[i].profit < jobs[j].profit)
            {
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }    
        }

        if (maxDeadline < jobs[i].deadline) maxDeadline = jobs[i].deadline;
    }

    // Prepare the job sequence based on deadlines
    vector<char> seq(maxDeadline + 1, '_');
    for (int i = 0; i < n; i++)
    {
        Job currentJob = jobs[i];
        for (int d = currentJob.deadline; d > 0; d--)
        {
            if (seq[d] != '_') continue;

            seq[d] = currentJob.jobId;
            break;
        }
    }

    // Output the sequence
    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << " ";
    }



    return 0;
}
