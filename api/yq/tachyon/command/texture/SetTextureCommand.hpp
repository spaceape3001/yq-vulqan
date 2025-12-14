////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TextureCommand.hpp>
#include <yq/tachyon/typedef/texture.hpp>

namespace yq::tachyon {
    class SetTextureCommand : public TextureCommand {
        YQ_OBJECT_DECLARE(SetTextureCommand, TextureCommand)
    public:
        SetTextureCommand(const Header&, const TextureCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const TextureCPtr&     texture() const { return m_texture; }

    protected:
        SetTextureCommand(const SetTextureCommand&, const Header&);
        virtual ~SetTextureCommand();
        
    private:
    
        TextureCPtr            m_texture;

        SetTextureCommand(const SetTextureCommand&) = delete;
        SetTextureCommand(SetTextureCommand&&) = delete;
        SetTextureCommand& operator=(const SetTextureCommand&) = delete;
        SetTextureCommand& operator=(SetTextureCommand&&) = delete;
    };
}
