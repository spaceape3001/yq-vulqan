////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaxSize4D.hpp"
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
#include <yq/tachyon/event/spatial/MaxSize4DEvent.hpp>


namespace yq::tachyon {
    AMaxSize⁴D::AMaxSize⁴D()
    {
    }
    
    AMaxSize⁴D::~AMaxSize⁴D()
    {
    }

    void        AMaxSize⁴D::max_size(emit_k)
    {
        send(new MaxSize⁴DEvent({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize⁴D::max_size(set_k, const Size4D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize⁴D::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size4D(v, m_max_size.y, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(set_k, y_k, double v) 
    {
        max_size(SET, Size4D(m_max_size.x,v, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(set_k, z_k, double v) 
    {
        max_size(SET, Size4D(m_max_size.x, m_max_size.y, v, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(set_k, w_k, double v) 
    {
        max_size(SET, Size4D(m_max_size.x, m_max_size.y, m_max_size.z, v ));
    }

    void        AMaxSize⁴D::max_size(add_k, const Size4D&v) 
    {
        max_size(SET, Size4D( m_max_size.x+v.x, m_max_size.y+v.y, m_max_size.z+v.z, m_max_size.w+v.w ));
    }
    
    void        AMaxSize⁴D::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x+v, m_max_size.y, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(add_k, y_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y+v, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(add_k, z_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z+v, m_max_size.w ));
    }

    void        AMaxSize⁴D::max_size(add_k, w_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z, m_max_size.w+v ));
    }

    void        AMaxSize⁴D::max_size(multiply_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x*v, m_max_size.y*v, m_max_size.z*v, m_max_size.w*v ));
    }
    
    void        AMaxSize⁴D::max_size(multiply_k, const Vector4D& v) 
    {
        max_size(SET, Size4D( m_max_size.x*v.x, m_max_size.y*v.y, m_max_size.z*v.z, m_max_size.w*v.w ));
    }
    
    void        AMaxSize⁴D::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x*v, m_max_size.y, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(multiply_k, y_k, double v) 
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y*v, m_max_size.z, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(multiply_k, z_k, double v)
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z*v, m_max_size.w ));
    }
    
    void        AMaxSize⁴D::max_size(multiply_k, w_k, double v)
    {
        max_size(SET, Size4D( m_max_size.x, m_max_size.y, m_max_size.z, m_max_size.w*v ));
    }

    void        AMaxSize⁴D::on_set_max_size4(const SetMaxSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize⁴D::on_set_max_sizeX(const SetMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize⁴D::on_set_max_sizeW(const SetMaxSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, W, cmd.w());
    }

    void        AMaxSize⁴D::on_set_max_sizeY(const SetMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize⁴D::on_set_max_sizeZ(const SetMaxSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Z, cmd.z());
    }

    void        AMaxSize⁴D::on_add_max_size4(const AddMaxSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize⁴D::on_add_max_sizeW(const AddMaxSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, W, cmd.Δw());
    }

    void        AMaxSize⁴D::on_add_max_sizeX(const AddMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize⁴D::on_add_max_sizeY(const AddMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize⁴D::on_add_max_sizeZ(const AddMaxSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δz());
    }
    
    void        AMaxSize⁴D::on_multiply_max_size(const MultiplyMaxSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize⁴D::on_multiply_max_size4(const MultiplyMaxSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize⁴D::on_multiply_max_sizeW(const MultiplyMaxSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, W, cmd.δw());
    }

    void        AMaxSize⁴D::on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }

    void        AMaxSize⁴D::on_multiply_max_sizeY(const MultiplyMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMaxSize⁴D::on_multiply_max_sizeZ(const MultiplyMaxSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Z, cmd.δz());
    }
}
