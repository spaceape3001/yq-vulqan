////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaterial.hpp"
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/command/shape/SetMaterialCommand.hpp>
#include <yq/tachyon/command/shape/SetMaterialUrlCommand.hpp>
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
    
    Url         AMaterial::material(url_k) const
    {
        return m_materialUrl;
    }

    void        AMaterial::material(emit_k)
    {
        send(new SetMaterialEvent({.source=typed()}, m_material, m_materialUrl));
    }
    
    void        AMaterial::material(set_k, const MaterialCPtr& mat) 
    {
        m_material      =    mat;
        m_materialUrl   = mat ? mat->url() : Url();
        mark();
        material(EMIT);
    }
    
    void        AMaterial::material(set_k, const Url& u)
    {
        m_materialUrl       = u;
        if(MaterialCPtr mat = Material::IO::load(u)){
            m_material      = mat;
        } else
            m_material      = {};
        mark();
        material(EMIT);
    }
    
    void        AMaterial::on_set_material(const SetMaterialCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        material(SET, cmd.material());
    }
    
    void        AMaterial::on_set_material_url(const SetMaterialUrlCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        material(SET, cmd.url());
    }
}
