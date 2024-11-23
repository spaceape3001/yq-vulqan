#! Tachyons

Tachyons are the root heavy object in this vulqan library.  

## Threads

Tachyons are owned and live on a thread (aside from threads themselves).  As the thread ticks, so do the tachyons.

## Ticking

**NOTE** Threads may tick the tachyons in a multithreaded fashion (ie, the parallel job), so do *NOT* bake in assumptions that two tachyons owned by the same Thread tachyon are running on the same C++ thread.

Ticking is where the tachyon does its work, so for instance

    Execution   MyNeatTachyon::tick(Context&)
    {
        // Do work here
        
        return {};
    }

Execution is the policy of ticking, specifying the default `{}` hints to the thread to keep the current ticking.

##  Update Cycle

Full update cycle to the tachyon is
1.  Process Inbox (advice, dispatch, & slots are called for each one)
2.  Execute `tick()`
3.  Send Outbox
4.  Create Snap

##  
