////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/scene/Perspective.hpp>

#include <tachyon/camera/NullCamera.hpp>

namespace yq::tachyon {
    Perspective0::Perspective0()
    {
        camera = new NullCamera;
    }
    
    Perspective0::~Perspective0()
    {
    }
}
