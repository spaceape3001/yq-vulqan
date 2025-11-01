////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AMaxSize4.hpp>
#include <yq/tachyon/command/size/AddMaxSize4Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeWCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize4Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeWCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize4Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeWCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZCommand.hpp>
#include <yq/tachyon/event/spatial/Size4Event.hpp>


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

    void        AMaxSize⁴::on_set_max_size4(const SetMaxSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize⁴::on_set_max_sizeX(const SetMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize⁴::on_set_max_sizeW(const SetMaxSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, W, cmd.w());
    }

    void        AMaxSize⁴::on_set_max_sizeY(const SetMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize⁴::on_set_max_sizeZ(const SetMaxSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Z, cmd.z());
    }

    void        AMaxSize⁴::on_add_max_size4(const AddMaxSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize⁴::on_add_max_sizeW(const AddMaxSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, W, cmd.Δw());
    }

    void        AMaxSize⁴::on_add_max_sizeX(const AddMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize⁴::on_add_max_sizeY(const AddMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize⁴::on_add_max_sizeZ(const AddMaxSizeᶻCommand&cmd)
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
    
    void        AMaxSize⁴::on_multiply_max_size4(const MultiplyMaxSize⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize⁴::on_multiply_max_sizeW(const MultiplyMaxSizeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, W, cmd.δw());
    }

    void        AMaxSize⁴::on_multiply_max_sizeX(const MultiplyMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }

    void        AMaxSize⁴::on_multiply_max_sizeY(const MultiplyMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMaxSize⁴::on_multiply_max_sizeZ(const MultiplyMaxSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Z, cmd.δz());
    }
}
