////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PSize1.hpp>
#include <tachyon/command/size/AddSize1Command.hpp>
#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/command/size/MultiplySize1Command.hpp>
#include <tachyon/command/size/MultiplySizeXCommand.hpp>
#include <tachyon/command/size/SetSize1Command.hpp>
#include <tachyon/command/size/SetSizeXCommand.hpp>

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
            mail(new SetSize¹Command({.target=object()}, v));
        }
    }

    void        PSize¹::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PSize¹::size(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize¹Command({.target=object()}, Δ));
        }
    }

    void        PSize¹::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣCommand({.target=object()}, Δx));
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
            mail(new MultiplySize¹Command({.target=object()}, Δ));
        }
    }

    void        PSize¹::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣCommand({.target=object()}, Δx));
        }
    }
}
