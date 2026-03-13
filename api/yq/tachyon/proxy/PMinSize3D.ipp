////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMinSize3D.hpp"

#include <yq/tachyon/command/size/AddMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZDCommand.hpp>

namespace yq::tachyon {
    PMinSize³D::PMinSize³D(const IMinSize³D& i) : m_min_size(i.min_size())
    {
        if(i.min_size(DISABLED))
            m_flags |= F::Disabled;
        if(i.min_size(SETTABLE))
            m_flags |= F::Settable;
        if(i.min_size(ADDABLE))
            m_flags |= F::Addable;
        if(i.min_size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PMinSize³D::~PMinSize³D()
    {
    }

    bool        PMinSize³D::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize³D::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize³D::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize³D::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize³D::min_size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize³DCommand({.target=object()}, v));
        }
    }

    void        PMinSize³D::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PMinSize³D::min_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʸDCommand({.target=object()}, y));
        }
    }
    
    void        PMinSize³D::min_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeᶻDCommand({.target=object()}, z));
        }
    }

    void        PMinSize³D::min_size(add_k, const Size3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize³DCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize³D::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize³D::min_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize³D::min_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PMinSize³D::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeDCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize³D::min_size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize³DCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize³D::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize³D::min_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize³D::min_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeᶻDCommand({.target=object()}, Δz));
        }
    }
}
