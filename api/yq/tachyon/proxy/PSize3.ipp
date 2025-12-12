////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PSize3.hpp>
#include <yq/tachyon/command/size/AddSize3Command.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize3Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZCommand.hpp>
#include <yq/tachyon/command/size/SetSize3Command.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZCommand.hpp>

namespace yq::tachyon {
    PSize³::PSize³(const ISize³& i) : m_size(i.size())
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

    PSize³::~PSize³()
    {
    }

    bool        PSize³::size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize³::size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize³::size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PSize³::size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PSize³::size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSize³Command({.target=object()}, v));
        }
    }

    void        PSize³::size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PSize³::size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeʸCommand({.target=object()}, y));
        }
    }
    
    void        PSize³::size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetSizeᶻCommand({.target=object()}, z));
        }
    }

    void        PSize³::size(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSize³Command({.target=object()}, Δ));
        }
    }

    void        PSize³::size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PSize³::size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PSize³::size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PSize³::size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize({.target=object()}, Δ));
        }
    }

    void        PSize³::size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySize³Command({.target=object()}, Δ));
        }
    }

    void        PSize³::size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PSize³::size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PSize³::size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplySizeᶻCommand({.target=object()}, Δz));
        }
    }
}
