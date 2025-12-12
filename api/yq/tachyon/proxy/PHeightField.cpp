////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PHeightField.hpp"
#include <yq/tachyon/asset/HeightField.hpp>
#include <yq/tachyon/command/SetHeightFieldCommand.hpp>
#include <yq/tachyon/command/SetHeightFieldUrlCommand.hpp>

namespace yq::tachyon {
    PHeightField::PHeightField(const IHeightField& i) : m_heightField(i.height_field()), m_url(i.height_field(URL))
    {
        if(i.height_field(DISABLED))
            m_flags |= F::Disabled;
        if(i.height_field(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PHeightField::~PHeightField()
    {
    }

    HeightFieldCPtr    PHeightField::height_field() const
    {
        return m_heightField;
    }
    
    Url     PHeightField::height_field(url_k) const
    {
        return m_url;
    }
    
    void    PHeightField::height_field(set_k, const HeightFieldCPtr& tex) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeightFieldCommand({.target=object()}, tex));
        }
    }
    
    void    PHeightField::height_field(set_k, const Url& u)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetHeightFieldUrlCommand({.target=object()}, u));
        }
    }
    
    bool    PHeightField::height_field(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool    PHeightField::height_field(settable_k) const 
    {
        return m_flags(F::Settable);
    }
}
