////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PSize1D.hpp"

#include <yq/tachyon/command/size/AddSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>

namespace yq::tachyon {
    PSize¹D::PSize¹D(const ISize¹D& i) : m_size(i.size())
    {
        if(i.size(DISABLED))
            m_flags |= F::Disabled;
        if(i.size(SETTABLE))
            m_flags |= F::Settable;
        if(i.size(ADDABLE))
            m_flags |= F::Addable;
        if(i.size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PSize¹D::~PSize¹D()
    {
    }

    bool        PSize¹D::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize¹D::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize¹D::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize¹D::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize¹D::size(set_k, const Size1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize¹DCommand({.target=object()}, v));
        }
    }

    void        PSize¹D::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PSize¹D::size(add_k, const Size1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize¹DCommand({.target=object()}, Δ));
        }
    }

    void        PSize¹D::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PSize¹D::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeDCommand({.target=object()}, Δ));
        }
    }

    void        PSize¹D::size(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize¹DCommand({.target=object()}, Δ));
        }
    }

    void        PSize¹D::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣDCommand({.target=object()}, Δx));
        }
    }
}
