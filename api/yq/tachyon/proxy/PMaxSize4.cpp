////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PMaxSize4.hpp>
#include <yq/tachyon/command/size/AddMaxSize4Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeWCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize4Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeWCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize4Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeWCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZCommand.hpp>

namespace yq::tachyon {
    PMaxSize⁴::PMaxSize⁴(const IMaxSize⁴& i) : m_max_size(i.max_size())
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

    PMaxSize⁴::~PMaxSize⁴()
    {
    }

    bool        PMaxSize⁴::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize⁴::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize⁴::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize⁴::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize⁴::max_size(set_k, const Size4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize⁴Command({.target=object()}, v));
        }
    }

    void        PMaxSize⁴::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PMaxSize⁴::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸCommand({.target=object()}, y));
        }
    }
    
    void        PMaxSize⁴::max_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeᶻCommand({.target=object()}, z));
        }
    }

    void        PMaxSize⁴::max_size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʷCommand({.target=object()}, w));
        }
    }

    void        PMaxSize⁴::max_size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize⁴Command({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize⁴::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize⁴::max_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PMaxSize⁴::max_size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʷCommand({.target=object()}, Δw));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize⁴Command({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʷCommand({.target=object()}, Δw));
        }
    }
}
