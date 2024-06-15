# Jobs and CronJobs

A Job creates one or more Pods to perform a given task. It makes sure to complete the task and deal with pod failures. Pods are deleted when task finishes.

- parallelism - to set the number of pods allowed to run in parallel;
- completions - to set the number of expected completions;
- activeDeadlineSeconds - to set the duration of the Job;
- backoffLimit - to set the number of retries before Job is marked as failed;
- ttlSecondsAfterFinished - to delay the cleanup of the finished Jobs.

Perform Jobs at scheduled times/dates with CronJobs

- startingDeadlineSeconds - to set the deadline to start a Job if scheduled time was missed;
- concurrencyPolicy - to allow or forbid concurrent Jobs or to replace old Jobs with new ones.
