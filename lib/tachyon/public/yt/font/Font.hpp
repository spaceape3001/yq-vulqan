////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/asset/Asset.hpp>
#include <yq/tachyon/typedef/font.hpp>

struct ImFont;

namespace yq::tachyon {
    class FontInfo : public AssetInfo {
    public:
    };

    class Font : public Asset {
    public:
    
    private:
        ImFont*     m_imgui = nullptr;
        void*       m_gd    = nullptr;
    };
}
