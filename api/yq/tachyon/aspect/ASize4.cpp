////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/ASize4.hpp>
#include <yq/tachyon/command/size/AddSize4Command.hpp>
#include <yq/tachyon/command/size/AddSizeWCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize4Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeWCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeZCommand.hpp>
#include <yq/tachyon/command/size/SetSize4Command.hpp>
#include <yq/tachyon/command/size/SetSizeWCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetSizeZCommand.hpp>
#include <yq/tachyon/event/spatial/Size4Event.hpp>


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

    void        ASize⁴::on_set_size4(const SetSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize⁴::on_set_sizeW(const SetSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, W, cmd.w());
    }
    
    void        ASize⁴::on_set_sizeX(const SetSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize⁴::on_set_sizeY(const SetSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize⁴::on_set_sizeZ(const SetSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Z, cmd.z());
    }

    void        ASize⁴::on_add_size4(const AddSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize⁴::on_add_sizeW(const AddSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, W, cmd.Δw());
    }
    
    void        ASize⁴::on_add_sizeX(const AddSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize⁴::on_add_sizeY(const AddSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize⁴::on_add_sizeZ(const AddSizeᶻCommand&cmd)
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
    
    void        ASize⁴::on_multiply_size4(const MultiplySize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize⁴::on_multiply_sizeW(const MultiplySizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, W, cmd.δw());
    }
    
    void        ASize⁴::on_multiply_sizeX(const MultiplySizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize⁴::on_multiply_sizeY(const MultiplySizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
    
    void        ASize⁴::on_multiply_sizeZ(const MultiplySizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Z, cmd.δz());
    }
}
