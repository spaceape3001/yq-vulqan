////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AMaxSize3.hpp>
#include <yq/tachyon/command/size/AddMaxSize3Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize3Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize3Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZCommand.hpp>
#include <yq/tachyon/event/spatial/Size3Event.hpp>


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
    
    void        AMaxSize³::on_set_max_size3(const SetMaxSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize³::on_set_max_sizeX(const SetMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize³::on_set_max_sizeY(const SetMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize³::on_set_max_sizeZ(const SetMaxSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Z, cmd.z());
    }

    void        AMaxSize³::on_add_max_size3(const AddMaxSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize³::on_add_max_sizeX(const AddMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize³::on_add_max_sizeY(const AddMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize³::on_add_max_sizeZ(const AddMaxSizeᶻCommand&cmd)
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
    
    void        AMaxSize³::on_multiply_max_size3(const MultiplyMaxSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize³::on_multiply_max_sizeX(const MultiplyMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMaxSize³::on_multiply_max_sizeY(const MultiplyMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMaxSize³::on_multiply_max_sizeZ(const MultiplyMaxSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Z, cmd.δz());
    }
}
