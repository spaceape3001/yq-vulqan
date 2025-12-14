////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ColorProfileCommand.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/net/Url.hpp>

namespace yq::tachyon {
    class SetColorProfileUrlCommand : public ColorProfileCommand {
        YQ_OBJECT_DECLARE(SetColorProfileUrlCommand, ColorProfileCommand)
    public:
        SetColorProfileUrlCommand(const Header&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&     url() const { return m_url; }

    protected:
        SetColorProfileUrlCommand(const SetColorProfileUrlCommand&, const Header&);
        virtual ~SetColorProfileUrlCommand();
        
    private:
    
        Url     m_url;

        SetColorProfileUrlCommand(const SetColorProfileUrlCommand&) = delete;
        SetColorProfileUrlCommand(SetColorProfileUrlCommand&&) = delete;
        SetColorProfileUrlCommand& operator=(const SetColorProfileUrlCommand&) = delete;
        SetColorProfileUrlCommand& operator=(SetColorProfileUrlCommand&&) = delete;
    };
}
