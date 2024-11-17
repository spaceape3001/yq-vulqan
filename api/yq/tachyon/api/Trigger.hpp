////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/tachyon/enum/MismatchPolicy.hpp>
#include <yq/tachyon/typedef/trigger.hpp>
#include <concepts>

namespace yq::tachyon {

    enum class TriggerResult : uint8_t {
        //! Accepted
        Accept  = 0,
        
        //! Rejected
        Reject,
        
        //! Type mismatch
        Mismatch,
        
        //! Exception/error thrown
        Exception,
        
        //! No accept is defined on the trigger
        Undefined,
        
        //! Other failure
        Failure
    };


    class TriggerInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        TriggerInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    
        //! \note NULL means it's generic post, not refined
        const PostInfo*     post_info() const { return m_postInfo; }

    protected:
        friend class Trigger;
        virtual TriggerResult accept(const Trigger&, const Post&) const = 0;
        
        const PostInfo*     m_postInfo      = nullptr;
    };
    
    /*! \brief Triggers posts
    
        A trigger is a detector of posts
    */
    class Trigger : public Object, public RefCount, public UniqueID {
    public:
        template <typename> class Fixer;
    private:
        YQ_OBJECT_INFO(TriggerInfo)
        YQ_OBJECT_FIXER(Fixer)
        YQ_OBJECT_DECLARE(Trigger, Object)
    public:
    
        static constexpr const TriggerResult   Accept       = TriggerResult::Accept;
        static constexpr const TriggerResult   Reject       = TriggerResult::Reject;
        
        struct Param {
            MismatchPolicy      mismatch = MismatchPolicy::Reject;
        };
        
        /*! \fn bool accept(const Post&pp) const;
        
            \brief This is your acceptance function, define it, implement it
            \param[in] pp   The post (ref to it)
            \return TRUE to accept the match (FALSE rejects)
        */
    
        //!     Calls the accept (filter) function, returns up/down
        bool                passed(const Post&) const;
        //!     Calls the accept (filter) function, returns more specific result
        TriggerResult       check(const Post&) const;

        MismatchPolicy      mismatch() const;
        
        static void init_info();

    protected:
        Trigger(const Param& p);
        ~Trigger();
        
    private:
        MismatchPolicy      m_mismatch;
    };
}
