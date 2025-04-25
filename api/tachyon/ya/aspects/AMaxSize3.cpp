////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMaxSize3.hpp>
#include <tachyon/command/size/AddMaxSize3.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/AddMaxSizeY.hpp>
#include <tachyon/command/size/AddMaxSizeZ.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize3.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSizeY.hpp>
#include <tachyon/command/size/MultiplyMaxSizeZ.hpp>
#include <tachyon/command/size/SetMaxSize3.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/command/size/SetMaxSizeZ.hpp>
#include <tachyon/event/spatial/Size3Event.hpp>


namespace yq::tachyon {
    AMaxSize³::AMaxSize³()
    {
    }
    
    AMaxSize³::~AMaxSize³()
    {
    }

    void        AMaxSize³::max_size(emit_k)
    {
        send(new Size³Event({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize³::max_size(set_k, const Size3D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize³::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size3D(v, m_max_size.y, m_max_size.z));
    }
    
    void        AMaxSize³::max_size(set_k, y_k, double v) 
    {
        max_size(SET, Size3D(m_max_size.x,v, m_max_size.z));
    }
    
    void        AMaxSize³::max_size(set_k, z_k, double v) 
    {
        max_size(SET, Size3D(m_max_size.x, m_max_size.y, v));
    }
    
    void        AMaxSize³::max_size(add_k, const Vector3D&v) 
    {
        max_size(SET, Size3D( m_max_size.x+v.x, m_max_size.y+v.y, m_max_size.z+v.z ));
    }
    
    void        AMaxSize³::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x+v, m_max_size.y, m_max_size.z ));
    }
    
    void        AMaxSize³::max_size(add_k, y_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y+v, m_max_size.z ));
    }
    
    void        AMaxSize³::max_size(add_k, z_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y, m_max_size.z+v ));
    }

    void        AMaxSize³::max_size(multiply_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x*v, m_max_size.y*v, m_max_size.z*v ));
    }
    
    void        AMaxSize³::max_size(multiply_k, const Vector3D& v) 
    {
        max_size(SET, Size3D( m_max_size.x*v.x, m_max_size.y*v.y, m_max_size.z*v.z ));
    }
    
    void        AMaxSize³::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x*v, m_max_size.y, m_max_size.z ));
    }
    
    void        AMaxSize³::max_size(multiply_k, y_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y*v, m_max_size.z ));
    }
    
    void        AMaxSize³::max_size(multiply_k, z_k, double v)
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y, m_max_size.z*v ));
    }
    
    void        AMaxSize³::on_set_max_size3(const SetMaxSize³&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize³::on_set_max_sizeX(const SetMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize³::on_set_max_sizeY(const SetMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize³::on_set_max_sizeZ(const SetMaxSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Z, cmd.z());
    }

    void        AMaxSize³::on_add_max_size3(const AddMaxSize³&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize³::on_add_max_sizeX(const AddMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize³::on_add_max_sizeY(const AddMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize³::on_add_max_sizeZ(const AddMaxSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δz());
    }
    
    void        AMaxSize³::on_multiply_max_size(const MultiplyMaxSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize³::on_multiply_max_size3(const MultiplyMaxSize³&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize³::on_multiply_max_sizeX(const MultiplyMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMaxSize³::on_multiply_max_sizeY(const MultiplyMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMaxSize³::on_multiply_max_sizeZ(const MultiplyMaxSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Z, cmd.δz());
    }
}
