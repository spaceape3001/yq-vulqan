////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/typedef/builder.hpp>

#include <system_error>
#include <vector>

namespace yq::tachyon {
    class Save;
    
    struct LoadAPI;
    struct SaveAPI;
    
    // *MAY* need meta... (so virtual object this)
    class Builder : public RefCount {
    public:
    
        struct Context;
    
        Builder(Save*);
        virtual ~Builder();

        #if 0   // still working these out
        virtual std::error_code build1_create(LoadAPI&) const;
        virtual std::error_code build2_configure(LoadAPI&) const;
        virtual std::error_code export2_tbd(SaveAPI&) { return {}; }
        #endif
        
        // using virtual methods to capture the type
        
        virtual bool            is_object() const { return false; }
        virtual bool            is_delegate() const { return false; }
        virtual bool            is_tachyon() const { return false; }
        virtual bool            is_thread() const { return false; }
        virtual bool            is_resource() const { return false; }
        
        Save*   save() { return m_save; }
        const Save*   save() const { return m_save; }
        
    private:
        Save*           m_save  = nullptr;
    };

}
