////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <tachyon/typedef/font.hpp>

struct ImFont;

namespace yq::tachyon {
    class FontInfo : public ResourceMeta {
    public:
    };

    class Font : public Resource {
    public:
    
    private:
        ImFont*     m_imgui = nullptr;
        void*       m_gd    = nullptr;
    };
}
