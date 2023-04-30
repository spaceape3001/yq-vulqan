////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ErrorDB.hpp>
#include <tachyon/task/Task.hpp>
#include <tachyon/task/TaskAPI.hpp>
#include <tachyon/task/TaskEngine.hpp>
#include <basic/DelayInit.hpp>
#include <atomic>

namespace yq::errors {
    using task_expired       = error_db::entry<"Task has expired">;
}

namespace yq::tachyon {

    Task::Task() 
    {
        static std::atomic<uint64_t>    sNext(0);
        m_taskId        = ++sNext;
    }
    
    Task::~Task()
    {
    }

    bool    Task::set_control(const TaskExecutionControl& ec)
    {
        if(std::get_if<always_t>(&ec)){
            m_control.mode      = TaskMode::Always;
            return true;
        }
        
        if(std::get_if<once_t>(&ec)){
            m_control.mode      = TaskMode::Once;
            return true;
        }
        
        if(auto pFreq = std::get_if<unit::Hertz>(&ec)){
            m_control.mode      = TaskMode::Frequency;
            m_control.spec      = pFreq->value;
            return true;
        }
        
        if(auto pInterval = std::get_if<unit::Second>(&ec)){
            m_control.mode      = TaskMode::Interval;
            m_control.spec      = pInterval->value;
            return true;
        }
        
        if(auto pUint = std::get_if<unsigned>(&ec)){
            m_control.mode      = TaskMode::Ticks;
            m_control.ticks     = *pUint;
            return true;
        }
        
        if(auto pskip = std::get_if<TaskSkip>(&ec)){
            m_control.mode      = TaskMode::Every;
            m_control.ticks     = pskip -> count;
            return true;
        }
        
        return false;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  TASK API


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  TASK ENGINE

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


