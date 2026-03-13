////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMaxSize1D.hpp"

#include <yq/tachyon/command/size/AddMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>

namespace yq::tachyon {
    PMaxSize¹D::PMaxSize¹D(const IMaxSize¹D& i) : m_max_size(i.max_size())
    {
        if(i.max_size(DISABLED))
            m_flags |= F::Disabled;
        if(i.max_size(SETTABLE))
            m_flags |= F::Settable;
        if(i.max_size(ADDABLE))
            m_flags |= F::Addable;
        if(i.max_size(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PMaxSize¹D::~PMaxSize¹D()
    {
    }

    bool        PMaxSize¹D::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize¹D::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize¹D::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize¹D::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize¹D::max_size(set_k, const Size1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize¹DCommand({.target=object()}, v));
        }
    }

    void        PMaxSize¹D::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PMaxSize¹D::max_size(add_k, const Size1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize¹DCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize¹D::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize¹D::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeDCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize¹D::max_size(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize¹DCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize¹D::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣDCommand({.target=object()}, Δx));
        }
    }
}
