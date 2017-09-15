# OS-Deadlock-Conditions
Create a Deadlock Scenario and Solve the Deadlock via 4 Main Solutions

4 Conditions are needed for Deadlock to occur "consistently":

1.) Mutual Exclusion - Threads/Processes must claim exclusive control of the 
resources they require.
- The Solution is to prevent or have no Mutual Exclusion. So threads have 
 Non-exclusive access only to resources then.

2.) No Preemption - a resource can be released only voluntarily by the 
process holding it, after that process has completed its task.
- The Solution is to allow preemption, so instead of a waiting, we remove/preempt
 resources from a thread, and give the resources to a new thread requesting it.

3.) Hold and Wait - a process/thread holding at least one resource 
is waiting to acquire additional resources held by other processes.
- The Solution is to remove Hold and Wait. In my code, A thread can only
 request resources only when it has none.

4.) Circular Wait - The processes in the system form a circular list or chain 
where each process in the list is waiting for a resource held 
by the next process in the list.
- The Solution is to make sure you lock the resources in the same order for
 each thread/process. So I make sure to lock mutex1 and then lock mutex2 for
 both thread1 and thread2.
