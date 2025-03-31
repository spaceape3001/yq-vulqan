////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Delegate.hpp>
#include <yt/typedef/command.hpp>
#include <yt/typedef/post.hpp>

namespace yq::tachyon {
    class Action;
    
    class ActionInfo : public DelegateInfo {
    public:
        template <typename> class Writer;
        template <typename> class Fixer;
        ActionInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~ActionInfo();
        
        // virtual CommandCPtr execute(const Action*, const PostCPtr&) const { return {}; }
    };

    class Action : public Delegate {
        YQ_OBJECT_INFO(ActionInfo)
        YQ_OBJECT_DECLARE(Action, Delegate)
    public:
        
        struct Payload;
    
        Action();
        ~Action();
        
        static void init_info();
        
        //! Our action (TRUE if successful)
        virtual bool  action(Payload&) const = 0;
    };
    
    struct Action::Payload {
        std::vector<PostCPtr>   outbound;   //!< Outbound posts that result from this action
        std::vector<PostCPtr>   inbound;    //!< Inbound posts that triggered this action
        std::vector<Any>        pargs;      //!< Positional arguments (0...1...2...etc)
        string_any_map_t        nargs;      //!< Named arguments
    };
}
