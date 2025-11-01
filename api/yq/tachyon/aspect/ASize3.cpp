////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/ASize3.hpp>
#include <tachyon/command/size/AddSize3Command.hpp>
#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/command/size/AddSizeYCommand.hpp>
#include <tachyon/command/size/AddSizeZCommand.hpp>
#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/command/size/MultiplySize3Command.hpp>
#include <tachyon/command/size/MultiplySizeXCommand.hpp>
#include <tachyon/command/size/MultiplySizeYCommand.hpp>
#include <tachyon/command/size/MultiplySizeZCommand.hpp>
#include <tachyon/command/size/SetSize3Command.hpp>
#include <tachyon/command/size/SetSizeXCommand.hpp>
#include <tachyon/command/size/SetSizeYCommand.hpp>
#include <tachyon/command/size/SetSizeZCommand.hpp>
#include <tachyon/event/spatial/Size3Event.hpp>


namespace yq::tachyon {
    ASize³::ASize³()
    {
    }
    
    ASize³::~ASize³()
    {
    }

    void        ASize³::size(emit_k)
    {
        send(new Size³Event({.source=typed()}, m_size));
    }
    
    void        ASize³::size(set_k, const Size3D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize³::size(set_k, x_k, double v) 
    {
        size(SET, Size3D(v, m_size.y, m_size.z));
    }
    
    void        ASize³::size(set_k, y_k, double v) 
    {
        size(SET, Size3D(m_size.x,v, m_size.z));
    }
    
    void        ASize³::size(set_k, z_k, double v) 
    {
        size(SET, Size3D(m_size.x, m_size.y, v));
    }
    
    void        ASize³::size(add_k, const Vector3D&v) 
    {
        size(SET, Size3D( m_size.x+v.x, m_size.y+v.y, m_size.z+v.z ));
    }
    
    void        ASize³::size(add_k, x_k, double v) 
    {
        size(SET, Size3D( m_size.x+v, m_size.y, m_size.z ));
    }
    
    void        ASize³::size(add_k, y_k, double v) 
    {
        size(SET, Size3D( m_size.x, m_size.y+v, m_size.z ));
    }
    
    void        ASize³::size(add_k, z_k, double v) 
    {
        size(SET, Size3D( m_size.x, m_size.y, m_size.z+v ));
    }

    void        ASize³::size(multiply_k, double v) 
    {
        size(SET, Size3D( m_size.x*v, m_size.y*v, m_size.z*v ));
    }
    
    void        ASize³::size(multiply_k, const Vector3D& v) 
    {
        size(SET, Size3D( m_size.x*v.x, m_size.y*v.y, m_size.z*v.z ));
    }
    
    void        ASize³::size(multiply_k, x_k, double v) 
    {
        size(SET, Size3D( m_size.x*v, m_size.y, m_size.z ));
    }
    
    void        ASize³::size(multiply_k, y_k, double v) 
    {
        size(SET, Size3D( m_size.x, m_size.y*v, m_size.z ));
    }
    
    void        ASize³::size(multiply_k, z_k, double v)
    {
        size(SET, Size3D( m_size.x, m_size.y, m_size.z*v ));
    }
    
    void        ASize³::on_set_size3(const SetSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize³::on_set_sizeX(const SetSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize³::on_set_sizeY(const SetSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize³::on_set_sizeZ(const SetSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Z, cmd.z());
    }

    void        ASize³::on_add_size3(const AddSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize³::on_add_sizeX(const AddSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize³::on_add_sizeY(const AddSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize³::on_add_sizeZ(const AddSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δz());
    }
    
    void        ASize³::on_multiply_size(const MultiplySize&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize³::on_multiply_size3(const MultiplySize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize³::on_multiply_sizeX(const MultiplySizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize³::on_multiply_sizeY(const MultiplySizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
    
    void        ASize³::on_multiply_sizeZ(const MultiplySizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Z, cmd.δz());
    }
}
