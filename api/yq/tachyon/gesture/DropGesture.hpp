////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/gesture/DragGesture.hpp>

namespace yq::tachyon {
    class DropGesture : public DragGesture {
        YQ_OBJECT_DECLARE(DropGesture, DragGesture)
    public:
    
        DropGesture(const Payload&);
        ~DropGesture();
        
        virtual void    drop() override;
        
        static void init_meta();
    };
}
