////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-vulqan/task/Task.hpp>
#include <yq-vulqan/task/TaskAPI.hpp>
#include <yq-vulqan/task/TaskEngine.hpp>
#include <yq-toolbox/basic/DelayInit.hpp>
#include <atomic>

namespace yq::tachyon {
    TaskEngine::TaskEngine()
    {
    }
    
    TaskEngine::~TaskEngine()
    {
        for(Task* tt : m_tasks)
            delete tt;
        m_tasks.clear();
    }

    bool    TaskEngine::add(Task*tt, TaskExecutionControl ec)
    {
        if(!tt)
            return false;
        if(tt->m_engine)
            return false;
        
        tt->m_engine        = this;
        m_tasks.push_back(tt);
        return true;
    }
        
    bool    TaskEngine::add(Task* tt, skip_t, unsigned int iv)
    {
        return add(tt, TaskSkip{iv});
    }
    
    void    TaskEngine::execute(Task*tt, TaskAPI& api)
    {
        tt->tick(api);
        ++(tt->m_ticks);
    }

    void    TaskEngine::step()
    {
        TaskAPI api;
        step(api);
        
    }

    void    TaskEngine::step(TaskAPI&api)
    {
            // todo... fill in the task API
        
        for(Task* t : m_tasks)
            execute(t, api);
    }
    

}


