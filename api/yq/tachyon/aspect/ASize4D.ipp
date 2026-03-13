////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ASize4D.hpp"
#include <yq/tachyon/command/size/AddSize4DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeWDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize4DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeWDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetSize4DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeWDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZDCommand.hpp>
#include <yq/tachyon/event/spatial/Size4DEvent.hpp>


namespace yq::tachyon {
    ASize⁴D::ASize⁴D()
    {
    }
    
    ASize⁴D::~ASize⁴D()
    {
    }

    void        ASize⁴D::size(emit_k)
    {
        send(new Size⁴DEvent({.source=typed()}, m_size));
    }
    
    void        ASize⁴D::size(set_k, const Size4D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize⁴D::size(set_k, x_k, double v) 
    {
        size(SET, Size4D(v, m_size.y, m_size.z, m_size.w ));
    }
    
    void        ASize⁴D::size(set_k, y_k, double v) 
    {
        size(SET, Size4D(m_size.x,v, m_size.z, m_size.w ));
    }
    
    void        ASize⁴D::size(set_k, z_k, double v) 
    {
        size(SET, Size4D(m_size.x, m_size.y, v, m_size.w ));
    }
    
    void        ASize⁴D::size(set_k, w_k, double v) 
    {
        size(SET, Size4D(m_size.x, m_size.y, m_size.z, v ));
    }
    
    void        ASize⁴D::size(add_k, const Size4D&v) 
    {
        size(SET, Size4D( m_size.x+v.x, m_size.y+v.y, m_size.z+v.z, m_size.w+v.w ));
    }
    
    void        ASize⁴D::size(add_k, x_k, double v) 
    {
        size(SET, Size4D( m_size.x+v, m_size.y, m_size.z, m_size.w ));
    }
    
    void        ASize⁴D::size(add_k, y_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y+v, m_size.z, m_size.w ));
    }
    
    void        ASize⁴D::size(add_k, z_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z+v, m_size.w ));
    }

    void        ASize⁴D::size(add_k, w_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z, m_size.w+v ));
    }

    void        ASize⁴D::size(multiply_k, double v) 
    {
        size(SET, Size4D( m_size.x*v, m_size.y*v, m_size.z*v, m_size.w*v ));
    }
    
    void        ASize⁴D::size(multiply_k, const Vector4D& v) 
    {
        size(SET, Size4D( m_size.x*v.x, m_size.y*v.y, m_size.z*v.z, m_size.w*v.w ));
    }
    
    void        ASize⁴D::size(multiply_k, x_k, double v) 
    {
        size(SET, Size4D( m_size.x*v, m_size.y, m_size.z, m_size.w ));
    }
    
    void        ASize⁴D::size(multiply_k, y_k, double v) 
    {
        size(SET, Size4D( m_size.x, m_size.y*v, m_size.z, m_size.w ));
    }
    
    void        ASize⁴D::size(multiply_k, z_k, double v)
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z*v, m_size.w ));
    }
    
    void        ASize⁴D::size(multiply_k, w_k, double v)
    {
        size(SET, Size4D( m_size.x, m_size.y, m_size.z, m_size.w*v ));
    }

    void        ASize⁴D::on_set_size4(const SetSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize⁴D::on_set_sizeW(const SetSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, W, cmd.w());
    }
    
    void        ASize⁴D::on_set_sizeX(const SetSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize⁴D::on_set_sizeY(const SetSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize⁴D::on_set_sizeZ(const SetSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Z, cmd.z());
    }

    void        ASize⁴D::on_add_size4(const AddSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize⁴D::on_add_sizeW(const AddSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, W, cmd.Δw());
    }
    
    void        ASize⁴D::on_add_sizeX(const AddSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize⁴D::on_add_sizeY(const AddSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize⁴D::on_add_sizeZ(const AddSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δz());
    }
    
    void        ASize⁴D::on_multiply_size(const MultiplySizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize⁴D::on_multiply_size4(const MultiplySize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize⁴D::on_multiply_sizeW(const MultiplySizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, W, cmd.δw());
    }
    
    void        ASize⁴D::on_multiply_sizeX(const MultiplySizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize⁴D::on_multiply_sizeY(const MultiplySizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
    
    void        ASize⁴D::on_multiply_sizeZ(const MultiplySizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Z, cmd.δz());
    }
}
