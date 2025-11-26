////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMaterial.hpp"
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/command/shape/SetMaterialCommand.hpp>

namespace yq::tachyon {
    PMaterial::PMaterial(const IMaterial& i) : m_material(i.material())
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
    
    void    PMaterial::material(set_k, const MaterialCPtr& mat) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaterialCommand({.target=object()}, mat));
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
