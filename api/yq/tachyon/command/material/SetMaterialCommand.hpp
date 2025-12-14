////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/MaterialCommand.hpp>
#include <yq/tachyon/typedef/material.hpp>

namespace yq::tachyon {
    class SetMaterialCommand : public MaterialCommand {
        YQ_OBJECT_DECLARE(SetMaterialCommand, MaterialCommand)
    public:
        SetMaterialCommand(const Header&, const MaterialCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const MaterialCPtr&     material() const { return m_material; }

    protected:
        SetMaterialCommand(const SetMaterialCommand&, const Header&);
        virtual ~SetMaterialCommand();
        
    private:
    
        MaterialCPtr            m_material;

        SetMaterialCommand(const SetMaterialCommand&) = delete;
        SetMaterialCommand(SetMaterialCommand&&) = delete;
        SetMaterialCommand& operator=(const SetMaterialCommand&) = delete;
        SetMaterialCommand& operator=(SetMaterialCommand&&) = delete;
    };
}
