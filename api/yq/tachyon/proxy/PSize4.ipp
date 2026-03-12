////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PSize4.hpp>
#include <yq/tachyon/command/size/AddSize4DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeWDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize4DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeWDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetSize4DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeWDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZDCommand.hpp>

namespace yq::tachyon {
    PSize⁴::PSize⁴(const ISize⁴& i) : m_size(i.size())
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

    PSize⁴::~PSize⁴()
    {
    }

    bool        PSize⁴::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize⁴::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize⁴::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize⁴::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize⁴::size(set_k, const Size4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize⁴DCommand({.target=object()}, v));
        }
    }

    void        PSize⁴::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PSize⁴::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸDCommand({.target=object()}, y));
        }
    }
    
    void        PSize⁴::size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeᶻDCommand({.target=object()}, z));
        }
    }

    void        PSize⁴::size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʷDCommand({.target=object()}, w));
        }
    }

    void        PSize⁴::size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PSize⁴::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PSize⁴::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PSize⁴::size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PSize⁴::size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʷDCommand({.target=object()}, Δw));
        }
    }

    void        PSize⁴::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeDCommand({.target=object()}, Δ));
        }
    }

    void        PSize⁴::size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PSize⁴::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PSize⁴::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PSize⁴::size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PSize⁴::size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʷDCommand({.target=object()}, Δw));
        }
    }
}
