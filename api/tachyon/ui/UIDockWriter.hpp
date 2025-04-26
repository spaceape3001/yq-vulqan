////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIWindowWriter.hpp>

namespace yq::tachyon {
    class UIDock;
    
    class UIDockWriter : public UIWindowWriter {
    public:
        UIDockWriter();
        UIDockWriter(UIDock*);
        UIDockWriter(const UIDockWriter&);
        ~UIDockWriter();
        
        UIDock*  element();
    };
}
