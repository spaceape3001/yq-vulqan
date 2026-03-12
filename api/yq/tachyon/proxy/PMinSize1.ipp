////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PMinSize1.hpp>
#include <yq/tachyon/command/size/AddMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>

namespace yq::tachyon {
    PMinSize¹::PMinSize¹(const IMinSize¹& i) : m_min_size(i.min_size())
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

    PMinSize¹::~PMinSize¹()
    {
    }

    bool        PMinSize¹::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize¹::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize¹::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize¹::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize¹::min_size(set_k, const Size1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize¹DCommand({.target=object()}, v));
        }
    }

    void        PMinSize¹::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PMinSize¹::min_size(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize¹DCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize¹::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize¹::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeDCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize¹::min_size(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize¹DCommand({.target=object()}, Δ));
        }
    }

    void        PMinSize¹::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣDCommand({.target=object()}, Δx));
        }
    }
}
