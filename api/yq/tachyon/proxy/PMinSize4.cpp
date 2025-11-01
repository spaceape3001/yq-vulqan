////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/proxy/PMinSize4.hpp>
#include <tachyon/command/size/AddMinSize4Command.hpp>
#include <tachyon/command/size/AddMinSizeWCommand.hpp>
#include <tachyon/command/size/AddMinSizeXCommand.hpp>
#include <tachyon/command/size/AddMinSizeYCommand.hpp>
#include <tachyon/command/size/AddMinSizeZCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <tachyon/command/size/MultiplyMinSize4Command.hpp>
#include <tachyon/command/size/MultiplyMinSizeWCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeZCommand.hpp>
#include <tachyon/command/size/SetMinSize4Command.hpp>
#include <tachyon/command/size/SetMinSizeWCommand.hpp>
#include <tachyon/command/size/SetMinSizeXCommand.hpp>
#include <tachyon/command/size/SetMinSizeYCommand.hpp>
#include <tachyon/command/size/SetMinSizeZCommand.hpp>

namespace yq::tachyon {
    PMinSize⁴::PMinSize⁴(const IMinSize⁴& i) : m_min_size(i.min_size())
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

    PMinSize⁴::~PMinSize⁴()
    {
    }

    bool        PMinSize⁴::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize⁴::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize⁴::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize⁴::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize⁴::min_size(set_k, const Size4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize⁴Command({.target=object()}, v));
        }
    }

    void        PMinSize⁴::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PMinSize⁴::min_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʸCommand({.target=object()}, y));
        }
    }
    
    void        PMinSize⁴::min_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeᶻCommand({.target=object()}, z));
        }
    }

    void        PMinSize⁴::min_size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʷCommand({.target=object()}, w));
        }
    }

    void        PMinSize⁴::min_size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize⁴Command({.target=object()}, Δ));
        }
    }

    void        PMinSize⁴::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize⁴::min_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize⁴::min_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PMinSize⁴::min_size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʷCommand({.target=object()}, Δw));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize({.target=object()}, Δ));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize⁴Command({.target=object()}, Δ));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PMinSize⁴::min_size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʷCommand({.target=object()}, Δw));
        }
    }
}
