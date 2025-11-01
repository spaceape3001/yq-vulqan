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
#include <yq/tachyon/api/Delegate.hpp>
#include <yq/tachyon/api/YesNo.hpp>
#include <yq/tachyon/api/MismatchPolicy.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/trigger.hpp>

#include <concepts>
#include <variant>

namespace yq::tachyon {
    class TriggerMeta : public DelegateMeta {
    public:
        template <typename C> class Writer;

        TriggerMeta(std::string_view zName, DelegateMeta& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~TriggerMeta();
    };
    
    /*! \brief Detector of posts
    
        This is meant to register "triggered" whenever a qualifying 
        post is found & values are suitablly matched.
    */
    class Trigger : public Delegate {
    private:
        YQ_OBJECT_META(TriggerMeta)
        YQ_OBJECT_DECLARE(Trigger, Delegate)
    public:
    
        /*! \brief General Trigger Result
        */
        using Result = std::variant<
            std::monostate,     //< TREATED AS FALSE/REJECT
            bool,               //< TRUE/FALSE accept/reject
          //Any,                //< Implied accept with optional parameter for the action
            accept_k,           //< ACCEPT
            reject_k,           //< REJECT
            mismatch_k,         //< Not-our-type (so mismatch policy)
            failure_k           //< General other failure (ie exception, error condition)
        >;
        
        struct Param {
            bool    mismatch    = false;    // TRUE turns mismatch to accept
            bool    errors      = false;    // TRUE turns failure to accept
            Param(){}
        };
        
        //! Gets the raw match data (with exception catching)
        Result                      analyze(const Post&) const;
        
        bool                        errors_policy() const { return m_errors; }
        bool                        mismatch_policy() const { return m_mismatch; }
        
        //! Return your relevant post info (default is post... absolutely generic)
        virtual const PostMeta&     post_info() const;
        
        bool                        triggered(const Post&) const;

        static void init_meta();


    protected:
    
        Trigger(const Param& p = Param());
        virtual ~Trigger();


        //! This is your advisor (accept/reject) function
        virtual Result      match(const Post&) const = 0;
        
    private:
        bool        m_mismatch;
        bool        m_errors;
    };
}
