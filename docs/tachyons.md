#! Tachyons

Tachyons are the root heavy object in this vulqan library.  

## Threads

Tachyons are owned and live on a thread (aside from threads themselves).  As the thread ticks, so do the tachyons.

## Ticking

**NOTE** Threads may tick the tachyons in a multithreaded fashion (ie, the parallel job), so do *NOT* bake in assumptions that two tachyons owned by the same Thread tachyon are running on the same C++ thread.

**NOTE** subclassing to a thread required a rename to this routine `subtick` instead.

Ticking is where the tachyon does its work, so for instance

    Execution   MyNeatTachyon::tick(const Context&)
    {
        // Do work here
        
        return {};
    }

Execution is the policy of ticking, specifying the default `{}` hints to the thread to keep the current ticking.

### Setup

Before tick is called, the tachyon must setup.  It uses a similar function.

    Execution   MyNeatTachyon::setup(const Context&)
    {
        // Do setup here
        
        return START;
    }

Expected values are broadly grouped into accepting/starting, rejecting startup, and waiting another cycle.

### Shutdown

After the tachyon decides enough is enough, it can trigger the shutdown callback instead.

    Execution   MyNeatTachyon::shutdown(const Context&)
    {
        // Do shutdown here
        
        return DELETE;
    }



##  Update Cycle

Full update cycle to the tachyon is
1.  Process Inbox (advice, dispatch, & slots are called for each one)
2.  Execute startup/tick/paused/shutdown (as appropriate)
3.  Send Outbox
4.  Create Snap

##  Creating (Non-Threads)

Creating of tachyons should be done via the create API.

    Tachyon::create<T>( ... args ... ); 

##  Deleting (Non-Threads)

To delete a non-thread tachyon, this is handled in the `tick()`.

    Execution   DeletingTachyon::tick(Context&)
    {
        return DELETE;
    }
    
##  IDs

Identifiers are unique to the specific tachyon; however, there are flavor of IDs for what we expect the object to be.  So, a WidgetID can be auto-downcasted to a TachyonID.



