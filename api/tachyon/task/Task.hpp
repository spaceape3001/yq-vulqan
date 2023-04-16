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
#include <tachyon/keywords.hpp>

namespace yq::tachyon {

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
    
        struct Skip { unsigned count = 0; };
        
    
        class API;
        class Engine;

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
        using ExecutionControl  = std::variant<std::monostate, std::error_code, bool, always_t, once_t, unsigned, unit::Hertz, unit::Second, Skip>;
        using EC = ExecutionControl;
        
    
        virtual EC  tick(API&) = 0;
        
        Task();
        
        //! Ticks this task has already done
        //! \note First tick will be ZERO here
        uint64_t        ticks() const { return m_ticks; }
    
        static void initInfo();
    
    protected:
        virtual ~Task();
    private:
        Engine*                 m_engine    = nullptr;
        uint64_t                m_ticks     = 0ULL;

        //! Modes, which will *ONLY* be re-evaulated after a tick
        enum class Mode : uint8_t {
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
        
        struct {
            union {
                unsigned int    ticks;
                double          spec;
            };

            Mode                mode = Mode::Once;
        }   m_control;


        struct TPoint {
            uint64_t        tick    = 0;
            unit::Second    time    = {};
        };

        TPoint      m_last, m_current, m_next;
        
        //  TaskEngine controls & statistics go here.....
        
        //  Returns TRUE if the control timing (could have) changed
        bool        set_control(const ExecutionControl&);
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


