////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Gesture.hpp>

namespace yq::tachyon {
    class SaveFileGesture : public Gesture {
        YQ_OBJECT_DECLARE(SaveFileGesture, Gesture)
    public:
    
        SaveFileGesture(const std::string&, const Param& p={});
        
    protected:
    
    };
}
