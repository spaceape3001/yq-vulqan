////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindowWriter.hpp>

namespace yq::tachyon {
    class UIDocker;
    
    class UIDockerWriter : public UIWindowWriter {
    public:
        UIDockerWriter();
        UIDockerWriter(UIDocker*);
        UIDockerWriter(const UIDockerWriter&);
        ~UIDockerWriter();
        
        UIDocker*  element();
    };
}
