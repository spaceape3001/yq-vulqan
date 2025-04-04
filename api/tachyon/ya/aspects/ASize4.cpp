////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/ASize4.hpp>
#include <ya/commands/size/AddSize4.hpp>
#include <ya/commands/size/AddSizeW.hpp>
#include <ya/commands/size/AddSizeX.hpp>
#include <ya/commands/size/AddSizeY.hpp>
#include <ya/commands/size/AddSizeZ.hpp>
#include <ya/commands/size/MultiplySize.hpp>
#include <ya/commands/size/MultiplySize4.hpp>
#include <ya/commands/size/MultiplySizeW.hpp>
#include <ya/commands/size/MultiplySizeX.hpp>
#include <ya/commands/size/MultiplySizeY.hpp>
#include <ya/commands/size/MultiplySizeZ.hpp>
#include <ya/commands/size/SetSize4.hpp>
#include <ya/commands/size/SetSizeW.hpp>
#include <ya/commands/size/SetSizeX.hpp>
#include <ya/commands/size/SetSizeY.hpp>
#include <ya/commands/size/SetSizeZ.hpp>
#include <ya/events/spatial/Size4Event.hpp>


namespace yq::tachyon {
    ASize⁴::ASize⁴()
    {
    }
    
    ASize⁴::~ASize⁴()
    {
    }

    void        ASize⁴::size(emit_k)
    {
        send(new Size⁴Event({.source=typed()}, m_size));
    }
    
    void        ASize⁴::size(set_k, const Size4D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize⁴::size(set_k, x_k, double v) 
    {
        size(SET, Size4D(v, m_size.y, m_size.z, m_size.w ));
    }
    
    void        ASize⁴::size(set_k, y_k, double v) 
    {
        size(SET, Size4D(m_size.x,v, m_size.z, m_size.w ));
    }
    
    void        ASize⁴::size(set_k, z_k, double v) 
    {
        size(SET, Size4D(m_size.x, m_size.y, v, m_size.w ));
    }
    
    void        ASize⁴::size(set_k, w_k, double v) 
    {
        size(SET, Size4D(m_size.x, m_size.y, m_size.z, v ));
    }
    
    void        ASize⁴::size(add_k, const Vector4D&v) 
    {
        size(SET, Size4D( m_size.x+v.x, m_size.y+v.y, m_size.z+v.z, m_size.w+v.w ));
    }
    
    void        ASize⁴::size(add_k, x_k, double v) 
    {
        size(SET, Size4D( m_size.x+v, m_size.y, m_size.z, m_size.w ));
    }
    
    void        ASize⁴::size(add_k, y_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y+v, m_size.z, m_size.w ));
    }
    
    void        ASize⁴::size(add_k, z_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z+v, m_size.w ));
    }

    void        ASize⁴::size(add_k, w_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z, m_size.w+v ));
    }

    void        ASize⁴::size(multiply_k, double v) 
    {
        size(SET, Size4D( m_size.x*v, m_size.y*v, m_size.z*v, m_size.w*v ));
    }
    
    void        ASize⁴::size(multiply_k, const Vector4D& v) 
    {
        size(SET, Size4D( m_size.x*v.x, m_size.y*v.y, m_size.z*v.z, m_size.w*v.w ));
    }
    
    void        ASize⁴::size(multiply_k, x_k, double v) 
    {
        size(SET, Size4D( m_size.x*v, m_size.y, m_size.z, m_size.w ));
    }
    
    void        ASize⁴::size(multiply_k, y_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y*v, m_size.z, m_size.w ));
    }
    
    void        ASize⁴::size(multiply_k, z_k, double v)
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z*v, m_size.w ));
    }
    
    void        ASize⁴::size(multiply_k, w_k, double v)
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z, m_size.w*v ));
    }

    void        ASize⁴::on_set_size4(const SetSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize⁴::on_set_sizeW(const SetSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, W, cmd.w());
    }
    
    void        ASize⁴::on_set_sizeX(const SetSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize⁴::on_set_sizeY(const SetSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize⁴::on_set_sizeZ(const SetSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Z, cmd.z());
    }

    void        ASize⁴::on_add_size4(const AddSize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize⁴::on_add_sizeW(const AddSizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, W, cmd.Δw());
    }
    
    void        ASize⁴::on_add_sizeX(const AddSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize⁴::on_add_sizeY(const AddSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize⁴::on_add_sizeZ(const AddSizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δz());
    }
    
    void        ASize⁴::on_multiply_size(const MultiplySize&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize⁴::on_multiply_size4(const MultiplySize⁴&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize⁴::on_multiply_sizeW(const MultiplySizeʷ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, W, cmd.δw());
    }
    
    void        ASize⁴::on_multiply_sizeX(const MultiplySizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize⁴::on_multiply_sizeY(const MultiplySizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
    
    void        ASize⁴::on_multiply_sizeZ(const MultiplySizeᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Z, cmd.δz());
    }
}
