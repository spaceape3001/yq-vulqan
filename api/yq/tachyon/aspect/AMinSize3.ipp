////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMinSize3.hpp"
#include <yq/tachyon/command/size/AddMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize3DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeZDCommand.hpp>
#include <yq/tachyon/event/spatial/MinSize3DEvent.hpp>


namespace yq::tachyon {
    AMinSize³::AMinSize³()
    {
    }
    
    AMinSize³::~AMinSize³()
    {
    }

    void        AMinSize³::min_size(emit_k)
    {
        send(new MinSize³DEvent({.source=typed()}, m_min_size));
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
    
    void        AMinSize³::on_set_min_size3(const SetMinSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize³::on_set_min_sizeX(const SetMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize³::on_set_min_sizeY(const SetMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize³::on_set_min_sizeZ(const SetMinSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Z, cmd.z());
    }

    void        AMinSize³::on_add_min_size3(const AddMinSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize³::on_add_min_sizeX(const AddMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize³::on_add_min_sizeY(const AddMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize³::on_add_min_sizeZ(const AddMinSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δz());
    }
    
    void        AMinSize³::on_multiply_min_size(const MultiplyMinSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize³::on_multiply_min_size3(const MultiplyMinSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize³::on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMinSize³::on_multiply_min_sizeY(const MultiplyMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMinSize³::on_multiply_min_sizeZ(const MultiplyMinSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Z, cmd.δz());
    }
}
