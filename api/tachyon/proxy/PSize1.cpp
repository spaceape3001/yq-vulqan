////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PSize1.hpp>
#include <tachyon/command/size/AddSize1.hpp>
#include <tachyon/command/size/AddSizeX.hpp>
#include <tachyon/command/size/MultiplySize.hpp>
#include <tachyon/command/size/MultiplySize1.hpp>
#include <tachyon/command/size/MultiplySizeX.hpp>
#include <tachyon/command/size/SetSize1.hpp>
#include <tachyon/command/size/SetSizeX.hpp>

namespace yq::tachyon {
    PSize¹::PSize¹(const ISize¹& i) : m_size(i.size())
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

    PSize¹::~PSize¹()
    {
    }

    bool        PSize¹::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize¹::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize¹::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize¹::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize¹::size(set_k, const Size1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize¹({.target=object()}, v));
        }
    }

    void        PSize¹::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣ({.target=object()}, x));
        }
    }
    
    void        PSize¹::size(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize¹({.target=object()}, Δ));
        }
    }

    void        PSize¹::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣ({.target=object()}, Δx));
        }
    }

    void        PSize¹::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize¹::size(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize¹({.target=object()}, Δ));
        }
    }

    void        PSize¹::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣ({.target=object()}, Δx));
        }
    }
}
