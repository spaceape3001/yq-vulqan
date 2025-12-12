////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/net/Url.hpp>

namespace yq::tachyon {
    class SetHeightFieldUrlCommand : public Command {
        YQ_OBJECT_DECLARE(SetHeightFieldUrlCommand, Command)
    public:
        SetHeightFieldUrlCommand(const Header&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&     url() const { return m_url; }

    protected:
        SetHeightFieldUrlCommand(const SetHeightFieldUrlCommand&, const Header&);
        virtual ~SetHeightFieldUrlCommand();
        
    private:
    
        Url     m_url;

        SetHeightFieldUrlCommand(const SetHeightFieldUrlCommand&) = delete;
        SetHeightFieldUrlCommand(SetHeightFieldUrlCommand&&) = delete;
        SetHeightFieldUrlCommand& operator=(const SetHeightFieldUrlCommand&) = delete;
        SetHeightFieldUrlCommand& operator=(SetHeightFieldUrlCommand&&) = delete;
    };
}
