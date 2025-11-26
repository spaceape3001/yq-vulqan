////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaterial.hpp"
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/command/shape/SetMaterialCommand.hpp>
#include <yq/tachyon/event/shape/SetMaterialEvent.hpp>

namespace yq::tachyon {
    AMaterial::AMaterial()
    {
    }
    
    AMaterial::~AMaterial()
    {
    }

    MaterialCPtr        AMaterial::material() const
    {
        return m_material;
    }

    void        AMaterial::material(emit_k)
    {
        send(new SetMaterialEvent({.source=typed()}, m_material));
    }
    
    void        AMaterial::material(set_k, const MaterialCPtr& mat) 
    {
        m_material  =    mat;
        mark();
        material(EMIT);
    }
    
    
    void        AMaterial::on_set_material(const SetMaterialCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        material(SET, cmd.material());
    }
    
}
