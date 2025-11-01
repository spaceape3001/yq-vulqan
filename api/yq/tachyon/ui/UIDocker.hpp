////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIWindow.hpp>

namespace yq::tachyon {
    class UIDockerWriter;
    
    /*! \brief Place for Docks
    */
    class UIDocker : public UIWindow {
        YQ_OBJECT_DECLARE(UIDocker, UIWindow)
    public:
        using Writer = UIDockerWriter;
        
        UIDocker(std::string_view, UIFlags flags={});
        UIDocker(const UIDocker&);
        
        UIDocker* clone() const override;
        
        static void init_meta();
    };
}
