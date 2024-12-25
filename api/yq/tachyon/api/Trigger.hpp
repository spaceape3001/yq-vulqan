////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/enum/MismatchPolicy.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/trigger.hpp>
#include <yq/tachyon/typedef/yesno.hpp>
#include <concepts>
#include <variant>

namespace yq::tachyon {


    class TriggerInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        TriggerInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        friend class Trigger;
    };
    
    /*! \brief Triggers posts
    
        A trigger is a detector of posts
    */
    class Trigger : public Object, public RefCount, public UniqueID {
    private:
        YQ_OBJECT_INFO(TriggerInfo)
        YQ_OBJECT_DECLARE(Trigger, Object)
    public:
    
        /*! \brief General Trigger Result
        */
        using Result = std::variant<
            std::monostate,     //< TREATED AS FALSE/REJECT
            bool,               //< TRUE/FALSE accept/reject
            accept_t,           //< ACCEPT
            reject_t,           //< REJECT
            mismatch_t,         //< Not-our-type (so mismatch policy)
            failure_t           //< General other failure (ie exception, error condition)
        >;
        
        struct Param {
            bool    mismatch;
            bool    errors;
        };
        
        //! Gets the raw match data (with exception catching)
        Result                      analyze(const Post&) const;
        
        bool                        errors_policy() const { return m_errors; }
        bool                        mismatch_policy() const { return m_mismatch; }
        
        //! Return your relevant post info (default is post... absolutely generic)
        virtual const PostInfo&     post_info() const;
        
        bool                        triggered(const Post&) const;

        static void init_info();

    protected:
        Trigger(const Param& p = {});
        ~Trigger();


        //! This is your advisor (accept/reject) function
        virtual Result      match(const Post&) const = 0;
        
    private:
        bool        m_mismatch;
        bool        m_errors;
    };
}
