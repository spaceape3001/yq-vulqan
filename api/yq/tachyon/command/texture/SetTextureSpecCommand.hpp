////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TextureCommand.hpp>

namespace yq::tachyon {
    class SetTextureSpecCommand : public TextureCommand {
        YQ_OBJECT_DECLARE(SetTextureSpecCommand, TextureCommand)
    public:
        SetTextureSpecCommand(const Header&, const std::string&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&     spec() const { return m_spec; }

    protected:
        SetTextureSpecCommand(const SetTextureSpecCommand&, const Header&);
        virtual ~SetTextureSpecCommand();
        
    private:
    
        std::string     m_spec;

        SetTextureSpecCommand(const SetTextureSpecCommand&) = delete;
        SetTextureSpecCommand(SetTextureSpecCommand&&) = delete;
        SetTextureSpecCommand& operator=(const SetTextureSpecCommand&) = delete;
        SetTextureSpecCommand& operator=(SetTextureSpecCommand&&) = delete;
    };
}
