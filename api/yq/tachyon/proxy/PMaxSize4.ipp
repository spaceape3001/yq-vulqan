////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PMaxSize4.hpp>
#include <yq/tachyon/command/size/AddMaxSize4DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeWDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize4DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeWDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize4DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeWDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZDCommand.hpp>

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
            mail(new SetMaxSize⁴DCommand({.target=object()}, v));
        }
    }

    void        PMaxSize⁴::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣDCommand({.target=object()}, x));
        }
    }
    
    void        PMaxSize⁴::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸDCommand({.target=object()}, y));
        }
    }
    
    void        PMaxSize⁴::max_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeᶻDCommand({.target=object()}, z));
        }
    }

    void        PMaxSize⁴::max_size(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʷDCommand({.target=object()}, w));
        }
    }

    void        PMaxSize⁴::max_size(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize⁴::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize⁴::max_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PMaxSize⁴::max_size(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʷDCommand({.target=object()}, Δw));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeDCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣDCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸDCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PMaxSize⁴::max_size(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʷDCommand({.target=object()}, Δw));
        }
    }
}
