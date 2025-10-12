////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Sound.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
    Sound::Sound()
    {
    }
    
    Sound::~Sound()
    {
    }
    
    void Sound::init_meta()
    {
        auto w = writer<Sound>();
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Sound)
