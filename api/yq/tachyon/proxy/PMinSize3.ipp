////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PMinSize3.hpp>
#include <yq/tachyon/command/size/AddMinSize3Command.hpp>
#include <yq/tachyon/command/size/AddMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize3Command.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize3Command.hpp>
#include <yq/tachyon/command/size/SetMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZCommand.hpp>

namespace yq::tachyon {
    PMinSize³::PMinSize³(const IMinSize³& i) : m_min_size(i.min_size())
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

    PMinSize³::~PMinSize³()
    {
    }

    bool        PMinSize³::min_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMinSize³::min_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMinSize³::min_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMinSize³::min_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMinSize³::min_size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSize³Command({.target=object()}, v));
        }
    }

    void        PMinSize³::min_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PMinSize³::min_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeʸCommand({.target=object()}, y));
        }
    }
    
    void        PMinSize³::min_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMinSizeᶻCommand({.target=object()}, z));
        }
    }

    void        PMinSize³::min_size(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSize³Command({.target=object()}, Δ));
        }
    }

    void        PMinSize³::min_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize³::min_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize³::min_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMinSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PMinSize³::min_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize({.target=object()}, Δ));
        }
    }

    void        PMinSize³::min_size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSize³Command({.target=object()}, Δ));
        }
    }

    void        PMinSize³::min_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMinSize³::min_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMinSize³::min_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMinSizeᶻCommand({.target=object()}, Δz));
        }
    }
}
