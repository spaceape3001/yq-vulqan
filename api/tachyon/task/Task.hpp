////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/basic/Object.hpp>
#include <yq/basic/UniqueID.hpp>
#include <0/math/units.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

#include <variant>

namespace yq::tachyon {

    class TaskEngine;
    struct TaskAPI;

    //! Used to designate as a "every-X" times
    struct TaskSkip { 
        unsigned count = 0; 
    };

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
        Skip                Task will be executed, repeatedly, every X times
    */
    using TaskExecutionControl  = std::variant<std::monostate, std::error_code, bool, always_t, once_t, unsigned, unit::Hertz, unit::Second, TaskSkip>;

    //! Modes, which will *ONLY* be re-evaulated after a tick
    enum class TaskMode : uint8_t {
        //! Run once & delete
        Once        = 0,
        
        //! Run specified number of ticks, then delete
        Ticks,

        //! Run always (every tick)
        Always,
        
        //! Run at specified frequency
        Frequency,
        
        //! Run at specified interval
        Interval,
        
        //! Run every X ticks
        Every
    };

    /*! \brief Something that's a task, with a tick or execute
    */
    class Task  {
        friend class TaskEngine;
    public:
    
        
        uint64_t        task_id() const { return m_taskId; }
        
    
        template <typename T>
        class Fixer;

        using EC = TaskExecutionControl;
        
    
        virtual EC  tick(TaskAPI&) = 0;
        
        Task();
        
        //! Ticks this task has already done
        //! \note First tick will be ZERO here
        uint64_t        ticks() const { return m_ticks; }
        
    
    protected:
        virtual ~Task();
    private:
        TaskEngine*             m_engine    = nullptr;
        uint64_t                m_ticks     = 0ULL;
        uint64_t                m_taskId;

        
        struct {
            union {
                unsigned int    ticks;
                double          spec;
            };

            TaskMode            mode = TaskMode::Once;
        }   m_control;


        struct TPoint {
            uint64_t        tick    = 0;
            unit::Second    time    = {};
        };

        TPoint      m_last, m_next;
        
        //  TaskEngine controls & statistics go here.....
        
        //  Returns TRUE if the control timing (could have) changed
        bool        set_control(const TaskExecutionControl&);
    };

    /*! \brief Creates a task with another object
    
        Assuming the other thing has something called "task()", then it'll be used
    */
    template <typename TT>
    class Task::Fixer : public Task, public TT {
    public:
    
        
    
    
    };

}


