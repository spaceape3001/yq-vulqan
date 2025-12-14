////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMaterial.hpp"
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/command/material/SetMaterialCommand.hpp>
#include <yq/tachyon/command/material/SetMaterialUrlCommand.hpp>

namespace yq::tachyon {
    PMaterial::PMaterial(const IMaterial& i) : m_material(i.material()), m_url(i.material(URL))
    {
        if(i.material(DISABLED))
            m_flags |= F::Disabled;
        if(i.material(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PMaterial::~PMaterial()
    {
    }

    MaterialCPtr    PMaterial::material() const
    {
        return m_material;
    }

    Url     PMaterial::material(url_k) const 
    {
        return m_url;
    }
    
    void    PMaterial::material(set_k, const MaterialCPtr& mat) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaterialCommand({.target=object()}, mat));
        }
    }
    
    void    PMaterial::material(set_k, const Url& u)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaterialUrlCommand({.target=object()}, u));
        }
    }
    
    bool    PMaterial::material(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool    PMaterial::material(settable_k) const 
    {
        return m_flags(F::Settable);
    }
}
