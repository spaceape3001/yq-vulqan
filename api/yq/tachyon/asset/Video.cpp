////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Video.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
    Video::Video()
    {
    }
    
    Video::~Video()
    {
    }
    
    void Video::init_meta()
    {
        auto w = writer<Video>();
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Video)
