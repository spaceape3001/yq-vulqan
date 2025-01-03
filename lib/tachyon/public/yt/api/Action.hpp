////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Delegate.hpp>

namespace yq::tachyon {
    class ActionInfo : public DelegateInfo {
    public:
        template <typename> class Writer;
        ActionInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl=std::source_location::current());
    
    protected:
        ~ActionInfo();
    };

    class Action : public Delegate {
        YQ_OBJECT_INFO(ActionInfo)
        YQ_OBJECT_DECLARE(Action, Delegate)
    public:
        Action();
        ~Action();
        
        static void init_info();
        
        virtual bool configure(/* TBD */) override;
    };
}
