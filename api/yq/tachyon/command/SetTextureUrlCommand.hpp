////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/net/Url.hpp>

namespace yq::tachyon {
    class SetTextureUrlCommand : public Command {
        YQ_OBJECT_DECLARE(SetTextureUrlCommand, Command)
    public:
        SetTextureUrlCommand(const Header&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&     url() const { return m_url; }

    protected:
        SetTextureUrlCommand(const SetTextureUrlCommand&, const Header&);
        virtual ~SetTextureUrlCommand();
        
    private:
    
        Url     m_url;

        SetTextureUrlCommand(const SetTextureUrlCommand&) = delete;
        SetTextureUrlCommand(SetTextureUrlCommand&&) = delete;
        SetTextureUrlCommand& operator=(const SetTextureUrlCommand&) = delete;
        SetTextureUrlCommand& operator=(SetTextureUrlCommand&&) = delete;
    };
}
