////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaxSize3D.hpp"
#include <yq/tachyon/command/size/AddMaxSize3DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize3DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize3DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZDCommand.hpp>
#include <yq/tachyon/event/spatial/MaxSize3DEvent.hpp>


namespace yq::tachyon {
    AMaxSize³D::AMaxSize³D()
    {
    }
    
    AMaxSize³D::~AMaxSize³D()
    {
    }

    void        AMaxSize³D::max_size(emit_k)
    {
        send(new MaxSize³DEvent({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize³D::max_size(set_k, const Size3D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize³D::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size3D(v, m_max_size.y, m_max_size.z));
    }
    
    void        AMaxSize³D::max_size(set_k, y_k, double v) 
    {
        max_size(SET, Size3D(m_max_size.x,v, m_max_size.z));
    }
    
    void        AMaxSize³D::max_size(set_k, z_k, double v) 
    {
        max_size(SET, Size3D(m_max_size.x, m_max_size.y, v));
    }
    
    void        AMaxSize³D::max_size(add_k, const Size3D&v) 
    {
        max_size(SET, Size3D( m_max_size.x+v.x, m_max_size.y+v.y, m_max_size.z+v.z ));
    }
    
    void        AMaxSize³D::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x+v, m_max_size.y, m_max_size.z ));
    }
    
    void        AMaxSize³D::max_size(add_k, y_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y+v, m_max_size.z ));
    }
    
    void        AMaxSize³D::max_size(add_k, z_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y, m_max_size.z+v ));
    }

    void        AMaxSize³D::max_size(multiply_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x*v, m_max_size.y*v, m_max_size.z*v ));
    }
    
    void        AMaxSize³D::max_size(multiply_k, const Vector3D& v) 
    {
        max_size(SET, Size3D( m_max_size.x*v.x, m_max_size.y*v.y, m_max_size.z*v.z ));
    }
    
    void        AMaxSize³D::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x*v, m_max_size.y, m_max_size.z ));
    }
    
    void        AMaxSize³D::max_size(multiply_k, y_k, double v) 
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y*v, m_max_size.z ));
    }
    
    void        AMaxSize³D::max_size(multiply_k, z_k, double v)
    {
        max_size(SET, Size3D( m_max_size.x, m_max_size.y, m_max_size.z*v ));
    }
    
    void        AMaxSize³D::on_set_max_size3(const SetMaxSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize³D::on_set_max_sizeX(const SetMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize³D::on_set_max_sizeY(const SetMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize³D::on_set_max_sizeZ(const SetMaxSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Z, cmd.z());
    }

    void        AMaxSize³D::on_add_max_size3(const AddMaxSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize³D::on_add_max_sizeX(const AddMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize³D::on_add_max_sizeY(const AddMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize³D::on_add_max_sizeZ(const AddMaxSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δz());
    }
    
    void        AMaxSize³D::on_multiply_max_size(const MultiplyMaxSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize³D::on_multiply_max_size3(const MultiplyMaxSize³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize³D::on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMaxSize³D::on_multiply_max_sizeY(const MultiplyMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
    
    void        AMaxSize³D::on_multiply_max_sizeZ(const MultiplyMaxSizeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Z, cmd.δz());
    }
}
