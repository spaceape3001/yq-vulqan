////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ShapeCommand.hpp>
#include <yq/net/Url.hpp>

namespace yq::tachyon {
    class SetMaterialUrlCommand : public ShapeCommand {
        YQ_OBJECT_DECLARE(SetMaterialUrlCommand, ShapeCommand)
    public:
        SetMaterialUrlCommand(const Header&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&     url() const { return m_url; }

    protected:
        SetMaterialUrlCommand(const SetMaterialUrlCommand&, const Header&);
        virtual ~SetMaterialUrlCommand();
        
    private:
    
        Url     m_url;

        SetMaterialUrlCommand(const SetMaterialUrlCommand&) = delete;
        SetMaterialUrlCommand(SetMaterialUrlCommand&&) = delete;
        SetMaterialUrlCommand& operator=(const SetMaterialUrlCommand&) = delete;
        SetMaterialUrlCommand& operator=(SetMaterialUrlCommand&&) = delete;
    };
}
