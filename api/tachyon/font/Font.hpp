////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/asset/Asset.hpp>
#include <tachyon/typedef/font.hpp>

struct ImFont;

namespace yq::tachyon {
    class FontInfo : public AssetMeta {
    public:
    };

    class Font : public Asset {
    public:
    
    private:
        ImFont*     m_imgui = nullptr;
        void*       m_gd    = nullptr;
    };
}
