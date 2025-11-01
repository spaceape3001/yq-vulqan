////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Perspective.hpp>

#include <yq/tachyon/camera/NullCamera.hpp>

namespace yq::tachyon {
    Perspective0::Perspective0()
    {
        camera = new NullCamera;
    }
    
    Perspective0::~Perspective0()
    {
    }
}
