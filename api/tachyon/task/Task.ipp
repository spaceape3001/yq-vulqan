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

namespace yq::errors {
    using task_expired       = error_db::entry<"Task has expired">;
}

namespace yq::tachyon {

   TaskInfo::TaskInfo(std::string_view name, ObjectInfo&base, const std::source_location& sl) :
        ObjectInfo(name, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Task::initInfo()
    {
        auto w = writer<Task>();
        w.abstract();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Task::Task() 
    {
    }
    
    Task::~Task()
    {
    }

    bool    Task::set_control(const ExecutionControl& ec)
    {
        if(std::get_if<always_t>(&ec)){
            m_control.mode      = Mode::Always;
            return true;
        }
        
        if(std::get_if<once_t>(&ec)){
            m_control.mode      = Mode::Once;
            return true;
        }
        
        if(auto pFreq = std::get_if<unit::Hertz>(&ec)){
            m_control.mode      = Mode::Frequency;
            m_control.spec      = pFreq->value;
            return true;
        }
        
        if(auto pInterval = std::get_if<unit::Second>(&ec)){
            m_control.mode      = Mode::Interval;
            m_control.spec      = pInterval->value;
            return true;
        }
        
        if(auto pUint = std::get_if<unsigned>(&ec)){
            m_control.mode      = Mode::Ticks;
            m_control.ticks     = *pUint;
            return true;
        }
        
        if(auto pskip = std::get_if<Skip>(&ec)){
            m_control.mode      = Mode::Every;
            m_control.ticks     = pskip -> count;
            return true;
        }
        
        return false;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  TASK API


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  TASK ENGINE

    Task::Engine::Engine()
    {
    }
    
    Task::Engine::~Engine()
    {
        for(Task* tt : m_tasks)
            delete tt;
        m_tasks.clear();
    }

    bool    Task::Engine::add(Task*tt, ExecutionControl ec)
    {
        if(!tt)
            return false;
        if(tt->m_engine)
            return false;
        
        tt->m_engine        = this;
        m_tasks.push_back(tt);
        return true;
    }
        
    bool    Task::Engine::add(Task* tt, skip_t, unsigned int iv)
    {
        return add(tt, Skip{iv});
    }
    
    void    Task::Engine::execute(Task*tt, API& api)
    {
        tt->tick(api);
        ++(tt->m_ticks);
    }

    void    Task::Engine::step()
    {
        API api;
        for(Task* t : m_tasks)
            execute(t, api);
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    YQ_INVOKE( Task::initInfo(); )
}


YQ_OBJECT_IMPLEMENT(yq::tachyon::Task)
