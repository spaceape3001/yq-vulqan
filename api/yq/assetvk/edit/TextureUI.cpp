////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TextureUI.hpp"
#include <yq/core/Result.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PTexture.hpp>
#include <misc/cpp/imgui_stdlib.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TextureUI)

namespace yq::tachyon {
    void TextureUI::init_meta()
    {
        auto w = writer<TextureUI>();
        w.description("UIEditor for Texture");
        w.edits<PTexture>();
        w.field("texture", &TextureUI::texture);
    }
    
    TextureUI::TextureUI(UIFlags flags)
    {
    }
    
    TextureUI::TextureUI(const TextureUI& cp) : UIEditor(cp)
    {
    }
    
    TextureUI* TextureUI::clone() const
    {
        return new TextureUI(*this);
    }

    void    TextureUI::texture()
    {
        PTexture* p   = snap()->proxy<PTexture>();
        if(!p)
            return ;
        
        std::string     v = to_string(p->texture(URL));
        if(ImGui::InputText("##texture", &v)){
            auto x  = to_url_view(v);
            if(x.good)
                p->texture(SET, ::yq::copy(x.value));
        }
    }
}
