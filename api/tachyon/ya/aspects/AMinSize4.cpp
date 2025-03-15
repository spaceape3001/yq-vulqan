////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMinSize4.hpp>
#include <ya/commands/size/AddMinSize4.hpp>
#include <ya/commands/size/AddMinSizeW.hpp>
#include <ya/commands/size/AddMinSizeX.hpp>
#include <ya/commands/size/AddMinSizeY.hpp>
#include <ya/commands/size/AddMinSizeZ.hpp>
#include <ya/commands/size/MultiplyMinSize.hpp>
#include <ya/commands/size/MultiplyMinSize4.hpp>
#include <ya/commands/size/MultiplyMinSizeW.hpp>
#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <ya/commands/size/MultiplyMinSizeY.hpp>
#include <ya/commands/size/MultiplyMinSizeZ.hpp>
#include <ya/commands/size/SetMinSize4.hpp>
#include <ya/commands/size/SetMinSizeW.hpp>
#include <ya/commands/size/SetMinSizeX.hpp>
#include <ya/commands/size/SetMinSizeY.hpp>
#include <ya/commands/size/SetMinSizeZ.hpp>
#include <ya/events/spatial/Size4Event.hpp>


namespace yq::tachyon {
    AMinSize⁴::AMinSize⁴()
    {
    }
    
    AMinSize⁴::~AMinSize⁴()
    {
    }

    void        AMinSize⁴::min_size(emit_k)
    {
        send(new Size⁴Event({.source=typed()}, m_min_size));
    }
    
    void        AMinSize⁴::min_size(set_k, const Size4D& sz) 
    {
        m_min_size  =    sz;
        mark();
        min_size(EMIT);
    }
    
    void        AMinSize⁴::min_size(set_k, x_k, double v) 
    {
        min_size(SET, Size4D(v, m_min_size.y, m_min_size.z, m_min_size.w));
    }
    
    void        AMinSize⁴::min_size(set_k, y_k, double v) 
    {
        min_size(SET, Size4D(m_min_size.x,v, m_min_size.z, m_min_size.w));
    }
    
    void        AMinSize⁴::min_size(set_k, z_k, double v) 
    {
        min_size(SET, Size4D(m_min_size.x, m_min_size.y, v, m_min_size.w));
    }
    
    void        AMinSize⁴::min_size(set_k, w_k, double v) 
    {
        min_size(SET, Size4D(m_min_size.x, m_min_size.y, m_min_size.z, v));
    }

    void        AMinSize⁴::min_size(add_k, const Vector4D&v) 
    {
        min_size(SET, Size4D( m_min_size.x+v.x, m_min_size.y+v.y, m_min_size.z+v.z, m_min_size.w+v.w ));
    }
    
    void        AMinSize⁴::min_size(add_k, x_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x+v, m_min_size.y, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴::min_size(add_k, y_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y+v, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴::min_size(add_k, z_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z+v, m_min_size.w ));
    }

    void        AMinSize⁴::min_size(add_k, w_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z, m_min_size.w+v ));
    }

    void        AMinSize⁴::min_size(multiply_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x*v, m_min_size.y*v, m_min_size.z*v, m_min_size.w*v  ));
    }
    
    void        AMinSize⁴::min_size(multiply_k, const Vector4D& v) 
    {
        min_size(SET, Size4D( m_min_size.x*v.x, m_min_size.y*v.y, m_min_size.z*v.z, m_min_size.w*v.w ));
    }
    
    void        AMinSize⁴::min_size(multiply_k, x_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x*v, m_min_size.y, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴::min_size(multiply_k, y_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y*v, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴::min_size(multiply_k, z_k, double v)
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z*v, m_min_size.w ));
    }
    
    void        AMinSize⁴::min_size(multiply_k, w_k, double v)
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z, m_min_size.w*v ));
    }

    void        AMinSize⁴::on_set_min_size4(const SetMinSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize⁴::on_set_min_sizeW(const SetMinSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, W, cmd.w());
    }
    
    void        AMinSize⁴::on_set_min_sizeX(const SetMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize⁴::on_set_min_sizeY(const SetMinSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize⁴::on_set_min_sizeZ(const SetMinSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Z, cmd.z());
    }

    void        AMinSize⁴::on_add_min_size4(const AddMinSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize⁴::on_add_min_sizeW(const AddMinSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, W, cmd.Δw());
    }
    
    void        AMinSize⁴::on_add_min_sizeX(const AddMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }

    void        AMinSize⁴::on_add_min_sizeY(const AddMinSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize⁴::on_add_min_sizeZ(const AddMinSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δz());
    }
    
    void        AMinSize⁴::on_multiply_min_size(const MultiplyMinSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize⁴::on_multiply_min_size4(const MultiplyMinSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize⁴::on_multiply_min_sizeW(const MultiplyMinSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, W, cmd.δw());
    }
    
    void        AMinSize⁴::on_multiply_min_sizeX(const MultiplyMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }

    void        AMinSize⁴::on_multiply_min_sizeY(const MultiplyMinSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMinSize⁴::on_multiply_min_sizeZ(const MultiplyMinSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Z, cmd.δz());
    }
}
