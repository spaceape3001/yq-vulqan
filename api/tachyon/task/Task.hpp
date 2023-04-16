////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Object.hpp>
#include <basic/UniqueID.hpp>
#include <variant>
#include <math/units.hpp>
#include <meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {

    //struct TaskAPI;
    class TaskEngine;

    struct always_t {};
    static const constexpr always_t ALWAYS;
    struct once_t {};
    static const constexpr once_t   ONCE;

    //! Execution policy of a task
    //! Monostate implies single-shot
    
    /*! \brief Task Execution Control
    
        This is a simple variant that controls how a task gets controlled.  
        It can be initial or altered at runtime.
        
        std::monostate      Continues as previous scheduled.
        std::error_code     An error, the task will terminate, otherwise continues as previously scheduled 
        bool                FALSE will abort, TRUE will continue as previously scheduled
        always_t            Task will be executed EVERY frame
        once_t              Task will be executed ONCE (or once more), next available tick
        unsigned            Task will be executed X times (or update the count remaining) at present update rate
        Hertz               Task will be executed at specified frequency (good for those needing more ticks, but not every tick)
        Second              Task will be executed in X seconds (good for slow/recurring)
    */
    using TaskExecutionControl  = std::variant<std::monostate, std::error_code, bool, always_t, once_t, unsigned, unit::Hertz, unit::Second>;
    
    
    class TaskInfo : public ObjectInfo {
    public:
    
        template <typename C> struct Writer;
    
        TaskInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());

    };
    

    /*! \brief Something that's a task, with a tick or execute
    */
    class Task : public Object, public UniqueID {
        YQ_OBJECT_INFO(TaskInfo)
        YQ_OBJECT_DECLARE(Task, Object)
    public:
    
        virtual TaskExecutionControl  tick() = 0;
        
        Task();
        
        const TaskExecutionControl& execution() const { return m_execution; }
        
        //! Ticks this task has already done
        //! \note First tick will be ZERO here
        uint64_t        ticks() const { return m_ticks; }
    
        static void initInfo();
    
    protected:
        virtual ~Task();
    private:
        friend class TaskEngine;
        TaskEngine*             m_engine    = nullptr;
        TaskExecutionControl    m_execution = ONCE;
        uint64_t                m_ticks     = 0ULL;
        
        //  TaskEngine controls & statistics go here.....
    };

    template <typename C>
    class TaskInfo::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(TaskInfo* ti) : ObjectInfo::Writer<C>(ti) 
        {
        }
        
        Writer(TaskInfo& ti) : Writer(&ti)
        {
        }
    };


}


