////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMinSize4D.hpp"
#include <yq/tachyon/command/size/AddMinSize4DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeWDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize4DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeWDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize4DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeWDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZDCommand.hpp>
#include <yq/tachyon/event/spatial/MinSize4DEvent.hpp>


namespace yq::tachyon {
    AMinSize⁴D::AMinSize⁴D()
    {
    }
    
    AMinSize⁴D::~AMinSize⁴D()
    {
    }

    void        AMinSize⁴D::min_size(emit_k)
    {
        send(new MinSize⁴DEvent({.source=typed()}, m_min_size));
    }
    
    void        AMinSize⁴D::min_size(set_k, const Size4D& sz) 
    {
        m_min_size  =    sz;
        mark();
        min_size(EMIT);
    }
    
    void        AMinSize⁴D::min_size(set_k, x_k, double v) 
    {
        min_size(SET, Size4D(v, m_min_size.y, m_min_size.z, m_min_size.w));
    }
    
    void        AMinSize⁴D::min_size(set_k, y_k, double v) 
    {
        min_size(SET, Size4D(m_min_size.x,v, m_min_size.z, m_min_size.w));
    }
    
    void        AMinSize⁴D::min_size(set_k, z_k, double v) 
    {
        min_size(SET, Size4D(m_min_size.x, m_min_size.y, v, m_min_size.w));
    }
    
    void        AMinSize⁴D::min_size(set_k, w_k, double v) 
    {
        min_size(SET, Size4D(m_min_size.x, m_min_size.y, m_min_size.z, v));
    }

    void        AMinSize⁴D::min_size(add_k, const Size4D&v) 
    {
        min_size(SET, Size4D( m_min_size.x+v.x, m_min_size.y+v.y, m_min_size.z+v.z, m_min_size.w+v.w ));
    }
    
    void        AMinSize⁴D::min_size(add_k, x_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x+v, m_min_size.y, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴D::min_size(add_k, y_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y+v, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴D::min_size(add_k, z_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z+v, m_min_size.w ));
    }

    void        AMinSize⁴D::min_size(add_k, w_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z, m_min_size.w+v ));
    }

    void        AMinSize⁴D::min_size(multiply_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x*v, m_min_size.y*v, m_min_size.z*v, m_min_size.w*v  ));
    }
    
    void        AMinSize⁴D::min_size(multiply_k, const Vector4D& v) 
    {
        min_size(SET, Size4D( m_min_size.x*v.x, m_min_size.y*v.y, m_min_size.z*v.z, m_min_size.w*v.w ));
    }
    
    void        AMinSize⁴D::min_size(multiply_k, x_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x*v, m_min_size.y, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴D::min_size(multiply_k, y_k, double v) 
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y*v, m_min_size.z, m_min_size.w ));
    }
    
    void        AMinSize⁴D::min_size(multiply_k, z_k, double v)
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z*v, m_min_size.w ));
    }
    
    void        AMinSize⁴D::min_size(multiply_k, w_k, double v)
    {
        min_size(SET, Size4D( m_min_size.x, m_min_size.y, m_min_size.z, m_min_size.w*v ));
    }

    void        AMinSize⁴D::on_set_min_size4(const SetMinSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize⁴D::on_set_min_sizeW(const SetMinSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, W, cmd.w());
    }
    
    void        AMinSize⁴D::on_set_min_sizeX(const SetMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize⁴D::on_set_min_sizeY(const SetMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize⁴D::on_set_min_sizeZ(const SetMinSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Z, cmd.z());
    }

    void        AMinSize⁴D::on_add_min_size4(const AddMinSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize⁴D::on_add_min_sizeW(const AddMinSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, W, cmd.Δw());
    }
    
    void        AMinSize⁴D::on_add_min_sizeX(const AddMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }

    void        AMinSize⁴D::on_add_min_sizeY(const AddMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize⁴D::on_add_min_sizeZ(const AddMinSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δz());
    }
    
    void        AMinSize⁴D::on_multiply_min_size(const MultiplyMinSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize⁴D::on_multiply_min_size4(const MultiplyMinSize⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize⁴D::on_multiply_min_sizeW(const MultiplyMinSizeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, W, cmd.δw());
    }
    
    void        AMinSize⁴D::on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }

    void        AMinSize⁴D::on_multiply_min_sizeY(const MultiplyMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMinSize⁴D::on_multiply_min_sizeZ(const MultiplyMinSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Z, cmd.δz());
    }
}
