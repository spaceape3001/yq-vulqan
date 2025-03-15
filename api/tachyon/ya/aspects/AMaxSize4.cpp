////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMaxSize4.hpp>
#include <ya/commands/size/AddMaxSize4.hpp>
#include <ya/commands/size/AddMaxSizeW.hpp>
#include <ya/commands/size/AddMaxSizeX.hpp>
#include <ya/commands/size/AddMaxSizeY.hpp>
#include <ya/commands/size/AddMaxSizeZ.hpp>
#include <ya/commands/size/MultiplyMaxSize.hpp>
#include <ya/commands/size/MultiplyMaxSize4.hpp>
#include <ya/commands/size/MultiplyMaxSizeW.hpp>
#include <ya/commands/size/MultiplyMaxSizeX.hpp>
#include <ya/commands/size/MultiplyMaxSizeY.hpp>
#include <ya/commands/size/MultiplyMaxSizeZ.hpp>
#include <ya/commands/size/SetMaxSize4.hpp>
#include <ya/commands/size/SetMaxSizeW.hpp>
#include <ya/commands/size/SetMaxSizeX.hpp>
#include <ya/commands/size/SetMaxSizeY.hpp>
#include <ya/commands/size/SetMaxSizeZ.hpp>
#include <ya/events/spatial/Size4Event.hpp>


namespace yq::tachyon {
    AMaxSize⁴::AMaxSize⁴()
    {
    }
    
    AMaxSize⁴::~AMaxSize⁴()
    {
    }

    void        AMaxSize⁴::max_size(emit_k)
    {
        send(new Size⁴Event({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize⁴::max_size(set_k, const Size4D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize⁴::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size4D(v, m_max_size.y, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(set_k, y_k, double v) 
    {
        max_size(SET, Size4D(m_max_size.x,v, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(set_k, z_k, double v) 
    {
        max_size(SET, Size4D(m_max_size.x, m_max_size.y, v, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(set_k, w_k, double v) 
    {
        max_size(SET, Size4D(m_max_size.x, m_max_size.y, m_max_size.z, v ));
    }

    void        AMaxSize⁴::max_size(add_k, const Vector4D&v) 
    {
        max_size(SET, Size4D( m_max_size.x+v.x, m_max_size.y+v.y, m_max_size.z+v.z, m_max_size.w+v.w ));
    }
    
    void        AMaxSize⁴::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x+v, m_max_size.y, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(add_k, y_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y+v, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(add_k, z_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z+v, m_max_size.w ));
    }

    void        AMaxSize⁴::max_size(add_k, w_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z, m_max_size.w+v ));
    }

    void        AMaxSize⁴::max_size(multiply_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x*v, m_max_size.y*v, m_max_size.z*v, m_max_size.w*v ));
    }
    
    void        AMaxSize⁴::max_size(multiply_k, const Vector4D& v) 
    {
        max_size(SET, Size4D( m_max_size.x*v.x, m_max_size.y*v.y, m_max_size.z*v.z, m_max_size.w*v.w ));
    }
    
    void        AMaxSize⁴::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x*v, m_max_size.y, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(multiply_k, y_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y*v, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(multiply_k, z_k, double v)
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z*v, m_max_size.w ));
    }
    
    void        AMaxSize⁴::max_size(multiply_k, w_k, double v)
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z, m_max_size.w*v ));
    }

    void        AMaxSize⁴::on_set_max_size4(const SetMaxSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize⁴::on_set_max_sizeX(const SetMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize⁴::on_set_max_sizeW(const SetMaxSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, W, cmd.w());
    }

    void        AMaxSize⁴::on_set_max_sizeY(const SetMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize⁴::on_set_max_sizeZ(const SetMaxSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Z, cmd.z());
    }

    void        AMaxSize⁴::on_add_max_size4(const AddMaxSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize⁴::on_add_max_sizeW(const AddMaxSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, W, cmd.Δw());
    }

    void        AMaxSize⁴::on_add_max_sizeX(const AddMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize⁴::on_add_max_sizeY(const AddMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize⁴::on_add_max_sizeZ(const AddMaxSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δz());
    }
    
    void        AMaxSize⁴::on_multiply_max_size(const MultiplyMaxSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize⁴::on_multiply_max_size4(const MultiplyMaxSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize⁴::on_multiply_max_sizeW(const MultiplyMaxSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, W, cmd.δw());
    }

    void        AMaxSize⁴::on_multiply_max_sizeX(const MultiplyMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }

    void        AMaxSize⁴::on_multiply_max_sizeY(const MultiplyMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMaxSize⁴::on_multiply_max_sizeZ(const MultiplyMaxSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Z, cmd.δz());
    }
}
