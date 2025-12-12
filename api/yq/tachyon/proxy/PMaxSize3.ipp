////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PMaxSize3.hpp>
#include <yq/tachyon/command/size/AddMaxSize3Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize3Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize3Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZCommand.hpp>

namespace yq::tachyon {
    PMaxSize³::PMaxSize³(const IMaxSize³& i) : m_max_size(i.max_size())
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

    PMaxSize³::~PMaxSize³()
    {
    }

    bool        PMaxSize³::max_size(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PMaxSize³::max_size(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PMaxSize³::max_size(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PMaxSize³::max_size(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PMaxSize³::max_size(set_k, const Size3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSize³Command({.target=object()}, v));
        }
    }

    void        PMaxSize³::max_size(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeˣCommand({.target=object()}, x));
        }
    }
    
    void        PMaxSize³::max_size(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeʸCommand({.target=object()}, y));
        }
    }
    
    void        PMaxSize³::max_size(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMaxSizeᶻCommand({.target=object()}, z));
        }
    }

    void        PMaxSize³::max_size(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSize³Command({.target=object()}, Δ));
        }
    }

    void        PMaxSize³::max_size(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize³::max_size(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize³::max_size(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMaxSizeᶻCommand({.target=object()}, Δz));
        }
    }

    void        PMaxSize³::max_size(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize({.target=object()}, Δ));
        }
    }

    void        PMaxSize³::max_size(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSize³Command({.target=object()}, Δ));
        }
    }

    void        PMaxSize³::max_size(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeˣCommand({.target=object()}, Δx));
        }
    }

    void        PMaxSize³::max_size(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeʸCommand({.target=object()}, Δy));
        }
    }

    void        PMaxSize³::max_size(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMaxSizeᶻCommand({.target=object()}, Δz));
        }
    }
}
