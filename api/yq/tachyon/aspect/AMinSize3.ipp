////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AMinSize3.hpp>
#include <yq/tachyon/command/size/AddMinSize3Command.hpp>
#include <yq/tachyon/command/size/AddMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize3Command.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize3Command.hpp>
#include <yq/tachyon/command/size/SetMinSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZCommand.hpp>
#include <yq/tachyon/event/spatial/Size3Event.hpp>


namespace yq::tachyon {
    AMinSize³::AMinSize³()
    {
    }
    
    AMinSize³::~AMinSize³()
    {
    }

    void        AMinSize³::min_size(emit_k)
    {
        send(new Size³Event({.source=typed()}, m_min_size));
    }
    
    void        AMinSize³::min_size(set_k, const Size3D& sz) 
    {
        m_min_size  =    sz;
        mark();
        min_size(EMIT);
    }
    
    void        AMinSize³::min_size(set_k, x_k, double v) 
    {
        min_size(SET, Size3D(v, m_min_size.y, m_min_size.z));
    }
    
    void        AMinSize³::min_size(set_k, y_k, double v) 
    {
        min_size(SET, Size3D(m_min_size.x,v, m_min_size.z));
    }
    
    void        AMinSize³::min_size(set_k, z_k, double v) 
    {
        min_size(SET, Size3D(m_min_size.x, m_min_size.y, v));
    }
    
    void        AMinSize³::min_size(add_k, const Vector3D&v) 
    {
        min_size(SET, Size3D( m_min_size.x+v.x, m_min_size.y+v.y, m_min_size.z+v.z ));
    }
    
    void        AMinSize³::min_size(add_k, x_k, double v) 
    {
        min_size(SET, Size3D( m_min_size.x+v, m_min_size.y, m_min_size.z ));
    }
    
    void        AMinSize³::min_size(add_k, y_k, double v) 
    {
        min_size(SET, Size3D( m_min_size.x, m_min_size.y+v, m_min_size.z ));
    }
    
    void        AMinSize³::min_size(add_k, z_k, double v) 
    {
        min_size(SET, Size3D( m_min_size.x, m_min_size.y, m_min_size.z+v ));
    }

    void        AMinSize³::min_size(multiply_k, double v) 
    {
        min_size(SET, Size3D( m_min_size.x*v, m_min_size.y*v, m_min_size.z*v ));
    }
    
    void        AMinSize³::min_size(multiply_k, const Vector3D& v) 
    {
        min_size(SET, Size3D( m_min_size.x*v.x, m_min_size.y*v.y, m_min_size.z*v.z ));
    }
    
    void        AMinSize³::min_size(multiply_k, x_k, double v) 
    {
        min_size(SET, Size3D( m_min_size.x*v, m_min_size.y, m_min_size.z ));
    }
    
    void        AMinSize³::min_size(multiply_k, y_k, double v) 
    {
        min_size(SET, Size3D( m_min_size.x, m_min_size.y*v, m_min_size.z ));
    }
    
    void        AMinSize³::min_size(multiply_k, z_k, double v)
    {
        min_size(SET, Size3D( m_min_size.x, m_min_size.y, m_min_size.z*v ));
    }
    
    void        AMinSize³::on_set_min_size3(const SetMinSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize³::on_set_min_sizeX(const SetMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize³::on_set_min_sizeY(const SetMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize³::on_set_min_sizeZ(const SetMinSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Z, cmd.z());
    }

    void        AMinSize³::on_add_min_size3(const AddMinSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize³::on_add_min_sizeX(const AddMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize³::on_add_min_sizeY(const AddMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize³::on_add_min_sizeZ(const AddMinSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δz());
    }
    
    void        AMinSize³::on_multiply_min_size(const MultiplyMinSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize³::on_multiply_min_size3(const MultiplyMinSize³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize³::on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMinSize³::on_multiply_min_sizeY(const MultiplyMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMinSize³::on_multiply_min_sizeZ(const MultiplyMinSizeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Z, cmd.δz());
    }
}
