////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AMinSize4.hpp>
#include <yq/tachyon/command/size/AddMinSize4Command.hpp>
#include <yq/tachyon/command/size/AddMinSizeWCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize4Command.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeWCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize4Command.hpp>
#include <yq/tachyon/command/size/SetMinSizeWCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZCommand.hpp>
#include <yq/tachyon/event/spatial/Size4Event.hpp>


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

    void        AMinSize⁴::on_set_min_size4(const SetMinSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize⁴::on_set_min_sizeW(const SetMinSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, W, cmd.w());
    }
    
    void        AMinSize⁴::on_set_min_sizeX(const SetMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize⁴::on_set_min_sizeY(const SetMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize⁴::on_set_min_sizeZ(const SetMinSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Z, cmd.z());
    }

    void        AMinSize⁴::on_add_min_size4(const AddMinSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize⁴::on_add_min_sizeW(const AddMinSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, W, cmd.Δw());
    }
    
    void        AMinSize⁴::on_add_min_sizeX(const AddMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }

    void        AMinSize⁴::on_add_min_sizeY(const AddMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize⁴::on_add_min_sizeZ(const AddMinSizeᶻCommand&cmd)
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
    
    void        AMinSize⁴::on_multiply_min_size4(const MultiplyMinSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize⁴::on_multiply_min_sizeW(const MultiplyMinSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, W, cmd.δw());
    }
    
    void        AMinSize⁴::on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }

    void        AMinSize⁴::on_multiply_min_sizeY(const MultiplyMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMinSize⁴::on_multiply_min_sizeZ(const MultiplyMinSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Z, cmd.δz());
    }
}
