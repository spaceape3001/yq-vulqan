////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/MaterialCommand.hpp>

namespace yq::tachyon {
    class SetMaterialSpecCommand : public MaterialCommand {
        YQ_OBJECT_DECLARE(SetMaterialSpecCommand, MaterialCommand)
    public:
        SetMaterialSpecCommand(const Header&, const std::string&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&     spec() const { return m_spec; }

    protected:
        SetMaterialSpecCommand(const SetMaterialSpecCommand&, const Header&);
        virtual ~SetMaterialSpecCommand();
        
    private:
    
        std::string     m_spec;

        SetMaterialSpecCommand(const SetMaterialSpecCommand&) = delete;
        SetMaterialSpecCommand(SetMaterialSpecCommand&&) = delete;
        SetMaterialSpecCommand& operator=(const SetMaterialSpecCommand&) = delete;
        SetMaterialSpecCommand& operator=(SetMaterialSpecCommand&&) = delete;
    };
}
