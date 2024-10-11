////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/task/Task.hpp>
#include <atomic>

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
}


