////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ITexture.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetTextureCommand;

    class ATexture : public ITexture, public virtual Tachyon::Helper {
    public:
    
        TextureCPtr        texture() const override;
        virtual void        texture(set_k, const TextureCPtr&) override;

        bool                texture(disabled_k) const { return false; }
        bool                texture(settable_k) const { return true; }

        const TextureCPtr& texture(ref_k) const { return m_texture; }

    protected:
        TextureCPtr        m_texture;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ATexture();
        virtual ~ATexture();

        void        texture(emit_k);
        
    private:
        void        on_set_texture(const SetTextureCommand&);
    };

}
